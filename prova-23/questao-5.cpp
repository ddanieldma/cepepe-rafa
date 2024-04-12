// A verificação de um loop na lista consiste em criar uma lista de endere
// ços e armazenar todos os endereços vistos até agora. Se a lista tiver
// um loop, eventualmente um endereço já armazenado será visto novamente.
// Não a forma mais esperta de resolver o problema mas funciona.

#include <iostream>
#include "linked-list.h"
#include "linked-list-pointer.h"
#include "utils.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;


int isOnList(LinkedList* const, int);
int hasLoop(LinkedList* const);


int main (){
	LinkedList* linkedlist = createLinkedList();
	addElement(linkedlist, 1);
	addElement(linkedlist, 2);
	addElement(linkedlist, 3);
	addElement(linkedlist, 4);
	addElement(linkedlist, 5);

	linkedlist->first->ptrNext->ptrNext->ptrNext->ptrNext->ptrNext = linkedlist->first->ptrNext->ptrNext;

	iguais();

	LinkedList* otherList = createLinkedList();

	isOnList(otherList, 6);

	addElement(otherList, 1);
	addElement(otherList, 2);
	addElement(otherList, 3);
	addElement(otherList, 4);
	addElement(otherList, 5);

	isOnList(otherList, 6);
	isOnList(otherList, 3);

	hasLoop(linkedlist);

	return 0;
}


int isOnList(LinkedList* const linkedlist, int iValue){
	if (linkedlist->first == nullptr){
		cout << "Lista vazia" << endl;
		return false;
	}

	Node* current = linkedlist->first;

	while(current != nullptr){
		if(current->iData == iValue){
			cout << "Valor presente na lista" << endl;

			return true;
		}
		current = current->ptrNext;
	}

	cout << "Valor não está presente na lista" << endl;
	
	return false;
}

int hasLoop(LinkedList* const linkedlist){
	LinkedListPointer* addressList = createLinkedListPointer();

	Node* current = linkedlist->first;

	while(current != nullptr){
		// se o endereço estiver na lista de endereços
		if(isOnListPointer(addressList, current)){
			cout << "Tem um loop";
			return true;
		}
		addElementPointer(addressList, current);
		current = current->ptrNext;
	}

	cout << "Não tem um loop";
	return false;
}