#include <iostream>
class Singleton
{

  private:
    Singleton(){}

  public:
    static Singleton* getInstance()
    {
      if(!instance)
      {
          instance = new Singleton;
      }
      return instance;
    }
    void operation()
    {
      std::cout << "Dirección: " << instance<<"\n";
    }

  protected:
    static Singleton* instance;


};

Singleton * Singleton::instance = 0;

int main(int argc, char** argv)
{
  //Singleton s;//Esta llamada ejecuta constructor por default
  //s.operation();
  Singleton * instance1 = Singleton::getInstance();
  Singleton * instance2 = Singleton::getInstance();
  instance1 -> operation();
  instance2 -> operation();

}
