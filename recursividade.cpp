#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;


unsigned long long iterativeFibonacci(unsigned int);
unsigned long long recursiveFibonacci(unsigned int);

int main(){
    // for (int i = 0; i <= 10; i++){
    //     cout << i << "-esimo termo da sequencia de Fibonacci(iterativo): " << iterativeFibonacci(i) << endl;
    //     cout << i << "-esimo termo da sequencia de Fibonacci(recursivo): " << recursiveFibonacci(i) << endl;
    // }

    // Qual será o mais eficiente?
    unsigned int uliNumberTests = 100000;
    unsigned int uiNumberTries = 10;
    
    cout << "Testes iterativos:" << endl;
    for (int j = 0; j < uiNumberTries; j++){
        auto timeStart = high_resolution_clock::now();
        for (int i = 0;i < uliNumberTests; i++){
            iterativeFibonacci(i);
        }
        auto timeEnd = high_resolution_clock::now();
    
        auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
        unsigned long int iCountTimeTaken = timeTaken.count();
        
        cout << "Tempo tomado pela " << j << "-ésima iteracao: " << iCountTimeTaken << endl;
    }
    
    cout << "Testes recursivos:" << endl;
    for (int j = 0; j < uiNumberTries; j++){
        auto timeStart = high_resolution_clock::now();
        for (int i = 0;i < uliNumberTests; i++){
            iterativeFibonacci(i);
        }
        auto timeEnd = high_resolution_clock::now();
    
        auto timeTaken = duration_cast<nanoseconds>(timeEnd - timeStart);
        unsigned long int iCountTimeTaken = timeTaken.count();
        
        cout << "Tempo tomado pela " << j << "-ésima iteracao: " << iCountTimeTaken << endl;
    }

    // No pior dosc

    return 0;
}

unsigned long long iterativeFibonacci(unsigned int uiNumber){
    if (uiNumber == 0) return 0;
    if (uiNumber == 1) return 1;

    unsigned long long ullPrevious = 0;
    unsigned long long ullCurrent = 1;
    unsigned long long ullNext = 1;

    for (int i = 2; i <= uiNumber; i++){
        ullNext = ullCurrent + ullPrevious;
        ullPrevious = ullCurrent;
        ullCurrent = ullNext;
    }

    return ullNext;
}

unsigned long long recursiveFibonacci(unsigned int uiNumber){
    if (uiNumber == 0) return 0;
    else if (uiNumber == 1) return 1;
    else{
        return recursiveFibonacci(uiNumber - 1) + recursiveFibonacci(uiNumber - 2);
    }
}