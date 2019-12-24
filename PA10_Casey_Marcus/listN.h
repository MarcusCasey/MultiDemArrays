/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ListN;

class Node 
{
 private:
    Node(int, Node*);
    int data;
    Node* next;
    friend class ListN;
    friend ostream& operator<<(ostream&, const ListN&);
};

class ListN 
{
 public:
   ListN();
   ListN(const ListN&);
   ~ListN();
   bool goToBeginning();
   bool goToEnd();
   bool goToNext();
   bool goToPrior();
   bool insertBefore(int);
   bool insertAfter(int);
   bool remove();
   bool isEmpty() const;
   bool isFull() const; // Return False by default
   void clear();
   bool readFile(string); // added read file for data
   bool get(int&) const; // added get fnc
   int  count(); // added count, for binary search
   ListN& operator=(const ListN&);
   friend ostream& operator<<(ostream&, const ListN&);
 private:
   Node* head;
   Node* cursor;
};
