#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getSeconds() {
    double sec;
    cout << "Please enter the fall time (in seconds): ";
    cin >> sec;
    while (sec < 0) {
        cout << "Error the fall time must be 0 or more." << endl;
        cout << "Please enter the fall time (in seconds): ";
        cin >> sec;
    }
    return sec;
}

double findEarthFallDist(double sec) {
    const double EARTH = 9.81;
    return 0.5 * EARTH * sec * sec;
}

double findMoonFallDist(double sec) {
    const double MOON = 1.625;
    return 0.5 * MOON * sec * sec;
}

void displayResults(double sec, double earthdist, double moondist) {
    cout << fixed << setprecision(3);
    cout << "\nThe object traveled " << earthdist << " meters in " << fixed << setprecision(1) << sec << " seconds on Earth." << endl;
    cout << fixed << setprecision(3);
    cout << "The object traveled " << moondist << " meters in " << fixed << setprecision(1) << sec << " seconds on the Moon." << endl;
}

int main() {
    double sec;
    double earthdist;
    double moondist;

    sec = getSeconds();

    earthdist = findEarthFallDist(sec);
    moondist = findMoonFallDist(sec);

    displayResults(sec, earthdist, moondist);

    return 0;
}