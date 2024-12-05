#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//let us assume we won't go over 100 numbers
const int MAXITEMS = 100;
int items[MAXITEMS], binAssignments[MAXITEMS];
int numItems=0; //stores actual # of items
const int BINCAPACITY = 100;

void validate() {
// WRITE YOUR CODE HERE
  int sum[MAXITEMS] = {0}; /* initialize the sum(s)
  of any numbers in any bins to zero */
  int i;
  for(i=0; i<numItems; i++){
    // check if any input item is out of range (larger than 100)
    if(items[i] > BINCAPACITY){
      cout << "Input item " << items[i] << " out of range" << endl;
      return;
    }
    // check if any bin is out of range (larger than 100 or larger than the number of input bins)
    if(binAssignments[i] > numItems){
      cout << "Bin " << binAssignments[i] << " out of range" << endl;
      return;
    }
    // add up every number that belongs in the same bin together
    sum[binAssignments[i]] += items[i];
  }

  for(i=0; i<numItems; i++){
    // check if the total of all numbers in any bin exceeds the capacity (100)
    if(sum[i] > BINCAPACITY){
      cout << "Bin " << i << " total goes above 100" << endl;
      return;
    }
  }

  int maxbin = binAssignments[0];

  for(i=0; i<numItems; i++){
    if(binAssignments[i] > maxbin){
      maxbin = binAssignments[i];
    }
  }

  bool unused = false;
  for(i=0; i<numItems; i++){
    // check if any bin is skipped/unused
    if(sum[i] == 0){
      unused = true; /* return true if any unused bin is found 
      and that unused bin is less than/equal to the largest bin*/
      if(unused && i <= maxbin){
        cout << "Bin " << i << " not used" << endl;
        return;
      }
    }
  }
  // the bin packing program is valid if there is no problem described above
  cout << "Valid" << endl;
}

int main() {
   string line;
   int numAssignments = 0;

   //get all the items first.
   getline(cin, line);  //get one line of input
   istringstream istr(line);  //convert it to inputstringstream
   //extract the numbers from the stream into the array
   while (istr >> items[numItems]) 
      numItems++;

    //get bin assignments now.
   getline(cin, line);
   istringstream istr2(line);
   while (istr2 >> binAssignments[numAssignments])
      numAssignments++;

    if (numItems != numAssignments) {
        cout << "# of items and # of bin assignments mismatch.";
        exit(1);
    }
    validate();
}
