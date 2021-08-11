#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAVL.h" 


typedef struct Dado{
  char palavra_pt[26];
  char palavra_eng[26];
  int ocorrencias;
} Tipo_Dado;

struct NO{
    Tipo_Dado info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
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

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}



void emOrdem_ArvAVL(ArvAVL *raiz,const char *busca,const int acessos,int *marcador){
    if(raiz == NULL)
        return;
    struct NO* atual = *raiz;
    if(*raiz != NULL){
      if(strncmp(busca,(*raiz)->info.palavra_eng,strlen(busca)) <= 0)
          emOrdem_ArvAVL(&((*raiz)->esq),busca,acessos,marcador);
       if(strncmp(busca,(*raiz)->info.palavra_eng,strlen(busca)) == 0 && (*raiz)->info.ocorrencias >= acessos){
        printf("%s\n",(*raiz)->info.palavra_eng);
        }
        if(strncmp(busca,(*raiz)->info.palavra_eng,strlen(busca)) >= 0)
           emOrdem_ArvAVL(&((*raiz)->dir),busca,acessos,marcador);
    }
  }


void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        //printf("%s\n",(*raiz)->info.palavra);
    }
}



//=================================
void RotacaoLL(ArvAVL *A){//LL
    //printf("RotacaoLL\n");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    //printf("RotacaoRR\n");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, const char *pt_br,const char *eng, int cont){ //insere em ordem alfabetica
    int res;
    if(*raiz == NULL){//�rvore vazia ou n� folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;
        strcpy(novo->info.palavra_pt,pt_br);
        strcpy(novo->info.palavra_eng,eng);
        novo->info.ocorrencias = cont;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(strcmp(eng,(*raiz)->info.palavra_eng) < 0){
        if((res = insere_ArvAVL(&(atual->esq), pt_br,eng,cont)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(strcmp(eng,(*raiz)->esq->info.palavra_eng)<0){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(strcmp(eng,atual->info.palavra_eng) > 0){
            if((res = insere_ArvAVL(&(atual->dir), pt_br,eng,cont)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if(strcmp((*raiz)->dir->info.palavra_eng,eng) < 0){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            return 0;
        }
    }
    
    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}


void preOrdem_ArvAVL_traducao(ArvAVL *raiz,const char *busca){ //funcao para percorrer a arvore
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        if(strcmp((*raiz)->info.palavra_eng,busca) == 0){
          printf("%s\n",(*raiz)->info.palavra_pt);
          (*raiz)->info.ocorrencias++;
        }
        preOrdem_ArvAVL_traducao(&((*raiz)->esq),busca);
        preOrdem_ArvAVL_traducao(&((*raiz)->dir),busca);
    }
}

void preOrdem_ArvAVL_acessos(ArvAVL *raiz,const char *busca,const int acessos){ //funcao para percorrer a arvore
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        if(strncmp(busca,(*raiz)->info.palavra_eng,strlen(busca)) == 0 && acessos >= (*raiz)->info.ocorrencias){
          printf("%s\n",(*raiz)->info.palavra_eng);
        }
        preOrdem_ArvAVL_acessos(&((*raiz)->esq),busca,acessos);
        preOrdem_ArvAVL_acessos(&((*raiz)->dir),busca,acessos);
    }
}
/*void posOrdem_ArvAVL_cont(ArvAVL *raiz,int ocorrencias){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
      if((*raiz)->info.cont >= ocorrencias){
        printf("%s %d\n",(*raiz)->info.palavra,(*raiz)->info.cont);
      }
        posOrdem_ArvAVL_cont(&((*raiz)->esq),ocorrencias);
        posOrdem_ArvAVL_cont(&((*raiz)->dir),ocorrencias);
        
      
    }
}
*/



