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
    int iData;
    Node* ptrNext;
} Node;

typedef struct LinkedList
{
	Node* first;
}LinkedList;

Node* createNode(int iValue){
	Node* temp = (Node*) malloc(sizeof(Node));
	
	temp->iData = iValue;
	temp->ptrNext = nullptr;

	return temp;
}

LinkedList* createLinkedList(){
	LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
	
	temp->first = nullptr;

	return temp;
}

int emptyList(LinkedList* const linkedlist){

	if(linkedlist->first == nullptr){
		cout << "Lista vazia" << endl;
		return true;
	}

	return false;
}

void addElement(LinkedList* const linkedlist, int iValue){
	Node* newElement = createNode(iValue);

	// Se a lista estiver vazia.
	if(emptyList(linkedlist)){
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

void removeElement(LinkedList* linkedlist, int iValue){
	if(emptyList(linkedlist)){
		return;
	}

	if(linkedlist->first->iData == iValue){
		Node* temp = linkedlist->first;
		linkedlist->first = linkedlist->first->ptrNext;

		free(temp);

		cout << "Removeu primeiro elemento" << endl;
		return;
	}
	
	// Current começa no segundo e previous no primeiro
	Node* current = linkedlist->first->ptrNext;
	Node* previous = linkedlist->first;

	while(current->ptrNext != nullptr){
		if(current->iData == iValue){
			previous->ptrNext = current->ptrNext;

			cout << "Removeu elemento " << current->iData << endl;
			free(current);

			return;
		}
		previous = current;
		current = current->ptrNext;
	}

	cout << "Elemento não encontrado" << endl;

	return;
}

void showElements(LinkedList* const linkedlist){
	if(emptyList(linkedlist)){
		return ;
	}
	
	Node* current = linkedlist->first;
	int iCounter = 1;

	while(current != nullptr){
		cout << "Elemento " << iCounter << ": " << current->iData << endl;

		current = current->ptrNext;
		iCounter++;
	}
	
	return;
}

void addElementFront(LinkedList* const linkedlist, int iValue){
	Node* newNode = createNode(iValue);
	
	// Se a lista não estiver vazia o primeiro elemento se torna o segundo.
	if(!(emptyList(linkedlist))){
		newNode->ptrNext = linkedlist->first;	
	}

	linkedlist->first = newNode;

	return;
}