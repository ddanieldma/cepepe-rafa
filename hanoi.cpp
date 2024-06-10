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
    unsigned int uiNumber = 1;

    cout << "Digite o numero de discos: ";
    cin >> uiNumber;
    solveHanoi(uiNumber, 'A', 'B', 'C');

    return 0;
}

void moveDisk(char fromRod, char toRod, unsigned int Disk){
    
}