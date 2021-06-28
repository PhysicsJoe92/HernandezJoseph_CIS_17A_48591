/* 
 * File:   BinaryStringSearch.cpp
 * Author: Joseph Hernandez
 * Created on June 25, 2021, 10:47 PM
 * Purpose: Modify binary search function to search for strings
 */

// Libraries
#include <iostream>
#include <string>
using namespace std;

// Prototype
void selectionSort(string[], int);
void swap(string &, string &);
int binarySearch(string[],int,string);

// Code Execution Begins Here
int main(){
    //Variables
    const int NUM_NAMES = 20;
    string srchName;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                              "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                              "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                              "Looney, Joe", "Wolfe, Bill", "James, Jean",
                              "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                              "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                              "Pike, Gordon", "Holland, Beth" };
    
    //Sort the names in ascending order
    selectionSort(names,NUM_NAMES);
    
    // Search for name
    cout << "Enter Last Name, First Name: ";
    getline(cin, srchName);
    int position = binarySearch(names,NUM_NAMES,srchName);
    
    if (position != -1)
        cout << names[position] << " was found" << endl;
    else{
        cout << srchName << " was not found" << endl;
    }
    
    return 0;
}

// Functions
void selectionSort(string array[],int SIZE){
    int minIndex;
    string minValue;
    
    for (int strtIndex = 0; strtIndex < (SIZE -1); strtIndex++){
        minIndex = strtIndex;
        minValue = array[strtIndex];
        for (int index = strtIndex + 1; index < SIZE;index++){
            if(array[index] < minValue){
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex],array[strtIndex]);
    }
}

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}

int binarySearch(string array[], int size, string name){
    int first = 0, 
        last = size - 1,
        middle,
        position = -1;
    bool found = false;
    
    while(!found && first <=last){
        middle = (first + last) / 2;
        if (array[middle] == name){
            found = true;
            position = middle;
        }
        else if (array[middle] > name) last = middle - 1;
        else first = middle + 1;
    }
    return position;
}