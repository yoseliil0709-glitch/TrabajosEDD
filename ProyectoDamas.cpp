#define _WIN32_WINNT 0x0600
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream> //Lee y escribe archivos
#include <vector>
#include <windows.h>
#include <chrono>
#include <conio.h>

using namespace std::chrono;
using namespace std;

enum Ficha {
    vacio = 0,
    FichaBlanca = 1,
    FichaNegra = 2,
    DamaBlanca = 3,
    DamaNegra = 4
};

int tiempo[3] = {0, 120, 120};
int turno = 1;
steady_clock::time_point tini;
const int limtiem = 120;

int tablero[8][8]; 
//1=FichaBlanca
// 2=FichaNegra
// 3=DamaBlanca
// 4=DamaNegra

struct Mov {
    int filaOri, colOri, filaDes, colDes; //Fila y columna de origen y destino
    int fichaMov; //Valor de la ficha que se movio
    int fichaCom; //Valor de la ficha comida
};

vector<Mov> historial; //Guarda los movimientos
int turnoGua = 1; //Turno actual para reanudar

int curF = 4, curC = 3; //Posicion del cursor(flechas)
int oriF = -1, oriC = -1; //Ficha seleccionada
int desF = -1, desC = -1;
bool haydestino = false; //True cuando ya presiono Enter

void InicializarTablero(){
    for(int f=0; f<8; f++) for(int c=0; c<8; c++) tablero[f][c]=vacio; //Vacia el tablero
    for(int f=0; f<3; f++) for(int c=0; c<8; c++) if((f+c)%2==1) tablero[f][c]=FichaNegra; //Coloca fichas negras arriba
    for(int f=5; f<8; f++) for(int c=0; c<8; c++) if((f+c)%2==1) tablero[f][c]=FichaBlanca; //Coloca fichas blancas abajo
}

int LeerTecla(){
        int t = _getch();
        if(t == 0 || t == 224) t = 256 + _getch();
        return t;
    }

void Esperar(float seg){
    Sleep((DWORD)(seg * 1000));
}

void MostrarTablero(){
    //Diseño del tablero (colores, numeros de coordenadas, posicion de las fichas)
    //Colores ANSI
    string RESET="\033[0m";
    string FONDOCLA="\033[47m";
    string FONDOOSC="\033[100m";
    string B="\033[97;1m";
    string N="\033[30;1m";
    string R="\033[91;1m";
    string A="\033[93;1m";

    cout<<"\n-------  0     1     2     3     4     5     6     7 ---\n";
    for(int f=0; f<8; f++){

        cout << " . " << f << " . "; //Bucle fila por fila
        for(int c=0; c<8; c++){ //Bucle de columnas
            string fondo = ((f+c)%2==0)? FONDOCLA:FONDOOSC;

            if(oriF==f && oriC==c){
             fondo = "\033[43m\033[30m"; //Fondo amarillo texto negro
            }
            if(haydestino && desF==f && desC==c){
             fondo = "\033[46m\033[30m"; //Fondo cian y texto negro
            }
            if(curF==f && curC==c && !(oriF==f && oriC==c)) {
             fondo = "\033[44;1m\033[97;1m"; //Azul fuerte + texto blanco
            }

            // Celdas de ancho fijo (5 caracteres) para que no se rompa la cuadrilla
            if(tablero[f][c]==vacio)        cout << fondo << "  -   " << RESET;
            else if(tablero[f][c]==FichaBlanca) cout << fondo << B << " b    " << RESET; // FICHA BLANCA
            else if(tablero[f][c]==FichaNegra)  cout << fondo << N << " n    " << RESET; // FICHA NEGRA
            else if(tablero[f][c]==DamaBlanca)  cout << fondo << A << " B    " << RESET; // DAMA BLANCA
            else if(tablero[f][c]==DamaNegra)   cout << fondo << R << " N    " << RESET; // DAMA NEGRA
        }
        cout << " " << f << endl;
    }
    cout<<"-------  0     1     2     3     4     5     6     7 ---";
}

