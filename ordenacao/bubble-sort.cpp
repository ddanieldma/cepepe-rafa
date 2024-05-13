#include <iostream>
#include <chrono>
// Lista duplamente encadeada
#include "doubly-linked-list.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;


void iguals();
void swapValue(int&, int&);
void swapValueDLL(int&, int&);
void printArray(int[], int);
void bubbleSort(int[], int);
void bubbleSortDLL(int[], int);
void optimizedBubbleSort(int[], int);
Node * createList(int);


int main(){
    Node* head = createList(100);
    displayList(head);
    
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 11, 10, 13};
    int iLength = sizeof(arriNumbers)/sizeof(arriNumbers[0]);

    cout << "Array original: " << endl;
    printArray(arriNumbers, iLength);
    iguals();

    // Há um pequeno erro nesse clock, que se torna irrelevante com execuções para
    // arrays muito grandes;
    auto timeStart = high_resolution_clock::now();
    bubbleSort(arriNumbers, iLength);
    auto timeStop = high_resolution_clock::now();

    cout << "Array ordenado: " << endl;
    printArray(arriNumbers, iLength);

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;

    return 0;
}


void iguals(){
    cout << "===============================" << endl;
}

void swapValue(int& iValor1, int& iValor2){
    int iTemp = iValor1;
    iValor1 = iValor2;
    iValor2 = iTemp;
}

void swapValueDLL(Node* ptr1, Node* ptr2){
    int iTemp = ptr1->iPayload;
    ptr1->iPayload = ptr2->iPayload;
    ptr2->iPayload = iTemp;
}

void printArray(int arriNumbers[], int iLength){
    for (int i = 0; i < iLength; i ++)
        cout << arriNumbers[i] << " ";
    cout << endl;
}

void bubbleSort(int arriNumbers[], int iLength){
    for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++)
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
}

void optimizedBubbleSort(int arriNumbers[], int iLength){
    bool bUnordered = false;
    
    for (int iOuterLoop = 0; iOuterLoop < iLength; iOuterLoop++){
        bUnordered = false;

        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++){
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1]){
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]);
                bUnordered = true;
            }
        }

        if (!bUnordered) break;
    }
}

Node* createList(int iNumElements){
    Node *head = nullptr;
    srand(13);
    
    for (int i = 0; i < iNumElements; i++){
        int iRandom = rand() % 100;
        insertEnd(&head, iRandom);
    }
    
    return head;
}