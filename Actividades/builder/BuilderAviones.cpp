#include<iostream>
#include<string>

using namespace std;
class Motor
{
	int potencia;
	int numSerie;
public:
	Motor()=default;
	Motor(int pot, int nS) : potencia(pot), numSerie(nS){}
	int getPotencia(){return potencia;}
	int getNumSerie(){return numSerie;}
};

class Alas
{
	string marca;
	int numSerie;
	int hiper;
	int spoilers;
public:
	Alas()=default;
	Alas(string m, int n, int h, int s) : marca(m), numSerie(n), hiper(h), spoilers(s){}
	string getMarca(){return marca;}
	int getNumeSerie(){return numSerie;}
	int getHiper(){return hiper;}
	int getSpoilers(){return spoilers;}
};

class Avion
{
	Motor* motor;
	Alas* alas;
	string marca;
	string modelo;
	int numSerie;
public:
	void setAlas(Alas* a){alas=a;}
	void setMotor(Motor* a){motor=a;}
	void setMarca(string m){marca=m;}
	void setModelo(string mod){modelo=mod;}
	void setNumSerie(int nS){numSerie=nS;}
	string getMarca(){return marca;}
	string getModelo(){return modelo;}
	int getNumSerie(){return numSerie;}
	Alas* getAlas(){return alas;}
	Motor* getMotor(){return motor;}
};

class Builder
{
protected:
	Avion* avion;
public:
	Avion* getAvion(){return avion;}
	void createAvion()
	{
		avion = new Avion();
	}
	virtual Motor* buildMotor() = 0;
	virtual Alas* buildAlas() = 0;
	virtual string buildMarca()=0;
	virtual string buildModelo()=0;
	virtual int buildNumSerie()=0;
};

class BoeingBuilder : public Builder
{
public:
	Motor* buildMotor()
	{
		Motor* motor = new Motor(10000,111111);
		avion->setMotor(motor);
		return motor;
	}
	Alas* buildAlas()
	{
		Alas* alas = new Alas("Boeing",101010,10,10);
		avion->setAlas(alas);
		return alas;
	}

	string buildMarca()
	{
		avion->setMarca("Boeing");
		return avion->getMarca();
	}
	string buildModelo()
	{
		avion->setModelo("722");
		return avion->getModelo();
	}
	int buildNumSerie()
	{
		avion->setNumSerie(23414);
		return avion->getNumSerie();
	}
};


class Director
{
	Builder* builder;
public:
	void setBuilder(string tipoAvion)
	{
		if(tipoAvion=="Boeing")
		{
			builder = new BoeingBuilder();
		}
	}
	Avion* getAvion(){return builder->getAvion();}
	void construct()
	{
		builder->createAvion();
		builder->buildAlas();
		builder->buildMotor();
		builder->buildMarca();
		builder->buildModelo();
		builder->buildNumSerie();
	}
};

int main()
{
	Director d;
	d.setBuilder("Boeing");
	d.construct();
	Avion* a = d.getAvion();
	cout << a->getMarca() <<endl;
}
