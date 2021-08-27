/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on 24 Aug 2021
 * Purpose: To convert Fahrenheit into Celsius
 */

// System Libraries
#include <iostream> // I/O Libraries
using namespace std; // STD Name-space where Library is compiled

//Code Begins here with main function
int main(int argc, char** argv){
    // Declare variables
    float fahr, cels;
    float ninfith = 1.8f;
    
    //Get the temperature in Fahrenheit
    cout << "Enter the temperature in Celsius: ";
    cin >> cels;
    
    //Convert Celsius to Fahrenheit F=(9/5)C+32
    fahr=ninfith*cels+32;
   //Display temperature in Fahrenheit
    cout << "The temperature is " << fahr << " degrees" << endl;
    return 0;
}


