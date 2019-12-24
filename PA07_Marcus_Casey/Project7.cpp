/**
 * Marcus Casey
 * CS202
 * Section 1103
 */

//import libraries
#include "Project7.h"
#include <iostream>

using namespace std;

//Constructor
polynomial::polynomial ()
{
	topDeg = 3;
	// start input number at 1 instead of 0
	coefficient = new int[topDeg + 1]; 
}

// Param Constructor
polynomial::polynomial (int takeDeg, int *takeCoeffs)
{
	topDeg = takeDeg;
	coefficient = new int[topDeg + 1];
	int *tcoefficient = coefficient;
	int *takeT = takeCoeffs;
	for (int i = 0; i < topDeg + 1; i++)
	{
		*tcoefficient = *takeT;
		tcoefficient++;
		takeT++;
	}
}
// Copy Constructory
polynomial::polynomial (const polynomial& takenPly)
{
	topDeg = takenPly.topDeg;
	coefficient = new int[topDeg + 1];
	int *tcoefficient = coefficient;
	int *takeT = takenPly.coefficient;
	for (int i = 0; i <= topDeg; i++)
	{
		*tcoefficient = *takeT;
		tcoefficient++;
		takeT++;
	}
}
// Destructor
polynomial::~polynomial ()
{
	delete[] coefficient;
	coefficient = NULL;
}

void polynomial::operator=(const polynomial& takenPly)
{
	topDeg = takenPly.topDeg;
	delete[] coefficient;
	coefficient = new int[topDeg + 1];
	int *tcoefficient = coefficient;
	int *takeT = takenPly.coefficient;
	for (int i = 0; i <= topDeg; i++)
	{
		*tcoefficient = *takeT;
		tcoefficient++;
		takeT++;
	}
	return;

}

bool polynomial::operator!=(const polynomial& takenPly)
{
	if (topDeg == takenPly.topDeg)
	{
	int *tcoefficient = coefficient;
	int *takeT = takenPly.coefficient;
	for (int i = 0; i <= topDeg; i++)
	{
		if (*tcoefficient != *takeT)
		{
			tcoefficient = NULL;
			takeT = NULL;
			return true;
		}
			tcoefficient++;
			takeT++;
		}
		tcoefficient = NULL;
		takeT = NULL;
	} else
	{
		return true;
	}
		return false;
}

polynomial polynomial::operator*(const polynomial& takenPly)
{
		int totalLikeTerm = (topDeg + 1) * (takenPly.topDeg + 1); 
		int combinationalTerm = (topDeg + takenPly.topDeg) + 1; 
		int selectedPlyTerm = topDeg + 1;
		int sentPerm = takenPly.topDeg + 1;
		int topTerm = (topDeg + takenPly.topDeg);
		int *selectedCoefficientT = coefficient;
		int *selectedCoeffL = takenPly.coefficient;
		int *selectedCoeffTv = selectedCoeffL;
		int selectedDegree = topDeg;
		const int takenDegree = takenPly.topDeg;
		int takenFromDegree = takenDegree;	
		int rawUnsort[combinationalTerm][combinationalTerm]; 	

//initialize array
	for (int i = 0; i < combinationalTerm; i++)
	{
		for (int j = 0; j < combinationalTerm; j++)
		{
			rawUnsort[i][j] = 0;
		}
	}
	
	for (int i = 0; i < selectedPlyTerm; i++)
	{
		//multiply coefficients
		takenFromDegree = takenDegree;
		selectedCoeffTv = selectedCoeffL;
		for (int j = 0; j < sentPerm; j++)
		{
			int locPower = topTerm - ((selectedDegree) + (takenFromDegree));
			int locProduct = 0;
			for (locProduct = 0; rawUnsort[locPower][locProduct] != 0; locProduct++)
			{
				// look for first space
			}

			int newCoeff = (*selectedCoefficientT) * (*selectedCoeffTv);
			rawUnsort[locPower][locProduct] = newCoeff;
			selectedCoeffTv++;
			takenFromDegree--;
}
		
			selectedDegree--;
			selectedCoefficientT++;
	}

	int *newCoeffs = new int[topTerm + 1];
	int *newCoeffTrav = newCoeffs;
	// add like terms
	for (int i = 0; i < combinationalTerm; i++)
	{
		int total = 0;
		*newCoeffTrav = 0;
		for (int j = 0; j <= topTerm; j++)
		{
			total += (rawUnsort[i][j]);
		}
		*newCoeffTrav = total;
		newCoeffTrav++;
	}
		polynomial tempPly(topTerm, newCoeffs);
		selectedCoefficientT = NULL;
		selectedCoeffL = NULL;
		selectedCoeffTv = NULL;
		delete[] newCoeffs;
		newCoeffs = NULL;
		newCoeffTrav = NULL;
		return tempPly;
}

