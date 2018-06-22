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
	//vector<string> papa= objeto->crearArbol(5);
	//int prueba = objeto->randomPos(24);
	//bool prueba = objeto->esOper("+");
	cout<<papa.size();

    vector<string> prueba;
    prueba.push_back("+");
    prueba.push_back("2");
    prueba.push_back("2");
    double res = objeto->solucionar(prueba);
    cout<<res;


    //aqui emieza la lectura del archivo de datos wine y su impresion de la matriz de doubles

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


	/*
	vector <int> prueba;
	prueba.push_back(1);
	prueba.push_back(2);
	prueba.push_back(3);
	prueba.push_back(5);

	vector <int>::iterator it;

	for(it = prueba.begin(); it != prueba.end(); it++){
        cout << *it << endl;
	}

	it = prueba.begin();
	it += 3;
    prueba.insert(it, 4);

    for(it = prueba.begin(); it != prueba.end(); it++){
        cout << *it << endl;
	}
    */


    return 0;
}
