#include <iostream>
#include "linked-list-aluno.h"
#include "utils.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;


int isOnList(LinkedList* const, long int);
LinkedList* intersection(LinkedList* const, LinkedList* const);

int main(){
	LinkedList* list1 = createLinkedList();
	LinkedList* list2 = createLinkedList();

	addElement(list1, 231708065);
	addElement(list1, 231708066);
	addElement(list1, 231708001);
	addElement(list1, 231708003);
	addElement(list1, 231708067);

	addElement(list2, 231708001);
	addElement(list2, 231708002);
	addElement(list2, 231708003);
	addElement(list2, 231708004);

	LinkedList* listIntersection = intersection(list1, list2);

	showElements(listIntersection);
	
	return 0;
}


int isOnList(LinkedList* const linkedlist, long int iMatricula){
	if (linkedlist->first == nullptr){
		cout << "Lista vazia" << endl;
		return false;
	}

	Node* current = linkedlist->first;

	while(current != nullptr){
		if(current->iMatricula == iMatricula){
			cout << "Valor presente na lista" << endl;

			return true;
		}
		current = current->ptrNext;
	}

	cout << "Valor não está presente na lista" << endl;
	
	return false;
}

LinkedList* intersection(LinkedList* const list1, LinkedList* const list2){
	if(list1->first == nullptr || list2->first == nullptr){
		cout << "Alguma das listas está vazia" << endl;
	}

	LinkedList* listIntersection = createLinkedList();
	
	Node* current = list1->first;

	while(current != nullptr){
		// Se o dado armazenado no nó atual estiver na lista.
		if(isOnList(list2, current->iMatricula)){
			cout << "Interseção encontrada" << endl;

			addElement(listIntersection, current->iMatricula);
		}
		current = current->ptrNext;
	}

	return listIntersection;
}