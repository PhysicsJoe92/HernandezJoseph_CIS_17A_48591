/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on 24 Aug 2021
 * Purpose: Convert U.S. dollar to Jap Yen and Euros
 */

// System Libraries
#include <iostream>     // I/O Libraries
#include <iomanip>
using namespace std;    // STD Name-space where Lib is compiled

// Code begins here with main
int main(int argc, char** argv){
    
    // Declare Variables
    const float YEN_PER_DOLLAR = 109.82f,   //Dollar val in Yen
                EURO_PER_DOLLAR = 0.85f;    //Dollar val in Euro
    float dollar, euro, yen;
     
    // Get user to enter the U.S. currency to convert
    cout << "Enter a dollar amount to be converted: ";
    cin >> dollar;
    
    //Convert from dollar to Yen and Euro
    euro=EURO_PER_DOLLAR*dollar;
    yen=YEN_PER_DOLLAR*dollar;
    
    // Display converted currency
    cout << "Dollar\t\tEuro\t\tYen" << endl;
    cout << "***************************************************" << endl;
    cout << fixed << setprecision(2);
    cout << dollar << "\t\t" << euro << "\t\t" << yen << endl;
  
    return 0;
}

