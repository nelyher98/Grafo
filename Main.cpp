#include <iostream>
#include <conio.h>
#include "Grafo.cpp"

using namespace std;

void Menu();

main()
{
	
Grafo *gra = new Grafo();

int op = 0,num = 0,p = 0;
char x,o,d,index,index2;

do{
Menu();
cin >> op;

   switch(op)
   {
	case 1:
		cout<<"¿Cuántos vértices quiere insertar?"<<endl;
		cin >> num;
		for(int i = 0;i<num;i++)
		{
		  	cout<<"Nombre del vertice"<<endl;
		  	cin>>x;
		  	gra->InsertarV(x);
		}
		break;
	case 2:
		gra->MostrarV();
		break;
	case 3:
		 cout<<"Inserte vertice de origen"<<endl;
		 cin>>o;
		 cout <<"Inserte vertice de destino"<<endl;
		 cin>>d;
		 cout<<"Inserte peso"<<endl;
		 cin>>p;
		 gra->BusquedaV(o,d,p);
		break;
	case 4:
		gra->MostrarA();
		break;
	case 5:
		cout<<"Ingresa el nodo del cual deseas empezar"<<endl;
		cin>>index;
		gra->RecorridoAnchura(index);	
		break;
	case 6:
		cout<<"Ingresa el nodo del cual deseas empezar"<<endl;
		cin>>index2;
		gra->RecorridoProfundidad(index2);
		break;
	case 7:
		break;
	    default:
		  cout<<"Elige una opción existente"<<endl;
    }
    cout<<endl<<endl;
    getch();
    system("cls");
    
 }while(op != 7);
 
 return 0;
}

void Menu()
{
 cout <<"MENU"<<endl;
 cout <<"1.Insertar Vertices"<<endl;
 cout <<"2.Mostrar vertices"<<endl;
 cout <<"3.Insertar aristas"<<endl;
 cout <<"4.Mostrar aristas"<<endl;
 cout <<"5.Recorrido de anchura"<<endl;
 cout <<"6.Recorrido de profundidad"<<endl;
 cout <<"7.Salir"<<endl;
 cout <<">>";
}
