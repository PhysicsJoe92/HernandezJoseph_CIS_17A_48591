/*
 * File: Population
 * Author: Joseph Hernandez
 * Created 24 June 2021
 * Purpose: To calculate the population growth
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Code Begins
int main() {
    // Variables
    int startPop, dlyInc, numDays;
    float totPop;
    
    // Get starting population
    cout << "Please enter the starting population number: ";
    cin >> startPop;
    
    // Validate starting organism population
    while (startPop < 2){
        cout << "You must enter a starting population of at least 2!\n"
                "Most species need to breed!\n"
                "Please enter the starting population number: ";
        cin >> startPop;
    }
    
    // Get population growth as a percentage
    cout << "Enter the average daily population growth: ";
    cin >> dlyInc;
    
    // Validate average daily population growth
    while (dlyInc < 0){
        cout << "You cannot have a negative population growth!\n"
                "Unless they are going extinct!\n"
                "Please enter the average daily population growth "
                "greater than or equal to 0: ";
        cin >> dlyInc;
    }
     // Get number of days they will multiply
    cout << "Enter the number of days you wish to calculate: ";
    cin >> numDays;
    
    // Validate the number of days
    while (numDays < 1){
        if (numDays == 0){
            cout << "The number of days has to be greater than zero! "
                    "You have to count more than just today!\n";
        }        
        else{
                cout << "You can not go back in time and have negative days! "
                "Unless, of course, you have a DeLorean time machine...\n";
        }
        cout << "Please enter the number of days you wish to calculate: ";
        cin >> numDays;
    }
    
    // Calculate the daily growth
    
    for (int n = 1; n <= numDays; n++){
        totPop = (startPop * (dlyInc/100.0))* n + startPop;
    cout << fixed << setprecision(1) << "Day " << n << " "
            "Population: " << totPop << endl;
    }
    return 0;
}
