#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h" 

struct NO{
    char info[24];
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int insere_ArvBin(ArvBin* raiz, char *caracter, int i){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    strcpy(novo->info,caracter);
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(strcmp(caracter,atual->info) == 0){
                free(novo);
                return 0;
            }
            if(i == 1)
                atual = atual->esq;
            if(i == 2){
                atual = atual->dir;
            }
        }
        if(i == 1)
            ant->esq = novo;
        if(i == 2){
            ant->dir = novo;
        }
       
    }
    return 1;
}






void preOrdem_ArvBin(ArvBin *raiz,int *contador_nodos, int* contador_sem_filhos)
{ 
    int contador_ed = 0;
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s ",(*raiz)->info);
        if((*raiz)->esq!=NULL){
        contador_ed++;
        }
        if((*raiz)->dir!=NULL){
        contador_ed++;
        }
        printf("%d ",contador_ed);
        if((*raiz)->esq!=NULL){
          printf("E");
        }
        if((*raiz)->dir!=NULL){
          printf("D");
        }
        if((*raiz)->dir == NULL && (*raiz)->esq == NULL)
          printf("F");
        printf("\n");
        (*contador_nodos)++;
        if(contador_ed == 0){
          (*contador_sem_filhos)++;
        }
        preOrdem_ArvBin(&((*raiz)->esq),contador_nodos,contador_sem_filhos);
        preOrdem_ArvBin(&((*raiz)->dir),contador_nodos,contador_sem_filhos);
    }
}



// Funcoes Adicionais de Arvore

void Insere_Procura_preOrdem_ArvBin(ArvBin *raiz, char *aux,char *aux2,char *aux3)
{
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL)
    { 
        if (strcmp(aux,(*raiz)->info) == 0 )
        {
            struct NO* info1;
            info1 = (struct NO*) malloc(sizeof(struct NO));
            strcpy(info1->info,aux2);
            info1->dir = NULL;
            info1->esq = NULL;
            struct NO* info2;
            info2 = (struct NO*) malloc(sizeof(struct NO));
            strcpy(info2->info,aux3);
            info2->dir = NULL;
            info2->esq = NULL;
            if(strcmp(aux2,"X") == 0)
            (*raiz)->esq = NULL;
            else
            (*raiz)->esq = info1;
            if(strcmp(aux3,"X") == 0)
            (*raiz)->dir = NULL;
            else
            (*raiz)->dir = info2;
        }
        Insere_Procura_preOrdem_ArvBin(&((*raiz)->esq),aux,aux2,aux3);
        Insere_Procura_preOrdem_ArvBin(&((*raiz)->dir),aux,aux2,aux3);
    }
}

