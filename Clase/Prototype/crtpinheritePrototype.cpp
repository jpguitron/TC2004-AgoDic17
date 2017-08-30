#include <iostream>
#include <string>
using namespace std;

class Mundo
{
  public:
    Mundo(string nombreMundo) : nombreMundo(nombreMundo){}//lista de inicialización
    string nombreMundo;
};

class Personaje
{
  public:
    Personaje() = default;//mi constructor default
    Personaje(string nombre) : nombre(nombre){}
    string nombre;
    int telefono;
    string correo;
    Mundo* mundo;
    virtual Personaje* clone() = 0;
};

template<class Base, class SubClass>
class Clone : public Base
{
  public:
    Base* clone()
    {
      return new SubClass(dynamic_cast<SubClass&>(*this));
    }
};

class Princesa : public Clone<Personaje,Princesa> //a esto se le llama CURIOUSLY RECURRYING TEMPLATE PATTERN
{
  public:
    Princesa(string n)
    {
      nombre = n;
    }
    Princesa(const Princesa& p)//porque no lo quiero modificar
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
    void grita(){cout<< "aaaaaaaaa"<<endl;}
};

int main()
{
  Princesa* pri = new Princesa("Rapunzel");
  pri->correo = "princesa1@hola.mx";
  pri->telefono = 123123;
  pri->mundo = new Mundo("Paleta");
  Personaje* p = pri->clone();
  pri->nombre = "RAPUNZEL";
  pri->mundo->nombreMundo = "Paleta2";
  cout << "princesa 1 "<<endl;
  cout << pri->nombre << endl;
  cout << pri->mundo->nombreMundo << endl;
  cout << "princesa 2 "<<endl;
  cout << p->nombre << endl;
  cout << p->correo << endl;
  cout << p->telefono << endl;
  cout << p->mundo->nombreMundo << endl;
}
