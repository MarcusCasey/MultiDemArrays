/**
 * Marcus Casey
 * CS202
 * Section 1103
 */

//import libraries
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//global variables
const int ZIP_L = 5;
const int CAR_NUM = 5;
const int AGENCY_NUM = 3;
//struct for program
struct carData {
  int year; //car year
  float price; //car price
  bool available; //is the car available
  char make[20]; //car make
  char model[20];//car model
};

struct agency{
  char name[20];
  carData inventory[5];
  int zipcode[ZIP_L];
};
//function prototypes
void printCars(bool isAvailable, agency *cars);
void mostExpensive(agency *cars);
void grabSelection(int &userInput);
void inputFile(agency *cars);
void estimatePrice(agency *cars);
int  strCompare(char *str1, char *str2);

int main() 
{ 

  //arr to store agency
  agency agenArr[AGENCY_NUM];
  // pointer to first agency
  agency *cars  = agenArr;
  //start menu
  int userInput = 0; 
	do 
        { //do code while userinput isn't 7
    //start menu title
	cout << "-------------------------"<< endl
	<< "Car Rental" << endl << "-------------------------"
	<< "-------------------------" << endl; 
	//text outputs for menu
	cout << "(1) Input Car File Data" << endl;
	cout << "(2) Print out all car data" << endl;
	cout << "(3) Print out all avail cars" << endl;
	cout << "(4) Most expensive car" << endl;
	cout << "(5) Estimate car rental $" << endl;
	cout << "(7) Exit program" << endl;
	cout << "-------------------------" << endl; 
    	//take in user input to execute menu
	grabSelection(userInput);
	//array of cars	
	cars = agenArr;
	switch (userInput) {
	case 1:
	//read in file and provide array of car
	inputFile(cars); 
	break;
	case 2:
	//read data and bool as false and assigning reference array
	printCars(false, cars); 
	break;
	case 3:
	//read data and bool as true and assigning reference array
	printCars(true, cars); 
	break;
	case 4:
	//grab the most expensive car
	mostExpensive(cars);
	break;
	case 5:
	//estimate car price
	estimatePrice(cars); 
	break;
	//exit program if userInput is 6
	case 7:
	cout << "Exiting..." << endl; 
	break;
	//if bad input
	default:
	cout << "Not a correct input" << endl; 
	}
//continue do while until user exits
	} while (userInput != 7); 
//return 0 to end main correctly	
return 0;
}

//function to print cars if avialable or not
void printCars(bool isAvailable, agency *cars) {
 //check if available 
 for (int i = 0; i < AGENCY_NUM; i++) {
        int *cdata = (*cars).zipcode; //create pointer to first integer in zip array
// populate array
        cout << "Location: " << (*cars).name << " ";
// print zipcode
        for (int k = 0; k < ZIP_L; k++) { 
            cout << *cdata;
            cdata++;
        } cout << endl;
          cout << "YEAR" << "           " << "MAKE" << "              " << "MODEL" << "                      " << "PRICE" << "            AVAILABLE" << endl;
// create pointer to first rentalCar in inventory
        carData *ldata = (*cars).inventory; 
        for (int d = 0; d < CAR_NUM; d++) {
            //only print avail cars
            if ((*ldata).available != false || isAvailable != true) {
            cout << "           " << (*ldata).year << "           "  << (*ldata).make << "           "<< (*ldata).model << "           $"
                     << (*ldata).price << "           " << boolalpha << (*ldata).available      << endl;
            } ldata++;
        } cout << endl;
          cars++;
    }
  }
//function to calculate most expensive car
void mostExpensive(agency *cars) {
//pos of the most expensive car
    float mostExpensive = 0.0;
    carData *toparr; // this will point to the most expensive car
    for (int i = 0; i < AGENCY_NUM; i++) {
        carData *dloc = (*cars).inventory;
        for (int k = 0; k < CAR_NUM; k++) {
            if ((*toparr).price > mostExpensive) { // if this is the most expensive car
                mostExpensive = (*dloc).price;
                toparr = dloc;
            } dloc++;
        } cars++;
    } cout << "The " << (*toparr).make << " " << (*toparr).model << "is the most expensive car @ " << (*toparr).price << endl;
}
//grab user input
void grabSelection(int &userInput) {
	cout << "Input: ";
// get user input and save it var
	cin >> userInput; 
	cout << "-------------------------" << endl;
}
//open and read in file
void inputFile(agency *cars) {
 // input file variable
	ifstream fileIn;
	//input file name
	char inputFileName[100]; 
	cout << "Input file name?: ";
	cin >> inputFileName; 
	//open file
	fileIn.open(inputFileName); 
	if (fileIn.is_open()) 
	//look to see if file is opened
	  for (int i = 0; i < AGENCY_NUM; i++) {
        //pointer to agency
	  int *dLoc = (*cars).zipcode; 
        //populate array
        fileIn >> (*cars).name;
	//populate zip array
        for (int h = 0; h < ZIP_L; h++) { 
            char zipData;
            fileIn >> zipData;
            int numZip = (int)zipData - 48;
            *dLoc = numZip; 
            dLoc++;
        }
//available / not?
        carData *zLoc = (*cars).inventory; 
        for (int k = 0; k < CAR_NUM; k++) {
            fileIn >> (*zLoc).year >> (*zLoc).make >> (*zLoc).model >> (*zLoc).price >> (*zLoc).available;
           zLoc++;
        }
        cars++;
      }
}
//estimate price of rental
void estimatePrice(agency *cars) {
 	//which car pos is selected
	int carPos;
	char agenName[20];
  	//how many days rented
	int daysRenting; 
	cout << "Agency Name: ";
	cin  >> agenName;
	cout << "Which car? (1-5): ";
	cin >> carPos; 
	cout << "How many days do you want to rent?: ";
	cin >> daysRenting;
	// find out agency
for (int i = 0; i < AGENCY_NUM; i++) { 
	if (strCompare((*cars).name, agenName)) {
	    i = AGENCY_NUM; 
            //end for and start assigning
            carData *dloc = (*cars).inventory;
		//cars are 1-5 not 0-4
            dloc += (carPos-1); 
            float price = (*dloc).price*daysRenting;
            cout << "Price to Rent Car is: $" << price << endl;
        } else {
            cars++;
        }
   }
}
//string compare from class
int strCompare(char *str1, char *str2){
    while ((*str1 != '\0') && (*str2 != '\0')) { 
        if (*str1 != *str2) { 
            return 0;
        } else {
            str1++;
            str2++;
        }
    }
    return 1; 
}
