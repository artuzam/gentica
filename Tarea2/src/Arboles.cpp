#include "Arboles.h"
#include <vector>
#include <stdio.h>
#include <iostream>

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

	vector <string>::iterator it;
	//vector <string>::iterator it2;

	vector <string>oper;
	vector <string>term;
	vector <string>var;

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



	for(it = oper.begin(); it != oper.end(); it++){
        cout << *it << endl;
	}


	for(it = term.begin(); it != term.end(); it++){
        cout << *it << endl;
	}


	return oper;
}

int Arboles::randomPos(int largo){
	srand (time(NULL));
	int indice = rand() % largo;
	cout << indice;
	return indice;

}


