#include "Arboles.h"


using namespace std;

Arboles::Arboles()
{
    oper.push_back("+");
    oper.push_back("-");
    oper.push_back("/");
    oper.push_back("*");

    // números o términos
    term.push_back("-1");
    term.push_back("-2");
    term.push_back("-3");
    term.push_back("-4");
    term.push_back("-5");
    term.push_back("-6");
    term.push_back("-7");
    term.push_back("-8");
    term.push_back("-9");
    term.push_back("1");
    term.push_back("2");
    term.push_back("3");
    term.push_back("4");
    term.push_back("5");
    term.push_back("6");
    term.push_back("7");
    term.push_back("8");
    term.push_back("9");
    term.push_back("-0.1");
    term.push_back("-0.01");
    term.push_back("-0.001");
    term.push_back("0.1");
    term.push_back("0.01");
    term.push_back("0.001");

    // variables. Se representan con este nombre pero luego tienen el valor que entra por el archivo
    var.push_back("v1");
    var.push_back("v2");
    var.push_back("v3");
    var.push_back("v4");
    var.push_back("v5");
    var.push_back("v6");
    var.push_back("v7");
    var.push_back("v8");
    var.push_back("v9");
    var.push_back("v10");
    var.push_back("v11");
    var.push_back("v12");
}

Arboles::~Arboles()
{
    //dtor
}

// crea un árbol en notación prefija (vector) con altura maxDepth
vector<string> Arboles::crearArbol(int maxDepth){

    //srand (time(NULL));
    string::size_type sz;  //alias de size_type, necesaria para el casting
    vector <string>::iterator it;

    vector <string>arbol(2047);

    //se llenan con lo que necesita cada uno en formato string para que todos puedan estar en el mismo vector
    // operadores
    //llenar Arbol de Strings vacíos
    fill(arbol.begin(), arbol.end(), "0");

    arbol.at(0) = "x";
    arbol.at(1) = "1";
    arbol.at(2) = "1";

    int prof = 1;

    for (unsigned i=0; i<arbol.size(); i++){
        int pos;
        if(arbol.at(i) == "0"){     // condición de parada
            break;
        }
        else if(arbol.at(i) == "x"){    // si encuentra una X la cambia por un operador
            pos = randomPos(oper.size());
            arbol.at(i) = oper.at(pos);
        }
        else{
            int hojaOx = randomPos(2);  //si encuentra un número decide si es una hoja o una X
            if(hojaOx == 0 && prof < maxDepth){ //solo puede ser X si el arbol no va más profundo de lo que debe ser
                string aux = arbol.at(i);
                double num = atof (aux.c_str());
                num ++;
                prof = num;
                std::ostringstream os;
                os << num;
                std::string str = os.str();
                arbol.at(i) = "x";
                insertarPos(arbol, i, str);
                i--;
            }
            else{
                int varonum = randomPos(2);
                if (varonum == 0){
                    pos = randomPos(term.size());
                    arbol.at(i) = term.at(pos);
                }
                else{
                    pos = randomPos(var.size());
                    arbol.at(i) = var.at(pos);
                }
            }
        }
    }
    return arbol;
}

// retorna un número entre 0 y largo
int Arboles::randomPos(int largo){

    int indice = rand() % largo;
    return indice;
}

// inserta el valor de insertado en las dos posiciones despues de posicion corriendo lo demás
vector<string> Arboles::insertarPos(vector<string>& original, int posicion, string insertado){
    int i = 0;
    while(original.at(i) != "0"){
        i++;
    }
    i--;
    while(i != posicion){                    //cuando no ha llegado donde empezó
        original.at(i+2) = original.at(i);
        i--;
    }
    original.at(posicion+1) = insertado;
    original.at(posicion+2) = insertado;

    return original;
}

// para ver si un elemento del vector es operador u operando. Sirve para resolver
bool Arboles::esOper(string s){
    bool es;
    if (s == "+" || s == "-" || s == "*" || s == "/"){
        es = true;
    }
    else{
        es = false;
    }
    return es;
}


