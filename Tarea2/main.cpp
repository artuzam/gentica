#include <iostream>
#include "Arboles.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
    Arboles * objeto = new Arboles();
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

    //aqui emieza la lectura del archivo de datos wine y su impresion de la matriz de doubles
    /*
    ifstream in("wine.txt");
    string bufferFila;
    vector < vector<double> > matrix;

    while (getline(in, bufferFila)) {
        if(bufferFila.size() > 0) {
            stringstream ss(bufferFila);
            string bufferNumero;
            vector<double> row;

            while(getline(ss, bufferNumero, ',')) {
                row.push_back(atof(bufferNumero.c_str()));
            }
            matrix.push_back(row);
        }
    }

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
