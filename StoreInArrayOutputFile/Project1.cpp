//import libraries
#include <iostream>
#include <fstream>

using namespace std;

//function prototypes
void strCopy(char str1[], char str2[]);
int strCompare(char str1[], char str2[]);

//global variable for array size
int size = 100; 

//main function
int main () {

//declare variables
char arrayNames[size][size]; 
char inputName[size]; 
char outputName[size]; 
char tempArray[size]; 
int  sortEnd = 0; 
//take in input & output files
cout << "Input File Name: ";
cin >> inputName;
cout << "Output File Name: ";
cin >> outputName;

//open file
ifstream fileIn; 
fileIn.open(inputName); 

if (fileIn.is_open()) 
{ 
 cout << "Unsorted: \n" << '\n';
//sort names into array & print unsorted

	for (int p = 0; p < 10; p++)
		{ 
		fileIn >> arrayNames[p]; 
		cout << arrayNames[p] << "\n"; 
		}
//start sort sequence
	
do {
	sortEnd = 0;
	for (int i = 0; i < 10; i++) 
		{
		if (strCompare(arrayNames[i], arrayNames[i+1]) < 0) 
			{
			//swap array names
			strCopy(tempArray, arrayNames[i]); 
			//move right to left
			strCopy(arrayNames[i], arrayNames[i+1]); 
			//move left to right
			strCopy(arrayNames[i+1], tempArray); 
			sortEnd = 1;
			}
		}	
     } while (sortEnd > 0);
	//list sorted array
	cout <<'\n' << "Sorted: \n" << '\n';

	for (int n = 10; n > 0; n--) 
	{
	cout << arrayNames[n-1] << "\n";
	}
	//close file
	fileIn.close(); 
} 
else
{
	cout << "Could not open input file";
}

//create output File
ofstream fileOut;
//open output file to store array
fileOut.open(outputName);

if (fileOut.is_open()) 
{
	//insert array into file
	for (int k = 10; k > 0; k--) 
		{
		fileOut << arrayNames[k-1] << "\n";
		}
} 
else
{
	cout << "Could not open output file";
}
//end main program
return 0;
}


void strCopy(char str1[], char str2[]) {
int i = 0;  

while (str2[i] != '\0') 
	{
	str1[i] = str2[i];
	i++;
	}
str1[i]='\0';
}

int strCompare(char str1[], char str2[]) {
//declare variable
int i = 0; 
//increment index to jump to next char for both arrays
while (str1[i] == str2[i] && str1[i] != '\0')
	{
	i++; 
	} 
if (str1[i] > str2[i])
	{
	return 1;
	}
else if (str1[i] < str2[i]) 
	{
	return -1;
	}
else
	{
	return 0;
	}
}

