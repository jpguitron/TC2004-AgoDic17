#include <string>
#include <iostream>
using namespace std;

class Computadoras
{
	protected:
		string procesador;
		string ram;
		string disco;
		string so;
		static Computadoras* instance;
		Computadoras(){}

public:

	static Computadoras* getInstance()
	{
		if(!instance)
		{
				instance = new Computadoras;
		}
		return instance;
	}

	template<class base, class Tipo>
    base* factoryMethod()
    {
        return new this;
    }
		void crear();
};

template <class base, class Tipo>
class ClonComputadoras:public Computadoras
{

	public:
		virtual base * clonar()
		{
			return new Tipo(dynamic_cast<Tipo&>(*this));
		}
};


class Desktop:public ClonComputadoras<Computadoras,Desktop>
{
};

class Laptop:public ClonComputadoras<Computadoras,Laptop>
{
};

class Netbook:public ClonComputadoras<Computadoras,Netbook>
{
};
class Tablet:public ClonComputadoras<Computadoras,Tablet>
{
};
class ServerP:public ClonComputadoras<Computadoras,ServerP>
{
};
class ServerT:public ClonComputadoras<Computadoras,ServerT>
{
};
