//These are the only header files allowed
//-----------------------------------------
#include <iostream>//for cin and cout
#include <iomanip>//for output formatting
#include <fstream>//for file handling
//-----------------------------------------
using namespace std;  //Define the namespace.

//*************Useful functions*******************************************************/
//getNumberOfRecords receives a c string with the filename/fullpath
// returns the number of lines/rows, and -1 if error
int getNumberOfRecords(char fn[]) {
    //input file stream is needed
    ifstream input;
    //call the open method
    input.open(fn);
    //test if the open function was succesful
    if (!input.is_open())
        return -1; //if open() failed, return -1
    //Use an accumulator. Local variables are NOT initialized by default
    int counter = 0;
    //Define a long c string to read the entire line(including blank spaces)
    char buffer[1000] = { '\0' };

    //Keep reading the file, till the EOF is found
    while (!input.eof()) {
        //getline() stops reading only when the newline is found
        input.getline(buffer, sizeof(buffer));
        //If the getline is successful, increase the counter
        counter++;
    }
    //Once the EOF is found, close the file
    input.close();
    //Return the value in the accumulator
    return counter;
}

//getStringLength receives a valid c string.
// return the number of characters, not including the '\0'
int getStringLength(const char* str) {
    //initialize a counter
    int i = 0;
    //Execute the loop-body till the '\0' is found
    while (str[++i] != '\0'); //<-- notice the pre increment on i and ;
    //Once the loop is done, return the value in i
    return i;
}

//copyString receives two c strings:
// const char * src: the source/original c string.
//                   const is used so it can accept c string literals
// char *& dst: the destination c string.
//        a modifiable (&) c string (char *)
void copyString(const char* src, char*& dst) {
    //First determine the length of the src
    int len = getStringLength(src);
    //Dynamically allocate memory for the dst.
    // Remember: the length does not include the '\0'
    dst = new char[len + 1];
    //Go through all the elements of the src, till '\0' is found
    int i = 0;
    while (src[i] != '\0') {
        //At each step, create a copy of src[i] into dst[i]
        dst[i] = src[i];
        //Move to the next element
        i++;
    }
    //Do not forget to add the string termination character in the
    //dst c string
    dst[i] = '\0';
}

/*************************************************************************************/
//Write here your code to define the enumerators, structures, inline-classes and any
// other function you may need.

enum AIRLINE {DL, AA, F9, UA, WN};

struct flight {
  int day;
  int carrier;
  int origin_id;
  int destination_id;
  AIRLINE a;
};

int readFlightDataBase(const char filename[], flight *& f, int size){
  ifstream input;
  input.open(filename);

  if(!input.is_open()){
    return -2;
  }

  int count = 0;
  char help[1000];

  for(int i=0; i<size; i++){
    input >> f[count].day;
    input >> f[count].carrier;
    input >> f[count].origin_id;
    input >> f[count].destination_id;

    if(f[count].carrier == 100){
      f[count].a = DL;
    }
    else if(f[count].carrier == 150){
      f[count].a = AA;
    }
    else if(f[count].carrier == 200){
      f[count].a = F9;
    }
    else if(f[count].carrier == 250){
      f[count].a = UA;
    }
    else if(f[count].carrier == 300){
      f[count].a = WN;
    }
    count++;
  }
  input.close();
  return count;
}

int countNumberOfFlightsByAirlines(flight *& f, int size, int anum){
  int count = 0;
  for(int i=0; i<size; i++){
    if(f[i].carrier == anum){
      count++;
    }
  }
  return count;
}

int countNumberOfFlightsByDays(flight *& f, int size, int d){
  int count = 0;
  for(int i=0; i<size; i++){
    if(f[i].day == d){
      count++;
    }
  }
  return count;
}

int countNumberOfFlightsbyOrigins(flight *& f, int size, int o_id){
  int count = 0;
  for(int i=0; i<size; i++){
    if(f[i].origin_id == o_id){
      count++;
    }
  }
  return count;
}

void getCarrierWLargestNumberOfFlights(flight *& f, int size,
int& airlineWLargest, int& largest_num_flights){
  largest_num_flights = 0;
  for(int i=0; i<size; i++){
    int count = 0;
    for(int j=0; j<size; j++){
      if(f[i].carrier == f[j].carrier){
        count++;
      }
    }
    if(count > largest_num_flights){
      largest_num_flights = count;
      airlineWLargest = f[i].carrier;
    }
  }
  return;
}

void getDayWLargestNumberOfFlights(flight *& f, int size,
int& dayWLargest, int& largest_num_flights){
  largest_num_flights = 0;
  for(int i=0; i<size; i++){
    int count = 0;
    for(int j=0; j<size; j++){
      if(f[i].day == f[j].day){
        count++;
      }
    }
    if(count > largest_num_flights){
      largest_num_flights = count;
      dayWLargest = f[i].day;
    }
  }
  return;
}



/*************************************************************************************/
int main() {
    //************************* [MAIN_CODE] ****************************************//
    //The flights_db2.txt is text file;
    char filename[] = "flights_db2.txt";

    //Count the number of lines in the input file.
    //Dynamically allocate an array of course structures
    //read the information from flights_db2.txt into airpoprt_db_array dynamic array
    int records = getNumberOfRecords(filename);

    if(records <= 0){
      return records;
    }

    flight* f = new flight[records];

    int N = readFlightDataBase(filename, f, records);

    if(N <= 0){
      return N;
    }
   /*************************************************************************************/
    //a)	How many AA(150) flights are in the input file ? 
    int countAA = countNumberOfFlightsByAirlines(f, N, 150);
    cout << "Number of AA flights: " << countAA << endl;
    //b)	The carrier(AIRLINE) with the largest number of flights is : 
    int anum, flight_anum;
    getCarrierWLargestNumberOfFlights(f, N, anum, flight_anum);
    cout << "Airline with largest number of flights: " << anum << " (with a total of " << flight_anum << " flights)" << endl;
    //c)	How many flights are there on the 3rd day of the month ? 
    int countFlightsinDays = countNumberOfFlightsByDays(f, N, 3);
    cout << "Number of flights on the 3rd day of the month: " <<
      countFlightsinDays << endl;
    // result: 300 (WN)
    //d)	The day of the  month with the largest number of flights is :
    int d, flight_dnum;
    getDayWLargestNumberOfFlights(f, N, d, flight_dnum);
    cout << "Day of the month with largest number of flights: " << d << " (with a total of " << flight_dnum << " flights)" << endl;
    //e)	How many flights are departing from AIRPORT_ID = 11298 ? :
    int countFlightsinID = countNumberOfFlightsbyOrigins(f, N, 11298);
    cout << "Number of flights departing from 11298: " << 
      countFlightsinID << endl;

   /******************************** [END] **********************************************/
    return 0;
}//End of main