
#include <iostream>    //Biblioteca de instruçoes
#include "lista.h"   // arquivo de cabeçalho criado pelo "programador"

void listaInit(Lista *lista)
{
    /*INICIA A LISTA VAZIA*/
    lista->primeiro = nullptr; // a lista sera inicializada como vazia
}

void escreveLista(Lista *lista) { //funçao para escrever a lista. Lista aponta para a lista que esta vazia
    if (listaIsEmpty(lista) ) { // verifica se a lista possui elementos, se a lista não estiver vazia,reliza uma busca para pelo elemento indicado.
        std::cout << "Lista Vazia!\n"; // imprimi uma mensagem para o usuario.
        return; // não retorna nada
    }

    No *pNo; //No aponta para pNo
    for( pNo = lista->primeiro; pNo != nullptr; pNo = pNo->proximo){ // Laço de repetição. Se pNo for diferente de nullptr,caso seja ira para o proximo no,ou seja  Verifica se a lista esta vazia
        std::cout << pNo->valor << "\t"; //imprimi tabulação(espaçamento) ou seja é similar ao tab do teclado
    }
    std::cout << "\n";// pula uma linha e similar ao aperta a tecla enter,que vai para uma proxima linha
}

int listaIsEmpty(Lista *lista)//
{
    if(lista->primeiro == nullptr) {  // Se a lista for vazia ,ela ira retorna verdadiro
        return true;
    } else {                       //   senão nao estiver vazia irá retorna falso.
        return false;
    }
}

void listaInsere(Lista *lista, int n) //função que  insere um elemento na lista, com 2 valores como parâmetro a lista que aponta para a lista e um valor do tipo inteiro
{
    /*ALOCA MEM�RIA PARA O NOVO N� (PONTEIRO)*/
    No *novo = new No; //no aponta para um novo no
    novo->valor = n; // e esse novo valor aponta para o valor que recebe n.
    novo->proximo = nullptr; // E esse novo aponta para o proximo  no  da lista que recebe nullptr (vazio)

    /*ACHA O LOCAL PARA INSER��O (ORDENADA)*/
    No *pAnterior, *pAtual;  // No aponta para pAnterior da lista que aponta para o pAtual da lista.
    pAnterior = nullptr;  // o pAnterior rebebe nada
    pAtual = lista->primeiro; // o valor atual da lista ponta para o primeiro da lista..

    while ( (pAtual != nullptr) && (pAtual->valor < n) ) {
        pAnterior = pAtual;
        pAtual =pAtual->proximo;
    }

    /*INSERE NOVO N� NO COME�O*/
    if( pAtual == lista->primeiro ) {
        novo->proximo = pAtual;
        lista->primeiro = novo;
    } else {
        /*INSERE NOVO N� ENTRE pAnterior E pAtual*/
        novo->proximo = pAtual;
        pAnterior->proximo = novo;
    }
}

void listaRemove(Lista *lista, int n) // função  recebe  parmetros  um ponteiro para a lista e o valor a ser removido  da lista
{
    /*PROCURA O ELEMENTO*/
    No *pAnterior, *pAtual;
    pAnterior = nullptr;       // pAnterior recebe nullptr(vazio), porque nao tem um elemento antes dele
    pAtual = lista->primeiro; // e o pA tual recebe o primeiro elemento da lista .

    while ( (pAtual != nullptr) && (pAtual->valor != n) ) { // quando Atual for diferente de nullptr(vazio) e pAtual aponta para  o valor que recebe um elemento diferente de n.
        pAnterior = pAtual;    //pAnterior recebe o elemento pAtual da lista .
        pAtual =pAtual->proximo;// pAtual recebe o elemento atual que é apontado para o proximo elemento da lista
    }

    /*VERIFICA SE O ELEMENTO EXISTE NA LISTA*/
    if ( pAtual == nullptr ) {     // Se o pAtual for igual a nullptr(vazio) ira aparecer uma mensagem para o usuario que o "elemento não existe na lista."
        std::cout << "Elemento nao existe na lista\n"; // mensagem na tela para o usuario.
    } else {
        if ( pAtual == lista->primeiro) {/*REMOVE DO INICIO*/  // Se o pAtual for igual  a lista que aponta para o primeiro elemento da lista.
            lista->primeiro = pAtual->proximo; // lista aponta para o primeiro elemento da lista, que recebe o elemento atual quje aponta para o priximo elemento.
        } else { /*REMOVE DO MEIO DA LISTA*/
            pAnterior->proximo = pAtual->proximo; // se o elemento  não for igual ele adiciona um proximo no a lista.
        }
        delete(pAtual); //libera mem�ria // libera memoria alocada no endereço indicado por pAtual.
    }
}
