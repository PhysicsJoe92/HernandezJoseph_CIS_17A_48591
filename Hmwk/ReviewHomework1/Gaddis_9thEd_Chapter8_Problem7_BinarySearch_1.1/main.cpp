/*
 * File: main.cpp  
 * Author: Joseph Hernandez
 * Created on 27 Aug 2021
 * Purpose: Use binary search function to search an array of strings
 */

// System Libraries
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function Prototypes
void slctSrt(string [], int);
int bSrch(string [], string, int);

// Code execution begins here with main
int main(){
    char moveOn;
    char pntHtry;
    int result;
    int count=1;
    const int NUM_NAMES = 20;
    string nmSrch;
    vector<string> nmHstry;
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
    
    do{
        // Search for name
        cout<<"(LastName, FirstName)\nSearch for a name:"<<endl;
        getline(cin, nmSrch);
        
        // Binary Search
        result=bSrch(names,nmSrch,NUM_NAMES);
 
        if(result!=-1) cout<<"Match found!"<<endl;
        else           cout<<"No match found"<<endl;
        
        // Continue search
        cout<<"Do you wish to find another name?\nY/N?"<<endl;
        cin>>moveOn;

        if(moveOn == 'Y' || moveOn == 'y'){
            count++;
        }

        nmHstry.push_back(nmSrch);
        
        cin.clear();
        cin.ignore(1000,'\n');
        
    }while(moveOn == 'Y' || moveOn == 'y');
   
    cout<<"Would you like to print your search history?\n";
    cout<<"Y/N"<<endl;
    cin>>pntHtry;
    
    if(pntHtry == 'Y' || pntHtry == 'y'){
        for(int i=0;i<count;i++){
            cout<<nmHstry[i]<<endl;
        }
    }
    
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
