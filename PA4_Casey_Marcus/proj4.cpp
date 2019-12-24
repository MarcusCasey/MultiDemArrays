/**
 * Marcus Casey
 * CS202
 * Section 1103
 */
// load libraries
#include <iostream>
#include <fstream>
using namespace std;

//given struct
struct Pieces {
    char *word;
    int jump;
};

// function prototypes
void decrypt(char *inputDecrypt, Pieces *pieceL, int *pieceK, int amtPiece, int amtKey);
void strConcat(char *str1, char *str2);
void strCopy(char *str1, char *str2);
void inputFile(ifstream *fileIn, Pieces *pieceL, int *pieceK, int amtPiece, int amtKey);
int  stringLength(char *str);

int main() {
// array to hold file name, take in file name
char *fileName = new char[20];
cout << "File Name: ";
cin >> fileName;
ifstream fileIn;
// open file, delete filename
fileIn.open(fileName); 
delete []fileName;
fileName = NULL;

int amtPiece;
int amtKey;
// if file is opened 
    if(fileIn.good()) {
        cout << "Success!! File Loaded." << endl;
       //get Piece & Key
      fileIn >> amtPiece >> amtKey;
    } else {
      cout << "Incorrect File Name or File Doesn't Exist" << endl;
    }
    // allocate & create arrays
    Pieces *pieceL = new Pieces[amtPiece];
    Pieces *pIndex = pieceL;
    int *pieceK = new int[amtKey];
    // temporary value until correct found
    char *inputDecrypt = new char[100];
    // load in file data
    inputFile(&fileIn, pieceL, pieceK, amtPiece, amtKey);
    // decrypt data
    decrypt(inputDecrypt, pieceL, pieceK, amtPiece, amtKey);
    // delete memory for each word & piece
    for (int l = 0; l < amtPiece; l++) {
        delete [](*pieceL).word;
        (*pieceL).word = NULL;
        pieceL++;
       }
    // dellete allocated memory for pieces
    pieceL = pIndex;
    delete []pieceL;
    pieceL = NULL;
    //delete allocated memory for Keys
    delete []pieceK;
    pieceK = NULL;
   // set inputDecrypt to correct length
    char *finishedDecrypt = new char[stringLength(inputDecrypt)+1]; 
    strCopy(finishedDecrypt, inputDecrypt);
    delete []inputDecrypt;
    inputDecrypt = NULL;
// output final decrypted result
    cout << "Decrypted File String: " << finishedDecrypt << endl;
    //dellete allocated memory 
    delete []finishedDecrypt;
    finishedDecrypt = NULL;
    return 0;
}
// fnc to decrypt input file
void decrypt(char *inputDecrypt, Pieces *pieceL, int *pieceK, int amtPiece, int amtKey) {
    Pieces *pIndex = pieceL;
    int *kIndex = pieceK;
//current pos
    int lIndex; 
// for loop to track keys
    for (int i = 0; i < amtKey; i++) { 
	// point to current key count
        pieceL += *pieceK;
	//keey track of index with key
        lIndex = *pieceK; 
	// if jump is zero stop, otherwise check if it wraps, jump needed length
        while((*pieceL).jump != 0) { 
            if ((lIndex + (*pieceL).jump) < amtPiece) { 
                pieceL += (*pieceL).jump; 
                lIndex += (*pieceL).jump; 
		//if not jump           
		 } else { 
                //new index for jump
                int difference = amtPiece - lIndex;
                int newHome = difference - (*pieceL).jump;
                pieceL = pIndex + newHome;
                lIndex = newHome;
                }
        }
       //concat final pieces
	strConcat(inputDecrypt, (*pieceL).word);
        pieceK++;
        pieceL = pIndex; 
      }
}

// fnc to combine two strings, taken from class & tutorials
void strConcat(char *str1, char *str2) {
    while(*str1 != '\0') {
        str1++;
    }
    while(*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = ' ';
}
// str copy from class & tutorials
void strCopy(char *str1, char *str2) {
    while (*str2 != '\0') {
         *str1 = *str2;

         str1++;
         str2++;
    }
    *str1 = '\0';
}

// load file
void inputFile(ifstream *fileIn, Pieces *pieceL, int *pieceK, int amtPiece, int amtKey) {
    Pieces *pIndex = pieceL; 
    int *kIndex = pieceK; 
  // for loop to use pointer for first char in array, get word and jump, create exact length for string   
 for (int i = 0; i < amtPiece; i++) {
        char *tempVar = new char[20]; 
        *fileIn >> tempVar >> (*pieceL).jump; 
        (*pieceL).word = new char[stringLength(tempVar)+1]; 
        strCopy((*pieceL).word, tempVar);
        delete []tempVar;
        tempVar = NULL;
        pieceL++;
    }
// grab key
    for (int j = 0; j < amtKey; j++) {
        *fileIn >> *pieceK; 
        pieceK++;
    }
    pieceL = pIndex; 
    pieceK = kIndex; 
    (*fileIn).close();
}
// str length from tutorials
int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        str++;
        length++;
    }
    return length;
}
