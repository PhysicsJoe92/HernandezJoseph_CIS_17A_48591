/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on 25 Aug 2021
 * Purpose: read in the number of rainy, sunny, or cloudy days during a three
 *          month period from a file. Then tally the number of R, S, or C days 
 *          to display.
 */

// System Libraries
#include <iostream>     // I/O Libraries
#include <iomanip>
#include <fstream>      // File Libraries
using namespace std;

// Global Variables
const unsigned char ROW=3;
const unsigned char COL=30;

// Function Prototypes
int mstRain(int , int , int );
void fillArr(char [][COL]);
void dspRain(int&);
void dspWthr(int [][5]);
void prtData(int [][5], int&);
void wthrInf(char [][COL], int [][5], int&);

// Code execution begins here with main
int main(int argc, char** argv){

    char rsArr[ROW][COL];
    int mnthWtr[ROW][5];
    int mostRn;

    //Fill array
    fillArr(rsArr);
    
    // Determine weather
    wthrInf(rsArr, mnthWtr, mostRn);
    
    // Display the weather for each month
    dspWthr(mnthWtr);

    // Display which month had the most rain
    dspRain(mostRn);
    
    // Print report in WeatherDataReport.txt file
    prtData(mnthWtr, mostRn);

    return 0;
}

// Functions

/*  
 *  Purpose:    Calculate which month had the most rain where 
 *              1=June(Z), 2=July(X), or 3=August(Y)
 */
int mstRain(int Z, int X, int Y){
    int month;
    
    if(Z>X && Z>Y)
        month=1;
    else if(X>Z && X>Y)
        month=2;
    else if(Y>Z && Y>X)
        month=3;
    
    return month;
}

/*
 * Purpose: Display which month had the most rain where 
 *          1=June, 2=July, or 3=August
 */
void dspRain(int& mR){
    if(mR==1)         cout<<"June had the most rainy days."<<endl;
    else if(mR==2)    cout<<"July had the most rainy days."<<endl;
    else if(mR==3)    cout<<"August had the most rainy days."<<endl;
}

/*
 * Purpose: Display the weather for each month
 */
void dspWthr(int wtrArr[][5]){
    // June totals
    cout<<"June had a total of:\n";
    cout<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][1]<<"\n";
    cout<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][1]<<"\n";
    cout<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][1]<<endl<<endl;

    // July totals
    cout<<"July had a total of:\n";
    cout<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][2]<<"\n";
    cout<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][2]<<"\n";
    cout<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][2]<<endl<<endl;
 
    // August totals
    cout<<"August had a total of:\n";
    cout<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][3]<<"\n";
    cout<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][3]<<"\n";
    cout<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][3]<<endl<<endl;                
    
    // Totals
    cout<<"There was a total of:\n";
    cout<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][4]<<"\n";
    cout<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][4]<<"\n";
    cout<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][4]<<endl<<endl;                
    
}

/*
 * Purpose: Fill the array that takes in the data from RainOrSine.txt 
 *          and stores it in memory
 */
void fillArr(char arr[][COL]){
    ifstream iFile;
    iFile.open("RainOrShine.txt");
    for (int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            iFile>>arr[i][j];
        }
    }
    iFile.close();
}

/*
 * Purpose: Print the data to a file WeatherDataReport.txt to create a report
 */
void prtData(int wtrArr[][5], int& mR){
    ofstream oFile;
    oFile.open("WeatherDataReport.txt");
        // June totals
    oFile<<"June had a total of:\n";
    oFile<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][1]<<"\n";
    oFile<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][1]<<"\n";
    oFile<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][1]<<endl<<endl;

    // July totals
    oFile<<"July had a total of:\n";
    oFile<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][2]<<"\n";
    oFile<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][2]<<"\n";
    oFile<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][2]<<endl<<endl;
 
    // August totals
    oFile<<"August had a total of:\n";
    oFile<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][3]<<"\n";
    oFile<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][3]<<"\n";
    oFile<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][3]<<endl<<endl;                
    
    // Totals
    oFile<<"There was a total of:\n";
    oFile<<"Cloudy days "<<right<<setw(3)<<wtrArr[0][4]<<"\n";
    oFile<<"Rainy days  "<<right<<setw(3)<<wtrArr[1][4]<<"\n";
    oFile<<"Sunny days  "<<right<<setw(3)<<wtrArr[2][4]<<endl<<endl;                
    
    if(mR==1)         oFile<<"June had the most rainy days."<<endl;
    else if(mR==2)    oFile<<"July had the most rainy days."<<endl;
    else if(mR==3)    oFile<<"August had the most rainy days."<<endl;
    oFile.close();
}

/*
 * Purpose: Take data from array and calculate the number of (C)cloudy days, 
 *          (R)rainy days, or (S)sunny days. Then run a total of those days for
 *          each individual month and for all three months.
 */
void wthrInf(char arr[][COL], int wArr[][5], int &rnMost){

    int cT=0;       // Total cloud
    int cldCntZ=0;  // June cloud total
    int cldCntX=0;  // July cloud total
    int cldCntY=0;  // Aug cloud total
    
    int rT=0;       // Total rain
    int rnCntZ=0;   // June rain total
    int rnCntX=0;   // July rain total
    int rnCntY=0;   // Aug rain total
       
    int sT=0;       // Total sun
    int sunCntZ=0;  // June sun total
    int sunCntX=0;  // July sun total
    int sunCntY=0;  // Aug sun total
    
    // Get totals for each month for cloudy, rainy, or sunny days
    for (int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(i==0){
                switch (arr[0][j]){         // Month of June
                    case 'C': cldCntZ++;
                    cT++;
                    break;
                    case 'R': rnCntZ++;
                    rT++;
                    break;
                    default: sunCntZ++;
                    sT++;
                    break;
                }
            }
            else if(i==1){
                switch (arr[1][j]){         // Month of July
                    case 'C': cldCntX++;
                    cT++;
                    break;
                    case 'R': rnCntX++;
                    rT++;
                    break;
                    default: sunCntX++;
                    sT++;
                    break;
                }
            }
            else if(i==2){                  // Month of August
                switch (arr[2][j]){
                    case 'C': cldCntY++;
                    cT++;
                    break;
                    case 'R': rnCntY++;
                    rT++;
                    break;
                    default: sunCntY++;
                    sT++;
                    break;
                }
            }
        }
    }
   // Assign values to 3x5 weather array for monthly data
    for(int i=0;i<ROW;i++){
       for(int j=0;j<5;j++){
           if(i==0){
               wArr[i][0]=0;     // Initialize first val in array
               wArr[i][1]=cldCntZ; // June cloud total
               wArr[i][2]=cldCntX; // July cloud total
               wArr[i][3]=cldCntY; // Aug cloud count
               wArr[i][4]=cT;      // Total Cloud
           }
           else if(i==1){
               wArr[i][0]=0;     // Initialize first val in array
               wArr[i][1]=rnCntZ;  // June rain total
               wArr[i][2]=rnCntX;  // July rain total
               wArr[i][3]=rnCntY;  // Aug rain total
               wArr[i][4]=rT;      // Total rain
           }
           else if(i==2){
               wArr[i][0]=0;     // Initialize first val in array
               wArr[i][1]=sunCntZ; // June sun total
               wArr[i][2]=sunCntX; // July sun total
               wArr[i][3]=sunCntY; // Aug sun total
               wArr[i][4]=sT;      // Total sun
           }
       }
   }
    rnMost = mstRain(rnCntZ, rnCntX, rnCntY);
}