#include <iostream>
using namespace std;

class IntIterator;//forward declaration, todos los datos deben ser pointers

class IntCollection
{
protected:
      int* array;
      int size;
      int cont;
  public:
    friend class IntIterator;
    IntCollection()
    {
      size = 10;
      array = new int (size);
      cont = 0;
    }
    void addElement(int value)
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
    IntIterator* getIterator();
    
    int at(int pos)
    {
      return array[pos];
    }

};

class IntIterator
{
  protected:
    IntCollection coll;
    int cont = 0;
  public:
    IntIterator(const IntCollection& coll): coll(coll){}
    bool hasNext()
    {
      if(cont < coll.cont)
        return true;
      return false;
    }
    int next()
    {
      return coll.at(cont++);
    }

};

IntIterator* IntCollection::getIterator()
{
  return new IntIterator(*this);
}


int main(int argc, char** argv)
{
  IntCollection i;
  i.addElement(1);
  i.addElement(4);
  i.addElement(2);
  i.addElement(3);
  IntIterator* it = i.getIterator();
  while(it->hasNext())
    cout << it->next() << endl;
  delete it;

}
