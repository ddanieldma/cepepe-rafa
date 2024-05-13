#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;


// Forma ruim de declarar uma funçõo que será usada em vários tipos.
/*
int MAX(int x, int y){
    return x > y ? x : y;
}

float MAX(float x, float y){
    return x > y ? x : y;
}
*/

// Forma boa: usando template.
template<typename T>
T MAX(T x, T y){
    // Printando nome do tipo.
    cout << typeid(T).name() << endl;
    // Chamamos o método do objeto typeid que imprime o tipo do objeto.
    return x > y ? x : y;
}
// Isso faz com que o compilador crie automaticamente, em tempo de compilação,
// uma função específica pra cada tipo, desde que, quando a função é chamada,
// ela obedeça o template específico.

// Instanciação explícita.
// Se usamos a forma acima, não é criada uma função no assembly que é utilizada,
// ou seja, o compilador fica constantemente recriando a função. Para que a função
// seja de fato criada, usamos instanciação explícita.

// Explicitando instanciação da função para caracteres.
template char MAX(char x, char y);


// Especialização Explícita
// Como podemos tratar um tipo de forma diferente de outro.
template<> const char* MAX<const char*>(const char* x, const char* y){
    return strcmp(x, y) > 0 ? x : y;
}


template<typename T>
T somaElementos(T* arr, int size){
    T soma;
    
    for (int i = 0; i < size; i++){
        soma += arr[i];
    }

    return soma;
}


int main(){
    // Com inteiros.
    // auto resultado_1 = MAX(13, 42);
    auto resultado_1 = MAX(static_cast<float>(13), 42.11f);
    // Templates são um caso em que não há tanto problema assim utilizar auto.
    cout << resultado_1 << endl;
    iguais();


    // Com float.
    // auto resultado_2 = MAX(13.7f, 42.11f);
    auto resultado_2 = MAX<double>(13, 42.11f);
    // Pedido do programador para instanciar o template com o tipo específico.
    cout << resultado_2 << endl;
    iguais();


    const char* b {"B"};
    const char* a {"A"};

    cout << "Endereço de A: " << &a << endl;
    cout << "Endereço de B: " << &b << endl;
    
    // Aqui utilizamos a versão especializada para caracteres do template.
    auto resultado_3 = MAX(a, b);
    cout << resultado_3 << endl;
    iguais();


    int arr[] = {13, 10, 42, 7, 3};
    int soma = somaElementos(arr, 5);
    cout << "Soma: " << soma << endl;


    return 0;
}