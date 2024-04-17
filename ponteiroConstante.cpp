#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	int inteiro = 7;
	// Ponteiro constante para inteiro.
	int* const constPtr = &inteiro;
	int outroInteiro = 42;
	// ERRO: expression must be modifiable lvalue
	// constPtr = &outroInteiro;

	cout << "Endereço do inteiro: " << &inteiro << endl;
	cout << "Endereço do outroInteiro: " << &outroInteiro << endl;
	cout << "Endereço armazenado por constPtr: " << constPtr << endl;

	// Ponteiro para inteiro constante.
	const int* ptrConst = &inteiro;
	// ERRO: assignment of read-only value.
	// *ptrConst = 42;

	const int* const constPtrConst = &inteiro;
	// ERRO:
	// *constPtrConst = 42;
	// constPtrConst = &outroInteiro;

	return 0;
}