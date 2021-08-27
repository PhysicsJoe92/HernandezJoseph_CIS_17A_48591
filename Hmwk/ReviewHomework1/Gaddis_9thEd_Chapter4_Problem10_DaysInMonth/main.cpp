/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on 24 Aug 2021
 * Purpose: Determine the number of days in the month
 */

// System Libraries
#include <iostream>     // I/O libraries
using namespace std;    // STD Name-space where lib is compiled

// Code begins here with main
int main(int argc, char** argv){
    
    // Declare variables
    int days, month, year;
    
    // Display purpose
    cout << "This program will determine if the number of days in a month\n";
    cout << "based on the year and month entered.\n\n";
    // Get the year and month
    cout << "Enter the month: ";
    cin >> month;
    
    while(month<=0 || month>12){
        cout << "Month must be entered from 1-12\n";
        cout << "Enter the month: ";
        cin >> month;
    }
    cout << "Enter the year: ";
    cin >> year;
    // Find case for month
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: days = 31;
        break;
        
        case 4:
        case 6:
        case 9:
        case 11: days = 30;
        break;
        
        // Determine if leap year
        case 2: if(year%100==0&&year%400==0||year%100!=0&&year%4==0){
                    days = 29;
                }
                else
                    days = 28;
        break;
        
        default: cout << "Invalid Choice" << endl;
    }
    // Display number of days
    cout << "Month " << month << " of the year " << year;
    cout << " has " << days << " days." << endl;
    return 0;
}