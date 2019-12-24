/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
#include <iostream>
using namespace std;


class ListA 
{
 public:
   ListA(int);
   ListA(const ListA&);
   ~ListA();
   bool goToBeginning();
   bool goToEnd();
   bool goToNext();
   bool goToPrior();
   bool insertBefore(int);
   bool insertAfter(int);
   bool remove();
   bool isEmpty() const;
   bool isFull() const;
   void clear(); // unused
   bool get(int&) const; //added get fnc
   ListA& operator=(const ListA&);
   friend ostream& operator<<(ostream&, const ListA&);
 private:
   int size;
   int actual;
   int cursor;
   int *data;
};
