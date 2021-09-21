/*
 * File: main.cpp  
 * Author: Joseph Hernandez
 * Created on 27 Aug 2021
 * Purpose: Use binary search function to search an array of strings
 */

// System Libraries
#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN 25
#define MAX_LEN 100

// Function Prototypes
void slctSrt(char [][NAME_LEN], int);
int bSrch(char [][NAME_LEN], char [], int);

// Code execution begins here with main
int main(){
    const int NUM_NAMES  = 20;
    int result;
    int count=1;
    char moveOn;
    char nmSrch[NAME_LEN];
    char names[][NAME_LEN]= 
                        {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                        "Looney, Joe", "Wolfe, Bill", "James, Jean",
                        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                        "Pike, Gordon", "Holland, Beth" };



    int n=sizeof(names)/sizeof(names[0]);
    
    // Sort char array
    slctSrt(names,n);


    do{
        // Search for name
        cout<<"(LastName, FirstName)\nSearch for a name:"<<endl;
        cin.getline(nmSrch, NAME_LEN);
    
        // Binary search
        result=bSrch(names,nmSrch,n);

        // Show results
        if(result!=-1){cout<<"Match found!"<<endl;}
        else{cout<<"No Match Found!"<<endl;}
    
        // Continue search
        cout<<"Do you wish to find another name?\nY/N?"<<endl;
        cin>>moveOn;
        if(moveOn=='Y' || moveOn=='y')  {count++;}
        
        // Clear input
        cin.clear();
        cin.ignore(1000,'\n');
    }while(moveOn == 'Y' || moveOn == 'y');

    return 0;
}

int bSrch(char arr[][NAME_LEN], char srch[], int n){
    int first=0,
        last=n-1,
        middle,
        pos;
    bool found=false;
    
    while(!found && first<=last){
        pos=-1;
        middle=(first+last)/2;
        if(strcmp(srch, arr[middle])== 0){
            found=true;
            pos=middle;
        }
        else if(strcmp(srch, arr[middle])<0){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
    }
   
    return pos;
}
void slctSrt(char arr[][NAME_LEN], int n){
    int minIndx;
    char minName[n];
    
    for(int i=0;i<n-1;i++){
        minIndx=i;
        strlcpy(minName, arr[i],n);
        for(int j=i+1;j<n;j++){
            if(strcmp(minName, arr[j])>0){
                strlcpy(minName, arr[j],n);
                minIndx=j;
            }
        }
            char temp[n];
            strlcpy(temp, arr[i],n);
            strlcpy(arr[i], arr[minIndx],n);
            strlcpy(arr[minIndx], temp,n);
    }
}
