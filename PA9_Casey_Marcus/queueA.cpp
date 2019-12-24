/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
// import header files
#include "queueA.h"

// construct
queueA::queueA(int total) {
max=total;
front=-1;
rear=-1;
data=new int[max];
}

// copy construct 
queueA::queueA(const queueA& pointQ) {
	max=pointQ.max;
	data=new int[max];
	front=pointQ.front;
	rear=pointQ.rear;
	for(int i=0; i<=rear; i++) {
	data[i]=pointQ.data[i];
	}
}

// destruct
queueA::~queueA() {
	max=0;
	front=-1;
	rear=-1;
	delete data;
	data=NULL; 
}

queueA& queueA::operator=(const queueA& pointQ) {
	if(pointQ.max!=max) {
		max=pointQ.max;
		delete[] data;
		data=NULL;
		int *data=new int[max];
	}
    front=pointQ.front;	
	rear=pointQ.rear;
	for(int i=0; i <= pointQ.rear; i++) {
	data[i]=pointQ.data[i];
	}
	return *this;
}

// all functions specified in header

bool queueA::enqueue(int count) {
	if(empty()) {
		front=rear=0;
		data[front]= count;
		return true;   
	}    
	if(!full()) {
		rear++;
		data[rear] = count; 
		return true; 
	} else {	
		cout << "Is full." << endl;
		return false; 
	}
}

bool queueA::dequeue() {
	// I couldn't get this FNC working, I tried many times to get it working but could not modify the header structure. Otherwise I would have included it in the function header...
	int inputInt;
	cin>>inputInt;
	if(!empty()) {
		inputInt=data[0];
		if(front==rear) {
			front=-1;
			rear=-1;
		}
		for(int i=0 ; i<rear; i++) {
			data[i]=data[i+1];
		}
		rear--;
		return true;
	} else {
		cout<< "Is empty." << endl;
		return false;
	}
}

bool queueA::empty()const {
	if(front == -1) {
        	return true;
	} else  {
		return false;
	}
}

bool queueA::full()const {
	if(rear==(max-1)) {
        	return true;
	} else {
		return false; 
	}
}

bool queueA::clear() {
	if(!empty()) { 
        	front=-1;
        	rear=-1; 
        	return true; 
	} else {
		return false; 
	}
}

bool queueA::operator==(const queueA& pointQ)const {
	bool result=false;
	int loc=0;
 // check if equal
	if(max!=pointQ.max) {
        	return false;
	} else if(front!=pointQ.front) {
		return false;
	} else if(rear!=pointQ.rear) {
		return false;
	}
	for(int i=0; i<=rear; i++) {
		if(data[loc]!=pointQ.data[loc]) {
			return result;
		}
		loc++;
	}
	result=true; 
	return result; 
}

ostream &operator<<(ostream& output, const queueA& pointQ) {	
 	if(pointQ.empty()) {
		output << "is empty.";
		return output;
	}
	for(int i =0; i <= pointQ.rear; i++) {
		output << pointQ.data[i] << " ";
	}
	cout << endl;
	return output;
}
