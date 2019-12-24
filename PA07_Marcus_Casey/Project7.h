/**
 * Marcus Casey
 * CS202
 * Section 1103
 */
#include <iostream>
using namespace std;
class polynomial
{
public:
	polynomial();
	polynomial(int sentDeg, int *sentCoeffs);	
	polynomial(const polynomial& takenPly);
	~polynomial();

	polynomial operator*(const polynomial& takenPly);
	polynomial operator*(const int scalar);
	void operator=(const polynomial& takenPly);
	bool operator==(const polynomial& takenPly);
	bool operator!=(const polynomial& takenPly);
	friend polynomial operator+(polynomial poly1, polynomial poly2);
	friend polynomial operator-(polynomial poly1, polynomial poly2);
	friend ostream& operator<<(ostream& os, const polynomial& takenPly);
	friend istream& operator>>(istream& is, polynomial& takenPly);
	int solve (int numPlug);
private:
	int *coefficient;
	int topDeg;
};
