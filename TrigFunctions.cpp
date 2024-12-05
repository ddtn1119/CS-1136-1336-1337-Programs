#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){
	double rad;
	double degrees;
	double r1;
	double r2;
	double r3;

	cout << "Please enter angle in degrees:" << endl;
	cin >> degrees;
	rad = (degrees * 3.141592653589793 / 180);
	r1 = sin(degrees * 3.141592653589793 / 180);
	r2 = cos(degrees * 3.141592653589793 / 180);
	r3 = tan(degrees * 3.141592653589793 / 180);
	cout << "sine(" << rad << ") = "<< r1 << endl;
	cout << "cosine(" << rad << ") = "<< r2 << endl;
	cout << "tangent(" << rad << ") = "<< r3 << endl;

	return 0;

}