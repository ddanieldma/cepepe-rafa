// Código base para usar em todas as auls de ordenação.

#include <iostream>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;


void iguals();
void swapValue(int&, int&);
void printArray(int[], int);
void Sort(int[], int);


int main(){
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 11, 10, 13};
    int iLength = sizeof(arriNumbers)/sizeof(arriNumbers[0]);

    cout << "Array original: " << endl;
    printArray(arriNumbers, iLength);
    iguals();

    // Há um pequeno erro nesse clock, que se torna irrelevante com execuções para
    // arrays muito grandes;
    auto timeStart = high_resolution_clock::now();
    Sort(arriNumbers, iLength);
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

void printArray(int arriNumbers[], int iLength){
    for (int i = 0; i < iLength; i ++)
        cout << arriNumbers[i] << " ";
    cout << endl;
}

void Sort(int arriNumbers[], int iLength){
    cout << "Rodei" << endl;
} 