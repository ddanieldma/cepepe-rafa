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

typedef struct linkedList
{
	Node* first;
}LinkedList;


int main(){
	// 1. estruturas
	// 2. função que cria no e lista
	// 3. adicionar elemento
	// 4. remover elemento
	// 5. mostrar primeiro, ultimo e todos
	
	LinkedList* linkedlist = createLinkedList();

	showElements(linkedlist);

	addElement(linkedlist, 1);
	addElement(linkedlist, 3);
	addElement(linkedlist, 2);
	addElement(linkedlist, 4);

	showElements(linkedlist);

	removeElement(linkedlist, 1);
	removeElement(linkedlist, 2);
	
	showElements(linkedlist);

	return 0;
}


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

void addElement(LinkedList* const linkedlist, int iValue){
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

void removeElement(LinkedList* linkedlist, int iValue){
	if(linkedlist->first == nullptr){
		cout << "Lista vazia" << endl;
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
	if(linkedlist-> first == nullptr){
		cout << "Lista vazia" << endl;

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