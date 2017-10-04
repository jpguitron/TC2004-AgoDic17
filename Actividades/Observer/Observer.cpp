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

class Trump : public Subject
{
public:
  Trump()=default;
	Trump(string n) : Subject(n){}
};
class Pena : public Subject
{
public:
  Pena()=default;
  Pena(string n) : Subject(n){}
};
class Lider : public Subject
{
public:
  Lider()=default;
  Lider(string n) : Subject(n){}
};

int main()
{
  Trump* trump = new Trump("trump");
  Pena* pena = new Pena("Pena");
  Lider* lider = new Lider("Gran hermano");
  Televisa* televisa = new Televisa();
  MVS* mvs = new MVS();
  Noticias* noticias = new Noticias();
  Radio* radio = new Radio();

  trump->setObservador(televisa);
  trump->setObservador(mvs);
  trump->setObservador(radio);
  trump->setObservador(noticias);

  pena->setObservador(televisa);
  pena->setObservador(radio);

  lider->setObservador(noticias);

  trump->saySomething("Build the wall");
  pena->saySomething("1>5");
  lider->saySomething(">o<");
}
