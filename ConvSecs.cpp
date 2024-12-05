#include <iostream>

using namespace std;

int main(){
    long long int input;
    cout << "Enter the number of seconds: " << endl;
    cin >> input;

    if (input <= 0) {
        cout << "seconds must be greater than zero" << endl;
    }
    else {
        long long int days = input / (24 * 3600);

        input = input % (24 * 3600);
        long long int hours = input / 3600;

        input %= 3600;
        long long int minutes = input / 60;

        input %= 60;
        long long int seconds = input;

        if (days > 0) {
            cout << "Day(s): " << days << endl;
        }
        if (hours > 0) {
            cout << "Hour(s): " << hours << endl;
        }
        if (minutes > 0) {
            cout << "Minute(s): " << minutes << endl;
        }
        if (seconds > 0) {
            cout << "Remaining second(s): " << seconds << endl;
        }
    }

    return 0;

}