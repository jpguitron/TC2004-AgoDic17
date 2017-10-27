#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define CANT 7
#define SIZEX 10
#define SIZEY 10

using namespace std;

template<class Tipo>
class Iterator;

template<class Tipo>
class Collection
{
protected:
      Tipo* array;
      int size;
      int cont;
  public:
    friend class Iterator<Tipo>;
    Collection()
    {
      size = CANT;
      array = new Tipo [size];
      cont = 0;
    }
    void addElement(Tipo value)
    {
      if(cont <= size)
      {
        array[cont++] = value;
        return;
      }
      cout << "Ya no hay espacio para agregar elementos" <<endl;
    }

    Iterator<Tipo>* getIterator();
    Tipo* at(int pos){return &array[pos];}
};

template<class Tipo>
class Iterator
{
  protected:
    Collection<Tipo> coll;
    int cont = 0;
  public:
    Iterator(const Collection<Tipo>& coll): coll(coll){}
    bool hasNext()
    {
      if(cont < coll.size)
        return true;
      return false;
    }
    Tipo* data()
    {
      cont+=1;
      return coll.at(cont-1);
    }
    void restart(){cont=0;}
    int getCont(){return cont;}
    void setCont(int c){cont=c;}
};

template<class Tipo>
Iterator<Tipo>* Collection<Tipo>::getIterator()
{
  return new Iterator<Tipo>(*this);
}

class GalaxiaLejana
{
   public:
    GalaxiaLejana(){}

  public:
    static GalaxiaLejana* getInstance()
    {
      if(!instance)
      {
          instance = new GalaxiaLejana;
      }
      return instance;
    }

    template<class Tipo>
      Tipo * factoryMethod()
      {
          return new Tipo;
      }

  protected:
    static GalaxiaLejana* instance;
};

class Objeto
{
 public:
  Objeto(){}

protected:
  string tipo;
  int x=0;
  int y=0;
  int s=1;
  int blocked[SIZEX][SIZEY]={{0}};
  int intentos[4]={{0}};
public:
  void stop(){s=0;}
  string getTipo(){return tipo;}
  void block(int x, int y)
  {
    blocked[x][y]=1;
  }
  int getStatus()
  {
    return s;
  }
  /*void move()
  {
    if(s)
    {
      y = rand() % SIZEY;
      x = rand() % SIZEX;
      while(blocked[x][y]==1)
      {
        y = rand() % SIZEY;
        x = rand() % SIZEX;
      }
    }
    else
    {
      y=-1;
      x=-1;
    }
  }*/

  void begin()
  {
    y = rand() % SIZEY;
    x = rand() % SIZEX;
    while(blocked[x][y]==1)
    {
      y = rand() % SIZEY;
      x = rand() % SIZEX;
    }
  }
  void move()
  {
    if(s)
    {
      int opt = rand() % 4;
      for(int x=0;x<4;x++)
        intentos[x]=0;
      move(opt);
    }
    else
    {
      y=-1;
      x=-1;
    }
  }
  void move(int a)
  {
    switch(a)
    {
      case 0:
        x++;
      break;
      case 1:
        x--;
      break;
      case 2:
        y++;
      break;
      case 3:
        y--;
      break;
    }
    if(blocked[x][y]==1 || x==-1 || x==SIZEX ||y==-1|| y==SIZEY)
    {
      revert(a);
      int opt = rand() % 4;
      int cant=0;
      for(int x=0;x<4;x++)
        cant+=intentos[x];
      intentos[a] = 1;
      if(cant==4)
        {
          cout<<"Teletransportación"<<endl;
          begin();
        }
      else
        move(opt);
    }
  }
  void revert(int a)
  {
    switch(a)
    {
      case 0:
        x--;
      break;
      case 1:
        x++;
      break;
      case 2:
        y--;
      break;
      case 3:
        y++;
      break;
    }
  }
  int getX(){return x;}
  int getY(){return y;}
};

class Spacecrafts:public Objeto
{
	 public:
		Spacecrafts(){}
};

class Asteroids:public Objeto
{
	 public:
		Asteroids(){}
};

class Planets:public Objeto
{
	 public:
		Planets(){}
};

class PES:public Spacecrafts
{
	 public:
		PES(){tipo="ES";}
};
class CS:public Spacecrafts
{
	 public:
		CS(){tipo="CS";}
};

class POS:public Spacecrafts
{
	 public:
		POS(){tipo="OS";}
};

