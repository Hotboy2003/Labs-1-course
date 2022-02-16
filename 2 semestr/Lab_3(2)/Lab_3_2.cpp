#include <iostream>
#include <math.h>

double f(double x)
{
	return pow((x - 3), 3);
}

double bisection(double a, double b, double eps)
{
	double x;
	while ((b - a) / 2 > eps) 
	{
		x = (a + b) / 2;
		if ((x == a) || (x == b))
			return x;
		else if ((f(a) * f(x)) > 0) 
			a = x;
		else 
			b = x;
	}
	return x;
}


int main()
{
	double eps = pow(10, -4);
	std::cout << bisection(0, INT_MAX, eps);
}