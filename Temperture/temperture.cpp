#include "temperture.h"

double Temperture::GetTemperature() const
{
	return m_value;
}

void Temperture::SetTemperture(const double value)
{
	m_value = value;
}

Celsius::Celsius(const Fahrenheit &other):Temperture(other.GetTemperature()/1.8)
{
}

double Celsius::GetWaterBolingPoint() const
{
	return 100;
}

double Celsius::GetWaterFreezingPoint() const
{
	return 0.0;
}

double Celsius::GetAbsoluteZero() const
{
	return -273.15;
}

char * Celsius::GetTempertureName() const
{
	return "Celsius";
}

Fahrenheit::Fahrenheit(const Celsius &c):Temperture(c.GetTemperature() *1.8)
{	
	m_value = c.GetTemperature();
}

double Fahrenheit::GetWaterBolingPoint() const
{
	return 212;
}

double Fahrenheit::GetWaterFreezingPoint() const
{
	return 32;
}

double Fahrenheit::GetAbsoluteZero() const
{
	return -459.67;
}

char * Fahrenheit::GetTempertureName() const
{
	return "Fahrenheit";
}





std::ostream & operator<<(std::ostream & os,const Temperture & obj)
{
	return os << obj.GetTempertureName() <<": "<< endl
	<< "Water boiling point: "<<obj.GetWaterBolingPoint()<<endl
	<< "Water freezing point: "<<obj.GetWaterFreezingPoint() << endl
	<< "Absolute zero: "<<obj.GetAbsoluteZero() << endl <<endl;
}

void main()
{
	Celsius c(20);
	Fahrenheit f(30);
	
	
	cout << c;
	cout << f;
	cout <<"Celsuce "<< c.GetTemperature();
	cout << "Fahrenheit " << f.GetTemperature();

	c = f;
	cout <<" Celsuce "<< c.GetTemperature();

}