double Arboles::solucionar(vector<string>& entrada){
    stack <double> solve;
    int pos;
    double res;

    // encontrar la primera posición ocupada, se guarda en pos
    pos = entrada.size()-1;
    bool encontrado = false;
    while(pos >= 0 && encontrado == false){
        if (entrada.at(pos) != "0")
            encontrado = true;
        else{
            pos--;
        }
    }

    // solucionar
    for(int i = pos; i >= 0; i--){
        if(!esOper(entrada.at(i))){
            string aux = entrada.at(i);
            solve.push(atof (aux.c_str()));
        }
        else{
            double a = solve.top();
            solve.pop();
            double b = solve.top();
            solve.pop();
            string oper = entrada.at(i);
            if (oper == "+"){
                solve.push(a+b);
            }
            else if(oper == "*"){
                solve.push(a*b);
            }
            else if(oper == "-"){
                solve.push(a-b);
            }
            else if(oper == "/"){
                solve.push(a/b);
            }
        }
    }
    res = solve.top();
    return res;
}

/* método que devuelve un sub-árbol a partir de una posición pos
   este método no revisa si pos es 0. Eso se tiene que revisar antes de llamarlo
   NO puede ser 0 porque en ese caso el sub-arbol sería el árbol completo
*/
vector<string> Arboles::subArbol(vector<string>& original, int pos){
    vector<string> subArbol;
    /*bool op = false;
    while (!op){
        if (esOper(original.at(pos)))
            op = true;
        else
            pos--;
    }
    */
    int cont = 1;

    while (cont > 0){
            if(esOper(original.at(pos))){
                subArbol.push_back(original.at(pos));
                cont++;
            }
            else{
                subArbol.push_back(original.at(pos));
                cont--;
            }
            pos++;
    }
    return subArbol;
}

vector<string> Arboles::mutar(vector<string>& original){
    srand (time(NULL));

    int posFin = original.size()-1;
    bool encontrado = false;
    while(posFin >= 0 && encontrado == false){
        if (original.at(posFin) != "0")
            encontrado = true;
        else{
            posFin--;
        }
    }

    string nueva;
    int pos = randomPos(posFin);
    if(esOper(original.at(pos))){
        nueva = oper.at(randomPos(oper.size()));
        original.at(pos) = nueva;
    }
    else{
        int varonum = randomPos(2);
            if (varonum == 0){
                nueva = term.at(randomPos(term.size()));
                original.at(pos) = nueva;
            }
            else{
                nueva = var.at(randomPos(var.size()));
                original.at(pos) = nueva;
            }
    }
    return original;
}


vector < vector<string> > Arboles::leer(){

    ifstream in("wine.txt");
    string bufferFila;
    vector < vector<string> > matrix;

    while (getline(in, bufferFila)) {
        if(bufferFila.size() > 0) {
            stringstream ss(bufferFila);
            string bufferNumero;
            vector<string> row;

            while(getline(ss, bufferNumero, ',')) {
                row.push_back(bufferNumero.c_str());
            }
            matrix.push_back(row);
        }
    }
    /*
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    */
    return matrix;
}



vector<string> Arboles::sustitucionVar(int fila, vector<string>& arbol, vector < vector<string> >& datos ){
     //int columnas = 12;
     string str;

     for(unsigned i = 0; i < arbol.size(); i++){

        str = arbol.at(i);

        if(str == "v1")
            arbol.at(i) = datos[fila][1];
        else
            if(str == "v2")
            arbol.at(i) = datos[fila][2];
        else
            if(str == "v3")
            arbol.at(i) = datos[fila][3];
        else
            if(str == "v4")
            arbol.at(i) = datos[fila][4];
        else
            if(str == "v5")
            arbol.at(i) = datos[fila][5];
        else
            if(str == "v6")
            arbol.at(i) = datos[fila][6];
        else
            if(str == "v7")
            arbol.at(i) = datos[fila][7];
        else
            if(str == "v8")
            arbol.at(i) = datos[fila][8];
        else
            if(str == "v9")
            arbol.at(i) = datos[fila][9];
        else
            if(str == "v10")
            arbol.at(i) = datos[fila][10];
        else
            if(str == "v11")
            arbol.at(i) = datos[fila][11];
        else
            if(str == "v12")
            arbol.at(i) = datos[fila][12];

    } //fin del for

 return arbol;
}

