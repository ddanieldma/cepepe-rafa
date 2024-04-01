#include <iostream>
#include "utils.h"

using namespace std;

// filas 
// estruturas FIFO, ou FCFS (First Come, First Served)

// pilhas
// esturas LIFO, LCFS (Last Come, First Served)

typedef struct Node{
    int iData;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Queue* newQueue(){
    // precisamos pedir memoria para o SO
    Queue* temp = (Queue*) malloc(sizeof(Queue));

    temp->front = nullptr;
    temp->rear = nullptr;

    return temp;
}

Node* newNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iData = iValue;
    temp->next = nullptr;

    return temp;
}

// aumentando a fila
void enQueue(Queue* const queue, int iValue){
    Node* temp = newNode(iValue);

    if (queue -> rear == nullptr){
        queue->front = temp;
        queue->rear = temp;
    }
    else{
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

void showFirstElement(Queue* const queue){
    cout << "Primeiro elmento da fila: " << ((queue->front != NULL) ? queue->front->iData : -1) << endl;
}

void showLastElement(Queue* const queue){
    cout << "Último elmento da fila: " << ((queue->rear != NULL) ? queue->rear->iData : -1) << endl;
}

void showElements(Queue* const queue){
    if (queue->front == nullptr){
        cout << "Fila vazia" << endl;
        return;
    }

    Node* current = queue->front;

    int iCounter = 1;
    while(current != nullptr){
        cout << "Elemento " << iCounter << " da fila: " << current->iData << endl;
        current = current->next;
        iCounter++;
    }
}

int main(){
    //1. Estrutura de um nó
    //2. Estrutura de uma fila
    //3. Função que cria uma fila
    //4. Função que cria um nó
    //5. Função que enfileira um nó
    //6. Função que exibe primeiro elemento
    //7. Função que exibe último elemento

    Queue* queue = newQueue();
    showFirstElement(queue);
    showLastElement(queue);

    iguais();

    // adicionando elementos na fila
    enQueue(queue, 0);
    showFirstElement(queue);
    showLastElement(queue);
    
    iguais();

    enQueue(queue, 10);
    showFirstElement(queue);
    showLastElement(queue);

    iguais();

    enQueue(queue, 11);
    enQueue(queue, 12);
    enQueue(queue, 13);
    enQueue(queue, 14);
    enQueue(queue, 15);
    showElements(queue);

    iguais();

    return 0;
}