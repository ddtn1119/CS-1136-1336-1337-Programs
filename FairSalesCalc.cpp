#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int chilidogs;
	int corndogs;
	int chips;
	int sdrinks;
	int waterb;

	cout << "Enter the number of chili dogs sold:" << endl;
	cin >> chilidogs;
	cout << "Enter the number of corn dogs sold:" << endl;
	cin >> corndogs;
	cout << "Enter the number of chips sold:" << endl;
	cin >> chips;
	cout << "Enter the number of soft drinks sold:" << endl;
	cin >> sdrinks;
	cout << "Enter the number of water bottles sold:" << endl;
	cin >> waterb;

	double chiliprice;
	double cornprice;
	double chipprice;
	double drinkprice;
	double waterprice;
	double taxable;
	double taxamount;
	double nontax;
	double total;

	chiliprice = (double) chilidogs*8.00;
	cornprice = (double) corndogs*6.00;
	chipprice = (double) chips*2.00;
	drinkprice = (double) sdrinks*5.00;
	waterprice = (double) waterb*4.00;
	taxable = (double) chiliprice + cornprice + chipprice + drinkprice;
	taxamount = (double) (chiliprice * 0.0825) + (cornprice * 0.0825) + (chipprice * 0.0825) + (drinkprice * 0.0825);
	nontax = (double) waterprice;
	total = (double) taxable + taxamount + nontax; 

	cout << fixed << setprecision(2);

	cout << "Taxable:     " << "$" << setw(8) << taxable << endl;
	cout << "Tax amount:  " << "$" << setw(8) << taxamount << endl;
	cout << "Non-taxable: " << "$" << setw(8) << nontax << endl;
	cout << "Total:       " << "$" << setw(8) << total << endl;

	return 0;

}