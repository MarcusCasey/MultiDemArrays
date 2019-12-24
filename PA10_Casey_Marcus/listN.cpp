/**

 * Marcus Casey

 * CS202

 * Section 1103

 */

//import header files
#include "listN.h"

// node
Node::Node(int data, Node* next) {
    this->data=data;
    this->next=next;
}

// constructor
ListN::ListN() {
    head=cursor=NULL;
}

// copy constructor
ListN::ListN(const ListN &forArray) {
    if (forArray.isEmpty()) {
        head=cursor=NULL;
    } else {
        head=cursor=new Node(forArray.head->data, NULL);
        Node* tempL=forArray.head;
        Node* tempZ=head;
        while(tempL!=NULL) {
            if (tempL->next!=NULL) {
                Node *nodeZ=new Node(tempL->next->data, NULL);
                tempZ->next=nodeZ;
                tempZ=nodeZ;
            }
            if (tempL==forArray.cursor) {
                cursor=tempZ;
            }
            tempL=tempL->next;
        }
    }
}

// destructor
ListN::~ListN() {
    clear();
}

// goToBeginning
bool ListN::goToBeginning() {
    if (!isEmpty()) {
        cursor=head;
        return true;
    } else {
        return false;
    }
}

// goToEnd
bool ListN::goToEnd() {
    if (!isEmpty()) {
        while(cursor->next!=NULL) {
            cursor=cursor->next;
        }
        return true;
    } else {
        return false;
    }
}

// goToNext
bool ListN::goToNext() {
    if (!isEmpty()) {
        if (cursor->next!=NULL) {
            cursor=cursor->next;
            return true;
        } else {
            return false; 
        }
    } else {
        return false;
    }
}

// goToPrior
bool ListN::goToPrior() {
    if (!isEmpty()) {
        if (cursor!=head) {
            Node *move=head;
            while(move->next!=cursor) {
                move=move->next;
            }
            cursor=move;
            move=NULL;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// insertBefore
bool ListN::insertBefore(int data) {
    if (!isFull()) {
        if (isEmpty()) {
            head=cursor=new Node(data, NULL);
        } else {
            if (cursor==head) {
                cursor=head=new Node(data, head);
            } else {
                Node *ptrZ=new Node(cursor->data, cursor->next);
                cursor->next=ptrZ;
                cursor->data=data;
                ptrZ=NULL;
            }
        }
        return true;
    } else {
        return false;
    }
}

// insertAfter
bool ListN::insertAfter(int data) {
    if (!isFull()) {
        if (isEmpty()) {
            head=cursor=new Node(data, NULL);
        } else {
            Node *ptrZ=new Node(data, NULL); 
            if (cursor->next==NULL) { 
                cursor->next=ptrZ;
                cursor=ptrZ;
                ptrZ=NULL;
            } else { 
                ptrZ->next=cursor->next;
                cursor->next=ptrZ;
                cursor=ptrZ;
                ptrZ=NULL;
            }
        }
        return true;
    } else {
        return false;
    }
}

// remove
bool ListN::remove() {
    if (!isEmpty()) {
        if (cursor==head) {
            cursor=head=head->next;
        } else {
            Node *ptrZ=cursor; 
            goToPrior();
            cursor->next=ptrZ->next;
            ptrZ=NULL;
        }
        return true;
    } else {
        return false;
    }
}

// isEmpty
bool ListN::isEmpty() const {
    return (head==NULL);
}

// isFull
bool ListN::isFull() const {
    return false;
}

// clear
void ListN::clear() {
    if (!isEmpty()) {
        Node *toRemove=head;
        while (head!=NULL) {
            toRemove=toRemove->next;
            delete head;
            head=toRemove;
        }

        head=cursor=NULL;
    }
}

// readFile
bool ListN::readFile(string fileName) {
    fstream fileInput;
    fileInput.open(fileName.c_str());
    if (fileInput.good()) {
        clear();
        int number;
        while (true) {
            fileInput>>number;
            if(fileInput.eof()) 
		{ break; }
            insertAfter(number);  
	    }
        return true;
    } else {
        return false;
    }
}

// get
bool ListN::get(int &current) const {
    if (!isEmpty()) {
        current=cursor->data;
        return true;
    } else {
        return false;
    }
}

// amt
int ListN::count() {
    int amt=0;
    while (cursor!=NULL) {
        amt++;
        cursor=cursor->next;
    }
    cursor=head;
    return amt;
}

// operator ::
ListN& ListN::operator=(const ListN &forArray) {
    this->clear();
    if (forArray.isEmpty()) {
        this->head=this->cursor=NULL;
    } else {
        this->head=this->cursor=new Node(forArray.head->data, NULL);
        Node *tempL=forArray.head;
        Node *tempZ=this->head; 
        while(tempL!=NULL) {
            if (tempL->next!=NULL) {
                Node *nodeZ=new Node(tempL->next->data, NULL); 
                tempZ->next=nodeZ;
                tempZ=nodeZ;
            }
            if (tempL==forArray.cursor) {
                this->cursor=tempZ;
            }
           	 tempL=tempL->next;
        }
    }
return *this;
}

// operator <<
ostream& operator<<(ostream &out, const ListN &toPrint) {
    Node *move=toPrint.head;
    while(move) {
        if (move==toPrint.cursor) {
            out<<"[" << move->data<<"] ";
        } else {
            out <<"|"<< move->data<<"| ";
        }
        move=move->next;
    }
    move=NULL;
    return out;
}
