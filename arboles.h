#ifndef ARBOLES_H
#define ARBOLES_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class arboles
{
    public:
        arboles();
        virtual ~arboles();
		int[] crearArbol(int maxDepth);
		int randomPos(int largo);

    protected:

    private:
};

#endif // ARBOLES_H
