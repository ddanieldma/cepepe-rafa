#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

void moveDisk(char, char, unsigned int);
void solveHanoi(unsigned int, char, char, char);

int main(){
    unsigned int uiNumberOfDisks = 1;

    cout << "Digite o numero de discos: ";
    cin >> uiNumberOfDisks;
    solveHanoi(uiNumberOfDisks, 'A', 'C', 'B');

    return 0;
}

void moveDisk(char fromRod, char toRod, unsigned int uiDisk){
    cout << "Move o disco " << uiDisk << " de " << fromRod << " para " << toRod << endl;
}

void solveHanoi(unsigned int uiNumberOfDisks, char fromRod, char toRod, char auxRod){
    if(uiNumberOfDisks == 1){
        moveDisk(fromRod, toRod, 1);
        return;
    }

    solveHanoi(uiNumberOfDisks - 1, fromRod, auxRod, toRod);
    moveDisk(fromRod, toRod, uiNumberOfDisks);
    solveHanoi(uiNumberOfDisks - 1, auxRod, toRod, fromRod);
}