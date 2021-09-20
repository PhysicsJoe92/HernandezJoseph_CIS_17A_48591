/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 * Created on 10 September 2021 22:34
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    int temp, input, size;
    vector <int> numbers;
    
    // Get how many numbers will be entered
    cout<<"Input the number of integers to input."<<endl;
    cin>>input;
    
    // Input validation
    while(input>=80){
        cout<<"Enter a number less than 80"<<endl;
        cin>>input;
    }
    
    cout<<"Input each number."<<endl;
    for(int i=0;i<input;i++){
        cin>>temp;
        numbers.push_back(temp);
    }
    
    // Put in Even or Odd vector
    for(int i=0;i<input;i++){
        if(numbers[i]%2==0){
            even.push_back(numbers[i]);
        }
        else
            odd.push_back(numbers[i]);
    }
}

void copy(vector<int> even, vector<int> odd,int arr[][COLMAX]){
    int sizeE, sizeO;
    int i=0,
        j=0;
    
    // Get the size of each vector
    sizeE=even.size();
    sizeO=odd.size();
    
    // Copy contents of vector into the array
    while(i<sizeE){
        arr[i][0]=even[i];
        i++;
    }
    while(j<sizeO){
        arr[j][1]=odd[j];
        j++;
    }
}

void prntAry(const int array[][COLMAX],int even,int odd,int wdth){
    int i=0,
        j=0;

    // Display header
    cout<<setw(wdth)<<"Array"
        <<setw(wdth)<<"Even"
        <<setw(wdth)<<"Odd"<<endl;
    
    while(i<even && j<odd){
        cout<<setw(2*wdth)<<array[i][0]
            <<setw(wdth)<<array[j][1]<<endl;
        i++;
        j++;
    }
    while(i<even){
        cout<<setw(2*wdth)<<array[i][0]<<endl;
        i++;
    }
    while(j<odd){
        cout<<setw(3*wdth)<<array[j][1]<<endl;
        j++;
    }
}

void prntVec(vector<int> even, vector<int> odd,int wdth){
    int sizeE, sizeO;
    int i=0,
        j=0;
    
    // Get size of each vector
    sizeE=even.size();
    sizeO=odd.size();

    // Display Header
    cout<<setw(wdth)<<"Vector"
        <<setw(wdth)<<"Even"
        <<setw(wdth)<<"Odd"<<endl;
    
    // Print vector
    while(i<sizeE && j<sizeO){
        cout<<setw(2*wdth)<<even[i]
            <<setw(wdth)<<odd[i]<<endl;
        i++;
        j++;
    }
    while(i<sizeE){
        cout<<setw(2*wdth)<<even[i]<<endl;
        i++;
    }
    while(j<sizeO){
        cout<<setw(3*wdth)<<odd[j]<<endl;
        j++;
    }  
}
