/**
 * Marcus Casey
 * CS202
 * Section 1103
 */

#include <iostream>
#include <fstream>
#include "Agency.h"

using namespace std;

const int ZIP_SIZE = 5;
const int CAR_NUM = 15;

// string functionality, moving this into main most likely
void strincpy(char *point, char *input);
void zipcpy(int *point, int *input);
 
 // creates car from nothing
Car::Car() {
  
    make = new char[20];
    *make = '\0';
    model = new char[20];
    *model = '\0';
    year = 0;
    price = 0.0;
    available = false;
}


Car::Car(const Car &car) {
    // create car from copy constructor
    make = new char[20];
    strincpy(make, car.make);
    model = new char[20];
    strincpy(model, car.model);
    year = car.year;
    price = car.price;
    available = car.available;
}

  // car destructor
Car::~Car() {
  
    delete [] make;
    make = NULL;
    delete [] model;
    model = NULL;
    year = 0;
    price = 0.0;
    available = false;
}

    // agency with parameters 
Car::Car(char *tempSetMake, char *tempModel, int tempYear, float tempPrice, bool tempAvailable) {
    make = new char[20];
    strincpy(make, tempSetMake);
    model = new char[20];
    strincpy(model, tempModel);
    year = tempYear;
    price = tempPrice;
    available = tempAvailable;
}


// set make initially
void Car::setMake(char *tempSetMake) {
    char *tempMakeMain = tempSetMake;
    char *makeMain = make;
    while (*tempSetMake != '\0') {
        *make = *tempSetMake;
         make++;
         tempSetMake++;
    }    make = makeMain;
    tempSetMake = tempMakeMain;
}
   
   // take in car, copy data into object after being initialized
void Car::copy(Car car) {
    strincpy(make, car.make);
    strincpy(model, car.model);
    year = car.year;
    price = car.price;
    available = car.available;
}


void Car::print() const {
	
    cout << year << " " << make << " " << model << " $" << price << " " << boolalpha << available << endl;
}

//set model temp to initialize
void Car::setModel(char *tempModel) {
    char *tempModelHome = tempModel;
    char *modelHome = model;
    while (*tempModel != '\0') {
        *model = *tempModel;
        model++;
        tempModel++;
    }   tempModel = tempModelHome;
    model = modelHome;
}

// set temp year 
void Car::setYear(int tempYear) {
    year = tempYear;
}

//set temp price
void Car::setPrice(float tempPrice) {
    price = tempPrice;
}


// helper fncs
int Car::getYear() const {
    return year;
}


float Car::getPrice() const {
    return price;
}


bool Car::getAvailable() const {
    return available;
}


void Car::setAvailable(bool tempAvailable) {
    available = tempAvailable;
}


char * Car::getMake() const {
    return make;
}


char * Car::getModel() const {
    return model;
}

  // create agency from nothing
Agency::Agency() {
  
    name = new char[20];
    zipcode = new int[5];
    inventory = new Car[CAR_NUM];
    char *fileName = new char[20];
    cout << "Enter file name: ";
    cin >> fileName;
    readInData(fileName);
    delete [] fileName;
    fileName = NULL;
}

  // Agency Deconstructor
Agency::~Agency() {
    delete [] inventory;
    inventory = NULL;
    delete [] name;
    name = NULL;
    delete [] zipcode;
    zipcode = NULL;
}

    // agency from copy construct
Agency::Agency(const Agency &agency) {
    name = new char[20];
    strincpy(name, agency.name);
    zipcode = new int[5];
    zipcpy(zipcode, agency.zipcode);
    inventory = new Car[CAR_NUM];
}

//pring out car info
void Agency::print() const {
    Car *carInfo = inventory;
    Car *carInfoMain = inventory;
    for (int i = 0; i < CAR_NUM; i++) {
        (*carInfo).print();
        carInfo++;
    }   carInfo = carInfoMain;
} 


// read in agency info
void Agency::readInData(char *fileName) {
    ifstream fileIn;
    fileIn.open(fileName);
    if (fileIn.is_open()) {
         fileIn >> name;
        int *zipFile = zipcode;
        int *zptrMain = zipcode;
        for (int j = 0; j < ZIP_SIZE; j++) { 
            char zipChar;
            fileIn >> zipChar; 
            int iZipNum = (int)zipChar - 48;
            *zipFile = iZipNum; 
            zipFile++;
        }   zipFile = zptrMain;
        Car *carInfo = inventory;
        Car *carInfoMain = inventory;
     	 // read in all other sep cars
        for (int i = 0; i < CAR_NUM; i++) {
            char *tempSetMake = new char[20];
            char *tempModel = new char[20];
            int tempYear = 0;
            float tempPrice;
            bool tempAvailable = false;
            fileIn >> tempYear >> tempSetMake >> tempModel >> tempPrice >> tempAvailable;
            (*carInfo).setYear(tempYear);
            (*carInfo).setMake(tempSetMake);
            (*carInfo).setModel(tempModel);
            (*carInfo).setPrice(tempPrice);
            (*carInfo).setAvailable(tempAvailable);
            delete [] tempSetMake;
            tempSetMake = NULL;
            delete [] tempModel;
            tempModel = NULL;
            carInfo++;
        }        carInfo = carInfoMain;
        cout << "Data from " << fileName << " read successfully" << endl; } else { cout << "Error reading from " << fileName << "." << endl; }
     fileIn.close();
}


// print out avail cars
void Agency::printAvailableCars() const {
    Car *carInfo = inventory;
    Car *carInfoMain = inventory;
     for (int i = 0; i < CAR_NUM; i++) {
        if ((*carInfo).getAvailable() == true) {
            (*carInfo).print();
        }  carInfo++;
    } carInfo = carInfoMain;
}

// find most expensive car
void Agency::findMostExpensive() const {
    Car *carInfo = inventory;
    Car *carInfoMain = inventory;
    Car *highestCost = inventory;
    for (int i = 0; i < CAR_NUM; i++) {
        if ((*carInfo).getPrice() > (*highestCost).getPrice()) {
            highestCost = carInfo;
        } carInfo++;
    } carInfo = carInfoMain;
    (*highestCost).print();
}

// agency estimate cost
float Agency::estimateCost(int carNum, int numDays) const {
    Car *carInfo = inventory;
    Car *carInfoMain = inventory;
    for (int i = 0; i < carNum-1; i++) {
        carInfo++;
    } float estimatedPrice = (*carInfo).getPrice() * numDays;
    carInfo = carInfoMain;
    return estimatedPrice;
}


//copy string
void strincpy(char *point, char *input) {
   while(*input) {
      *point = *input;
      input++;
      point++;
   }   *point = '\0';
}


//copy zip
void zipcpy(int *point, int *input) {
   for (int i = 0; i < ZIP_SIZE; i++) {
       *point = *input;
       input++;
       point++;
   }
}
