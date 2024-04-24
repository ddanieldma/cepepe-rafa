// Não tem um jeito bom de retornar um array e iterar por ele em c++ sem
// o uso de estruturas específicas, como o std::vector ou std:array;ggg

#include <iostream>

using namespace std;


int* retornaArray(){
	int* array = new int[10];

	array[0] = 10;
	array[1] = 20;

	return array;
}


int main(){
	int* array = retornaArray();
	
	cout << "Elemento [" << 0 << "]: " << array[0] << endl;
	cout << "Elemento [" << 1 << "]: " << array[1] << endl;

	cout << "Tamanho do array: " << sizeof(array)/sizeof(int) << endl;

	return 0;
}