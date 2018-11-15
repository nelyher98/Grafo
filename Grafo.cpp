/*AUTOR: NELY HERNÁNDEZ GARCÍA
FECHA:18/10/2018
MATERIA: ESTRUCTURA DE DATOS AVANZADAS*/
#include <iostream>
#include "Grafo.h"
#include <list>
#include <queue>
#include <stack>


using namespace std;

/****************CONSTRUCTORES*********/

Grafo::Grafo()
{
	ini = NULL;
	
}

/****************FUNCION VACIA*********/

bool Grafo::Vacio()
{	
 return ini == NULL;	
}

/****************FUNCIONES INSERTAR*********/

//VERTICE

void Grafo::InsertarV(char x)
{
	Vertice* nuevo = new Vertice(x);
	Vertice* aux = ini;
	
	if(Vacio() == true)
	{
		ini = nuevo;
	}
	else
	{	
	  
	  
	  while(aux -> sigV != NULL)
	  {
	  	
	  	aux = aux -> sigV;

      }
      
	  aux->sigV = nuevo;
	  
	}
}

//ARISTAS

void Grafo::InsertarA(Vertice *o,Vertice *d, int p)
{
	
	Arista *aux;
	Arista *nuevaA = new Arista(p);
	nuevaA -> ver = d;
		
	if(o -> arista == NULL)
	{
		o -> arista = nuevaA;
	}
	else
	{
		aux = o -> arista;
		
		while(aux -> sigA != NULL)
		{
		 aux = aux -> sigA;	
		} 
		
		aux -> sigA = nuevaA;
	}
	
	cout<<""<<d->dato<<""<<o->dato<<""<<nuevaA->peso<<endl;
	
	cout<<"EntraI"<<endl;
	
}

/****************FUNCIONES MOSTRAR*********/

void Grafo::MostrarV()
{
	Vertice *aux = ini;
	
	
	if(Vacio())
	{
	 cout << "No hay ningun dato" << endl;	
	}
	else
	{
	   while(aux != NULL)
	  {
	  	cout << ""<<aux->dato;
		aux = aux -> sigV;
		
	  }
	}
}
	
void Grafo::MostrarA()
{
	Vertice *aux1 = ini;
	Arista *aux2;
	
	 
	if(Vacio())
	{
	 cout << "No hay ningun dato" << endl;	
	}
	else
	{
		while(aux1 != NULL)
		{

		 cout<<" "<<aux1->dato<<"->";
		 
		 aux2  = aux1 -> arista;
		 
		 while(aux2 != NULL)
		 {
		   cout<<""<<aux2->peso<<":"<<aux2->ver->dato<<"->";
		   
		   aux2 = aux2 -> sigA;
		   
		 }
		 aux1 = aux1 -> sigV;
		 
		 cout<<endl;
		}	
	}
}

/****************BUSQUEDA DE VERTICES*********/

void Grafo::BusquedaV(char o,char d,int p)
{
	Vertice *origen = ini;
	Vertice *destino = ini;

	
	while(origen->dato != o)
	{
	 origen = origen -> sigV;
	 
	}
	
	while(destino -> dato != d)
	{
	 destino = destino -> sigV;	
	}
	
	cout<<"EntraB"<<endl;
	InsertarA(origen,destino,p);
	
    
}

/****************RECORRIDO ANCHURA*********/

void Grafo::RecorridoAnchura(char o)
{
  
  Vertice* origen = ini;
  int band = 0, band2 = 0;
	
  //FINDING THE DESIRED NODE
  
  while(origen->dato != o)
	{
		
	 origen = origen -> sigV;
	 
	}	
	
  	Vertice *actual = origen;
  	
  	//QUEUE CREATION AND LIST TO VISIT NODES
  	
	queue<Vertice*>cola;
	list<Vertice*>lista;
	list<Vertice*>::iterator i;
	
	cola.push(origen);
	
	while(!cola.empty())
	{
		band = 0;
		actual = cola.front();
		cola.pop();
		
		for(i = lista.begin(); i != lista.end(); i++)
		{
			if(*i == actual)
			{
			 	 band = 1;
			}
		}
		
		if(band == 0)
		{
			cout<<""<<actual->dato<<endl;
			
			lista.push_back(actual);
			
			Arista *aux;
			aux = actual -> arista;
			
			while(aux != NULL)
			{
				band2 = 0;
				
				for(i = lista.begin(); i != lista.end(); i++)
				{
				  if(aux -> ver == *i )
				   {
					 band2 = 1;
				   }	
				}
				
				if(band2 == 0)
				{
					cola.push(aux -> ver);
				}
				
				aux = aux -> sigA;
			}
	   }
		
	}
	
}

/****************RECORRIDO PROFUNDIDAD*********/

void Grafo::RecorridoProfundidad(char o)
{
  
  int band = 0, band2 = 0;
  Vertice* origen = ini;
	
  //FINDING THE DESIRED NODE
  
  while(origen->dato != o)
	{
		
	 origen = origen -> sigV;
	 
	}
	
   //SETTING IT AS THE ACTUAL VERTEX	
	
   Vertice *actual = origen;
   
   //CREATING THE STACK FOR THE VERTICES
   
   stack<Vertice*>pila;
   list<Vertice*>lista;
   list<Vertice*>::iterator i;
   
   //PUSHING THE STARTING VERTEX
   
   pila.push(origen);
   
   //STARTING TO TAKE OUT THE VERTICES
   
   while(!pila.empty())
   {   	 
   	 band = 0; //INITIALIAZING FALG
   	 
   	 actual = pila.top(); 
   	 pila.pop();
   	 
   	 //VISITING VERTICES
   	 
   	 for( i = lista.begin(); i != lista.end(); i++)
   	 {
   	   if(*i == actual)
	    {
		  	band = 1;
	    } 
	 }
	 if( band == 0)
	 {
	 	cout<<""<<actual->dato<<endl;
	 	lista.push_back(actual);
	 	
	 	Arista *aux;
	 	aux = actual -> arista;
	 	
	 	while(aux != NULL)
	 	{
	 		band2 = 0;
	 		
	 		for(i = lista.begin(); i != lista.end(); i++)
	 		{
	 		  if(*i == aux->ver)	
	 		  {
	 		  	band2 = 1;
			  }
			}
			if(band2 == 0)
			{
			  pila.push(aux->ver);	
			}
			
			aux = aux -> sigA;
		}
	 }
	 
   }
  	
}