polynomial operator-(polynomial ply1, polynomial ply2)
{
		int topDegree, subDegree;
		int ply1Degree = ply1.topDeg;
		int ply2Degree = ply2.topDeg;
	if (ply1Degree > ply2Degree || ply1Degree == ply2Degree)
	{
		topDegree = ply1Degree;	
	} else
	{
		topDegree = ply2Degree;
	}
		int *temp1Coeffs = new int[topDegree + 1];
		int *temp2Coeffs = new int[topDegree + 1];
		int *coeff1T = temp1Coeffs;
		int *coeff2T = temp2Coeffs;
		int *sent1Trav = ply1.coefficient;
		int *sent2Trav = ply2.coefficient;
	for (int i = 0; i <= topDegree; i++)
	{
		if (ply1Degree == topDegree)
		{
			*coeff1T = *sent1Trav;
			*coeff2T = 0;	
			if (i >= (topDegree - ply2Degree))
			{
				*coeff2T = *sent2Trav;		
				sent2Trav++;		
			}	
			sent1Trav++;	
		} else if (ply2Degree == topDegree)
		{
			*coeff2T = *sent2Trav;
			*coeff1T = 0;	
			if (i >= (topDegree - ply1Degree))
			{
				*coeff1T = *sent1Trav;		
				sent1Trav++;
			}
			sent2Trav++;
		}	
		coeff1T++;
		coeff2T++;
	}
		coeff1T = temp1Coeffs;
		coeff2T = temp2Coeffs;
		int *totalCoeffArr = new int[topDegree + 1];
		int *totalT = totalCoeffArr;
		for (int i = 0; i <= topDegree; i++)
	{
		*totalT = (*coeff1T) - (*coeff2T);	
		coeff1T++;
		coeff2T++;
		totalT++;
	}
		delete[] temp1Coeffs;
		temp1Coeffs = NULL;
		delete[] temp2Coeffs;
		temp2Coeffs = NULL;
		coeff1T = NULL;
		coeff2T = NULL;
		sent1Trav = NULL;
		sent2Trav = NULL;
		polynomial addPly(topDegree, totalCoeffArr);
		delete[] totalCoeffArr;
		totalCoeffArr = NULL;
		totalT = NULL;
		return addPly;
}

bool polynomial::operator==(const polynomial& takenPly)
{
	if (topDeg == takenPly.topDeg)
	{
		int *tcoefficient = coefficient;
		int *takeT = takenPly.coefficient;
		for (int i = 0; i <= topDeg; i++)
		{
			if (*tcoefficient != *takeT)
			{
				tcoefficient = NULL;
				takeT = NULL;
				return false;
			}
			tcoefficient++;
			takeT++;
		}
	} else
	{
		return false;
	}
		return true;
}
polynomial polynomial::operator*(const int scalar)
{
	int *tcoefficient = coefficient;
	for (int i = 0; i <= topDeg; i++)
	{
		(*tcoefficient) *= scalar;
		tcoefficient++;
	}
		tcoefficient = NULL;
		polynomial tempPly(topDeg, coefficient);
		return tempPly;
}

