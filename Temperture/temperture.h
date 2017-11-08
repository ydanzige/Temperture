#pragma once
#include <iostream>
using namespace std;
class Temperture 
{
protected:
	double m_value;
public:
	explicit Temperture(const double value) :m_value(value) {}
	double GetTemperature() const;
	void SetTemperture(const double value);
	virtual double GetWaterBolingPoint() const = 0;
	virtual double GetWaterFreezingPoint()const = 0;
	virtual double GetAbsoluteZero()const = 0;
	virtual char* GetTempertureName()const = 0;
	friend std::ostream & operator<<(std::ostream & os,const Temperture & obj);
	
	
};
class Fahrenheit;
class Celsius :public Temperture
{

public:
	Celsius(const double value) :Temperture(value) {}
	//convertor from farenheit to celsius
	Celsius(const Fahrenheit&);	
	double GetWaterBolingPoint() const;
	double GetWaterFreezingPoint()const;
	double GetAbsoluteZero()const;
	char* GetTempertureName()const;
	

};

class Fahrenheit :public Temperture
{

public:
	Fahrenheit(double value) :Temperture(value) {}
	//convertor from celsius to farenite
	Fahrenheit(const Celsius&);	
	double GetWaterBolingPoint() const;
	double GetWaterFreezingPoint()const;
	double GetAbsoluteZero()const;
	char* GetTempertureName()const;	
};

