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
    srand(time(NULL));

    Arboles * objeto = new Arboles();

    //vector < vector<string> > temp = objeto->crearGeneracion();

    //lee el archivo wine.txt y regresa vector
    /*
    vector < vector<string> > temp = objeto->leer();

    vector<string> subs = objeto->sustitucionVar(0, prueba, temp);

    cout << "Sustituimos los var" << endl;

    for(unsigned i = 0; i < subs.size(); i++){
        cout << subs.at(i) << " ";
    }
    */

/*

    //imprime matriz para ver si se metieron bien los valores
      for(int i = 0; i < temp.size(); i++) {
        for(int j = 0; j < temp[i].size(); j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
*/


    //vector<string> prueba= objeto->crearArbol(5);
    //cout<<prueba.size();






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

    vector<string> prueba2;
    prueba2.push_back("+");
    prueba2.push_back("/");
    prueba2.push_back("7");
    prueba2.push_back("5");
    prueba2.push_back("-3");
    prueba2.push_back("0");
    prueba2.push_back("0");
    prueba2.push_back("0");
    prueba2.push_back("0");

    for (unsigned i = 0; i < prueba.size(); i++){
        cout<<prueba.at(i)<<" ";
    }
    cout<<endl;

    for (unsigned i = 0; i < prueba2.size(); i++){
        cout<<prueba2.at(i)<<" ";
    }
    cout<<endl;

    objeto->cruzar(prueba, prueba2);

    cout<<"Cruzados"<<endl;
    for (unsigned i = 0; i < prueba.size(); i++){
        cout<<prueba.at(i)<<" ";
    }
    cout<<endl;

    for (unsigned i = 0; i < prueba2.size(); i++){
        cout<<prueba2.at(i)<<" ";
    }
    cout<<endl;

    return 0;
}

