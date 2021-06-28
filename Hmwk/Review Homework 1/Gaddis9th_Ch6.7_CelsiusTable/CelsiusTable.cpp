/*
*File: CelsiusTable
*Author: Joseph Hernandez
*Created 24 June 2021
*Purpose: To convert Fahrenheit to Celsius and provide a table
*/

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Functions
float celsius (float);

//Code Begins
int main () {
	// Variables
	float C;
	
	// Display Table
	cout << "***********************************\n"
		    "*  Fahrenheit   |   Celsius       *\n"
	    	"***********************************\n";
	// Loop to display conversion table
	for (int F = 0; F <= 20; F++){
	C = celsius(F);
	cout << fixed << setprecision(2) <<F << 
                "	        |     " << C <<endl;
	}
	
	
	return 0;
}


// Call Function
float celsius (float F){
	return (5.0/9.0)*(F - 32);
}