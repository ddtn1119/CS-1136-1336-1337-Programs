#include <iostream>

using namespace std;

int main() {
    int upperbound;
    int lowerbound;
    int newline = 0;

    cout << "Enter the ASCII code that is the lower bound [32 through 126]: ";
    cin >> lowerbound;
    while (lowerbound < 32 || lowerbound > 126) {
        cout << "\nError occurred. Invalid lower bound entered." << endl;
        cout << "Enter the ASCII code that is the lower bound [32 through 126]: ";
        cin >> lowerbound;
    }
    cout << "Enter the ASCII code that is the upper bound [" << lowerbound << " through 126]: ";
    cin >> upperbound;
    while (upperbound < lowerbound || upperbound > 126) {
        cout << "\nError occurred. Invalid upper bound entered." << endl;
        cout << "Enter the ASCII code that is the upper bound [" << lowerbound << " through 126]: ";
        cin >> upperbound;
    }
    // create the loop

    cout << "\nThe characters with ASCII values in range " << lowerbound << " through " << upperbound << " are:\n" << endl;
    for (int i = lowerbound; i <= upperbound; i++) {
        // only print out 15 characters in a single line
        if (newline == 15) {
            cout << endl;
            // recount all characters after each new line
            newline = 0;
        }
        cout << char(i);
        newline++;
    }
    cout << endl;
    return 0;
}