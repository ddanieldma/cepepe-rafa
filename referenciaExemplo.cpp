# include <iostream>

using std::cout;
using std::cin;
using std::endl;

void somaUm(int numero){
	numero++;
	return;
}

void somaUmRef(int& numero){
	numero++;
	return;
}

int main (){
	int numero;
	
	cout << "Digite um número: ";
	cin >> numero;

	somaUm(numero);
	cout << "Tentando somar 1 no numero normalmente: " << numero << endl;
	
	somaUmRef(numero);
	cout << "Tentando somar 1 no numero com referencia: " << numero << endl;
	
	return 0;
}