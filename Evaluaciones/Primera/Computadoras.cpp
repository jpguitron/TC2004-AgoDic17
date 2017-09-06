#include <string>
#include <iostream>
#include "Computadoras.h"
using namespace std;

		void Computadoras::crear()
		{
			cout<<"Ram: ";
			cin>>procesador;
			cout<<"Procesador:  ";
			cin>>ram;
			cout<<"Espacio del disco duro disco: ";
			cin>>disco;
			cout<<"Ensamblado componentes.."<<endl;
			cout<<"Que sistema operativo quiere: ";
			cin>>so;
			cout<<"Empaquetando"<<endl;
		}



Computadoras * Computadoras::instance = 0;

int main()
{
	//Computadoras * instance1 = Computadoras::getInstance();
	Computadoras * instance1 = Computadoras::getInstance();
	Desktop * cosa = instance1->factoryMethod<Computadoras,Desktop>();
	//instance1->crear("ServerT");

  return 0;
}
