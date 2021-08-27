/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on 24 Aug 2021
 * Purpose: Display Celsius and Fahrenheit on a table using functions
 */

// System Libraries
#include <iostream>     // I/O Libraries
#include <iomanip>
using namespace std;    // STD Name-spacing where Lib is compiled

// Function Prototypes
float celsius(float);

// Code begins here with main
int main(int argc, char** argv){
    
    // Declare variables
    float fahr;
    
    // Display heading
    cout<<"     Fahrenheit \t Celsius"<<endl;
    for(int i=0;i<37;i++)
        cout<< "*";
    cout << endl;
    
    // Fill Table
    for(fahr=1;fahr<21;fahr++){
        cout<<fixed<<setprecision(2)<<setw(12)<<fahr;
        cout<<" \t ";
        cout<<fixed<<setprecision(2)<<setw(14)<<celsius(fahr)<<endl;
    }
    for(int i=0;i<37;i++)
        cout<< "*";
    cout << endl;   
    return 0;
}


// Functions
float celsius(float f){
    float cels;
    cels=(5.0/9.0)*(f-32);
    return cels;
}