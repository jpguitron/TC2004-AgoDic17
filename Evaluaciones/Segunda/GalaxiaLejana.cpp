#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

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

    Tipo at(int pos)
    {
      return array[pos];
    }
    Tipo* atp(int pos)
    {
      return &array[pos];
    }
    void restart(){cont=0;}

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
    Tipo next()
    {
      return coll.at(cont++);
    }
    Tipo* nextp()
    {
      return coll.atp(cont++);
    }
    Tipo* dataAt(int a)
    {
      return coll.atp(a);
    }


};

template<class Tipo>
Iterator<Tipo>* Collection<Tipo>::getIterator()
{
  return new Iterator<Tipo>(*this);
}

template<class Tipo, class F>
void find_if(Iterator<Tipo>* it, F f)
{
  int num;
  while(it->hasNext())
  {
    Tipo num = it->next();
    if(f(num))
      cout << "Busqueda: "<<num << endl;
  }

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
  //string tipo;
  int x=0;
  int y=0;
  int s=1;
  int blocked[SIZEX][SIZEY]={{0}};
public:
  void stop(){s=0;}
  void block(int x, int y)
  {
    blocked[x][y]=1;
  }
  int getStatus()
  {
    return s;
  }
  void move()
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
		PES(){}
};
class CS:public Spacecrafts
{

	 public:
		CS(){}
};

class POS:public Spacecrafts
{

	 public:
		POS(){}
};

class SM:public Asteroids
{

	 public:
		SM(){}
};

class IM:public Asteroids
{

	 public:
		IM(){}
};

class DP:public Planets
{

	 public:
		DP(){}
};

class EA:public Planets
{
public:
		EA(){}
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
public:
  void setObjetos(Objeto s){objetos->addElement(s);}

  void start()
  {
    srand (time(NULL));
    int run=1;
    while(run)
    {

    for(int cont1=0;cont1<CANT;cont1++)
    {
      Objeto* obj = it->dataAt(cont1);
      obj->move();
    }

    int x1;
    int x2;
    int y1;
    int y2;

    for(int cont1=0;cont1<CANT;cont1++)
    {
      for(int cont2=0;cont2<CANT;cont2++)
      {
        if(!(cont1==cont2))
        {
          x1=it->dataAt(cont1)->getX();
          x2=it->dataAt(cont2)->getX();
          y1=it->dataAt(cont1)->getY();
          y2=it->dataAt(cont2)->getY();
          if(x1==x2&&y1==y2 && x1!=-1 &&y1!=-1)
          {
            it->dataAt(cont1)->stop();
            it->dataAt(cont2)->stop();
            tab[x1][y1]=1;
            cout<<"Colisión en: "<<x1<<" "<<y1<<endl;
            for(int cont3=0;cont3<CANT;cont3++)
            {
              it->dataAt(cont3)->block(x1,y1);
            }
          }
        }
      }
    }
    int cont4;
    int num =0;
    for(cont4=0;cont4<CANT;cont4++)
    {
      if(it->dataAt(cont4)->getStatus())
        num+=it->dataAt(cont4)->getStatus();
    }
    if(num==1||num==0)
      run=0;
  }
  for(int x=0;x<SIZEX;x++)
  {
    for(int y=0;y<SIZEY;y++)
    {
      cout<<tab[x][y]<<" ";
    }
    cout<<endl;
  }
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