void Arboles::cruzar (vector<string>& v1, vector<string>& v2){
    srand (time(NULL));

    //determinar tamaño real de ambos vectores, es decir, hasta donde están llenos
    int posFin1 = v1.size()-1;
    bool encontrado = false;
    while(posFin1 >= 0 && encontrado == false){
        if (v1.at(posFin1) != "0")
            encontrado = true;
        else{
            posFin1--;
        }
    }
    int posFin2 = v2.size()-1;
    encontrado = false;
    while(posFin2 >= 0 && encontrado == false){
        if (v2.at(posFin2) != "0")
            encontrado = true;
        else{
            posFin2--;
        }
    }
    //posiciones aleatorias que no sean 0
    int part1 = randomPos(posFin1);
    int part2 = randomPos(posFin2);
    if(part1 == 0)
        part1++;
    if(part2 == 0)
        part2++;

    cout<<"part1: "<<part1<<endl;
    cout<<"part2: "<<part2<<endl;

    //definir los sub-arboles
    vector<string> subv1 = subArbol(v1, part1);
    vector<string> subv2 = subArbol(v2, part2);

    cout<<"Crea sub-arboles:"<<endl;
    for (unsigned i = 0; i < subv1.size(); i++){
        cout<<subv1.at(i)<<" ";
    }
    cout<<endl;

    for (unsigned i = 0; i < subv2.size(); i++){
        cout<<subv2.at(i)<<" ";
    }
    cout<<endl;

    if (subv1.size() == subv2.size()){
        for (unsigned i = 0; i < subv1.size(); i++){
            v1.at(part1+i) = subv2.at(i);
            v2.at(part2+i) = subv1.at(i);
        }
    }
    else{
        if(subv1.size() > subv2.size()){
            int dif = subv1.size() - subv2.size();
            int i = posFin1;
            int j = part2 + dif;
            //hacer campo en v2
            while(i != part1){
                v2.at(i+dif) = v2.at(i);
                i--;
            }
            //cerrar el campo en v1
            while(j != posFin1){
                v1.at(i-dif) = v1.at(i);
            }
        }
        else{
            int dif = subv1.size() - subv2.size();
            int i = posFin2;
            int j = part1 + dif;
            //hacer campo en v1
            while(i != part2){
                v1.at(i+dif) = v1.at(i);
                i--;
            }
            //cerrar el campo en v2
            while(j != posFin2){
                v2.at(i-dif) = v2.at(i);
                j--;
            }
        }
        for (unsigned i = 0; i < subv2.size(); i++){
            v1.at(part1+i) = subv2.at(i);
        }
        for (unsigned i = 0; i < subv1.size(); i++){
            v2.at(part2+i) = subv1.at(i);
        }
    }
}

// crea 500 árboles aleatorios de tamaños variables
vector < vector<string> > Arboles :: crearGeneracion(){
    srand(time(NULL));
    vector < vector<string> > matrix;

    for (unsigned i = 0; i < 83; i++){
        vector<string> aux = crearArbol(5);
        matrix.push_back(aux);
    }

    for (unsigned i = 83; i < 166; i++){
         matrix.push_back(crearArbol(6));
    }

    for (unsigned i = 166; i < 249; i++){
         matrix.push_back(crearArbol(7));
    }

    for (unsigned i = 249; i < 332; i++){
        matrix.push_back(crearArbol(8));
    }

    for (unsigned i = 332; i < 415; i++){
        matrix.push_back(crearArbol(9));
    }

    for (unsigned i = 415; i < 500; i++){
        matrix.push_back(crearArbol(10));
    }

    return matrix;
}






