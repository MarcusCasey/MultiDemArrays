//import libraries
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//global variables
const int AMOUNT_CARS = 10;

//struct for program
struct carData {
  int year; //car year
  float price; //car price
  bool available; //is the car available
  char make[20]; //car make
  char model[20];//car model
};

//function prototypes
void printCars(bool availableOnly, carData cars[]);
void mostExpensive(carData cars[]);
void grabSelection(int &selection);
void inputFile(carData cars[]);
void estimatePrice(carData cars[]);

int main() 
{
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
	carData cars[AMOUNT_CARS]; 
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
void printCars(bool availableOnly, carData cars[]) {
 //check if available 
 if (availableOnly != true) 
	{
 	cout << "Data for all cars:" << endl;
	} else 
	{
	cout << "Data for available cars:" << endl;
	}
	cout<<"--------------------------------------------------------------------"<<endl;
  for (int i = 0; i < AMOUNT_CARS; i++)
  { //go through each car in cars array
    //only print only available if specified
    if (cars[i].available != false || availableOnly != true) 
    {
      //print and format data
	cout << cars[i].year << " " << cars[i].make << " " << cars[i].model << " $" << cars[i].price << " " << boolalpha << " " << cars[i].available << endl;
    }
  }
}

//function to calculate most expensive car
void mostExpensive(carData cars[]) {
//pos of the most expensive car
	int expPos = 0; 
	for (int i = 0; i < AMOUNT_CARS; i++) 
	{ //look for number if bigger assign to current expos 
	if (cars[i].price > cars[expPos].price)
	{ 
	expPos = i; 
	}
	}
	cout << "The Most Expensive Car:" << cars[expPos].year << " " << cars[expPos].make << " "<< cars[expPos].model << endl;
}

//grab user input
void grabSelection(int &userInput) {
	cout << "Input: ";
// get user input and save it var
	cin >> userInput; 
	cout << "-------------------------" << endl;
}

//open and read in file
void inputFile(carData cars[]) {
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
	{
	for (int i = 0; i < AMOUNT_CARS; i++)
	{ //grab all data
	fileIn >> cars[i].year >> cars[i].make >> cars[i].model>> cars[i].price >> cars[i].available;
	}
	cout << "File read... Please input next action" << endl;
	} else { 
	cout << "No file inputed exists ";
	}
}

//estimate price of rental
void estimatePrice(carData cars[]) {
 	//which car pos is selected
	int carPos;
  	//how many days rented
	int daysRenting; 
	cout << "Which car? (1-10): ";
	cin >> carPos; 
	cout << "How many days do you want to rent?: ";
	cin >> daysRenting;
	// determine price
	float amount = daysRenting * cars[carPos-1].price ; 
	cout << "Total amount is: $" << amount << endl;
}