ostream& operator<<(ostream& os, const polynomial& takenPly)
{
	int maxDegree = takenPly.topDeg;
	int *tcoefficient = takenPly.coefficient;
	for (int i = maxDegree; i >= 0; i--)
	{
		if (i == maxDegree)
		{
			if (*tcoefficient != 0 && *tcoefficient != 1)
			{
				// term 1
				os << *tcoefficient << "x^" << i; 
			} else if (*tcoefficient != 0 && *tcoefficient == 1)
			{
				// term 2
				os << "x^" << i; 
			} else if (*tcoefficient == 0)
			{
				os << "0";
			}
			
		} else if (i != maxDegree && i != 0 && *tcoefficient != 0)
		{ // formatting for printing
			if (i != 1)
			{
				if (*tcoefficient > 0)
				{
					os << " + " << *tcoefficient << "x^" << i;
				} else if (*tcoefficient < 0)
				{
					os << " - " << ((*tcoefficient) * -1) << "x^" << i;
				}
			} else if (i == 1)
			{
				if (*tcoefficient > 0)
				{
					os << " + " << *tcoefficient << "x";
				} else if (*tcoefficient < 0)
				{
					os << " - " << ((*tcoefficient) * -1) << "x";
				}
			}
		} else if (i == 0 && *tcoefficient != 0)
		{
			if (*tcoefficient > 0)
				{
					os << " + " << *tcoefficient;
				} else if (*tcoefficient < 0)
				{
					os << " - " << ((*tcoefficient) * -1);
				}
		}
		tcoefficient++;
	}
		tcoefficient = NULL;
		return os;
}

// solve polynomial
int polynomial::solve (int numPlug)
{

	int total = 0;
	int selectDegree = topDeg;
	int *selectCoeff = coefficient;
	for (int i = 0; i < topDeg; i++) 
	{
		int grabNum = numPlug;
		int numBase = numPlug;
		// take number to power of polynomial
		for (int j = 1; j < selectDegree; j++)
		{
			grabNum *= numBase;
		}
		grabNum *= *selectCoeff;
		total += grabNum;
		selectCoeff++;
		selectDegree--;
		// multiply num that's been powered by coefficient
	}
		total += (*selectCoeff); // add input number to final equation 
		selectCoeff = NULL;
		return total;
}
istream& operator>>(istream& is, polynomial& takenPly)
{
		is >> takenPly.topDeg;
		delete[] takenPly.coefficient;
		takenPly.coefficient = new int[takenPly.topDeg + 1];
		int *tcoefficient = takenPly.coefficient;
		for (int i = 0; i <= takenPly.topDeg; i++)
	{
		is >> *tcoefficient;
		tcoefficient++;
	}
		tcoefficient = NULL;
		return is;
}

polynomial operator+(polynomial ply1, polynomial ply2)
{
		int topDegree;
		int subDegree;
		int ply1Degree = ply1.topDeg;
		int ply2Degree = ply2.topDeg;
	if (ply1Degree > ply2Degree || ply1Degree == ply2Degree)
	{
		topDegree = ply1Degree;
	} else
	{
		topDegree = ply2Degree;
	}
		int *temp1Coeffs = new int[topDegree + 1];
		int *temp2Coeffs = new int[topDegree + 1];
		int *coeff1T = temp1Coeffs;
		int *coeff2T = temp2Coeffs;
		int *sent1Trav = ply1.coefficient;
		int *sent2Trav = ply2.coefficient;
	for (int i = 0; i <= topDegree; i++)
	{
		if (ply1Degree == topDegree)
		{
			*coeff1T = *sent1Trav;
			*coeff2T = 0;
			
			if (i >= (topDegree - ply2Degree))
			{
				*coeff2T = *sent2Trav;		
				sent2Trav++;		
			}		
			sent1Trav++;			
		} else if (ply2Degree == topDegree)
		{
			*coeff2T = *sent2Trav;
			*coeff1T = 0;	
			if (i >= (topDegree - ply1Degree))
			{
				*coeff1T = *sent1Trav;			
				sent1Trav++;				
			}			
			sent2Trav++;
		}		
		coeff1T++;
		coeff2T++;	
	}	
		coeff1T = temp1Coeffs;
		coeff2T = temp2Coeffs;
		int *totalCoeffArr = new int[topDegree + 1];
		int *totalT = totalCoeffArr;	
	for (int i = 0; i <= topDegree; i++)
	{
		*totalT = (*coeff1T) + (*coeff2T);		
		coeff1T++;
		coeff2T++;
		totalT++;	
	}
		delete[] temp1Coeffs;
		temp1Coeffs = NULL;	
		delete[] temp2Coeffs;
		temp2Coeffs = NULL;
		coeff1T = NULL;
		coeff2T = NULL;
		sent1Trav = NULL;
		sent2Trav = NULL;
		polynomial addPly(topDegree, totalCoeffArr);
		delete[] totalCoeffArr;
		totalCoeffArr = NULL;
		totalT = NULL;
		return addPly;
}
