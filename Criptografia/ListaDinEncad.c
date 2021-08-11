#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    char dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, char dados){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = dados;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere início
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, char dados){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = dados;
    no->prox = (*li);
    *li = no;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int imprime_lista(Lista* li){
  if(li == NULL)
    return 0;
  if((*li) == NULL)
    return 0;
  Elem *no = (Elem*) malloc(sizeof(Elem));
  no = *li;
  while(no->prox != NULL){
    printf("%c",no->dados);
    no = no->prox;
  }
  printf("%c",no->dados);
  return 1; 
}

int modif_lista_chave(Lista *li, int key){
  if(li == NULL){
    return 0;
  }
  if(*li == NULL){
    return 0;
  }
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  no = *li;
  while(no->prox != NULL){
    no->dados = no->dados + key;
    no = no->prox;
  }
  no->dados = no->dados + key;
  return 1;
}

int modif_lista_ciclica(Lista *li){
  if(li == NULL){
    return 0;
  }
  if(*li == NULL){
    return 0;
  }
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  int i = 1;
  no = *li;
  while(no->prox != NULL){
    no->dados = no->dados + i;
    no = no->prox;
    i++;
    if(i == 4){
      i = 1;
    }
  }
  no->dados = no->dados + i;
  return 1;
}

int modif_lista_ciclica_inverso(Lista *li){
  if(li == NULL){
    return 0;
  }
  if(*li == NULL){
    return 0;
  }
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  int i = -1;
  no = *li;
  while(no->prox != NULL){
    no->dados = no->dados + i;
    no = no->prox;
    i--;
    if(i == -4){
      i = -1;
    }
  }
  no->dados = no->dados + i;
  return 1;
}

int modif_lista_ciclica_5key(Lista *li, Lista *li2){
  int i = 0;
  if(li == NULL){
    return 0;
  }
  if(*li == NULL){
    return 0;
  }
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  Elem *no2 = (Elem *) malloc(sizeof(Elem));
  if(no2 == NULL){
    return 0;
  }
  no = *li;
  no2 = *li2;
  while(no->prox != NULL){
    no->dados = no->dados + no2->dados - 48;
    no = no->prox;
    no2 = no2->prox;
    i++;
    if(i==5){
      no2 = *li2;
      i = 0;
    }
  }
  no->dados = no->dados + no2->dados - 48;
  return 1;
  

}

int modif_lista_ciclica_5keyd(Lista *li, Lista *li2){
  int i = 0;
  if(li == NULL){
    return 0;
  }
  if(*li == NULL){
    return 0;
  }
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  Elem *no2 = (Elem *) malloc(sizeof(Elem));
  if(no2 == NULL){
    return 0;
  }
  no = *li;
  no2 = *li2;
  while(no->prox != NULL){
    no->dados = no->dados - no2->dados + 48;
    no = no->prox;
    no2 = no2->prox;
    i++;
    if(i==5){
      no2 = *li2;
      i = 0;
    }
  }
  no->dados = no->dados - no2->dados + 48;
  return 1;
}

int insere_caracter(Lista *li, int contador){
  int i = 1;
  if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = '*';
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 0;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && i<4*contador){
            ant = atual;
            atual = atual->prox;
            i++;
        }
          if(atual!=*li){
            no->prox = atual;
            ant->prox = no;
          }
        }
        return 1;
    }

int modifica_inserido(Lista *li, Lista *li2){
  int i = 0,cont = 0;
  if(li == NULL){
    return 0;
  }
  if(*li == NULL){
    return 0;
  }
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  Elem *no2 = (Elem *) malloc(sizeof(Elem));
  if(no2 == NULL){
    return 0;
  }
  no = *li;
  no2 = *li2;
  while(no->prox != NULL){
    if(cont<3){
    no->dados = no->dados + no2->dados - 48;
    no2 = no2->prox;
    cont++;
    i++;
    }
    else{
      cont = 0;
    }
    no = no->prox;
    if(i==5){
      no2 = *li2;
      i = 0;
    }
  }
  if(cont!=3)
  no->dados = no->dados + no2->dados - 48;
  return 1;
}


int remover_elemento(Lista *li){
  if( li == NULL)
    return 0;
  if( *li == NULL)
    return 0;
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL)
    return 0;
  Elem *ant = *li;
  no = *li;
  while(no->prox != NULL){
    ant = no;
    no = no->prox;
    if(no->dados == '*'){
      ant->prox = no->prox;
      free(no);
    }
  }
  return 1;
}



