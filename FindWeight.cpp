#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const string LIGHT_MESSAGE("The object is light");
    const string HEAVY_MESSAGE("The object is heavy");

    const double ACCEL_EARTH = 9.807;
    const double ACCEL_VENUS = 8.87;
    const double ACCEL_MARS = 3.7;

    const string HEADING1("Planet");
    const string HEADING2("Weight (N)");
    const unsigned int HEADING1_LEN = 6;
    const unsigned int PRECISION = 4;
    const unsigned int HEADING2_LEN = 14;

    double mass, weight;

    cout << "Please enter the mass of an object in kilograms: ";
    cin >> mass;

    if (mass <= 0.0)
    {
        cout << "\nError, invalid mass entered.\nThe entered mass must be greater than zero." << endl;
    }
    else
    {
        cout << fixed << showpoint << setprecision(PRECISION);
        cout << endl;
        cout << left << setw(HEADING1_LEN) << HEADING1 << '\t';
        cout << right << setw(HEADING2_LEN) << HEADING2 << endl;
        cout << "\n";



        weight = mass * ACCEL_EARTH;

        cout << left << setw(HEADING1_LEN) << "Earth" << '\t';
        cout << right << setw(HEADING2_LEN) << weight;

        if (weight < 5.0)
        {
            cout << "\tThe object is light\n";
        }
        else if (weight > 1500)
        {
            cout << "\tThe object is heavy\n";
        }
        else
        {
            cout << endl;
        }



        weight = mass * ACCEL_VENUS;



        cout << left << setw(HEADING1_LEN) << "Venus" << '\t';
        cout << right << setw(HEADING2_LEN) << weight << endl;

        weight = mass * ACCEL_MARS;



        cout << left << setw(HEADING1_LEN) << "Mars" << '\t';
        cout << right << setw(HEADING2_LEN) << weight << endl;
    }



    return 0;
}