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
char state_abbreviation[][3] = {"TX","AZ","WA","AK","AR","MT","FL","GA","CA","MS",
                                "NY","TN","ID","MI","OK","NJ","OH","CO","IA","VI",
                                "MO","TT","IL","NC","OR","UT","PR","LA","KY","PA",
                                "IN","NM","MN","VA","NV","WY","WI","ND","SD","ME",
                                "RI","MA","NE","HI","SC","AL","NH","KS","WV","DE",
                                "DC","CT","MD","VT" };
//The number of state abbreviations 
int size_state_abbreviation = sizeof(state_abbreviation) / sizeof(state_abbreviation[0]);

/*************************************************************************************/
//Write here your code to define the enumerators, structures, inline-classes and any
// other function you may need.
class airport {
  private:
    int airport_id;
    char* state;
    string airport_name;
  public:
    // accessors
    int getAirportID() const;
    char* getState() const;
    string getAirportName() const;
    // mutators
    void setAirportID(int);
    void setState(char*);
    void setAirportName(string);
    // constructor
    airport();
    // destructor
    ~airport();
};


/*************************************************************************************/
int main() {
    //************************* [MAIN_CODE] ****************************************//
    //The airport_db2.txt is text file;
    char filename[] = "airports_db2.txt";

    //Count the number of lines in the input file.
    //Dynamically allocate an array of course structures
    //read the information from airport_db2.txt into airpoprt_db_array dynamic array

   /*************************************************************************************/
   // a)	How many airports are in TX:
   // b)	Whatâ€™s the state abbreviation / code with the largest number of airports ? 
   // c)	Which airport has the shortest name ? 
   /******************************** [END] **********************************************/
    return 0;
}//End of main