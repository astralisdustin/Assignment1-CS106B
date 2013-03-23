/*
 * File: warmup1.cpp
 * --------------------------
 * Name: Dustin Hawkinson
 * Section: none
 * This program checks for perfect numbers between 1 and 1000.
 * 
 */

#include <iostream>
#include "console.h"
using namespace std;

bool IsPerfect (int n);

int main() {
   
    for (int i = 1; i < 10000; i++) {
        if (IsPerfect(i) == true)
            cout << i << endl;
    }
    
   return 0;
}


bool IsPerfect (int n){

    int result = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0)
        result += i;
    }
    if (result == n)
        return true;
    else return false;
    
}