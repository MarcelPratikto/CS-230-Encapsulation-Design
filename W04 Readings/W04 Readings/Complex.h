#pragma once
class Complex
{
public:
	Complex();
	Complex(double r, double i);
	Complex(const Complex& complex);
	const void display();
	void set(double r, double i);
	const double getReal();
	const double getImaginary();

private:
	double real;
	double imaginary;
};

