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

typedef struct Queue
{
	Node* ptrFirst;
}Queue;


Node* createNode(int);
Queue* createQueue();
bool emptyQueue(Queue*);
void enQueue(Queue* const, int);
void deQueue(Queue*, int);
void showElements(Queue* const);


Node* createNode(int iValue){
	/*Cria nó da fila.*/
	
	// Alocando memória.
	Node* temp = (Node*) malloc(sizeof(Node));
	
	// Inicializando nó.
	temp->iData = iValue;
	temp->ptrNext = nullptr;

	return temp;
}

Queue* createQueue(){
	/*Cria fila.*/
	
	// Alocando memória.
	Queue* temp = (Queue*) malloc(sizeof(Queue));
	
	// Inicializando estrutura.
	temp->ptrFirst = nullptr;

	return temp;
}

bool emptyQueue(Queue* queue){
	/*Diz se a fila está vazia ou não.*/
	
	if(queue->ptrFirst == nullptr){
		cout << "Fila vazia" << endl;
		return true;
	}

	return false;
}

void enQueue(Queue* const queue, int iValue){
	/*Adiciona elemento na fila*/
	
	Node* newElement = createNode(iValue);

	// Se a fila estiver vazia.
	if(emptyQueue(queue)){
		queue->ptrFirst = newElement;

		return;
	}

	// Percorrendo a lista toda.
	Node* current = queue->ptrFirst;
	while(current->ptrNext != nullptr) current = current->ptrNext;

	// Adicionando novo elemento.
	current->ptrNext = newElement;

	return;
}

void deQueue(Queue* queue, int iValue){
	/*Remove elemento da fila.*/
	
	if(emptyQueue(queue)) return;

	// Vamos deletar o primeiro nó.
	Node* deletionNode = queue->ptrFirst;
	// E setamos o segundo para ser o novo primeiro.
	queue->ptrFirst = deletionNode->ptrNext;

	free(deletionNode);

	return;
}

void showElements(Queue* const queue){
	if(emptyQueue(queue)) return;
	
	cout << "Payload: ";
	Node* current = queue->ptrFirst;

	while(current != nullptr){
		cout << current->iData << " ";

		current = current->ptrNext;
	}
	
	cout << endl;

	return;
}