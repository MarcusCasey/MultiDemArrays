/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
#include <iostream>
using namespace std;
const bool NODE = false;

class List 
{
 public:
   List(int=10);
   List(const List&);
   ~List();
   bool goToBeginning();
   bool goToEnd();
   bool goToNext();
   bool goToPrior();
   bool insertBefore(int);
   bool insertAfter(int);
   bool remove();
   bool isEmpty() const;
   bool isFull() const;
   void clear();
   List& operator=(const List&);
   friend ostream& operator<<(ostream&, const List&);
 private:
   int size;
   int actual;
   int cursor;
   int *data;
};
