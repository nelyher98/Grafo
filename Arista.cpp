/*AUTOR: NELY HER�NDEZ GARC�A
FECHA:18/10/2018
MATERIA: ESTRUCTURA DE DATOS AVANZADAS*/
#include <iostream>
#include "Arista.h"

using namespace std;

Arista::Arista(int p)
{
	peso = p;
	sigA = NULL;
	ver = NULL;
}

Arista::~Arista()
{
	
}
