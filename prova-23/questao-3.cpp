// O arquivo linked-list-aluno.h tem a mesma implementação de lista encadeada
// com pequenas mudanças. Portanto, se esse arquivo e o linked-list.h
// forem incluídos no mesmo arquivo, haverá conflito.

#include <iostream>
#include "linked-list-aluno.h"
#include "utils.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;


void changeFirstLast(LinkedList* const linkedlist){
	if (linkedlist->first == nullptr){
		cout << "Lista vazia";

		return;
	}

	Node* first = linkedlist->first;
	Node* current = linkedlist->first;

	// Iteramos até o penúltimo elemento.
	while(current->ptrNext->ptrNext != nullptr){
		current = current->ptrNext;
	}

	// Último aponta pra o segundo.
	current->ptrNext->ptrNext = first->ptrNext;
	// Lista aponta pra o úlitmo (agora primeiro).
	linkedlist->first = current->ptrNext;
	// O penúltimo aponta para o primeiro (agora último)
	current->ptrNext = first;
	// E o primeiro aponta para nada
	first->ptrNext = nullptr;

	return;
}


int main(){
	LinkedList* listaAlunos = createLinkedList();

	addElement(listaAlunos, 231708001);
	addElement(listaAlunos, 231708002);
	addElement(listaAlunos, 231708003);
	addElement(listaAlunos, 231708004);
	addElement(listaAlunos, 231708004);
	addElement(listaAlunos, 231708004);
	
	showElements(listaAlunos);

	cout << "Removendo aluno" << endl;

	removeElement(listaAlunos, 231708003);
	showElements(listaAlunos);

	changeFirstLast(listaAlunos);
	showElements(listaAlunos);

	return 0;
}