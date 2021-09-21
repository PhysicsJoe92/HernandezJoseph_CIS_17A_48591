/*
 * File: main.cpp  
 * Author: Joseph Hernandez
 * Created on 27 Aug 2021
 * Purpose: Use binary search function to search an array of strings
 */

// System Libraries
#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
void slctSrt(string [], int);
int bSrch(string [], string, int);

// Code execution begins here with main
int main(){
    char moveOn;
    int result;
    const int NUM_NAMES = 20;
    string nmSrch;

    string names[NUM_NAMES] = 
                            {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                            "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                            "Looney, Joe", "Wolfe, Bill", "James, Jean",
                            "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                            "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth" };

    // Sort the string array
    slctSrt(names, NUM_NAMES);
    
        // Search for name
        cout<<"(LastName, FirstName)\nSearch for a name:"<<endl;
        getline(cin, nmSrch);
        
        // Binary Search
        result=bSrch(names,nmSrch,NUM_NAMES);
        
        //Show results
        if(result!=-1) cout<<"Match found!"<<endl;
        else           cout<<"No match found"<<endl;

    return 0;
}

int bSrch(string arr[], string name, int size){
    int first=0,
        last=size-1,
        middle,
        pos=-1;
    bool found = false;
    
    while(!found && first<=last){
        middle=(first+last) / 2;
        if(arr[middle]==name){
            found=true;
            pos=middle;
        }
        else if(arr[middle]>name)   last=middle-1;
        else    first=middle+1;
    }
    return pos;
}


void slctSrt(string arr[], int size){
        int minIndx;
        string minName;
        string tmp;
        for(int i=0;i<(size-1);i++){
            minIndx=i;
            minName=arr[i];
            for(int j=i+1;j<size;j++){
                if(arr[j]<minName){
                    minName=arr[j];
                    minIndx=j;
                }
            }
            tmp=arr[minIndx];
            arr[minIndx]=arr[i];
            arr[i]=tmp;
        }
}
