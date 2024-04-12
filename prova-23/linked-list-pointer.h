// 1. Lista aponta só para o primeiro elemento
// 2. Adiciona no final
// 3. Não tem tamanho

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct NodePointer
{
    void* address;
    NodePointer* ptrNext;
} NodePointer;

typedef struct LinkedListPointer
{
	NodePointer* first;
}LinkedListPointer;

NodePointer* createNodePointer(void* address){
	NodePointer* temp = (NodePointer*) malloc(sizeof(NodePointer));
	
	temp->address = address;
	temp->ptrNext = nullptr;

	return temp;
}

LinkedListPointer* createLinkedListPointer(){
	LinkedListPointer* temp = (LinkedListPointer*) malloc(sizeof(LinkedListPointer));
	
	temp->first = nullptr;

	return temp;
}

void addElementPointer(LinkedListPointer* const linkedlist, void* address){
	NodePointer* newElement = createNodePointer(address);

	// Se a lista estiver vazia.
	if(linkedlist->first == nullptr){
		linkedlist->first = newElement;

		return;
	}

	NodePointer* current = linkedlist->first;

	while(current->ptrNext != nullptr){
		current = current->ptrNext;
	}

	current->ptrNext = newElement;

	return;
}

int isOnListPointer(LinkedListPointer* linkedlist, void* address){
	if (linkedlist->first == nullptr){
		cout << "Lista vazia" << endl;
		return false;
	}

	NodePointer* current = linkedlist->first;

	while(current != nullptr){
		if(current->address == address){
			cout << "Valor presente na lista" << endl;

			return true;
		}
		current = current->ptrNext;
	}

	cout << "Valor não está presente na lista" << endl;
	
	return false;
}

// void removeElement(LinkedList* linkedlist, int iValue){
// 	if(linkedlist->first == nullptr){
// 		cout << "Lista vazia" << endl;
// 	}

// 	if(linkedlist->first->iData == iValue){
// 		Node* temp = linkedlist->first;
// 		linkedlist->first = linkedlist->first->ptrNext;

// 		free(temp);

// 		cout << "Removeu primeiro elemento" << endl;
// 		return;
// 	}
	
// 	// Current começa no segundo e previous no primeiro
// 	Node* current = linkedlist->first->ptrNext;
// 	Node* previous = linkedlist->first;

// 	while(current->ptrNext != nullptr){
// 		if(current->iData == iValue){
// 			previous->ptrNext = current->ptrNext;

// 			cout << "Removeu elemento " << current->iData << endl;
// 			free(current);

// 			return;
// 		}
// 		previous = current;
// 		current = current->ptrNext;
// 	}

// 	cout << "Elemento não encontrado" << endl;

// 	return;
// }

// void showElements(LinkedList* const linkedlist){
// 	if(linkedlist-> first == nullptr){
// 		cout << "Lista vazia" << endl;

// 		return ;
// 	}
	
// 	Node* current = linkedlist->first;
// 	int iCounter = 1;

// 	while(current != nullptr){
// 		cout << "Elemento " << iCounter << ": " << current->iData << endl;

// 		current = current->ptrNext;
// 		iCounter++;
// 	}
	
// 	return;
// }