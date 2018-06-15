#include "Arboles.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

Arboles::Arboles()
{
    //ctor
}

Arboles::~Arboles()
{
    //dtor
}

vector<string> Arboles::crearArbol(int maxDepth){

	srand (time(NULL));

	vector <string>::iterator it;
	//vector <string>::iterator it2;

	vector <string>oper; //vector de operadores
	vector <string>term; //vector de constantes
	vector <string>var;  //vector de variables

    vector <string>arbol(31);

    string::size_type sz;  //alias de size_type, necesaria para el casting

	//se llenan con lo que necesita cada uno en formato string para que todos puedan estar en el mismo vector
	oper.push_back("+");
    oper.push_back("-");
    oper.push_back("/");
    oper.push_back("*");

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

    var.push_back("1");
    var.push_back("2");
    var.push_back("3");
    var.push_back("4");
    var.push_back("5");
    var.push_back("6");
    var.push_back("7");
    var.push_back("8");
    var.push_back("9");
    var.push_back("10");
    var.push_back("11");
    var.push_back("12");

    //llenar Arbol de Strings vacíos
    fill(arbol.begin(), arbol.end(), "0");

    //IMPRESIÓN
    arbol.at(0) = "x";
    arbol.at(1) = "1";
    arbol.at(2) = "1";

    cout<<arbol.size()<<endl;

    cout<<"Empieza: "<<endl;

    for (unsigned i=0; i<arbol.size(); i++){
        int pos;
        if(arbol.at(i) == "0"){
            break;
        }
        else if(arbol.at(i) == "x"){
            // cout<<"Se mete"<<endl;
            pos = randomPos(oper.size());
            arbol.at(i) = oper.at(pos);
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
        cout << *it << endl;
	}
    /*


    */

	return arbol;

}

int Arboles::randomPos(int largo){

	int indice = rand() % largo;
	cout << "indice:"<<indice<<endl;
	return indice;

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


