/*AUTOR: NELY HERNÁNDEZ GARCÍA
FECHA:12/10/2018
MATERIA: ESTRUCTURA DE DATOS AVANZADAS*/
#ifndef ARISTA_H
#define ARISTA_H
#include "Vertice.h"

class Vertice;
class Grafo;

class Arista
{
  private:
  	int peso;
  	Arista *sigA;
  	Vertice *ver;
  public:
  	Arista(int);
  	~Arista();	
  	
  	friend class Vertice;
  	friend class Grafo;
};

#endif
