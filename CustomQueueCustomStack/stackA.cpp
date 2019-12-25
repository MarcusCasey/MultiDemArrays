/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
// import header files
#include "stackA.h"

//  construct
stackA::stackA(int holdAmt) {
	max = holdAmt;
	top = -1;  
	data = new int [max];
}

// copy construct
stackA::stackA(const stackA& amt) {
	max = amt.max;
	top = amt.top; 
	data = new int[max]; 
	for(int i = 0; i < top; i++) {
        	data[i] = amt.data[i];
	}
}

// destructor
stackA::~stackA() {
	delete[] data;
	data = NULL; 
	max = 0;
	top = 0;
}

stackA& stackA::operator=(const stackA& amt) {
	int loc = 0; 
	if(this != &amt) {
		if(max != amt.max) {
			delete[] data;
			data = new int [amt.max+1];
			max = amt.max;
		}
		for(int i = 0; i <= amt.max; i++) {
			data[loc] = amt.data[loc];
		}
		data[loc] = '0';
	}
	return *this;
}

bool stackA::push(int current) {
	int loc = 0; 
	if(!empty()) {
		top = 0;
		data[loc] = current;
		return true;  
	}
	else if(!full()&& !empty()) { 
        	top++;
        	data[top] = current;
        	return true;
	}else{ 
		return false;
	} 
}
// couldn't get template working with this fnc
bool stackA<T>::pop(int& current) {
	if(!empty()) {
        	ugh = data[top];
        	data[top] = '\0';
		top--;
		return true;
	} else {
		return false;
	}
}

//get top

bool stackA::empty()const {
	if(top == 0) {
        	return true; 
	}
	return false;
}

bool stackA::full()const {
	if(top >= max) {
        	return true;
	}
	return false;  
}
bool stackA::clear() {
	if(!empty()) { 
		for(int i = 0; i < max; i++) {
		data[i] = '\0'; 
		}
		top = -1;
	} 
}

bool stackA::operator==(const stackA& amt)const {
	bool correct = false;
	int loc = 0;
	if(max == amt.max)	{
        	return false;
	}
	for(int i =0; i <= max; i++) {
		if(data[loc]== amt.data[loc])	{
			return correct;
		}
		loc++;
	}
	correct = true; 
	return correct; 
}

ostream &operator<<(ostream&, const stackA&){
	for(int i =0; i < actual; i++)	{
		output << amt.data[i];
	}

	return output;
}

