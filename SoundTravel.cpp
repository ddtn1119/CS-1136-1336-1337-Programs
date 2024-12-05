#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  const double airspeed = 1133.2;
  const double waterspeed = 4871.0;
  const double steelspeed = 16400.0;
  int medium;
  double distance;
  double time;

  cout << "\tTime for Sound to Travel through a Medium given Distance\n" <<     endl;
  cout << "1 - Air\n2 - Water\n3 - Steel\n" << endl;
  cout << "Enter the number of the medium:" << endl;
  cin >> medium;

  if(medium != 1 && medium != 2 && medium != 3){
    cout << "The entry is invalid. Please run the program again." << endl;
  }
  else{
    cout << "Enter the distance to travel (in feet):" << endl;
    cin >> distance;
    cout << fixed << setprecision(4);
    if(distance <= 0){
      cout << "The distance must be greater than zero." << endl;
    }
    else if(medium == 1){
      time = (double) distance / airspeed;
      cout << "In air it will take " << time << " seconds to travel " <<          distance << " feet." << endl;
    }
    else if(medium == 2){
      time = (double) distance / waterspeed;
      cout << "In water it will take " << time << " seconds to travel " <<        distance << " feet." << endl;
    }
    else if(medium == 3){
      time = (double) distance / steelspeed;
      cout << "In steel it will take " << time << " seconds to travel " <<        distance << " feet." << endl;
    }
  }

  return 0;
}