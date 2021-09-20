/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    //Exit
    return 0;
}

int  read(char arr[][COLMAX],int &row){
    int col=0;
    
    for(int i=0;i<row;i++){
        cin>>arr[i];
    }
    
    for(int j=0;j<row;j++){
        if(strlen(arr[j])>col){
            col=strlen(arr[j]);                
        }
    }
    
    return col;
}

void sort(char array[][COLMAX], int rowIn, const char replace[], const char with[]){
    char tmp[COLMAX];
    for(int i=0;i<rowIn-1;i++) {
        int min=i;
        for(int j=i+1;j<rowIn;j++) {
            if (strcmp(array[min], array[j], replace, with) > 0) {
                min=j;
            }
        }
        if (min!=i) {
            strcpy(tmp, array[i]);
            strcpy(array[i], array[min]);
            strcpy(array[min], tmp);
        }
    }
}

void print(const char array[][COLMAX], int rowIn, int){
    for (int i=0;i<rowIn;i++){
        cout<<array[i]<<endl;
    }
}

int strcmp(char arrFrst[], char arrScnd[], const char replace[], const char with[]){
    // Define two strings.
    char *copyarrFrst;
    char *copyarrScnd;

    copyarrFrst = new char[strlen(arrFrst)+1];
    copyarrScnd = new char[strlen(arrScnd) + 1];

    for(int i=0; i<strlen(arrFrst); i++)
    {
        copyarrFrst[i] = arrFrst[i];
    }
    copyarrFrst[strlen(arrFrst)] = '\0';
    for(int i=0; i<strlen(arrScnd); i++){
        copyarrScnd[i] = arrScnd[i];
    }

    copyarrScnd[strlen(arrScnd)] = '\0';

    for(int j=0; j<strlen(replace); j++){
        for(int i=0; i<strlen(arrFrst); i++){
            if(arrFrst[i] == replace[j]){
                copyarrFrst[i] = with[j];
            }
        }

        for(int i=0; i<strlen(arrScnd); i++){
            if(arrScnd[i] == replace[j]){
                copyarrScnd[i] = with[j];
            }
        }
    }
    return strcmp(copyarrFrst, copyarrScnd);
}