/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 * Created on 18 September 2021 00:32
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void getAray(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    getAray(array);
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
        cout << endl;
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
void getAray(char a[]){
    int count = 0;
    while(cin>>a&&count++<=20){};
}
int read(char a[]){
    unsigned char count = 0;
    while(a[count++]!='\0'){};
    return count-1;
}
void sort(char a[], int n){
   for(int i = 0; i < n-1; i++){
       for(int j = i; j < n; j++){
           if(a[i]>a[j]){
               a[i]=a[i]^a[j];
               a[j]=a[i]^a[j];
               a[i]=a[i]^a[j];
           }
       }
   }
}
void print(const char a[],int n){
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
}