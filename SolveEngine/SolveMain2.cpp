#include "NewtonRaphson.h"
#include <cmath>
#include <iostream>
#include "BSCall2.h"
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

	double start;

	std::cout << "\nEnter initial guess\n";
	std::cin >> start;

	double tolerance;

	std::cout << "\nEnter Tolerance\n";
	std::cin >> tolerance;

	BSCall2 theCall(r, d, Expiry, Spot, Strike);

	// Explicitly specify the template parameter
	double vol = NewtonRaphson<BSCall2, &BSCall2::Price, &BSCall2::Vega>(Price, start, tolerance, theCall);
	double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);

	std::cout << "\n vol: " << vol << "\npricetwo: " << PriceTwo << "\n";

	std::cin.ignore();
	std::cin.get();

	return 0;

}