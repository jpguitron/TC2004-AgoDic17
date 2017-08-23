#include <iostream>
#include <ctime>
using namespace std;
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
    void getHora()
    {
      time_t now = time(0);
      char* dt = ctime(&now);
      cout << "La hora exacta es: " << dt << endl;
    }

  protected:
    static Singleton* instance;


};

Singleton * Singleton::instance = 0;

int main(int argc, char** argv)
{
  Singleton * instance1 = Singleton::getInstance();
  instance1 -> getHora();
}
