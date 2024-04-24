#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// LISTA, pilha e fila
// Torre de Hanoi com pilha
// Lista circular: o ultimo elemento aponta para o primeiro
// Lista duplamente encadeada: todo nó aponta para o anterior e para o próximo (buble sort)

// LISTA DUPLAMENTE ENCADEADA:


typedef struct Node{
    int iPayload;
    Node *ptrNext;
    Node *ptrPrev;
} Node;


Node *createNode(int);
void insertFront(Node **, int);
void insertEnd(Node **, int);
void displayList(Node *);
void insertAfter(Node*, int);
void deleteNode(Node**, Node*);


// Driver code.
int main(){
    Node *head = nullptr;
    displayList(head);
    cout << "==============" << endl;
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    displayList(head);
    cout << "==============" << endl;
    return 0;
}

Node *createNode(int iPayload){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void displayList(Node *node){

    // Se o nó passado é apenas um ponteiro nulo.
    if (node == nullptr){
        cout << "Lista vazia" << endl;
        return;
    }

    // Se o nó anterior não foi o nullptr (apenas no começo da lista).
    if (node->ptrPrev != nullptr){
        cout << "Meio ou Fim da Lista" << endl;
        return;
    }

    Node *temp = node;

    cout << "Payload: ";

    while (temp != nullptr){
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node **head, int iPayload){
    // Insere novo valor no começo da lista.
    
    Node *newNode = createNode(iPayload);

    // Se a lista já tiver algum elemento.
    if (*head != nullptr){
        newNode->ptrNext = (*head);
        newNode->ptrNext->ptrPrev = newNode;
        *head = newNode;
    }
    // Se não, newNode passa a ser nosso único elemento.
    else
        *head = newNode;

    return;
}

void insertEnd(Node **head, int iPayload){
    Node *newNode = createNode(iPayload);

    if (*head == nullptr){
        (*head) = newNode;
        return;
    }

    Node *temp = (*head);

    // Percorremos a lista até seu fim(ptrNext do ultimo nó é NULL)
    while (temp->ptrNext != nullptr)
        temp = temp->ptrNext;

    newNode->ptrPrev = temp; // newNode aponta para o fim da lista
    temp->ptrNext = newNode; // Antigo último elemento aponta para o novo nó
}

void insertAfter(Node* ptrLocation, int iPayload){
    if (ptrLocation == nullptr){
        cout << "Location é NULL" << endl;
        return;
    }

    Node* newNode = createNode(iPayload);
    // Corrigir nó a ser inserido.
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    // Corrigir ponto de inserção.
    ptrLocation->ptrNext = newNode;

    // Corrigir ponto após.
    if (newNode->ptrNext != nullptr)
        newNode->ptrNext->ptrPrev = newNode;

    return;
}

void deleteNode(Node** head, Node*ptrDelete){
    // Deleta um nó dado head da lista e o nó que deve ser deletado.

    if (head == nullptr || ptrDelete == nullptr){
        cout << "Não é possível fazer a operação de deleção." << endl;
        return;
    }

    // Se formos deletar o primeiro elemento.
    if (ptrDelete == (*head)){
        (*head)->ptrNext->ptrPrev = nullptr;
        (*head) = (*head)->ptrNext;

        free(ptrDelete);
    }
    // Se o elemento estiver no meio.
    else if (ptrDelete->ptrNext != nullptr){
        // Nós em volta do nó que será deletado apontam um para o outro.
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

        free(ptrDelete);
    }
    // Se o elemento estiver no final.
    else{
        ptrDelete->ptrPrev->ptrNext = nullptr;

        free(ptrDelete);
    }

    return;
}

// Exercício 1 elaborar a função válida void insertBefore(Node*, int).
// Exercício 2 elaborar a função válida Node* searchNodeByValue(Node*, int).
// Exercício 3 elaborar a função válida void deleteNodebyValue(Node**, int).