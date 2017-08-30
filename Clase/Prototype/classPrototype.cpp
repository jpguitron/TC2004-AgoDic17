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

class Princesa : public Personaje
{
  public:
    Princesa(string n) : Personaje(n){}
    Princesa(const Princesa& p)//porque no lo quiero modificar
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
    void grita(){cout<< "aaaaaaaaa"<<endl;}
    Personaje* clone()
    {
      return new Princesa(*this);
    }
};

class Villano : public Personaje
{
  public:
    Villano(string n) : Personaje(n){}
    Villano(const Villano& p)//porque no lo quiero modificar
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
    void secuestra(){cout<< "te atrapé" <<endl;}
    Personaje* clone()
    {
      return new Villano(*this);
    }
};

class Heroe : public Personaje
{
  public:
    Heroe(string n) : Personaje(n){}
    Heroe(const Heroe& p)//porque no lo quiero modificar
    {
      nombre = p.nombre;
      telefono = p.telefono;
      correo = p.correo;
      mundo = new Mundo(p.mundo->nombreMundo);
    }
    void rescata(){cout<< "te salve" <<endl;}
    Personaje* clone()
    {
      return new Heroe(*this);
    }
};

int main()
{
  Princesa* pri = new Princesa("Rapunzel");
  pri->correo = "princesa1@hola.mx";
  pri->telefono = 123123;
  pri->mundo = new Mundo("Paleta");
  // Princesa* p = dynamic_cast<Princesa*>(pri->clone());   convertir personaje a princesa se llama "downcasting"
  Personaje* p = pri->clone();
  pri->nombre = "RAPUNZEL";
  pri->mundo->nombreMundo = "Paleta2";
  Princesa* pp = dynamic_cast<Princesa*>(p->clone());
  pp->mundo->nombreMundo = "Paletita";
  cout << "princesa 1 "<<endl;
  cout << pri->nombre << endl;
  cout << pri->mundo->nombreMundo << endl;
  cout << "princesa 2 "<<endl;
  cout << p->nombre << endl;
  cout << p->correo << endl;
  cout << p->telefono << endl;
  cout << p->mundo->nombreMundo << endl;
}
