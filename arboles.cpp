#include "arboles.h"

arboles::arboles()
{
    //ctor
}

arboles::~arboles()
{
    //dtor
}

arboles::int[] crearArbol(int maxDepth){
	char oper[] = {'+','-','/','*'};
	double term[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,1,2,3,4,5,6,7,8,9,-0.1,-0.01,-0.001,0.1,0.01,0.001};
	
	
	int arbol[31];
	
}

arboles::int randPos(int largo){
	srand (time(NULL));
	int indice = rand() % largo;
}