#include <iostream>

using namespace std;


// criação de structs como tipo de variável
// mudando a forma como o c trata o tipo struct Livro
typedef struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
} Livro;

struct Ponto
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};

typedef struct Biblioteca
{
    string strNome;
    int iTamAcervo;
    Livro livros[1000];    
} Biblioteca;

void iguals();
void listaLivros(Biblioteca biblioteca);
void adicionaLivro(Biblioteca biblioteca, Livro novoLivro);


int main(){
    // criação de struct "on the fly"
    struct{
        int iIdade;
        string strNome;
    }   alunoEMAp1, alunoEMAp2;

    alunoEMAp1.iIdade = 18;
    alunoEMAp1.strNome = "Ana";
    
    alunoEMAp2.iIdade = 18;
    alunoEMAp2.strNome = "Ana";

    cout << "Idade do alunoEMAp1: " << alunoEMAp1.iIdade << endl;
    cout << "Nome do alunoEMAp1: " << alunoEMAp1.strNome << endl;
    
    cout << "Idade do alunoEMAp2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do alunoEMAp2: " << alunoEMAp2.strNome << endl;

    iguals();

    Livro livro1;
    livro1.strTitulo = "Outliers: The Story of Success";
    livro1.strAutor = "Malcolm Gladwell";
    livro1.iPublicacao = 2008;
    
    Livro livro2;
    livro2.strTitulo = "How to Grow Old";
    livro2.strAutor = "Marus Tullius Cicero";
    livro2.iPublicacao = -44;

    cout << "Titulo livro 1: " << livro1.strTitulo << endl;
    cout << "Autor livro 1: " << livro1.strAutor << endl;
    cout << "Ano de publicacao 1: " << livro1.iPublicacao << endl;
    
    cout << "Titulo livro 2: " << livro2.strTitulo << endl;
    cout << "Autor livro 2: " << livro2.strAutor << endl;
    cout << "Ano de publicacao 2: " << livro2.iPublicacao << endl;

    iguals();
    
    struct Ponto telaComputador[640][640];
    telaComputador[0][0].usRed = 0;
    telaComputador[0][0].usGreen = 0;
    telaComputador[0][0].usBlue = 0;

    iguals();

    Livro livro3;
    livro3.strTitulo = "1984";
    livro3.strAutor = "Geroge Orwell";
    livro3.iPublicacao = 1949;

    Biblioteca biblioteca;
    biblioteca.strNome = "BMHS";
    biblioteca.iTamAcervo = 0;

    biblioteca.livros[0] = livro1;
    biblioteca.iTamAcervo += 1;
    biblioteca.livros[1] = livro2;
    biblioteca.iTamAcervo += 1;
    biblioteca.livros[2] = livro3;
    biblioteca.iTamAcervo += 1;

    listaLivros(biblioteca);

    return 0;
}

void iguals(){
    cout << "==========================================" << endl;
}

// dever de casa: verificar tamanho vazia
void listaLivros(Biblioteca biblioteca){
    cout << "\nLivros do acervo da " << biblioteca.strNome << "\n\n" << endl;
    
    for (int i = 0; i < biblioteca.iTamAcervo; i++){
        cout << "Titulo " << i << ": " << biblioteca.livros[i].strTitulo << " por " << biblioteca.livros[i].strAutor << endl;
        cout << "Publicado em: " << biblioteca.livros[i].iPublicacao << endl;
    }
}

// dever de casa: verificar se está completa
void adicionaLivro (Biblioteca biblioteca, Livro novoLivro){
    biblioteca.livros[biblioteca.iTamAcervo] = novoLivro;
    biblioteca.iTamAcervo += 1;
}