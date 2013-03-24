/*
 * File: NumericConversion.cpp
 * ---------------------------
 * Name: Dustin Hawkinson
 *
 * This file is titled incorrectly.  The file is
 * assignment 1, program 4 - Strings
 *
 * I am sure this code is super inefficient :(
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

string removeDuplicateNums(string str);
string charToInt(char chr);
string truncateResult(string str);
string convertName(string name);


/* Main program */

int main() {
    
    while (true) {
        cout << "Enter surname (RETURN to quit): ";
        string name = getLine();
        if (name != ""){
            string soundex = convertName(name);
            cout << "Soundex code for " << name << " is " << soundex << endl;
        } else {
            break;
        }
    }
    
    return 0;
}

/* removes any consecutive digits and removes all 0's */
string removeDuplicateNums(string str){
    
    string strNew;
    strNew += str[0];
    
    for (int i = 1; i < str.length(); i++) {
        
        if (str[i] != str[i - 1] && str[i] != '0'){
            strNew += str[i];
        }
        
    }
    
    return strNew;
    
}

/* Takes in one char at a time and converts to the numeric equivelent */
string charToInt(char chr){
    
    string str = " ";
    
    if (chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U'
        || chr == 'H' || chr == 'W' || chr == 'Y') {
        
        str[0] = '0';
        
    } else if (chr == 'B' || chr == 'F' || chr == 'P' || chr == 'V') {
        
        str[0] = '1';
    
    } else if (chr == 'C' || chr == 'G' || chr == 'J' || chr == 'K' || chr == 'Q'
               || chr == 'X' || chr == 'Z' || chr == 'S') {
     
        str[0] = '2';
    
    } else if (chr == 'D' || chr == 'T') {
        
        str[0] = '3';
        
    } else if (chr == 'M' || chr == 'N') {
        
        str[0] = '4';
        
    } else if (chr == 'L') {
        
        str[0] = '5';
        
    } else if (chr == 'R') {
        
        str[0] = '6';
        
    } else {
        
        return "";
        
    }
    
    return str;

}

/* Reduces the resulting string to a length of 4, or adds 0's to increase
 * increase length to 4 */
string truncateResult(string str){
    
    string strNew = "    ";
    strNew[0] = str [0];
    
    for (int i = 1; i < 5; i++) {
        
        if (str[i] >= '1' && str[i] <= '6')
            strNew[i] = str[i];
        else
            strNew[i] = '0';
        
    }
    
    
    return strNew;
}

/* converts the input name to the soundex code */
string convertName(string EnteredName){
 
    string name = toUpperCase(EnteredName);
    string str = " ";
    str[0] = name[0]; //keeps the first character the same
    
    for (int i = 1; i < name.length(); i++) {  //replaces letters with numbers
        str += (charToInt(name[i]));
    }
    
    str = removeDuplicateNums(str);
    
    str = truncateResult(str);
    
    return str;
}