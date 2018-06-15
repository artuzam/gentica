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

using namespace std;

class Arboles
{
    public:
        Arboles();
        virtual ~Arboles();
        vector<string> crearArbol(int maxDepth);
		int randomPos(int largo);
		bool esOper(string s);
		vector<string> insertarPos(vector<string>& original, int posicion, string insertado);

    protected:

    private:
};

#endif // ARBOLES_H