void ActuTabl(){
    cout << "\n\n Actualizando el juego......." << endl;
    Sleep(1000); //1 segundo de espera
    system("cls"); //Limpia pantalla
}

bool Comer(int f, int c){
    //Verifica que la ficha en la columna y fila pueda comer fichas del contrincante
    int pieza=tablero[f][c]; if(pieza==vacio) return false; //Obtiene el valor de casilla si es vacia aborta
    //Checa que si en la casilla a continuacion hay una ficha del enemigo
    //Checa si dos casillas adelante esta sin ninguna ficha, si esta vacia devuelve true
    //No permite a las fichas de los jugadores ir hacia su punto de partida (que no avancen las blancas para abajo y las negra para arriba)
    int dirs[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}}; //Aqui revisa las 4 diagonales {-1,-1},{-1,1},{1,-1},{1,1}
    for(int d=0; d<4; d++){ //Intera en las 4 direcciones

        int df=dirs[d][0], dc=dirs[d][1]; //Obtiene el cambio de fila y columna actual

        if(pieza==FichaBlanca && df>0) continue; //Bloquea que las blancas avancen para abajo
        if(pieza==FichaNegra && df<0) continue; //Bloquea que la negra avance para arriba

        int fm=f+df, cm=c+dc, filaDes=f+2*df, colDes=c+2*dc; // Calcula casilla donde esta enemigo y destino final

        if(filaDes<0||filaDes>=8||colDes<0||colDes>=8) continue;
        if(tablero[filaDes][colDes]!=vacio) continue;

        int enemigo=tablero[fm][cm];

        if(pieza==FichaBlanca && (enemigo==FichaNegra||enemigo==DamaNegra)) return true;
        if(pieza==FichaNegra && (enemigo==FichaBlanca||enemigo==DamaBlanca)) return true;
        if(pieza==DamaBlanca && (enemigo==FichaNegra||enemigo==DamaNegra)) return true;
        if(pieza==DamaNegra && (enemigo==FichaBlanca||enemigo==DamaBlanca)) return true;
    }
    return false;
}

//Nos ayuda a recorrer todo el tablero en busca de oportunidades de comer, si hay oportunidad obliga al jugador a hacerlo
bool ComerAFuerzas(int turno){

    for(int f=0; f<8; f++) for(int c=0; c<8; c++){

        int p=tablero[f][c];

        if(turno==1 && (p==FichaBlanca||p==DamaBlanca) && Comer(f,c)) return true;
        if(turno==2 && (p==FichaNegra||p==DamaNegra) && Comer(f,c)) return true;
    }
    return false;
}

//Cuenta las fichas de los jugadores y lo mantiene informado sin que el jugador este contando sus fichas
//Superviza si un jugador gana
int contarFichas(int turno){

    int count=0;

    for(int f=0; f<8; f++) for(int c=0; c<8; c++){
        if(turno==1 && (tablero[f][c]==FichaBlanca||tablero[f][c]==DamaBlanca)) count++;
        if(turno==2 && (tablero[f][c]==FichaNegra||tablero[f][c]==DamaNegra)) count++;
    }
    return count;
}

//Situaciones que valida
//Que la ficha avance a un espacio vacio y dentro del tablero
//Que la ficha avance en forma de diagonal (abs)
//Que el jugador no coma nomas una cuando puede comer dos (no se lo permite lo bloquea)
//Que si se mueve una casilla este correcta la dirreccion de la ficha
//Que si mueve dos casillas este un enemigo en medio de las dos casillas
bool esMovimientoValido(int filaOri, int colOri, int filaDes, int colDes, int turno){

    if(filaDes<0||filaDes>=8||colDes<0||colDes>=8) return false;
    if(tablero[filaDes][colDes]!=vacio) return false;
    if(abs(filaDes-filaOri)!=abs(colDes-colOri)) return false;

    bool Captura=abs(filaDes-filaOri)==2;

    if(ComerAFuerzas(turno) && !Captura) return false;

    int pieza=tablero[filaOri][colOri];

    if(abs(filaDes-filaOri)==1){
        if(pieza==FichaBlanca && filaDes>filaOri) return false;
        if(pieza==FichaNegra && filaDes<filaOri) return false;
        return true;
    }

    if(abs(filaDes-filaOri)==2){
        int fm=(filaOri+filaDes)/2, cm=(colOri+colDes)/2;
        int enemigo=tablero[fm][cm];

        if(turno==1 && enemigo!=FichaNegra && enemigo!=DamaNegra) return false;
        if(turno==2 && enemigo!=FichaBlanca && enemigo!=DamaBlanca) return false;
        return true;
    }
    return false;
}

