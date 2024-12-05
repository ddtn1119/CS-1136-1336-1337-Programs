#include <iostream>

using namespace std;

int main() {
    unsigned int num;
    // create an array
    int elevenprimes[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    bool prime = true;
    cout << "Enter a positive whole number in the range 2 through 1000:" << endl;
    cin >> num;

    // produce no output if the number is less than 2 & greater than 1000
    if (num < 2 || num > 1000) {
        cout << num << " is not in the range 2 through 1000." << endl;
    }
    else {
        // loop 11 times
        for (int i = 0; i < 11; i++) {
            if (num == elevenprimes[i]) {
                cout << num << " is prime." << endl;
                return 0;
            }
        }
        // number is not prime if divisible by one of the 11 prime numbers
        for (int i = 0; i < 11; i++) {
            if (num % elevenprimes[i] == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << num << " is prime." << endl;
        }
        else {
            cout << num << " is divisible by:" << endl;
            for (int i = 0; i < 11; i++) {
                if (num % elevenprimes[i] == 0) {
                    cout << elevenprimes[i] << endl;
                }
            }
        }
    }
    return 0;
}