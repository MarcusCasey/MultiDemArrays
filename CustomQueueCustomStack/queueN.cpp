/**

 * Marcus Casey

 * CS202

 * Section 1103

 */
// import header files
#include "queueN.h"
// construct
NodeQ::NodeQ(int amt, NodeQ* nodeS) {
	data = amt; 
	next = nodeS; 
}

// construct
queueN::queueN() {
	int total;
	front = NULL; 
	rear = NULL;
}

// copy construct 
queueN::queueN(const queueN& nodeP) { 
	front = nodeP.front; 
	rear = nodeP.rear; 
}
// destruct
queueN::~queueN() { 
	delete front;
	delete rear;
	front = NULL;
	rear = NULL;
}

// header fncs

queueN& queueN::operator=(const queueN& nodeP) {
	front = nodeP.front; 
	rear =  nodeP.rear;
	return *this; 
}

bool queueN::enqueue(int amt) {
	if(full()) {
		return false;
	}	
	if(empty()) {
		front = new NodeQ(amt,NULL);
		rear = front; 
	} else {
		rear-> next = new NodeQ(amt,NULL);
		rear= rear->next; 
	}
	return true; 
}

// I couldn't get this FNC working, I tried many times to get it working but could not modify the header structure. Otherwise I would have included it in the function header...
bool queueN::dequeue() {
	int amt;
	cin>>amt;
	if(empty()) {
		return false;
	}
	if(front == rear) {
		amt = front->data;
		delete front;
		front = rear = NULL;
		return true;
	}
	if(front->next==rear) {
	
	amt = front->data;
	delete front;
	front = rear;
	return true;
	}
	
	NodeQ* hold=front-> next;
	amt=front->data;
	front = hold;
	return true; 
}


//getFront

bool queueN::empty()const
{
	if(front == NULL) {
        return true;
	} else {
		return false;
	}
}

bool queueN::full()const
{ 
	return false; 
}

bool queueN:: clear()
{
	if(empty()) {
		cout << "Is empty.";
		return false;
	}  
   	NodeQ* buffer;
	while(front-> next != NULL) {
		buffer = front->next;
		delete front;
		front = buffer;
	}
	delete front;
	front = NULL;
	return true;
}

bool queueN::operator == (const queueN& nodeP)const
{
	NodeQ* expanda;
	NodeQ* nodePta;
	NodeQ* expand = nodeP.front;
	NodeQ* nodePt = front;
	
  	if((nodeP.front == NULL) & (front == NULL)) {
		return true;
	}	
	if(((nodeP.front == NULL) & (front != NULL)) || ((nodeP.front != NULL) & (front == NULL)))	{
  		return false;
	}
	while((nodePt->next != NULL) || (expand->next != NULL))   {
		if( ((expand->next != NULL) & (nodePt->next == NULL))|| ((expand->next == NULL) & (nodePt->next != NULL)))	{
	    		return false;
		}
		if(expand->data != nodePt->data)	{
			return false;
		}
		expanda=expand->next;
		expand=expanda;
		nodePta=nodePt->next;
		nodePt =nodePta;
	}
	return true; 
}

ostream& operator<<(ostream& output, const queueN& nodeP)
{
	NodeQ* nodePt = nodeP.front;
	NodeQ* nodePta;
	if(nodeP.empty()) {
		output << "Is empty.";
	}
	while(nodePt->next != NULL) {
		output << nodePt->data << " ";
		nodePta = nodePt->next;
		nodePt = nodePta;
	}
	output << nodePt->data;	
	return output; 
}
