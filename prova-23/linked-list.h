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

void removeElements(LinkedList* linkedlist, int iValue){
	// Função que remove todas as ocorrências (não só a primeira) de um 
	// valor.

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

	while(current != nullptr){
		if(current->iData == iValue){
			previous->ptrNext = current->ptrNext;
			cout << "Removeu elemento " << current->iData << endl;
			
			// Se o current for o último eliminamos ele e saímos do loop.
			if(current->ptrNext == nullptr){
				cout << "Fim da lista" << endl;
				free(current);
				break;
			}
			// Se não for, criamos um temp, andamos com o current e 
			// eliminamos o temp
			else{
				Node* temp = current;
				current = current->ptrNext;
				free(temp);
			}
		}
		else{
			previous = current;
			current = current->ptrNext;
		}
	}

	cout << "Fim da execução" << endl;

	return;
}

void clearList(LinkedList* linkedlist){
	if(emptyList(linkedlist)){
		return;
	}
	
	Node* current = linkedlist->first;
	
	// Aponta a lista para nada.
	linkedlist->first = nullptr;

	// Percorre os elementos da antiga lista liberando a memória de todos.
	while(current != nullptr){
		Node* temp = current;
		current = current->ptrNext;

		cout << "Removendo elemento: " << temp->iData << endl;
		free(temp);
	}

	// E por fim libera a memória reservada no next do último elemento.
	free(current);
}

void reverseList(LinkedList* const linkedlist){
	if(emptyList(linkedlist)){
		return;
	}

	Node* current = linkedlist->first;
	Node* next = linkedlist->first->ptrNext;
	Node* temp;

	while(next != nullptr){
		cout << current->iData << endl;
		// Current aponta para o elemento posterior ao next
		current->ptrNext = next->ptrNext;
		// Next aponta para o current (anterior a si mesmo)
		next->ptrNext = current;
		// Variável temporária salva o próximo elemento para que o current
		// tenha para onde avançar, next avança e logo em seguida o current.
		temp = next;
		next = current->ptrNext;
		current = temp;
	}

	linkedlist->first = current;

	return;
}