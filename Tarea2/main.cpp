#include <iostream>
#include "Arboles.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>


using namespace std;

int main()
{
     Arboles * objeto = new Arboles();

    //lee el archivo wine.txt y regresa vector
    vector < vector<string> > temp = objeto->leer();
    vector<string> prueba = objeto->crearArbol(5);

    vector<string> subs = objeto->sustitucionVar(0, prueba, temp);

     cout << "Sustituimos los var" << endl;

    for(int i = 0; i < subs.size(); i++){
        cout << subs.at(i) << " ";
    }


/**

    //imprime matriz para ver si se metieron bien los valores
      for(int i = 0; i < temp.size(); i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
**/


    //vector<string> prueba= objeto->crearArbol(5);
    //cout<<prueba.size();




    /*

    //pruebas de subArbol y solucionar
    vector<string> prueba;
    prueba.push_back("/");
    prueba.push_back("2");
    prueba.push_back("*");
    prueba.push_back("6");
    prueba.push_back("2");
    prueba.push_back("0");
    prueba.push_back("0");
    prueba.push_back("0");
    prueba.push_back("0");

    for (unsigned i = 0; i < prueba.size(); i++){
        cout<<prueba.at(i);
    }
    cout<<endl;

    double res = objeto->solucionar(prueba);
    cout<<"Resultado:"<<res<<endl;

    vector<string> sub = objeto->subArbol(prueba, 3);
    for (unsigned i = 0; i < sub.size(); i++){
        cout<<sub.at(i);
    }
    cout<<endl;

    prueba = objeto->mutar(prueba);
    for (unsigned i = 0; i < prueba.size(); i++){
        cout<<prueba.at(i);
    }
    cout<<endl;

**/
    return 0;
}

