/*
 * File: DaysInMonth
 * Author: Joseph Hernandez
 * Created 24 June 2021
 * Purpose: To tell how many days are in a given month
 */
// System Libraries
#include <iostream>
using namespace std;

// Code Begins
int main(){
    // Variables
    int month, year;
    
    //Get month and year
    cout << "Please enter the month of the year, from 1 to 12: ";
    cin >> month;
    cout << endl <<
            "Please enter the year: ";
    cin >> year;
    cout << endl;
    
    //Display the number of days
    switch (month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: cout << "There are 31 days in month " << month << endl; break;
        case 4:
        case 6:
        case 9:
        case 11: cout << "There are 30 days in month " << month << endl; break;
        case 2:{
            if (year % 100 == 0){
                if (year % 400 == 0)
                    cout << "There are 29 days for month " << month << endl;
                else cout << "There are 28 days for month " << month << endl;
            }
            else if (year % 100 != 0){
                if (year % 4 == 0)
                    cout << "There are 29 days for month " << month << endl;
                else cout << "There are 28 days for month " << month << endl;
            } break;
            default:
                cout << "You did not enter in the correct format.\n"
                    "Please try again.\n";
        }
    }
    return 0;
}