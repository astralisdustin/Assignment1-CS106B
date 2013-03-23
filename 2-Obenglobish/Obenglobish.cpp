/*
 * File: Obenglobish.java
 * ----------------------
 * Name: Dustin Hawkinson
 * Section: None
 * This file is the second  program in assigment one.  Not obenglobish.
 */

#include <iostream>
#include "console.h"
#include "simpio.h"
#include "random.h"
using namespace std;


int enterNumOfVoters();
double enterPercentageSpread();
double enterVotingError();
double calculateInvalidPercent(int voters, double spread, double error);


/* Main program */

int main() {
    int voters = enterNumOfVoters();
    double spread = enterPercentageSpread();
    double error = enterVotingError();
    //Randomize();
    double result = calculateInvalidPercent(voters, spread, error);
    
    cout << "Chance of an invalid election result after 500 trials = " << result << "%" << endl;
    
    return 0;
}

/*takes in the number of voters from the user*/
int enterNumOfVoters(){
    
    int voters = 0;
    
    while (voters < 1){
        cout << "Enter number of voters: ";
        voters = getInteger();
    }
    
    return voters;
    
}

/*takes in the percentage spread from the user*/
double enterPercentageSpread(){
    
    double result = -1;
    
    while (result < 0 || result > 1) {
        cout << "Enter percentage spread between candidates: ";
        result = getReal();
    }
    
    return result;
    
}

/*takes in the voting error percentage from the user*/
double enterVotingError(){
    
    double result = -1;
    
    while (result < 0 || result > 1) {
        cout << "Enter voting error percentage: ";
        result = getReal();
    }
    
    return result;
}

/*calculates the invalid percentage based on voters, spread, and error, and returns it*/
double calculateInvalidPercent(int voters, double spread, double error){
    
    int invalidElection = 0;
    int candidateAvotes = voters * spread + voters / 2;
    int candidateBvotes = voters - candidateAvotes;
    
    for (int i = 0; i < 500; i++) { //runs the election 500 times and records invalid elections
        int actualAvotes = 0;
        int actualBvotes = 0;
        
        for (int i = 0; i < candidateAvotes; i++) { //gives each vote for A the chance to be misrecorded
            if (randomChance(error))
                actualBvotes++;
            else actualAvotes++;
        }
        
        for (int i = 0; i < candidateBvotes; i++) { //gives each vote for B the chance to be misrecorded
            if (randomChance(error))
                actualAvotes++;
            else actualBvotes++;
        }

        if (actualBvotes >= actualAvotes)
            invalidElection++;

    }
        
    return double(invalidElection) / 500 * 100;
   
}