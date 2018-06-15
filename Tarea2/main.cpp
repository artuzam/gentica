#include <iostream>
#include "Arboles.h"
#include <vector>
#include <iterator>

using namespace std;

int main()
{

    Arboles * objeto = new Arboles();
	vector<string> papa= objeto->crearArbol(5);
	//int prueba = objeto->randomPos(24);
	bool prueba = objeto->esOper("+");
	cout<<prueba;

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
