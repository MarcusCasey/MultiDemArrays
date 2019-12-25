/**

 * Marcus Casey

 * CS202

 * Section 1103

 */

//import header files
#include "listA.h"

// constructor
ListA::ListA(int size) {
    this->size=size;
    this->actual=0;
    this->cursor=-1;
    this->data=new int[size];
}

// copy constructor
ListA::ListA(const ListA &arrayCopy) {
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
ListA::~ListA() {
    this->size=0;
    this->actual=0;
    this->cursor=-1;
    delete[] this->data;
}

// goToBeginning 
bool ListA::goToBeginning() {
    if (!isEmpty()) {
        cursor=0;
        return true;
    } else {
        return false;
    }
}

// goToEnd
bool ListA::goToEnd() {
    if (!isEmpty()) {
        cursor=actual-1;
        return true;
    } else {
        return false;
    }
}

// goToNext
bool ListA::goToNext() {
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
bool ListA::goToPrior() {
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
bool ListA::insertBefore (int inserList) {
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
bool ListA::insertAfter(int inserList) {
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
bool ListA::remove() {
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
bool ListA::isEmpty() const {
    return (actual==0);
}

// is full
bool ListA::isFull() const {
    return (actual==size);
}

// get
bool ListA::get(int &toReturn) const {
    if (!isEmpty()) {
        toReturn=data[cursor];
        return true;
    } else {
        return false;
    }
}

void clear(){
}

// operator=
ListA& ListA::operator=(const ListA &arrayCopy) {
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
ostream& operator<<(ostream &fileInput, const ListA &printOut) {
    for (int i=0; i<printOut.actual; i++) {
        if (i==(printOut.cursor)) {
            fileInput << "["<<printOut.data[i] << "] ";
        } else {
            fileInput << "|"<<printOut.data[i] << "| ";
        }
    }
    return fileInput;
}
