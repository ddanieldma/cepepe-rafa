#include <iostream>

using namespace std;

void troca(int& iValor1, int& iValor2);

int& trocaElemento(int iElemento, int arriVetor[]);

void iguals();

int main(){
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;

    cout << "Valor da string: " << strNome << " Endereço da String: " << &strNome <<endl;
    cout << "Valor do Inteiro: " << iValor << " Endereço do Inteiro: " << &iValor <<endl;
    iguals();

    string& strrefNome = strNome;
    int& irefValor = iValor;

    cout << "Valor Ref.string: " << strrefNome << " Endereço da Ref.String: " << &strrefNome <<endl;
    cout << "Valor Ref.Inteiro: " << irefValor << " Endereço do Ref.Inteiro: " << &irefValor <<endl;
    iguals();

    strrefNome = "C. Camacho";
    irefValor = iValorFuturo;

    cout << "Valor da string: " << strNome << " Endereço da String: " << &strNome <<endl;
    cout << "Valor do Inteiro: " << iValor << " Endereço do Inteiro: " << &iValor <<endl;
    iguals();
    
    int iValor1 = 2;
    int iValor2 = 12;

    cout << "Valor 1: " << iValor1 << endl;
    cout << "Valor 2: " << iValor2 << endl;

    // o c++ automaticamente cria um referenciamento das variáveis para que seja
    // possível alterar diretamente o valor na memória, não uma cópia dele
    troca(iValor1, iValor2);

    cout << "Valor 1: " << iValor1 << endl;
    cout << "Valor 2: " << iValor2 << endl;

    iguals();

    int arriVetor[5] = {0, 7, 13, 42 ,666};
    cout<<"Vetor: " << endl;
    for (int i = 0; i < 5; i++){
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    trocaElemento(4, arriVetor) = 111;
    
    cout << "-----" << endl;

    cout<<"Vetor: " << endl;
    for (int i = 0; i < 5; i++){
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    return 0;
}

void troca(int& iValor1, int& iValor2){
    int iTemp = iValor1;
    iValor1 = iValor2;
    iValor2 = iTemp;
}

// aqui usamos a referência para mudar diretamente o valor na posição requerida do vetor.
// a função retorna uma referência para a posição que pedimos do vetor e, ao atribuirmos
// um valor a esse retorno, estamos alterando diretamente o valor naquela posição do vetor.
int& trocaElemento(int iElemento, int arriVetor[]){
    return arriVetor[iElemento];
}

void iguals(){
    cout << "==============================================" << endl;
}