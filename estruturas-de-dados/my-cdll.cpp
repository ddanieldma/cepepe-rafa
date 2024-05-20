#include <iostream>
#include "utils.h"

using namespace std;


// Estrutura do nó. Na lista TODO nó aponta para um next e previous.
// O head define o "primeiro" nó.
typedef struct Node{
	int iPayload;
	Node* ptrNext;
	Node* ptrPrevious;
}Node;


Node* createNode(int);
bool emptyList(Node**);
bool firstOrSecondNode(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void insertStart(Node** , int);
Node* getFirstElement(Node**);
Node* getLastElement(Node**);
Node* getNodeByValue(Node**, int);
void removeElement(Node**, Node*);


int main(){
	// 1. Criação da lista.
	// 2. Criação e inicialização de nó.
	// 3. Inserir elemento no final da lista.
	// 4. Imprimir toda a lista.
	// 5. Inserir elemento no começo da lista.
	// 6. Encontrar primeiro e último elemento.
	// 7. Encontrar elemento pelo valor.
	
	// 8. Remover último e primeiro elemento.
	// 9. Remover elemento pelo valor.
	// 10. Remover e adicionar elemento antes ou depois de algum elemento.
	
	cout << "Nó solto" << endl;
	Node* newNode = createNode(15);

	cout << newNode->iPayload << endl;
	cout << newNode->ptrNext << endl;
	cout << newNode->ptrPrevious << endl;
	displayList(newNode);
	iguais();

	cout << "Criando head" << endl;

	Node* head = nullptr;

	displayList(head);
	iguais();

	cout << "Inserindo elementos no final" << endl;
	insertEnd(&head, 1);
	insertEnd(&head, 13);
	insertEnd(&head, 42);

	displayList(head);
	iguais();

	cout << "Inserindo elemento no começo" << endl;
	Node* head2 = nullptr;
	insertStart(&head2, 777);
	insertStart(&head2, 13);
	insertStart(&head2, 1);

	displayList(head2);
	iguais();

	cout << "Primeiro elemento das duas listas:" << endl;
	
	Node* first = getFirstElement(&head);
	cout << first->iPayload << " e ";
	first = getFirstElement(&head2);
	cout << first->iPayload << endl;
	
	cout << "Último elemento das duas listas:" << endl;
	Node* last = getLastElement(&head);
	cout << last->iPayload << " e ";
	last = getLastElement(&head2);
	cout << last->iPayload << endl;
	iguais();

	cout << "Procurando valores pela lista" << endl;
	Node* head3 = nullptr;
	Node* find = getNodeByValue(&head3, 12);
	cout << find << endl;
	find = getNodeByValue(&head2, 13);
	cout << find->iPayload << endl;
	find = getNodeByValue(&head2, 14);

	return 0;
}


Node* createNode(int iPayload){
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->iPayload = iPayload;
	newNode->ptrNext = nullptr;
	newNode->ptrPrevious = nullptr;

	return newNode;
}

bool emptyList(Node** head){
	if(*head == nullptr){
		cout << "Lista vazia" << endl;

		return true;
	}

	return false;
}

bool firstOrSecondNode(Node** head, int iPayload, Node* newNode){
	// Função que verifica se o nó que vai ser adicionado é o primeiro ou o
	// segundo da lista (casos especiais) e, caso seja, o adiciona à lista.
	
	if(emptyList(head)){
		*head = newNode;

		return true;
	}

	Node* first = *head;
	
	// Se ainda só tivermos um nó na lista.
	if(first->ptrNext == nullptr){
		// Organizando conexões.
		// O primeiro nó aponta duas vezes para o novo nó.
		first->ptrNext = newNode;
		first->ptrPrevious = newNode;

		// E vice-versa.
		newNode->ptrNext = first;
		newNode->ptrPrevious = first;

		return true;
	}

	return false;
}

void insertEnd(Node** head, int iPayload){
	Node* newNode = createNode(iPayload);

	if(firstOrSecondNode(head, iPayload, newNode))
		return;

	Node* first = *head;
	
	// Antigo último nó aponta para o novo nó.
	first->ptrPrevious->ptrNext = newNode;
	// Novo nó aponta para o antigo último e para o primeiro.
	newNode->ptrPrevious = first->ptrPrevious;
	newNode->ptrNext = first;
	// Primeiro nó aponta para o novo último nó
	first->ptrPrevious = newNode;

	return;
}

// Com uma lista circular podemos começar de qualquer nó.
void displayList(Node* initialNode){
	if(initialNode == nullptr){
		cout << "Erro: nó nulo" << endl;

		return;
	}
	
	Node* current = initialNode;

	cout << "Payload: " << current->iPayload << " ";
	
	// Dando primeiro passo para poder entrar no while.
	current = current->ptrNext;

	while(current != initialNode && current != nullptr){
		cout << current->iPayload << " ";
		
		current = current->ptrNext;
	}

	cout << endl;

	return;
}

void insertStart(Node** head, int iPayload){
	Node* newNode = createNode(iPayload);

	if(firstOrSecondNode(head, iPayload, newNode)){
		// Nesse caso precisamos mudar a head para o novo elemento também.
		*head = newNode;
		
		return;
	}

	Node* previousFirst = *head;

	// Organizando conexões.
	// O antigo últino nó aponta para o novo.
	previousFirst->ptrPrevious->ptrNext = newNode;
	// O novo nó aponta para o último e o antigo primeiro.
	newNode->ptrNext = previousFirst;
	newNode->ptrPrevious = previousFirst->ptrPrevious;
	// O antigo primeiro nó aponta para o novo
	previousFirst->ptrPrevious = newNode;
	// E a head aponta para o novo primeiro nó.
	*head = newNode;

	return;
}

Node* getFirstElement(Node** head){
	if (emptyList(head)){
		return nullptr;
	}

	return *head;
}

Node* getLastElement(Node** head){
	if(emptyList(head)){
		return nullptr;
	}

	Node* first = *head;
	return first->ptrPrevious;
}

Node* getNodeByValue(Node** head, int iValue){
	if (emptyList(head))
		return nullptr;

	Node* current = *head;

	if (current->iPayload == iValue)
		return current;

	// Dando primeiro passo para poder entrar no while.
	current = current->ptrNext;

	while(current != *head && current != nullptr){
		if (current->iPayload == iValue)
			return current;
		
		current = current->ptrNext;
	}

	cout << "Valor não encontrado na lista" << endl;

	return nullptr;
}

void removeElement(Node** head, Node* deleteNode){
	if(emptyList(head))
		return;

	Node* first = *head;
	// Se tivermos apenas um elemento na lista.
	if(first->ptrNext == nullptr){
		*head = nullptr;
		free(first);
	
		return;
	}

	// Se tivermos apenas dois elementos na lista.
	if(first->ptrNext->ptrNext = *head){
		
	}
}