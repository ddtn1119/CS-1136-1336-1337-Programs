#include <iostream>

using namespace std;

int main(){
	double purchase;
	double stateSales;
	double countySales;
	double totalSales;

	cout << "Please enter your purchase amount:" << endl;
	cin >> purchase;

	stateSales = purchase*0.06;
	countySales = purchase*0.02;
	totalSales = stateSales + countySales;

	cout << "State sales tax = $" << stateSales << endl;
	
	cout << "County sales tax = $" << countySales << endl;
	
	cout << "Total sales tax = $" << totalSales << endl;

	return 0;
}