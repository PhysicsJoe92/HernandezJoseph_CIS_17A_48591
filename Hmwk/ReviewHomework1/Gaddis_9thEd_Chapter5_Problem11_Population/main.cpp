/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on 24 Aug 2021
 * Purpose: Predict the size of a population of an organism
 */

// System Libraries
#include <iostream>     // I/O Libraries
using namespace std;    // STD Name-spacing where Lib is compiled

// Code begins here with main
int main (int argc, char** argv){
    
    // Declare variables
    float PERCENT = .01f;
    float dlyInc;
    int stPop;
    int days;
    int dlyAvg;
    int popEst;
    
    // Get the starting population size
    cout << "What is the starting population of the organism?"<<endl;
    cin >> stPop;
    
    while(stPop<2){
        cout<<"Please enter a starting population greater than 2"<<endl;
        cout<<"What is the starting population of the organism?"<<endl;
        cin>>stPop;
    }
    
    cout<<"What is the average daily population increase"
            <<" as a percentage?"<<endl;
    cin>>dlyAvg;
    
    while(dlyAvg<0||dlyAvg>100){
        cout<<"Please enter a percentage between 0 and 100"<<endl;
        cin>>dlyAvg;
    }
    
    cout<<"How many days will the population increase?"<<endl;
    cin>>days;
    
    while(days<1){
        cout<<"Please enter a number of days greater than zero"<<endl;
        cout<<"How many days will the population increase?"<<endl;
        cin>>days;
    }
    
    // Calculate the daily increase in population
    dlyInc=stPop*dlyAvg*PERCENT;
    popEst=days*(stPop+dlyInc);
    
    // Display the estimated total number of the population
    cout<<"The total population: "<<popEst<<endl;
    
    return 0;
}