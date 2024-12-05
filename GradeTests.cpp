#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// function to get the number of questions (responses & keys) in each file
int readQuestionNums(string filename) {
    ifstream file(filename);

    if (!file) {
        return 0;
    }
    else {
        // increment the counter as the user types in their inputs in each file
        int count = 0;
        char answers;
        while (file >> answers) {
            count++;
        }

        return count;
    }
}

// function to display the result which takes the student's responses, the answer keys, and number of questions on the quiz/test as parameters
void displayResults(const char studentResponses[], const char answerKeys[], int questions) {
    int incorrect = 0;
    double grade;
    // count the number of incorrect answers out of the number of questions
    for (int i = 0; i < questions; i++) {
        if (studentResponses[i] != answerKeys[i]) {
            cout << "Question " << i + 1 << " has incorrect answer '" << studentResponses[i] << "', the correct answer is '" << answerKeys[i] << "'." << endl;
            incorrect++;
        }
    }
    cout << incorrect << " questions were missed out of " << questions << "." << endl;
    grade = (((double)questions - incorrect) / questions) * 100;
    cout << "The student grade is " << fixed << setprecision(2) << grade << "%" << endl;
    // the student failed the quiz if the grade percentage is less than 72.50%
    if (grade < 72.5) {
        cout << "The student has failed the quiz." << endl;
    }
    else {
        cout << "The student has passed the quiz." << endl;
    }
}

int main() {
    string keysFile, ResFile;
    char myKeys, myResponses;
    char answerKeys[50], studentResponses[50];
    ifstream file, file1, file2;
    int ansNums = 0, questNums = 0;

    cout << "Enter the name of the file containing the key." << endl;
    cin >> keysFile;
    file1.open(keysFile);
    // if the file failed to open or if the user types the wrong file name
    if (file1.fail()) {
        cout << "\"" << keysFile << "\" could not be opened." << endl;
        return 0;
    }
    // if the file reader reaches the end of file and finds the file empty
    else if (file1.peek() == EOF) {
        cout << "The file containing the key was empty." << endl;
        return 0;
    }
    else {
        int i = 0;
        while (file1 >> myKeys) {
            answerKeys[i] = myKeys;
            i++;
        }

    }


    cout << "Enter the name of the file containing the student's responses." << endl;
    cin >> ResFile;
    file2.open(ResFile);
    if (!file2) {
        cout << "\"" << ResFile << "\" could not be opened." << endl;
        return 0;
    }
    else {
        int i = 0;
        while (file2 >> myResponses) {
            studentResponses[i] = myResponses;
            i++;
        }

    }

    // close each file after done with getting the number of inputs in each file
    questNums = readQuestionNums(keysFile);
    file1.close();
    ansNums = readQuestionNums(ResFile);
    file2.close();

    // print out the error messages if there is a mismatch between each file, even if the student's response file is empty
    if (ansNums < questNums) {
        cout << "File error! There is a mismatch between the number of questions and answers." << endl;
    }
    else {
        displayResults(studentResponses, answerKeys, questNums);
    }

    return 0;
}