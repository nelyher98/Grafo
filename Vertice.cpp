/*AUTOR: NELY HERÁNDEZ GARCÍA
FECHA:18/10/2018
MATERIA: ESTRUCTURA DE DATOS AVANZADAS*/
#include <iostream>
#include "Vertice.h"

using namespace std;

Vertice::Vertice (char x)
{
   	dato = x;
   	sigV  = NULL;
   	arista = NULL;
}

Vertice::~Vertice()
{
	
}
