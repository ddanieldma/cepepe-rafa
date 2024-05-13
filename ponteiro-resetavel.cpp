#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
	int* ptrInt = nullptr;
	int inteiroUm = 7;
	int inteiroDois = 42;

	cout << "Inteiro um: " << inteiroUm << " Endereço inteiro um: " << &inteiroUm << endl;
	cout << "Inteiro Dois: " << inteiroDois << " Endereço inteiro Dois: " << &inteiroDois << endl;

	ptrInt = &inteiroUm;
	cout << "Pointer pra inteiro um: " << ptrInt << endl;
	ptrInt = &inteiroDois;
	cout << "Pointer pra inteiro dois: " << ptrInt << endl;
	
	int& iRef = inteiroUm;
	cout << "iRef com ponteiro um: " << iRef << endl;
	iRef++;
	cout << "iRef com ponteiro um++: " << iRef << endl;
	iRef = 666;
	cout << "iRef 666: " << iRef << endl;
	iRef = inteiroDois;
	cout << "iRef com ponteiro dois: " << iRef << endl;
	cout << "Endereço de iRef: " << &iRef << endl;
	// Estamos alterandoo valor do inteiro que foi colocado inicialmente na referência.
	cout << "Inteiro um: " << inteiroUm << endl;

	// ERRO: não é possível converter de int para int*
	// iRef = &inteiroDois;

	// Ponteiro é resetável e referência não:
	// O ponteiro é um tipo que armazena endereços de memória. A referência
	// funciona mais como um rótulo para um determinada variável: não é resetável
	// e todas as alterações mudam na verdade o valor salvo na memória. Mesmo quan
	// do tentamos usar o endereço da referência recebemos o endereço da variável
	// por ela referenciada.


	return 0;
}