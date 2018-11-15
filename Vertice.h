/*AUTOR: NELY HERNÁNDEZ GARCÍA
FECHA:12/10/2018
MATERIA: ESTRUCTURA DE DATOS AVANZADAS*/
#ifndef VERTICE_H
#define VERTICE_H
#include "Arista.h"

class Arista;
class Grafo;

class Vertice
{
 private:
 	char dato;
 	Vertice *sigV;
 	Arista *arista;
 public:
 	Vertice(char);
 	~Vertice();
 	
 	friend class Arista;
 	friend class Grafo;	
};

#endif
