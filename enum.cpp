#include <iostream>

using std::cout;
using std::endl;


void iguals();


int main(){
    enum Streaming {AppleTv, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, Max};

    Streaming streamingSubscription = AppleTv;

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

    enum Mes {JANEIRO, FEVEREIRO = 10, MARCO, ABRIL, MAIO};

    Mes mesProvas = JANEIRO;
    cout << "Janeiro: " << mesProvas << endl;
    mesProvas = MAIO;
    cout << "Maio: " << mesProvas << endl;

    // ta incompleto
    enum Semana {Segunda = 10, Terca = 1, Quarta = -3};

    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;

    return 0;
}


void iguals(){
    cout << "==============================================================" << endl;
}