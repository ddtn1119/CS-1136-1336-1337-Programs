#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

int main() {
    unsigned seed;
    unsigned int i;
    int flip;
    char yn;
    int flipcount = 1;
    int manyHeads = 0;
    int manyTails = 0;
    double headper;
    double tailper;

    cin >> seed;
    srand(seed);

    while (true) {
        if (!cin) {
            break;
        }

        int ht = rand() % 2 + 1;
        if (ht == 1) {
            cout << "Flip = Heads" << endl;
            manyHeads++;
        }
        if (ht == 2) {
            cout << "Flip = Tails" << endl;
            manyTails++;
        }

        cout << "\nDo you want to flip again? Enter Y for yes and N for no" << endl;
        cin >> yn;

        while ((yn != 'y' && yn != 'Y') && (yn != 'n' && yn != 'N')) {
            cout << "Invalid character." << endl;
            cout << "\nDo you want to flip again? Enter Y for yes and N for no" << endl;
            cin >> yn;

        }
        if (yn == 'y' || yn == 'Y') {
            flipcount++;
        }
        if (yn == 'n' || yn == 'N') {
            headper = (double)manyHeads / flipcount * 100;
            tailper = (double)manyTails / flipcount * 100;
            cout << fixed << setprecision(1);
            cout << "\n" << manyHeads << " of the " << flipcount << " flips were Heads or " << headper << "% were Heads." << endl;
            cout << manyTails << " of the " << flipcount << " flips were Tails or " << tailper << "% were Tails." << endl;
            break;
        }
    }


    return 0;
}