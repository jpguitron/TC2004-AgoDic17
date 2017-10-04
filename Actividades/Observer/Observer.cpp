#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Observer
{
public:
  virtual void actualizar(string actualizacion)=0;
};


class Televisa : public Observer
{
public:
  void actualizar(string actualizacion){cout<<"Noticiero por televisión(Televisa): "<<actualizacion<<endl;}
};

class Radio : public Observer
{
public:
  void actualizar(string actualizacion){cout<<"Noticiero por radio: "<<actualizacion<<endl;}
};

class Noticias : public Observer
{
public:
  void actualizar(string actualizacion){cout<<"Noticiero por televisión(internacional): "<<actualizacion<<endl;}
};

class MVS : public Observer
{
public:
  void actualizar(string actualizacion){cout<<"Noticiero por televisión(MVS): "<<actualizacion<<endl;}
};

class Subject
{
  vector<Observer*> observadores;
protected:
  string nombre;
public:
  Subject()=default;
  Subject(string n) : nombre(n){}
  void setObservador(Observer* ob){observadores.push_back(ob);}
  void saySomething(string say)
  {
    for(int x=0;observadores.size()>x;x++)
      observadores[x]->actualizar(say);
  }
};

class trump : public Subject
{
public:
  trump()=default;
	trump(string n) : Subject(n){}
};
class pena : public Subject
{
public:
  pena()=default;
  pena(string n) : Subject(n){}
};
class lider : public Subject
{
public:
  lider()=default;
  lider(string n) : Subject(n){}
};

int main()
{

}
