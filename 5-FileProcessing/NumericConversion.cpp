/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: Dustin Hawkinson
 *
 * This file is titled incorrectly.  The file is
 * assignment 1, program 4 - Strings
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "vector.h"
#include <fstream>
using namespace std;

/* Function prototypes */

string getFileName();
Vector<string> readFile(string str);
void drawHistogram(Vector<string> scores);

/* Main program */

int main() {
    string file = getFileName();
    Vector<string> scores = readFile(file);
    drawHistogram(scores);
    cout << "test" << endl;  //if I take this line out, nothing in drawHistogram() works?!?!!
    return 0;
}

/*Asks the user for the filename*/
string getFileName(){
    
    cout << "Enter the file name: ";
    /*For some reason I had to add the path to the filename*/
    return "/Users/astral/Downloads/Assignment1-xcode/5-FileProcessing/" + getLine();
    
}

/*opens the requested file, read the contents into and returns scores*/
Vector<string> readFile(string str){
    
    ifstream filestr;
    Vector<string> scores;
    string line;
    
    //open file
    while (true) {
        filestr.open(str.c_str());
        if (filestr.is_open()) {
            break;
        }
        cout << "ERROR opening file, try again." << endl;
        str = getFileName();
    }
   
    //read file contents into scores
    while (true) {
        if (filestr.fail()) {
            filestr.clear();
            break;
        }
        
        getline(filestr, line);
        scores.add(line);
        cout << line << endl;
        
        
    }

    filestr.close();
    return scores;
}

/**/
void drawHistogram(Vector<string> scores){
    
    
    //testing.... doesn't work
    cout << scores.toString();
    cout << "hi" << scores.size();

    
    
    
    
}
