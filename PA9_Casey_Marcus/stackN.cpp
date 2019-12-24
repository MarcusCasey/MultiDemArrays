/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
// import header files
#include "stackN.h"

NodeS::NodeS(int amt, NodeS* vari) {
  data= amt;
  next = vari;
}

stackN::stackN(int amt) {
	top = NULL;
}

stackN::~stackN() {
	NodeS* amtPt;
	while(top->next != NULL)	{		
	amtPt = top->next;
		delete top;
		top= amtPt;
	}
	delete top;
	top = NULL;
}

/*not working
bool stackN::pop(int& amt) { 
	if(empty()) {
		return false;
	}
	if(top->next == NULL) {
		amt = top->data;
		delete top;
		top = NULL;
		return true;
	}	else	{
		amt = top->data;
		delete top;
		top = amtPt;
		return true;
	}
	return false;
}
*/

bool stackN::empty()const {	
	if(top == NULL) {
		return true;
	}
	return false;
}

bool stackN:: full()const {
	return false;
}


ostream &operator << (ostream& output, const stackN& )
{

}



