#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double readFutureValue() {
    double future = 0;
    do {
        cout << "Enter the future value of the investment: ";
        cin >> future;
        if (future <= 0) {
            cout << "Error the future value must be greater than zero." << endl;
        }
    } while (future <= 0);
    return future;
}

double readInterestRate() {
    double rate = 0;
    do {
        cout << "Enter the annual interest rate: ";
        cin >> rate;
        if (rate <= 0) {
            cout << "Error the annual interest rate must be greater than zero." << endl;
        }
    } while (rate <= 0);
    return rate / 100;
}

int readYears() {
    int yrs = 0;
    do {
        cout << "Enter the whole number of years of the investment: ";
        cin >> yrs;
        if (yrs <= 0) {
            cout << "Error the number of years must be greater than zero." << endl;
        }
        if (yrs > 0) {
            continue;
        }
    } while (yrs <= 0);
    return yrs;
}

double presentValue(double futureValue, double interestRate, int numberYears) {
    return futureValue / (pow(1 + interestRate, numberYears));
}

void displayResults(double presentValue, double futureValue, double interestRate, int numberYears) {
    cout << fixed << setprecision(2) << "Present value: $" << presentValue << endl;
    cout << "Years: " << numberYears << endl;
    cout << fixed << setprecision(3) << "Annual interest rate: " << interestRate*100 << "%" << endl;
    cout << fixed << setprecision(2) << "Future value: $" << futureValue << endl;
}

int main() {
    double present;
    double future;
    double rate;
    int yrs;

    future = readFutureValue();
    rate = readInterestRate();
    yrs = readYears();

    present = presentValue(future, rate, yrs);
    displayResults(present, future, rate, yrs);

    return 0;
}