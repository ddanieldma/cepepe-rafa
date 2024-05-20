#include <iostream>

using namespace std;


// Definindo estrutura do nó da lista.
typedef struct Node{
	int iPayload;
	Node* ptrNext;
	Node* ptrPrevious;
} Node;


bool emptyList(Node**);
Node* createNode(int);
void insertEnd(Node**, int);
void displayList(Node**);
void insertStart(Node**, int);
Node* getFirstElement(Node**);
Node* getLastElement(Node**);


int main(){
	// 1. Criação da lista.
	// 2. Criação e inicialização de nó
	// 3. Inserir elemento no final da lista.
	// 4. Imprimir toda a lista.
	// 5. Inserir elemento no começo da lista.
	// 6. Encontrar primeiro e último elemento.
	
	// 7. Encontrar elemento pelo valor.
	// 8. Remover último e primeiro elemento.
	// 9. Remover elemento pelo valor.
	// 10. Remover e adicionar elemento antes ou depois de algum elemento.

	// Ponteiro que indica começo da DLL.
	Node* head = nullptr;
	
	Node* first = getFirstElement(&head);
	Node* last = getLastElement(&head);

	displayList(&head);

	insertEnd(&head, 42);
	insertEnd(&head, 666);

	displayList(&head);

	insertStart(&head, 1);
	insertStart(&head, 13);

	displayList(&head);

	first = getFirstElement(&head);
	last = getLastElement(&head);

	cout << first->iPayload << endl;
	cout << last->iPayload << endl;

	return 0;
}


bool emptyList(Node** head){
	if (*head == nullptr){
		cout << "Lista vazia" << endl;
		return true;
	}

	return false;
}

Node* createNode(int iPayload){
	Node* newNode = (Node*) malloc(sizeof(Node));

	newNode->iPayload = iPayload;
	newNode->ptrNext = nullptr;
	newNode->ptrPrevious = nullptr;

	return newNode;
}

void insertEnd(Node** head, int iPayload){
	Node* newNode = createNode(iPayload);
	
	// Se a lista estiver vazia o primeiro nó não aponta para ninguém.
	if(emptyList(head)){
		*head = newNode;
		
		return;
	}

	Node* current = *head;
	
	// Vai até o fim da lista.
	while(current->ptrNext != nullptr){
		current = current->ptrNext;
	}

	// Configurando conexões com o novo nó.
	// O antes último nó agora aponta para o novo.
	current->ptrNext = newNode;
	// E o novo nó aponta para o antes último.
	newNode->ptrPrevious = current;

	return;
}

void displayList(Node** head){
	if(emptyList(head)){
		return ;
	}

	cout << "Payload: ";

	Node* current = *head;
	while(current != nullptr){
		cout << current->iPayload << " ";
		current = current->ptrNext;
	}

	cout << endl;

	return;
}

void insertStart(Node** head, int iPayload){
	Node* newNode = createNode(iPayload);

	if(emptyList(head)){
		*head = newNode;
	}

	Node* first = *head;

	// Configurando conexões.
	// Antigo primeiro nó aponta para o novo nó.
	first->ptrPrevious = newNode;
	// Novo primeiro nó aponta para o antigo primeiro nó.
	newNode->ptrNext = first;
	// head aponta para o novo primeiro nó.
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

	Node* current = *head;

	while(current->ptrNext != nullptr){
		current = current->ptrNext;
	}

	return current;
}