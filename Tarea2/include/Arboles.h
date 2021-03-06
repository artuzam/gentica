#ifndef ARBOLES_H
#define ARBOLES_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class Arboles
{
    public:
        Arboles();
        virtual ~Arboles();
        vector <string>oper; //vector de operadores
        vector <string>term; //vector de constantes
        vector <string>var;  //vector de variables
        vector<string> crearArbol(int maxDepth);
        int randomPos(int largo);
        bool esOper(string s);
        vector<string> insertarPos(vector<string>& original, int posicion, string insertado);
        double solucionar(vector<string>& entrada);
        vector<string> subArbol(vector<string>& original, int pos);
        vector<string> mutar(vector<string>& original);
        vector < vector<string> > leer();  //lee archivo y devuelve matriz
        vector<string> sustitucionVar(unsigned int fila, vector<string>& arbol, vector<vector<string> >& datos); //sustituye los Var por los valores que se leen
        void cruzar (vector<string>& v1, vector<string>& v2);
        vector < vector<string> > crearGeneracion();
        vector <string> evaluar(vector < vector<string> >& bosque, vector<vector<string> >& datos );
        double sigmoid (double x);


    protected:

    private:
};

#endif // ARBOLES_H