class SM:public Asteroids
{
	 public:
		SM(){tipo="SM";}
};

class IM:public Asteroids
{
	 public:
		IM(){tipo="IM";}
};

class DP:public Planets
{
	 public:
		DP(){tipo="DP";}
};

class EA:public Planets
{
public:
		EA(){tipo="EA";}
};

class Observer
{
public:
  virtual void actualizar(string actualizacion)=0;
};


class Chisme : public Observer
{
public:
  void actualizar(string actualizacion){cout<<"Colisión detectada: "<<actualizacion<<endl;}
};

class Tablero
{
protected:
  int tab[SIZEX][SIZEY]={{0}};

  Collection<Objeto> *objetos = new Collection<Objeto>;
  Iterator<Objeto>* it = objetos->getIterator();
  Iterator<Objeto>* it2 = objetos->getIterator();
  Iterator<Objeto>* it3 = objetos->getIterator();
public:
  void setObjetos(Objeto s){objetos->addElement(s);}

  void start()
  {
    srand (time(NULL));
    int run=1;
    while(it->hasNext())
    {
      Objeto* obj = it->data();
      obj->begin();
    }
    it->restart();
    cout<<"********************************"<<endl;
    cout<<"**** Detección de colisiones ***"<<endl;
    cout<<"********************************"<<endl;
    while(run)
    {
        while(it->hasNext())
        {
          Objeto* obj = it->data();
          obj->move();
          /*if(obj->getX()!=-1)
          cout<<obj->getX()<<" "<<obj->getY()<<endl;*/
        }
        //cout<<"------------------"<<endl;
        /*cout<<"********************************"<<endl;
        for(int x=0;x<SIZEX;x++)
        {
          cout<<"***** ";
          for(int y=0;y<SIZEY;y++)
            cout<<tab[y][x]<<" ";
          cout<<"******"<<endl;
        }
        cout<<"********************************"<<endl;*/
        it->restart();

        int x1;
        int x2;
        int y1;
        int y2;

        while(it->hasNext())
        {
          Objeto *obj1 = it->data();
          it2->setCont(it->getCont());
          while(it2->hasNext())
          {
            Objeto *obj2 = it2->data();
            if(obj1!=obj2)
            {
              x1=obj1->getX();
              x2=obj2->getX();
              y1=obj1->getY();
              y2=obj2->getY();

            if(x1==x2&&y1==y2 && x1!=-1 &&y1!=-1)
            {
              obj1->stop();
              obj2->stop();
              tab[x1][y1]=1;
              cout<<"* Colisión en "<<x1<<" "<<y1<<" de "<<obj1->getTipo()<<" con "<<obj2->getTipo()<<" *"<<endl;
              while(it3->hasNext())
              {
                Objeto *obj3 = it3->data();
                obj3->block(x1,y1);
              }
              it3->restart();
            }
          }

          }
          it2->restart();
        }
          it->restart();

          int num =0;
          while(it->hasNext())
          {
            Objeto* obj = it->data();
            num+=obj->getStatus();
          }
          it->restart();
          if(num==1||num==0)
            run=0;

        }
        cout<<"********************************"<<endl;
        for(int x=0;x<SIZEX;x++)
        {
          cout<<"***** ";
          for(int y=0;y<SIZEY;y++)
            cout<<tab[y][x]<<" ";
          cout<<"******"<<endl;
        }
        cout<<"********************************"<<endl;
  }

};

GalaxiaLejana * GalaxiaLejana::instance = 0;

int main(int argc, char** argv)
{
  GalaxiaLejana * instance1 = GalaxiaLejana::getInstance();
  Tablero * tab = instance1->factoryMethod<Tablero>();

  PES * s1 = instance1 ->factoryMethod<PES>();
  CS * s2 = instance1 ->factoryMethod<CS>();
  POS * s3 = instance1 ->factoryMethod<POS>();

  SM* a1 = instance1 ->factoryMethod<SM>();
  IM * a2 = instance1 ->factoryMethod<IM>();

  DP * p1 = instance1 ->factoryMethod<DP>();
  EA * p2 = instance1 ->factoryMethod<EA>();

  tab->setObjetos(*s1);
  tab->setObjetos(*s2);
  tab->setObjetos(*s3);
  tab->setObjetos(*a1);
  tab->setObjetos(*a2);
  tab->setObjetos(*p1);
  tab->setObjetos(*p2);

  tab->start();
}
