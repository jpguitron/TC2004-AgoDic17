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
		bool ensamble;
		bool empaquetar;

		static Computadoras* instance;
		Computadoras(){}

public:
	virtual ~Computadoras (){};
	static Computadoras* getInstance();

	template<class Tipo>
    Tipo * factoryMethod()
    {
        return new Tipo;
    }
		void componentes();
		void ensamblado();
		void sop();
		void empaque();
};

template <class base, class Tipo>
class ClonComputadoras:public base
{
protected:
	ClonComputadoras(){}
	public:
		base * clonar()
		{
			return new Tipo(dynamic_cast<Tipo&>(*this));
		}
};


class Desktop:public ClonComputadoras<Computadoras,Desktop>
{
	friend class Computadoras;
	private:
		Desktop(){}
};

class Laptop:public ClonComputadoras<Computadoras,Laptop>
{
	friend class Computadoras;
private:
		Laptop(){}
};

class Netbook:public ClonComputadoras<Computadoras,Netbook>
{
	friend class Computadoras;
	private:
		Netbook(){}
};
class Tablet:public ClonComputadoras<Computadoras,Tablet>
{
	friend class Computadoras;
	private:
		Tablet(){}
};
class ServerP:public ClonComputadoras<Computadoras,ServerP>
{
	friend class Computadoras;
	private:
		ServerP(){}
};
class ServerT:public ClonComputadoras<Computadoras,ServerT>
{
	friend class Computadoras;
	private:
		ServerT(){}
};
