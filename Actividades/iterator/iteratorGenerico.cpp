#include <iostream>
using namespace std;

template<class Tipo>
class Iterator;//forward declaration, todos los datos deben ser pointers

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
      size = 10;
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
    /*IntIterator* getIterator()
    {
      return new IntIterator(*this);
    }*/
    Iterator<Tipo>* getIterator();

    Tipo at(int pos)
    {
      return array[pos];
    }

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
      if(cont < coll.cont)
        return true;
      return false;
    }
    Tipo next()
    {
      return coll.at(cont++);
    }

};

template<class Tipo>
Iterator<Tipo>* Collection<Tipo>::getIterator()
{
  return new Iterator<Tipo>(*this);
}


bool busqueda(int num)
{
  if(num>5)
    return true;
  return false;

}


bool busqueda(char c)
{
  if(c=='A')
    return true;
  return false;
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

int main(int argc, char** argv)
{
  Collection<char> i;
  i.addElement('A');
  i.addElement('A');
  i.addElement('B');
  i.addElement('C');
  Iterator<char>* it = i.getIterator();
  /*while(it->hasNext())
    cout << it->next() << endl;*/
  find_if<char, bool(*)(char)>(it,busqueda);

  delete it;

}
