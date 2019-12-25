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
List::List(int k) {
    head=cursor=NULL;
}

// copy constructor
List::List(const List &forArray) {
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
List::~List() {
    clear();
}

// goToBeginning
bool List::goToBeginning() {
    if (!isEmpty()) {
        cursor=head;
        return true;
    } else {
        return false;
    }
}

// goToEnd
bool List::goToEnd() {
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
bool List::goToNext() {
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
bool List::goToPrior() {
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
bool List::insertBefore(int data) {
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
bool List::insertAfter(int data) {
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
bool List::remove() {
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
bool List::isEmpty() const {
    return (head==NULL);
}

// isFull
bool List::isFull() const {
    return false;
}

// clear
void List::clear() {
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

// operator ::
List& List::operator=(const List &forArray) {
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
ostream& operator<<(ostream &out, const List &toPrint) {
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
