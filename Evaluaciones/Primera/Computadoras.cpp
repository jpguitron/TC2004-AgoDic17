#include <string>
#include <iostream>
#include "Computadoras.h"
using namespace std;


		Computadoras* Computadoras::getInstance()
		{
			if(!instance)
			{
					instance = new Computadoras;
			}
			return instance;
		}

		void Computadoras::componentes()
		{
			cout<<"Ram: ";
			cin>>procesador;
			cout<<"Procesador:  ";
			cin>>ram;
			cout<<"Espacio del disco duro disco: ";
			cin>>disco;
		}
		void Computadoras::ensamblado()
		{
			cout<<"Ensamblado componentes.."<<endl;
			ensamble = true;
		}
		void Computadoras::sop()
		{
			cout<<"Que sistema operativo quiere: ";
			cin>>so;
		}
		void Computadoras::empaque()
		{
			cout<<"Empaquetando"<<endl;
			empaquetar = true;
		}



Computadoras * Computadoras::instance = 0;

int main()
{
	Computadoras * instance1 = Computadoras::getInstance();
	Desktop * pc = instance1->factoryMethod<Desktop>();
	pc->componentes();
	pc->ensamblado();
	pc->sop();
	pc->empaque();
	Desktop * pc2 = dynamic_cast<Desktop*>(pc->clonar());

	Laptop * laptop = instance1->factoryMethod<Laptop>();
	laptop->componentes();
	laptop->ensamblado();
	laptop->sop();
	laptop->empaque();
	Laptop * laptop2 = dynamic_cast<Laptop*>(laptop->clonar());

	ServerP * server = instance1->factoryMethod<ServerP>();
	server->componentes();
	server->ensamblado();
	server->sop();
	server->empaque();
	ServerP * server2 = dynamic_cast<ServerP*>(server->clonar());

  return 0;
}
