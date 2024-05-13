#include <iostream>

using namespace std;

// Estrutura de criação de namespace.
/*
namespace [identifier]
{
    [entities]
}

*/

namespace FGV{
    int iValor = 666;

    void mockFunction(){
        cout << "Namesapce FGV" << endl;
    }

    // Namespaces aninhados.
    namespace EMAp{
    int iValor = 42;

    void mockFunction(){
        cout << "Namespace EMAp" << endl;
    }
}
}

int iValor = 1;


// Aqui definimos que sempre que mockFunction for chamada estamos querendo a função do namespace 
// EMAp.
// using EMAp::mockFunction;
// Ou então:
// using namespace EMAp;


// Driver code.
int main(){
    // Quando queremos acessar o namespace global é só não especificar nenhum namespace.
    int iValor = 10;

    cout << "Valor de iValor: " << iValor << endl; // 10

    // Namespace local:
    cout << "Valor de ::iValor: " << ::iValor << endl; // 1

    cout << "Valor de FGV::iValor: " << FGV::iValor << endl; // 666
    
    FGV::mockFunction(); // Namespace FGV
    FGV::EMAp::mockFunction(); // Namespace EMAp

    return 0;
}