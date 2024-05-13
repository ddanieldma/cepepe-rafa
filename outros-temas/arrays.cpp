#include <iostream>

using namespace std;

int main (){
    // criando um array de inteiros todo inicializado com 0's
    int x[100] = {0};

    cout << "x[0] = " << x[0] << ", endereco: " << &x[0] << endl;
    cout << "x[1] = " << x[1] << ", endereco: " << &x[1] << endl;
    cout << "x[99] = " << x[99] << ", endereco: " << &x[99] << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < 100; i++){
        cout<<x[i]<<"\n";
    }

    return 0;
}
