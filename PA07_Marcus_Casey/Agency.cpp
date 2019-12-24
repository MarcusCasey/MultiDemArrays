/**
 * Marcus Casey
 * CS202
 * Section 1103
 */

// import libraries
#include "Project7.h"
#include <iostream>
#include <fstream>

using namespace std;

int displayMenu ();
void printPly (polynomial* ply, int amtPly);

int main ()
{
	ifstream fileInput;
	char *inputName = new char[20];
	cout << "Sample Polynomial File Name: ";
	cin >> inputName;
	fileInput.open(inputName);
	int amtPly;
	fileInput >> amtPly;
	polynomial *ply = new polynomial[amtPly];
	polynomial *tPly = ply;
	for (int i = 0; i < amtPly; i++)
	{
		fileInput >> (*tPly);
		tPly++;
	}
		fileInput.close();
		tPly = ply;
		printPly(ply, amtPly);
		int selection = displayMenu();
	while (selection != 0)
	{
		if (selection == 1)
		{
			tPly = ply;					
			int inputNum;		
			cout << "Number to solve with: ";
			cin >> inputNum;		
			cout << "Solving for x=" << inputNum << ":" << endl;	
			for (int i = 0; i < amtPly; i++)
			{
				int result = (*tPly).solve(inputNum);		
				cout << "\t"<< *tPly << " when x=" << inputNum << "Solved: " << result << endl;
				tPly++;
			}
			tPly = ply;
		} else if (selection == 2)
		{
			polynomial *ply1 = ply;
			polynomial *ply2 = ply;	
			printPly(ply, amtPly);	
			int selectionA, selectionB;	
			do
			{
				cout << "Which polyinomal would you like to compare? (#): ";
				cin >> selectionA;		
				cout << "Which polyinomal would you like to compare to? (#): ";
				cin >> selectionB;		
				if (selectionA > amtPly || selectionB > amtPly)
				{
					cout << "Number was out of range." << endl;	
				}
				
			} while (selectionA > amtPly || selectionB > amtPly);	
			for (int i = 0; i < (selectionA - 1); i++)
			{
				ply1++;
			}
			for (int i = 0; i < (selectionB - 1); i++)
			{
				ply2++;
			}
			cout << "Is " << *ply1 << " = " << *ply2 << " ?" << endl;
			if (*ply1 == *ply2)
			{
				cout << "Answer: True" << endl;
			} else if (*ply1 != *ply2)
			{
				cout << "Answer: False" << endl;
			}	
			ply1 = NULL;
			ply2 = NULL;
		} else if (selection == 3)
		{
			polynomial *ply1 = ply;
			polynomial *ply2 = ply;	
			printPly(ply, amtPly);	
			int selectionA, selectionB;	
			do
			{
				cout << "Whcih polynomial would you like to change (#): ";
				cin >> selectionA;	
				cout << "Enter the polynomial you'd like to set to equal (#): ";
				cin >> selectionB;	
				if (selectionA > amtPly || selectionB > amtPly)
				{
					cout << "Numbers out of range." << endl;	
				}
			} while (selectionA > amtPly || selectionB > amtPly);
			for (int i = 0; i < (selectionA - 1); i++)
			{
				ply1++;
			}	
			for (int i = 0; i < (selectionB - 1); i++)
			{
				ply2++;	
			}	
			cout << "Assigning " << *ply1 << " equal -> " << *ply2 << endl;	
			(*ply1) = (*ply2);	
			cout << "The polynomial was set to equal " << *ply1 << endl;	
			ply1 = NULL;
			ply2 = NULL;
		} else if (selection == 4)
		{
			int inputNum;
			cout << "Which number would you like to multiply by? : ";
			cin >> inputNum;
				
			printPly(ply, amtPly);	
			int selection;	
			do
			{
				cout << "Enter the number of the polynomial you wish to change: ";
				cin >> selection;		
				if (selection > amtPly)
				{
					cout << "Numbers out of range." << endl;		
				}	
			} while (selection > amtPly);
			polynomial *currentPly = ply;	
			for (int i = 0; i < (selection - 1); i++)
			{
				currentPly++;	
			}	
			polynomial finalPly = (*currentPly);
			finalPly = finalPly * inputNum;	
			cout << (*currentPly) << " * " << inputNum << " = " << finalPly << endl;	
			currentPly = NULL;
		} else if (selection == 5)
		{
			polynomial *ply1 = ply;
			polynomial *ply2 = ply;	
			printPly(ply, amtPly);	
			int selectionA, selectionB;	
			do
			{
				cout << "Enter the number of the first polynomial to multiply: ";
				cin >> selectionA;	
				cout << "Enter the number of the second polynomial to multiply: ";
				cin >> selectionB;	
				if (selectionA > amtPly || selectionB > amtPly)
				{
					cout << "One of more numbers out of range." << endl;	
				}	
			} while (selectionA > amtPly || selectionB > amtPly);	
			for (int i = 0; i < (selectionA - 1); i++)
			{
				ply1++;
			}
			for (int i = 0; i < (selectionB - 1); i++)
			{
				ply2++;
			}	
			polynomial finalPly = (*ply1) * (*ply2);	
			cout << "(" << (*ply1) << ") * (" << (*ply2) << ") = " << finalPly << endl;	
			ply1 = NULL;
			ply2 = NULL;
		} else if (selection == 6)
		{
			printPly(ply, amtPly);
		} else if (selection == 7)
		{
			polynomial *ply1 = ply;
			polynomial *ply2 = ply;
			printPly(ply, amtPly);	
			int selectionA, selectionB;	
			do
			{
			cout << "What is the first polynomial you'd like to add? (#): ";
			cin >> selectionA;	
			cout << "What is the second polynomial you'd like to add? (#): ";
			cin >> selectionB;	
				if (selectionA > amtPly || selectionB > amtPly)
				{
					cout << "One number is too large" << endl;	
				}
			} while (selectionA > amtPly || selectionB > amtPly);
				
			for (int i = 0; i < (selectionA - 1); i++)
			{
				ply1++;
			}
			for (int i = 0; i < (selectionB - 1); i++)
			{
				ply2++;
			}
			polynomial addPly = (*ply1) + (*ply2);	
			cout << "(" << (*ply1) << ") + (" << (*ply2) << ") = " << addPly << endl;
			ply1 = NULL;
			ply2 = NULL;
		} else if (selection == 8)
		{
			polynomial *ply1 = ply;
			polynomial *ply2 = ply;
			printPly(ply, amtPly);	
			int selectionA, selectionB;	
			do
			{
				cout << "Which first polynomial would you like subtract (#): ";
				cin >> selectionA;	
				cout << "Which second polynomial would you like subtract (#): ";
				cin >> selectionB;	
				if (selectionA > amtPly || selectionB > amtPly)
				{
					cout << "One selection out of range." << endl;	
				}
			} while (selectionA > amtPly || selectionB > amtPly);
			for (int i = 0; i < (selectionA - 1); i++)
			{
				ply1++;
			}
			for (int i = 0; i < (selectionB - 1); i++)
			{
				ply2++;
			}	
			polynomial finalPly = (*ply1) - (*ply2);	
			cout << "(" << (*ply1) << ") - (" << (*ply2) << ") = " << finalPly << endl;	
			ply1 = NULL;
			ply2 = NULL;
		} else
		{
				cout << "Incorrect input, enter a different number" << endl;
		}
		selection = displayMenu();
	}
	delete[] ply;
	ply = NULL;
	delete[] inputName;
	inputName = NULL;
	return 0;
}

int displayMenu ()
{
	int selection;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "#1 Solve each polynomial with a inputNum" << endl;
	cout << "#2 Check if two polynomials are equal" << endl;
	cout << "#3 Set one polynomial equal to another" << endl;
	cout << "#4 Multiply a polynomial by a scalar inputNum" << endl;
	cout << "#5 Multiply a polynomial by another polynomial" << endl;
	cout << "#6 Print all polynomials to screen" << endl;
	cout << "#7 Find the total of two polynomials" << endl;
	cout << "#8 Find the difference of two polynomials" << endl;
	cout << "#0 Exit" << endl;
	cout << "Input number to select option ";
	cin >> selection;
	return selection;
	cout << "--------------------------------------------------------------------" << endl;
}

void printPly (polynomial* ply, int amtPly)
{
	polynomial *tPly = ply;
	for (int i = 0; i < amtPly; i++)
	{
		cout << (i + 1) << ". " << *tPly << endl;
		tPly++;
	}
	tPly = NULL;
	return;
}