//Ya con la verificacion anterior permite al jugador moverse
//Si pudo comer el jugador con salto doble borrar la ficha del enemigo que estuvo en medio del movimiento
//Coloca la ficha en el destino que selecciono el jugador
//Convierte fichas a damas (corona) si ficha blanca llega a la fila 0 se hace DamaBlanca y si una negra llega a la fila 7 se hace DamaNegra
void MovimientosTablero(int filaOri, int colOri, int filaDes, int colDes){
    Mov m;
    m.filaOri = filaOri; m.colOri = colOri; m.filaDes = filaDes; m.colDes = colDes;
    m.fichaMov = tablero[filaOri][colOri];
    m.fichaCom = vacio;

    if(abs(filaDes-filaOri)==2){
        m.fichaCom = tablero[(filaOri+filaDes)/2][(colOri+colDes)/2];
        tablero[(filaOri+filaDes)/2][(colOri+colDes)/2] = vacio;
    }

    historial.push_back(m);
    tablero[filaDes][colDes]=tablero[filaOri][colOri];
    tablero[filaOri][colOri]=vacio;

    if(tablero[filaDes][colDes]==FichaBlanca && filaDes==0) tablero[filaDes][colDes]=DamaBlanca;
    if(tablero[filaDes][colDes]==FichaNegra && filaDes==7) tablero[filaDes][colDes]=DamaNegra;
}

bool TieneMovimientos(int turno){

    for(int f=0; f<8; f++)

        for(int c=0; c<8; c++){

            int p = tablero[f][c]; //Obtiene movimientos

            //Ignora las fichas del contrincante
            if(turno==1 && (p!=FichaBlanca && p!=DamaBlanca)){
            continue;
            }
            if(turno==2 && (p!=FichaNegra && p!=DamaNegra)){
            continue;
            }

            int dirs[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}}; //Revisa las 4 diagonales
            for(int d=0; d<4; d++){
                int nf=f+dirs[d][0], nc=c+dirs[d][1]; //Casilla diagonal adyacente

                if(nf>=0&&nf<8&&nc>=0&&nc<8 && tablero[nf][nc]==vacio) return true; //Casilla vacia en el tablero
                int nf2=f+2*dirs[d][0], nc2=c+2*dirs[d][1];//Casila de salto(doble diagonal)
                //Hay enemigo enmedio y destino libre
                if(nf2>=0&&nf2<8&&nc2>=0&&nc2<8 && tablero[nf2][nc2]==vacio && tablero[nf][nc]!=vacio && tablero[nf][nc]!=p) return true;
            }
        }
    return false; //Ninguna ficha se movio
}

void GuarPar(const string& archivo){
    string nombreFinal = archivo + ".txt";
    ofstream file(nombreFinal);
    if(!file){
        cout << "No se puede abrir el archivo\n";
        return;
    }
    file << turnoGua << "\n"; // Turno

    for(int f = 0; f < 8; f++){//Tablero completo
      for(int c = 0; c < 8; c++){ file << tablero[f][c] << " ";
      }
      file << "\n";
    }
    file << historial.size() << "\n"; //Cantidad de movimiento

    for(size_t i = 0; i<historial.size(); i++){ //Cada movimiento
      file << historial[i].filaOri << " " << historial[i].colOri << " "
             << historial[i].filaDes << " " << historial[i].colDes << " "
             << historial[i].fichaMov << " " << historial[i].fichaCom << "\n";
    }
    file << tiempo[1] << " " << tiempo[2] << "\n";
    file.close();
    cout << "Partida guardada en: " << archivo << endl;
}

