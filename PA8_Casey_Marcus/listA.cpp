/**

 * Marcus Casey

 * CS202

 * Section 1103

 */

//import header files
#include "listA.h"

// constructor
List::List(int size) {
    this->size=size;
    this->actual=0;
    this->cursor=-1;
    this->data=new int[size];
}

// copy constructor
List::List(const List &arrayCopy) {
    if (this!=&arrayCopy) {
        this->data=new int[arrayCopy.size];
        this->size=arrayCopy.size;
        this->cursor=arrayCopy.cursor;
        this->actual=arrayCopy.actual;
        for (int i=0; i<arrayCopy.actual; i++) {
            this->data[i] = arrayCopy.data[i];
        }
    } else {
        cout << "error: can't copy own List" << endl;
    }
}

// destructor
List::~List() {
    this->size=0;
    this->actual=0;
    this->cursor=-1;
    delete[] this->data;
}

// goToBeginning 
bool List::goToBeginning() {
    if (!isEmpty()) {
        cursor=0;
        return true;
    } else {
        return false;
    }
}

// goToEnd
bool List::goToEnd() {
    if (!isEmpty()) {
        cursor=actual-1;
        return true;
    } else {
        return false;
    }
}

// goToNext
bool List::goToNext() {
    if (!isEmpty()) {
        if (cursor<actual-1) {
            cursor++;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
// goToPrior
bool List::goToPrior() {
    if (!isEmpty()) {
        if (cursor>0) {
            cursor--;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// insertBefore
bool List::insertBefore (int inserList) {
    if (!isFull()) {
        if (isEmpty()) {
            cursor++;
            data[cursor]=inserList;
            actual++;
        } else {
            for (int i=actual; i>cursor; i--) {
                data[i]=data[i-1];
            }
            data[cursor]=inserList;
            actual++;
        }
        return true;
    } else {
        return false;
    }
}

// insert After
bool List::insertAfter(int inserList) {
    if (!isFull()) {
        for (int i=actual; i>cursor; i--) {
            data[i]=data[i-1];
        }
        cursor++;
        data[cursor]=inserList;
        actual++;
        return true;
    } else {
        return false;
    }
}

// remove
bool List::remove() {
    if (!isEmpty()) {
        for (int i=cursor; i<actual; i++) {
            data[i]=data[i+1];
        }
        actual--;
        if (cursor==actual) {
            cursor--;
        }
        return true;
    } else {
        return false;
    }
}

// is empty
bool List::isEmpty() const {
    return (actual==0);
}

// is full
bool List::isFull() const {
    return (actual==size);
}

void List::clear(){
cursor = 0;
actual = 0;
size = 0;

delete data;
data = NULL;
}

// operator=
List& List::operator=(const List &arrayCopy) {
        delete [] this->data;
        this->data=new int[arrayCopy.size];
        this->size=arrayCopy.size;
        this->cursor=arrayCopy.cursor;
        this->actual=arrayCopy.actual;
        for (int i=0; i<arrayCopy.actual; i++) {
            this->data[i] = arrayCopy.data[i];
        }

    return *this;
}

// operator <<
ostream& operator<<(ostream &fileInput, const List &printOut) {
    for (int i=0; i<printOut.actual; i++) {
        if (i==(printOut.cursor)) {
            fileInput << "["<<printOut.data[i] << "] ";
        } else {
            fileInput << "|"<<printOut.data[i] << "| ";
        }
    }
    return fileInput;
}
