#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAXTAM 100


typedef struct
{
    int Item[MAXTAM];
    int Topo;
} TPilha;

void TPilhaInicia(TPilha *p)
{
    p->Topo=-1;
}
int TPIlhaVazia(TPilha *p)
{
    if(p->Topo==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int TPilhaCheia(TPilha *p)
{
    if(p->Topo==MAXTAM-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void TPilhaInsere(TPilha *p,int x)
{
    if(TPilhaCheia(p)==1)
    {
        printf("ERRO: Pilha a pilha está cheia");
    }
    else
    {
        p->Topo++;
        p->Item[p->Topo] = x;
    }
}
int TPilhaRemove(TPilha *p)
{
    int auxiliar;
    if(TPIlhaVazia(p)==1)
    {
        printf("ERRO: pilha vazia!");
    }
    else
    {
        auxiliar=p->Item[p->Topo];
        p->Topo--;
        return auxiliar;
    }

}

int main()
{
    TPilha *p=(TPilha*)malloc(sizeof(TPilha));
    TPilhaInicia(p);

    TPilhaInsere(p,2);
    TPilhaInsere(p,3);
    TPilhaInsere(p,4);

    int auxiliar;

    auxiliar=TPilhaRemove(p);
    printf("\n O número removido é o : %d\n", auxiliar,setlocale(LC_ALL,""));



    return 0;
}
