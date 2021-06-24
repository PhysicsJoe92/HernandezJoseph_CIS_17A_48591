/*
 * File: Currency Conversion
 * Author: Joseph Hernandez
 * Created 24 June 2021
 * Purpose: To convert currency from USD to Yen and Euro 
 */

// System Libraries
#include <iostream>
using namespace std;

//Global Variables
const float YEN_PER_DOLLAR = 110.88;
const float EURO_PER_DOLLAR = 0.84;

// Code Begins
int main(){
    // Variables
    float USD, YEN, EURO;
    
    // Get user to enter USD amount
    cout << "Please enter the USD amount you would like to convert:" << endl;
    cin >> USD;
    
    // Convert currency
    YEN = YEN_PER_DOLLAR * USD;
    EURO = EURO_PER_DOLLAR * USD;
    
    // Display Conversion
    cout << "The conversion rate from USD to Yen is " << YEN_PER_DOLLAR <<
            ", which converts to " << YEN << " Japanese Yen." << endl;
    cout << "The conversion rate from USD to Euro is " << EURO_PER_DOLLAR << 
            ", which converts to " << EURO << " Euros." << endl;
    
    return 0;
}