void CarParti(const string& archivo){
    ifstream file(archivo); //Abre archivo
    if(!file){
        cout << "No existe ninguna partida guardada\n";
        return;
    }
    historial.clear(); //Vacia el historial anterior

    file >> turnoGua; //De que turno se reanuda el juego

    //Recorre todo el tablero
    for(int f = 0; f < 8; f++){
        for(int c = 0; c < 8; c++){
            file >> tablero[f][c];
        }
    }
    int n;
    file >> n;

    for(int i = 0; i < n; i++){
        Mov m;
        file >> m.filaOri >> m.colOri >> m.filaDes >> m.colDes >> m.fichaMov >> m.fichaCom;
        historial.push_back(m);
    }
    file >> tiempo[1] >> tiempo[2];
    file.close();
    cout << "Partida cargada desde: " << archivo << endl;
}

vector<string> ListarArchivosGuardados(){
    vector<string> partidas;
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA("*.txt", &findData);
    
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (strcmp(findData.cFileName, ".") != 0 && 
                strcmp(findData.cFileName, "..") != 0 &&
                !(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                partidas.push_back(findData.cFileName);
            }
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
    return partidas;
}

void MostrarHis(){
    if (historial.empty()){
        cout << "No hay movimientos guardados"<< endl;
        return;
    }
    cout << "++++++++++Movimientos guardados+++++++++"<< endl;
    for (size_t i = 0; i < historial.size(); i++){
        cout << (i + 1) << ") Origen: [" << historial[i].filaOri << "," << historial[i].colOri << "] -> Destino: [" << historial[i].filaDes << "," << historial[i].colDes << "]";
             cout << " [Ficha capturada: ";
        if (historial[i].fichaCom == FichaBlanca) cout << "FichaBlanca";
        else if (historial[i].fichaCom == FichaNegra) cout << "FichaNegra";
        else if (historial[i].fichaCom == DamaBlanca) cout << "DamaBlanca";
        else if (historial[i].fichaCom == DamaNegra) cout << "DamaNegra";
        else cout << "vacio";
        cout << "]";
        cout << endl;
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
}

void error(const string& msg){
    system("cls");
    MostrarTablero();
    cout << "\nFichas blancas: " << contarFichas(1) << "| Negras: " << contarFichas(2) << endl;
    cout << "Tiempo blancas: " << tiempo[1] << "s | Negras: " << tiempo[2] << "s\n";
    cout << "\nTurno " << (turno==1? "BLANCAS (b)":"NEGRAS(n)") << endl;
    cout << "(O) Origen | (X) Rendirse | (G) Guardar | (H) Historial " << endl;
    cout << "\n ERROR " << msg << endl;
}

int main(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD m = 0;
    GetConsoleMode(h, &m);
    SetConsoleMode(h, m | 0x0004);
    char opc;
    cout << "Partida nueva (N) o partida guardada (G): ";
    cin >> opc;

    if (opc == 'G' || opc == 'g'){
        vector<string> partidas = ListarArchivosGuardados();
        
        if(partidas.empty()){
            cout << "No hay partidas guardadas encontradas.\n";
            InicializarTablero(); historial.clear(); turnoGua = 1;
        } else {
            cout << "\n=== PARTIDAS GUARDADAS ===\n";
            for(size_t i=0; i<partidas.size(); i++){
                cout << "[" << i+1 << "] " << partidas[i] << endl;
            }
            cout << "============================\n";
            
            int sel;
            cout << "Elige un numero para cargar: ";
            cin >> sel;
            
            if(sel >= 1 && sel <= (int)partidas.size()){
                CarParti(partidas[sel-1]);
            } else {
                cout << "Opcion invalida, iniciando partida nueva.\n";
                InicializarTablero(); historial.clear(); turnoGua = 1;
            }
        }
    } else{
        InicializarTablero();
        historial.clear();
        turnoGua = 1;
    }

    //Se llena el tablero de 0 y despues se ponen las fichas
    turno = turnoGua;
    int filaOri,colOri,filaDes,colDes;
    char accion;

    while(true){
        MostrarTablero();
        tini = steady_clock::now(); //Empieza el tiempo
        cout << "\nFichas Blancas: "<<contarFichas(1)<<" | Negras: "<<contarFichas(2)<<endl;
        cout << "Tiempo blancas: "<< tiempo[1] << "s | Negras: " << tiempo[2] << "s\n";

        if(contarFichas(1)==0){
            cout << "\nGANAN NEGRAS\n"; break;
        }
        
        if(contarFichas(2)==0){
            cout << "\nGANAN BLANCAS\n"; break;
        }

        if(!TieneMovimientos(turno)){
        cout << "\nGANAN " << (turno==1?"NEGRAS":"BLANCAS") << " (rival sin movimientos)\n";
        break;
        }
        
        cout<<"\nTurno "<<(turno==1?"BLANCAS (b)":"NEGRAS (n)")<<endl;
        cout << "(O) Origen | (X) Rendirse | (G) Guardar | (H) Historial " <<endl;
        cin >> accion;

        int turnojug = turno; //Guarda el turno actual

        if(accion=='X' || accion=='x'){
        cout << "\nGanan " << (turno==1?"NEGRAS":"BLANCAS") << " por rendicion\n"<<endl;
        break; // Sale del while(true) y termina el juego
        }

        if(accion == 'G' || accion == 'g'){
            string nombre;
            cout << "Nombre del archivo guardado: ";
            cin >> nombre;
            GuarPar(nombre);
            continue;
        }

        if(accion == 'H' || accion == 'h'){
            MostrarHis();
            continue;
        }

        if(accion != 'O' && accion != 'o'){
            error("Opcion incorrecta\n");
            continue;
        }
        oriF = -1; oriC = -1; desF = -1; desC = -1; haydestino = false;

while(true){
    system("cls");
    MostrarTablero();
    cout << "\nMuevete con las FLECHAS | ENTER: seleccionar/confirmar | ESC: cancelar\n";

    int t = LeerTecla();

    if(t == 27){ accion = 'X'; break; }  

    if(t == 256+72 && curF > 0) curF--;       
    if(t == 256+80 && curF < 7) curF++;        
    if(t == 256+75 && curC > 0) curC--;       
    if(t == 256+77 && curC < 7) curC++;        

    if(t == 13){
        if(!haydestino){
            // Primera vez: selecciona ficha (se pone amarilla)
            if(turno==1 && tablero[curF][curC]!=FichaBlanca && tablero[curF][curC]!=DamaBlanca){
                error("Esa ficha blanca no es tuya"); continue;
            }
            if(turno==2 && tablero[curF][curC]!=FichaNegra && tablero[curF][curC]!=DamaNegra){
                error("Esa ficha negra no es tuya"); continue;
            }
            oriF = curF; oriC = curC;
        } else {
            // Confirma destino (ya está CIAN)
            break;
        }
    }

    // Si ya hay ficha seleccionada y se mueve, marca destino posible
    if(oriF != -1 && (t==256+72||t==256+80||t==256+75||t==256+77)){
        desF = curF; desC = curC; haydestino = true;
    }
}

if(accion == 'X') break;

filaOri = oriF; colOri = oriC;
filaDes = desF; colDes = desC;

        if(esMovimientoValido(filaOri,colOri,filaDes,colDes,turno)){
            MovimientosTablero(filaOri,colOri,filaDes,colDes);

            turno = (turno == 1)?2:1;
            turnoGua = turno;

            ActuTabl();

            if(abs(filaDes-filaOri)==2 && Comer(filaDes,colDes)){
                cout<<"¡¡Continua comiendo con la misma ficha!!\n"<<endl;
                continue;
            }
            
        }else {
            error("Lo siento, no se puede realizar el movimiento deseado\n");
        }
        int gastado = (int)duration_cast<seconds> (steady_clock::now()-tini).count();
        tiempo[turnojug] -= gastado;
        if(tiempo[turnojug] <= 0){
            cout << "\nSE ACABO EL TIEMPO. GANAN " << (turnojug == 1?"NEGRAS":"BLANCAS") << endl;
            break;
        }
    }
    return 0;
}