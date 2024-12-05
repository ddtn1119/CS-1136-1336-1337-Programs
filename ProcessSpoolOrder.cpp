#include <iostream>
#include <iomanip>

using namespace std;

// this void asks for user inputs (number of spools ordered, spools in stock, & custom shipping charge) to get order
// pointers must be used for this void function to store the inputs
void getOrder(int& spoolsOrder, int& spoolsStock, char& choiceShipping, double& customShipping) {
    cout << "Please enter the number of spools ordered: ";
    cin >> spoolsOrder;
    // keep letting the user enter the number of spools ordered if less than 1
    while (spoolsOrder < 1) {
        cout << "Error, the number of spools must be at least 1." << endl;
        cout << "Please enter the number of spools ordered: ";
        cin >> spoolsOrder;
    }
    cout << "Please enter the number of spools in stock: ";
    cin >> spoolsStock;
    // keep letting the user enter the number of spools in stock if less than 0
    while (spoolsStock < 0) {
        cout << "Error, the spools in stock should be 0 or more." << endl;
        cout << "Please enter the number of spools in stock: ";
        cin >> spoolsStock;
    }
    cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
    cin >> choiceShipping;
    if (choiceShipping == 'Y' || choiceShipping == 'y') {
        cout << "What is the shipping and handling charge? ";
        cin >> customShipping;
        while (customShipping < 0) {
            cout << "Error, the charge must be at least $0.00." << endl;
            cout << "What is the shipping and handling charge? ";
            cin >> customShipping;
        }
    }
    else if (choiceShipping == 'N' || choiceShipping == 'n') {
        customShipping = 20.95;
    }
    else {
        // if the choice is either yes or no, print out the message error and keep letting the user enters the response again until correct
        while (choiceShipping != 'Y' || choiceShipping != 'y' || choiceShipping != 'N' || choiceShipping != 'n') {
            cout << "Error, this is not a valid response." << endl;
            cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
            cin >> choiceShipping;
        }
    }

    return;
}

// this function calculates the shipping charge
// the ship charge equals the number of spools ship multiplied by the default shipping price
double calcShipping(int spoolsShip, double defaultShip = 20.95) {
    double shipCharge = 0.00;
    shipCharge = defaultShip * spoolsShip;
    return shipCharge;
}

// this function calculates the charge for the number of spools ordered excluding the shipping charge
// price for each spool is $157.55
double calcSpools(int spoolsOrder) {
    double spoolsCharge = 0.00;
    spoolsCharge = spoolsOrder * 157.55;
    return spoolsCharge;
}

// the total adds the number of spools shipped multiplied by 157.55 plus the default shipping price
double calcTotal(int spoolsShip, double defaultShip = 20.95) {
    double total = 0.00;
    total = spoolsShip * 157.55 + defaultShip;
    return total;
}

int main() {
    int spoolsOrder, spoolsStock, spoolsShip, spoolsBack;
    char choiceShipping;
    double charge, customShipping, total, shipping;
    getOrder(spoolsOrder, spoolsStock, choiceShipping, customShipping);
    cout << endl;

    if (spoolsOrder > spoolsStock) {
        spoolsShip = spoolsStock;
        spoolsBack = spoolsOrder - spoolsStock;
        // only print the number of spools on back order if the number of spools ordered is larger than the number of spools in stock
        cout << "Spools ready for shipping: " << spoolsShip << endl;
        cout << "Spools on back order: " << spoolsBack << endl;
        charge = calcSpools(spoolsShip);
    }
    else {
        spoolsShip = spoolsOrder;
        spoolsBack = 0;
        cout << "Spools ready for shipping: " << spoolsShip << endl;
        charge = calcSpools(spoolsShip);
    }

    if (choiceShipping == 'Y' || choiceShipping == 'y') {
        // if the user chooses yes for custom shipping & handling charge then calculate the shipping with the price of custom shipping
        shipping = calcShipping(spoolsShip, customShipping);
    }
    else {
        // else only calculate with the number of spools shipping
        shipping = calcShipping(spoolsShip);
    }

    total = calcTotal(spoolsShip, shipping);


    cout << "Charges for " << spoolsShip << " spools: $" << fixed << setprecision(2) << charge << endl;
    cout << "Shipping and handling for " << spoolsShip << " spools: $" << fixed << setprecision(2) << shipping << endl;
    cout << "Total charges (Incl. shipping & handling): $" << fixed << setprecision(2) << total << endl;

    return 0;
}