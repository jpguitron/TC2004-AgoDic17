#include <iostream>
using namespace std;

class Product
{
  public:
    void operation()
    {
      cout << "Estoy en operación \n";
    }
    void operation2()
    {
      cout << "Estoy en operación 2 \n";
    }
};

class Creator
{
  private:
      virtual Product* createProduct(int type) = 0;
  public:
      Product * factoryMethod(int type)
      {
        Product *p =createProduct(type);
        p -> operation();
        return p;
      }
};

class CreatorA : public Creator
{
  public:
      Product* createProduct(int type)
      {
        if(type == 1)
        {
          return new Product;
        }
      }
};

int main(int argc, char** argv)
{
  //creator deberia ser un Singleton
  //Create concretps con constructor privado
  Creator *s = new CreatorA;
  Product *p = s->factoryMethod(1);
  p->operation2();

  delete p;
  delete s;
}
