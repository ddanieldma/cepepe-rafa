#include <iostream>
#include "utils.h"

using namespace std;

int square(int*);
int somaVetor(const int[], const size_t);

int main(){
    int* ptrInt = nullptr;

    cout << "PTR: "  << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    iguais();

    int iNumMagico = 42;
    cout << "Endereço de iNumMagico" << &iNumMagico << endl;

    ptrInt = &iNumMagico;
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;
    cout << "Endereço de PTR: " << &ptrInt << endl;     
    iguais();

    int iNum1 = 42;
    int iNum2 = 666;

    // criando ponteiro constante, onde o endereço não pode ser alterado mas
    // o valor nele armazenado sim
    int* const ptrNum1 = &iNum1;
    *ptrNum1 = 7;
    //ERRO
    // ptrNum1 = &iNum2;

    // ponteiro para inteiro constante
    const int* ptrNum2 = &iNum1;
    ptrNum2 = &iNum2;
    // ERRO
    // *ptrNum2 = 7
    
    iguais();
    
    // função quadrado que usa ponteiro funcionando como se fosse referência
    cout << "Quadrado: " << square(&iNum1) << endl;
    
    iguais();

    int arriValores[5] = {0, 7, 13, 42, 666};
    cout << "Endereço de [0]: " << arriValores << endl;

    int* ptrArrayValores1 = arriValores;
    cout << "PTR: " << ptrArrayValores1 << endl;
    
    int* ptrArrayValores2 = &arriValores[0];
    cout << "PTR: " << ptrArrayValores2 << endl;

    iguais();

    // porque, em c++, vetor é ponteiro e ponteiro é vetor
    cout << "Valor de ptrArrayValores[0]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores[0]:" << ptrArrayValores1 << endl;

    // a aritmética de ponteiros funciona de acordo com o tamanho do dado a que o ponteiro
    // se refere
    ptrArrayValores1++;
    cout << "Valor de ptrArrayValores[1]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores[1]:" << ptrArrayValores1 << endl;
    
    ptrArrayValores1 += 3;
    cout << "Valor de ptrArrayValores[4]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores[4]:" << ptrArrayValores1 << endl;
    
    ptrArrayValores1 -= 2;
    cout << "Valor de ptrArrayValores[2]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores[2]:" << ptrArrayValores1 << endl;

    iguais();

    cout << "Subtração de ponteiros: " << ptrArrayValores1 - ptrArrayValores2 << endl;
    // distancia entre dois ponteiros

    return 0;
}

int square(int* ptrNum){
    return *ptrNum * *ptrNum;
}

int somaVetor(const int* valores, const size_t tamVetor){
    return -1;
}