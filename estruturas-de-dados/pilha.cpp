#include <iostream>
#include "utils.h"

using namespace std;

typedef struct Node{
	int iData;
	Node* ptrNext;
} Node;

typedef struct Stack{
	Node* ptrTop;
} Stack;

// Definindo funções.
Node* newNode(int );
Stack* newStack();
void push(Stack* const stack, int);
void showTopElement(Stack* const stack);
void showElements(Stack* const stack);
void pop(Stack* const stack);

int main(){
    //1. Estrutura de um nó
    //2. Estrutura de uma fila
    //3. Função que cria uma fila
    //4. Função que cria um nó
    //5. Função que adiciona um nó
    //6. Função que exibe primeiro elemento
	//7. Função que exibe todos os elementos

    //8. Função que remove um nó

    Stack* stack = newStack();
	
	pop(stack);
	showTopElement(stack);
	cout << "-----" << endl;
	push(stack, 1);
	showTopElement(stack);
	cout << "-----" << endl;
	push(stack, 5);
	showTopElement(stack);
	cout << "-----" << endl;
	push(stack, 42);
	showTopElement(stack);
	cout << "-----" << endl;
	push(stack, 666);
	showTopElement(stack);
	cout << "===============" << endl;
	showElements(stack);

	iguais();
	pop(stack);
	cout << "-----" << endl;
	showElements(stack);


    return 0;
}


// funções
Node* newNode(int iValue){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iData = iValue;
    temp->ptrNext = nullptr;

    return temp;
}

Stack* newStack(){
    // Precisamos pedir memoria para o SO.
    Stack* temp = (Stack*) malloc(sizeof(Stack));

    // Fila vazia: primeiro e último elementos nulos.
    temp->ptrTop = nullptr;

    return temp;
}

void push(Stack* const stack, int iValue){
	Node* temp = newNode(iValue);

	temp->ptrNext = stack->ptrTop;
	stack->ptrTop = temp;

	return;
}

void showTopElement(Stack* const stack){
	cout << "Topo da pilha: " << ((stack->ptrTop != nullptr) ? stack->ptrTop->iData : -1) << endl;
}

void showElements(Stack* const stack){

	if(stack->ptrTop == nullptr){
		cout << "Pilha vazia" << endl;
		return;
	}

	Node* current = stack->ptrTop;
	while (current->ptrNext != nullptr){
		cout << "Elemento: " << current->iData << endl;
		current = current->ptrNext;
	}

	return;
}

void pop(Stack* const stack){

	if(stack->ptrTop == nullptr){
		cout << "Pilha vazia" << endl;
		return;
	}

	Node* temp = stack->ptrTop;

	cout << "Elemento removido: " << stack->ptrTop->iData << endl;

	stack->ptrTop = temp->ptrNext;

	free(temp);
}