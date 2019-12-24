/**

 * Marcus Casey

 * CS202

 * Section 1103

 */

// import header files
#include <iostream>
#include <string>
#include "listA.h"
#include "listN.h"

using namespace std;
// function prototypes
int binarySearch(ListA, int, int, int);
bool sort(ListN&);

// main
int main() {
    ListN listNode;
    int remove;
// get file name
    string inputName;
    cout << "Enter file name for search: ";
    cin  >> inputName;
    if (listNode.readFile(inputName)) {
        cout << "File Successfully Loaded" << endl;
    } else {
        cout << "Error; file didn't load." << endl;
	return 0;
    }
    cout << "Unsorted Node List: " << listNode << endl<<"--------------------------------------------------------------------------------"<<endl;
    sort(listNode);
    cout << "Sorted Node List: " << listNode << endl<<"--------------------------------------------------------------------------------"<<endl;
    // move node list to array list
    int countArray = listNode.count();
    ListA listArray = ListA(countArray);
    while(!listNode.isEmpty()) {
        int data;
        listNode.get(data);
        listArray.insertAfter(data);
        listNode.remove();
    }
    cout << "Sorted Array List: " << listArray << endl <<"--------------------------------------------------------------------------------"<<endl;
// get search num
    int numSearch;
    cout << "Enter number to search index of: ";
    cin >> numSearch;
    cout << "Index in Array is: ";
    cout << binarySearch(listArray, numSearch, 0, countArray-1) << endl;
    return 0;
}

// binary search algorythm
int binarySearch(ListA list, int numSearch, int begin, int stopE) {
   // grab middle value
    int midNum = (begin+stopE)/2;
    // begin to compare numbers
    list.goToBeginning();
    for (int i = 0; i < midNum; i++) {
        list.goToNext();
    }
    int middleVal;
    list.get(middleVal);
	// look through top half
    if (numSearch > middleVal) { // search top half
        return binarySearch(list, numSearch,midNum+1, stopE);
    } 
	else if (numSearch < middleVal) {
	// look throuhgh bottom half
        return binarySearch(list, numSearch,begin, midNum-1);
    } else if (middleVal == -1) {
	return -1;
	} else {
 // return the middle value if it was already grabbed
        return midNum;
    }
}

//sort algorythm
bool sort(ListN &listNode) {
    int remove;
    if (!listNode.isEmpty()) {
        bool isSorted = true;
        while(isSorted) {
            isSorted = false;
            listNode.goToBeginning();
	// when false it is after
            while(listNode.goToNext()) { 
                int currentStart;
                listNode.get(currentStart);

                int after;
                listNode.get(after);
                listNode.goToPrior();
                int startL;
                listNode.get(startL);
	// if need after
                if (startL > after) { 
                    listNode.remove();
                    listNode.insertAfter(after);
                    listNode.goToNext();
                    int current;
                    listNode.get(current);
                    listNode.remove();
                    listNode.insertAfter(startL);
                    isSorted = true;
                } else {
	// otherwise go to next
                    listNode.goToNext();
                }

            }
        }
	// continue
        listNode.goToBeginning();
        listNode.remove();
        return true;
    } else {
        return false;
    }
}
