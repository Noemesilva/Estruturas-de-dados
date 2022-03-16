#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


 typedef struct dadoNo{
 int id;
 }DadoNo;

typedef struct no{
    DadoNo dado;
    struct no* novo;
}No;

typedef struct lista{
int tamanho;
No* CabecaLista;
}Lista;

Lista* criarLista();
void insereNaLista(Lista*lista,DadoNo dado);
void imprimirLista(Lista* lista);
void removerDaLista(Lista* lista);
bool listaVazia(Lista* lista);

Lista* criarLista(){
    Lista* lista=(Lista*)malloc(sizeof(Lista));

    lista-> tamanho=5;
    lista->CabecaLista=NULL;
    return lista;
}
void insereNaLista(Lista* lista,DadoNo dado){
    No* no=(No*)malloc(sizeof(No));
    no->dado=dado;
    no->novo=lista->CabecaLista;
    lista->CabecaLista= no;
    lista-> tamanho++;
}
void imprimirLista(Lista* lista){

   if(listaVazia(lista)){
        printf("Lista vazia!");
   return;

}

   No* p=lista ->CabecaLista;

   while(p!=NULL){
    printf("%d ",p->dado.id);
    p=p->novo;
   }
   printf("\n");
}

bool listaVazia(Lista* lista){
    return(lista->tamanho==0);
}
void removerDaLista(Lista* lista){
    if(!listaVazia(lista)){
        No* p=lista->CabecaLista;

        lista->CabecaLista=p->novo;
        free(p);
        lista->tamanho--;
}
    }

int main()
{
  Lista* lista=criarLista();
   printf("tamanho da lista: %d \n",lista->tamanho);
   Lista* a=criarLista();
   DadoNo dado;

   dado.id=1;
   insereNaLista(a,dado);

    dado.id=2;
    insereNaLista(a,dado);

    dado.id=3;
    insereNaLista(a,dado);

    dado.id=4;
    insereNaLista(a,dado);

    dado.id=5;
    insereNaLista(a,dado);

    dado.id=6;
    insereNaLista(a,dado);

    imprimirLista(a);
    removerDaLista(a);
    imprimirLista(a);



   //printf("valor inicial da lista: %d\nproximo valor da lista: %d",a->CabecaLista->dado.id, a->CabecaLista->novo->dado.id);


}
