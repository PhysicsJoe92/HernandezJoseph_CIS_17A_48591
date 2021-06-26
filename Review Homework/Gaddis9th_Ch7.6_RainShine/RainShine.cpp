/*
* File: RainShine
* Author: Joseph Hernandez
* Created: 25 June 2021
* Prupose: Track number of rainny, sunny, or cloudy for a 3 month period
*/


// Libraries
#include <iostream>
#include <fstream>
using namespace std;

// Global variables
const int ROWS = 3, COLMNS = 30;

string MONTHS[ROWS] = {"June","July","August"};
string WTHR_NAME[ROWS] = {"Rainny", "Sunny", "Cloudy"};
const char WTHR_TYPE [ROWS] = {'R','S','C'};

// Prototypes
void getFile (char [][COLMNS], string);
void shMonth(const char [][COLMNS], int);
void shDays(const char[][COLMNS], int);
void shHighest(const char [][COLMNS]);

// Code Begins
int main(){
	// Variables
	char wthrCond[ROWS][COLMNS];
	//Get info from file
	getFile(wthrCond, "RainOrShine.txt");
	// Step through array for each day
	for (int a = 0; a <ROWS; a++) shDays(wthrCond, a);
	// Step through array for each month
	for (int i = 0; i < ROWS; i++) shMonth(wthrCond,i);
	// Display highest number of rainny days
	shHighest(wthrCond);
	cout << endl;

	return 0;
}

// Functions
void getFile(char array[][COLMNS], string RainShine){
	ifstream inFile;
	inFile.open(RainShine);
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLMNS; c++){
		inFile >> array[r][c];
		}
	}
	inFile.close();
}

void shDays (const char array[][COLMNS], int v){
	int total;
	for (int r = 0; r < ROWS; r++){
		total = 0;
		for (int c = 0; c < COLMNS; c++)
		if (array[r][c] == WTHR_TYPE[v]){
			total++;
		}
	cout << "Total number of " << WTHR_NAME[v] << " days for the month "
		<< MONTHS[r] << " are " << total << endl;
	}
	cout << endl;
}

void shMonth(const char array[][COLMNS], int i){
	int total = 0;
	for (int r = 0; r < ROWS; r++){
	for (int c = 0; c < COLMNS; c++)
		if (array[r][c] == WTHR_TYPE[i]) total++;
	}
	cout << "The total " << WTHR_NAME[i] << " days for every month is "
		<< total << endl;
}

void shHighest (const char array[][COLMNS]){
	int sum, totRain[ROWS];
	
	for (int r = 0; r < ROWS; r++){
		sum = 0;
		for (int c = 0; c < COLMNS; c++)
			if (array[r][c] == 'R') sum++;
		totRain[r] = sum;
	}
	cout << endl;

	int mostRain = totRain[0];
	string mostRainM = MONTHS[0];
	for (int i = 1; i < ROWS; i++){
		if(totRain[i] > mostRain){
			mostRain = totRain[i];
			mostRainM = MONTHS[i];
		}
		else if (totRain[i] == mostRain){
			mostRain = totRain[i];
			mostRainM += ", ";
			mostRainM += MONTHS[i];
		}
	}
	cout << mostRainM << " was had the most rainny days with a total of "
		<< mostRain << " days of rain" << endl;
}