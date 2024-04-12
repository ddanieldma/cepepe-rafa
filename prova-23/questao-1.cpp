// O arquivo linked-list-aluno.h tem a mesma implementação de lista encadeada
// com pequenas mudanças. Portanto, se esse arquivo e o linked-list.h
// forem incluídos no mesmo arquivo, haverá conflito.

#include <iostream>
#include "linked-list-aluno.h"
#include "utils.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(){
	LinkedList* listaAlunos = createLinkedList();

	addElement(listaAlunos, 231708001);
	addElement(listaAlunos, 231708002);
	addElement(listaAlunos, 231708003);
	addElement(listaAlunos, 231708004);
	
	showElements(listaAlunos);

	cout << "Removendo aluno" << endl;

	removeElement(listaAlunos, 231708003);
	showElements(listaAlunos);

	return 0;
}