/*AUTOR: NELY HERNÁNDEZ GARCÍA
FECHA:12/10/2018
MATERIA: ESTRUCTURA DE DATOS AVANZADAS*/
#ifndef GRAFO_H
#define GRAFO_H
#include "Arista.h"
#include "Arista.cpp"
#include "Vertice.h"
#include "Vertice.cpp"


class Grafo
{
  private:
    Vertice *ini;
  public:
  	Grafo();
  	~Grafo();
  	bool Vacio();
    void InsertarV(char);	
    void InsertarA(Vertice* o,Vertice* d,int);
    void BusquedaV(char,char,int);
    void MostrarV();
    void MostrarA();
    void RecorridoAnchura(char);
    void RecorridoProfundidad(char);
};

#endif
