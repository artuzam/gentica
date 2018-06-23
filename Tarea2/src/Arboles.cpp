#include "Arboles.h"


using namespace std;

Arboles::Arboles()
{
    oper.push_back("+");
    oper.push_back("-");
    oper.push_back("/");
    oper.push_back("*");

    // n�meros o t�rminos
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

// crea un �rbol en notaci�n prefija (vector) con altura maxDepth
vector<string> Arboles::crearArbol(int maxDepth){

	srand (time(NULL));
    string::size_type sz;  //alias de size_type, necesaria para el casting
	vector <string>::iterator it;

    vector <string>arbol(31);

	//se llenan con lo que necesita cada uno en formato string para que todos puedan estar en el mismo vector
	// operadores


    //llenar Arbol de Strings vac�os
    fill(arbol.begin(), arbol.end(), "0");

    arbol.at(0) = "x";
    arbol.at(1) = "1";
    arbol.at(2) = "1";

    for(it = arbol.begin(); it != arbol.end(); it++){
        cout << *it << " ";
	}
	cout<<endl;
    cout<<"Max Depth: " << maxDepth <<endl;

    int prof = 1;

    for (unsigned i=0; i<arbol.size(); i++){
        int pos;
        if(arbol.at(i) == "0"){     // condici�n de parada
            break;
        }
        else if(arbol.at(i) == "x"){    // si encuentra una X la cambia por un operador
            pos = randomPos(oper.size());
            arbol.at(i) = oper.at(pos);
        }
        else{
            int hojaOx = randomPos(2);  //si encuentra un n�mero decide si es una hoja o una X
            cout<<"Profundidad: " << prof <<endl;
            if(hojaOx == 0 && prof < maxDepth){ //solo puede ser X si el arbol no va m�s profundo de lo que debe ser
                string aux = arbol.at(i);
                double num = atof (aux.c_str());
                num ++;
                cout<<"NUM: " << num <<endl;
                prof = num;
                cout<<"Profundidad: " << prof <<endl;
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
        for(it = arbol.begin(); it != arbol.end(); it++){
            cout << *it << " ";
        }
        cout<<endl;
    }

    //arbol = insertarPos(arbol, 1, "420");

    //IMPRESI�N
    //cout<<arbol.size();

	return arbol;
}

// retorna un n�mero entre 0 y largo
int Arboles::randomPos(int largo){

	int indice = rand() % largo;
	return indice;
}

// inserta el valor de insertado en las dos posiciones despues de posicion corriendo lo dem�s
vector<string> Arboles::insertarPos(vector<string>& original, int posicion, string insertado){
    int i = 0;
    while(original.at(i) != "0"){
        i++;
    }
    i--;
    while(i != posicion){                    //cuando no ha llegado donde empez�
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

    // encontrar la primera posici�n ocupada, se guarda en pos
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

/* m�todo que devuelve un sub-�rbol a partir de una posici�n pos
   este m�todo no revisa si pos es 0. Eso se tiene que revisar antes de llamarlo
   NO puede ser 0 porque en ese caso el sub-arbol ser�a el �rbol completo
*/
vector<string> Arboles::subArbol(vector<string>& original, int pos){
    vector<string> subArbol;
    bool op = false;
    while (!op){
        if (esOper(original.at(pos)))
            op = true;
        else
            pos--;
    }

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
    string nueva;
    int pos = 3;//randomPos(original.size());
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





