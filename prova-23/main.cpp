#include <iostream>
#include "linked-list.h"
#include "utils.h"

using namespace std;

int main(){
	LinkedList* linkedlist = createLinkedList();

	addElement(linkedlist, 7);
	addElement(linkedlist, 42);
	addElement(linkedlist, 666);
	addElement(linkedlist, 1024);

	showElements(linkedlist);

	iguais();

	cout << "Invertendo lista" << endl;
	reverseList(linkedlist);
	showElements(linkedlist);

	return 0;
}