#include "VanillaOption2.h"
#include "SimpleMC8.h"
#include "MCStatistics.h"
#include <iostream>
#include "ConvergenceTable.h"
#include "ParkMiller.h"
#include "Digital.h"
using namespace std;

int main()
{
	double S;
	double K1, K2, K3;
	std::cout << "spot\n";
	std::cin >> S;
	std::cout << "strike1\n";
	std::cin >> K1;
	std::cout << "strike2\n";
	std::cin >> K2;
	PayOffDigitalCall one(K1);
	PayOffDigitalPut two(K2);
	PayOff* p = one.clone();
	Wrapper<PayOff> four = p;
	{
		PayOff* q = two.clone();
		Wrapper<PayOff> five = q;
		std::cout << "four :";
		std::cout << (*four)(S)
			<< " five :"
			<< (*five)(S) << "\n";
		four = five;
	}
	std::cout << " four :" << (*four)(S) << "\n";
	cin.ignore();
	cin.get();
	return 0;
}