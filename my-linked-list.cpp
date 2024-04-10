#include <iostream>
#include "utils.h"

using namespace std;

typedef struct Node{
    int iData;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* front;
    Node* rear;
	int iSize;
} LinkedList;

LinkedList* newLinkedList(){
    // Precisamos pedir memoria para o SO.
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));

    // Lista vazia: primeiro e último elemento nulo e tamanho = 0.
    temp->front = nullptr;
    temp->front = nullptr;
	temp->iSize = 0;

    return temp;
}

Node* newNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iData = iValue;
    temp->next = nullptr;

    return temp;
}

void enLinkedList(LinkedList* const linkedlist, int iValue){
    // Adiciona elemento na lista.

    // Cria novo nó
    Node* temp = newNode(iValue);

	// Se a lista estiver vazia
	if(linkedlist->iSize == 0){
		linkedlist->front = temp;
		linkedlist->rear = temp;
	}
	else{
		linkedlist->rear->next = temp;
		linkedlist->rear = temp;
	}

	linkedlist->iSize++;

	return;
}

void showElement(LinkedList* const linkedlist, int iIndex){
	if(linkedlist->iSize == 0)	{
		cout << "Lista vazia" << endl;
	}
	else if(linkedlist-> iSize < iIndex - 1){
		cout << "Índice dado maior que o tamanho da lista" << endl;
	}

	Node* current = linkedlist->front;

	int iCounter;

	for (iCounter = 0; iCounter < iIndex; iCounter++){
		current = current->next;
	}

	cout << "Lista [" << iCounter << "] = " << current->iData << endl;
}

void deLinkedList(LinkedList* const linkedlist, int iValue){
    // Remove elemento da lista pelo dado nele contido.

    if (linkedlist->iSize == 0){
        cout << "Lista vazia" << endl;
        return;
    }

	Node* current = linkedlist->front;
	
	// contador para verificar se o valor removido não é o primeiro ou o último
	int iCounter = 1;


	while(current->next != nullptr) {
		if(current->next->iData == iValue){
    		if(iCounter == 1){
				// Se o elemento a ser removido for o primeiro.
				linkedlist->front = linkedlist->front->next;
			}
			else if(iCounter == linkedlist->iSize - 1){
				// Se o elemento a ser removido for o último.
				linkedlist->rear = current;
			}
			
			cout << "Valor " << current->next->iData << " removido." << endl;
			
			// Reserva o próximo elemento (que será removido) e transforma
			// o próximo elemento no posterior ao que será removido
			Node* temp = current->next;
			current->next = current->next->next;
			free(temp);
			
			linkedlist->iSize--;

			return;
		}
		current = current->next;
		iCounter++;
	}

	cout << "Elemento não encontrado na lista" << endl;

	return;
}


void showElements(LinkedList* const linkedlist){
    // Percorre toda a fila exibindo seu elementos.

    //Fila vazia.
    if (linkedlist->iSize == 0){
        cout << "Fila vazia" << endl;
        return;
    }

    Node* current = linkedlist->front;

    int iCounter = 0;
    while(current != nullptr){
		cout << "Lista [" << iCounter << "] = " << current->iData << endl;
        current = current->next;
        iCounter++;
    }
}

int main(){
	//1. Estrutura de um nó
    //2. Estrutura de uma lista encadeada
    //4. Função que cria uma lista encadeada
    //3. Função que cria um nó
    //5. Função que enfileira um nó
    //6. Função que exibe elemento pelo índice na lista
    //7. Função que exibe todos os elementos
    //8. Função que remove um nó pelo dado nele contido

	LinkedList* linkedlist = newLinkedList();
	
	enLinkedList(linkedlist, 7);
	enLinkedList(linkedlist, 13);
	enLinkedList(linkedlist, 42);
	enLinkedList(linkedlist, 666);
	enLinkedList(linkedlist, 1024);

	iguais();
	cout << "Tamanho da lista: " << linkedlist->iSize << endl;

	iguais();
	cout << "Primeiro elemento da lista" << endl;
	showElement(linkedlist, 0);
	cout << "Segundo elemento da lista" << endl;
	showElement(linkedlist, 1);
	cout << "Último elemento da lista" << endl;
	showElement(linkedlist, linkedlist->iSize - 1);

	iguais();
	cout << "Todos os elementos" << endl;
	showElements(linkedlist);

	iguais();
	cout << "Removendo elemento da lista" << endl;
	deLinkedList(linkedlist, 666);
	showElements(linkedlist);
	cout << "Tamanho da lista: " << linkedlist->iSize << endl;
	deLinkedList(linkedlist, 1);


    return 0;
}