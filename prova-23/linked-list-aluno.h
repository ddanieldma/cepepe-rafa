// 1. Lista aponta só para o primeiro elemento
// 2. Adiciona no final
// 3. Não tem tamanho

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    long int iMatricula;
    Node* ptrNext;
} Node;

typedef struct linkedList
{
	Node* first;
}LinkedList;

Node* createNode(long int iValue){
	Node* temp = (Node*) malloc(sizeof(Node));
	
	temp->iMatricula = iValue;
	temp->ptrNext = nullptr;

	return temp;
}

LinkedList* createLinkedList(){
	LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
	
	temp->first = nullptr;

	return temp;
}

void addElement(LinkedList* const linkedlist, long int iValue){
	Node* newElement = createNode(iValue);

	// Se a lista estiver vazia.
	if(linkedlist->first == nullptr){
		linkedlist->first = newElement;

		return;
	}

	Node* current = linkedlist->first;

	while(current->ptrNext != nullptr){
		current = current->ptrNext;
	}

	current->ptrNext = newElement;

	return;
}

void removeElement(LinkedList* linkedlist, long int iValue){
	if(linkedlist->first == nullptr){
		cout << "Lista vazia" << endl;
	}

	if(linkedlist->first->iMatricula == iValue){
		Node* temp = linkedlist->first;
		linkedlist->first = linkedlist->first->ptrNext;

		free(temp);

		cout << "Removeu primeiro aluno" << endl;
		return;
	}
	
	// Current começa no segundo e previous no primeiro
	Node* current = linkedlist->first->ptrNext;
	Node* previous = linkedlist->first;

	while(current->ptrNext != nullptr){
		if(current->iMatricula == iValue){
			previous->ptrNext = current->ptrNext;

			cout << "Removeu aluno " << current->iMatricula << endl;
			free(current);

			return;
		}
		previous = current;
		current = current->ptrNext;
	}

	cout << "Aluno não encontrado" << endl;

	return;
}

void showElements(LinkedList* const linkedlist){
	if(linkedlist-> first == nullptr){
		cout << "Lista vazia" << endl;

		return ;
	}
	
	Node* current = linkedlist->first;
	int iCounter = 1;

	while(current != nullptr){
		cout << "Aluno " << iCounter << ": " << current->iMatricula << endl;

		current = current->ptrNext;
		iCounter++;
	}
	
	return;
}

int emptyList(LinkedList* const linkedlist){

	if(linkedlist->first == nullptr){
		return true;
	}

	return false;
}