#include <iostream>

using namespace std;

void iguals();

int main(){
    enum Streaming {AppleTv, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, Max};

    Streaming streamingSubscription = CrunchyRoll;

    switch (streamingSubscription){
        case AppleTv:
            cout << "Nunca usei... não tenho recursos para adquirir [" << streamingSubscription << "]" << endl;
        break;

        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
        break;

        default:
            cout << "NADA" << endl;
    }
    
    iguals();

    enum Mes {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};

    Mes mesProvas = MAIO;
    cout << mesProvas << endl;

    // ta incompleto
    enum Semana {Segunda, Terca, Quarta, Quinta, Sexta, Sabado, Domingo};

    return 0;
}

void iguals(){
    cout << "==============================================" << endl;
}