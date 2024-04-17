#include <iostream>
#include "linked-list.h"
#include "utils.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;


int floydMethod(LinkedList* const);


int main(){
	LinkedList* linkedlist = createLinkedList();
	addElement(linkedlist, 1);
	addElement(linkedlist, 2);
	addElement(linkedlist, 3);
	addElement(linkedlist, 4);
	addElement(linkedlist, 5);

	linkedlist->first->ptrNext->ptrNext->ptrNext->ptrNext->ptrNext = linkedlist->first->ptrNext;

	iguais();

	int iSizeLoop = floydMethod(linkedlist);
	cout << "Tamanho do loop: " << iSizeLoop << endl;

	LinkedList* otherList = createLinkedList();

	addElement(otherList, 1);
	addElement(otherList, 2);
	addElement(otherList, 3);
	addElement(otherList, 4);
	addElement(otherList, 5);

	LinkedList* thirdList = createLinkedList();
	addElement(thirdList, 13);

	iSizeLoop = floydMethod(thirdList);
	cout << "Tamanho do loop: " << iSizeLoop << endl;
	
	return 0;
}


int floydMethod(LinkedList* const linkedlist){
	if (emptyList(linkedlist)){
		cout << "Lista vazia" << endl;
	}

	Node* tartaruga = linkedlist->first;
	Node* lebre = linkedlist->first->ptrNext;

	while(lebre != nullptr && lebre->ptrNext != nullptr){
		if(tartaruga == lebre){
			// Agora, para contar o tamanho do loop, paramos a lebre e per-
			// corremos o loop uma última vez com a tartaruga para descobrir
			// o tamanho do loop
			int iCounter = 1;
			tartaruga = tartaruga->ptrNext;

			cout << "Há um loop" << endl;

			while(tartaruga != lebre){
				tartaruga = tartaruga->ptrNext;
				iCounter = iCounter + 1;
			}

			return iCounter;
		}
		
		tartaruga = tartaruga->ptrNext;
		// A lebre precisa andar de dois em dois e ter uma verificação
		// para a posição atual e a próxima para evitar o acesso de memó
		// não alocada;
		lebre = lebre->ptrNext->ptrNext;
	}

	cout << "Não há um loop" << endl;

	return 0;
}