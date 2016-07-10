#include "Bisection.h"
#include <cmath>
#include <iostream>
#include "BSCallClass.h"
#include "BlackScholesFormulas.h"

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double r;
	double d;
	double Price;

	std::cout << "\nEnter expiry\n";
	std::cin >> Expiry;

	std::cout << "\nStrike\n";
	std::cin >> Strike;

	std::cout << "\nEnter spot\n";
	std::cin >> Spot;

	std::cout << "\nEnter price\n";
	std::cin >> Price;

	std::cout << "\nEnter r\n";
	std::cin >> r;

	std::cout << "\nEnter d\n";
	std::cin >> d;

	double low, high;

	std::cout << "\nEnter lower guess\n";
	std::cin >> low;

	std::cout << "\nEnter higher guess\n";
	std::cin >> high;

	double tolerance;

	std::cout << "\nEnter Tolerance\n";
	std::cin >> tolerance;

	BSCall theCall(r, d, Expiry, Spot, Strike);

	double vol = Bisection(Price, low, high, tolerance, theCall);
	double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

	std::cout << "\n vol: " << vol << "\npricetwo: " << PriceTwo << "\n";

	std::cin.ignore();
	std::cin.get();

	return 0;

}