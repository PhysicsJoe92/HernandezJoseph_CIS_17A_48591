/*
 * File: CtoF.cpp
 * Author: Joseph Hernandez
 * Created on 23 Jun 2021, 9:35 pm
 * Purpose: To convert Celsius to Fahrenheit
*/

// System Libraries
#include <iostream>
using namespace std;

// Code begins here
int main() {
    // Variables
    float Cels, Fahr;

    // Get user to enter degrees in Celsius
    cout << "Please enter the degrees in Celsius: ";
    cin >> Cels;
    cout << endl;

    // Convert to Fahrenheit
    Fahr = (9.0 / 5.0) * Cels + 32;

    // Display temperature
    cout << "The temperature in Fahrenheit is " << Fahr << "." << endl;

    return 0;
}
