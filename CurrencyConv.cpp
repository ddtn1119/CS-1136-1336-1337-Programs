#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double dollars;
	double pesos;
	double euros;
	double yen;
	
	cout << "Enter the dollar amount:" << endl;
	cin >> dollars;

	pesos = dollars*20.06;
	euros = dollars*0.99;
	yen = dollars*143.08;

	
	cout << setw(10) << "Dollars" << "\t";
	cout << setw(10) << "Pesos" << "\t";
	cout << setw(10) << "Euros" << "\t";
	cout << setw(10) << "Yen" << endl;

	cout << fixed << setprecision(2);

	cout << setw(10) << dollars << "\t";
	cout << setw(10) << pesos << "\t";
	cout << setw(10) << euros << "\t";
	cout << setw(10) << yen << endl;

	return 0;

	

}