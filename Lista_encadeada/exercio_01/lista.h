#ifndef LISTA_H      //Se não for definidada a LISTA_H
#define LISTA_H      //Defina a LISTA_H

/*estrutura do n�*/
typedef struct no {     // foi definida uma estrutura do tipo no
    int valor ;          //espaço para armazenar os dados, é do tipo inteiro
    struct no * proximo; // Esse no aponta para o proximo no
} No;

typedef struct lista {   // Foi definido uma estrutura do tipo lista
    No * primeiro;      // O no aponta para o primeiro no da lista
} Lista;

void listaInit(Lista *lista);  // Cabeçalho das funçoes que foram implementadas dentro do arquivo lista.cpp
void escreveLista(Lista *lista);
int listaIsEmpty(Lista *lista);
void listaInsere(Lista *lista, int n);
void listaRemove(Lista *lista, int n);

#endif // LISTA_H // final   // fechamento do ifndef
