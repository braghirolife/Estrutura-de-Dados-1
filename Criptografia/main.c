#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(void) {
  Lista *li; //declara lista de caracteres
  Lista *li2; //declara lista de caracteres chave
  int seletor; //seletor para o que se quer fazer
  char c; //caracteres que serao inseridos na lista
  li = cria_lista(); //lista criada
  li2 = cria_lista();
  int contador = 1,tamanho;
  scanf("%d ",&seletor); //escolha do seletor


  switch(seletor){ //casos do seletor
  
    case 1:
     while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_chave(li, 1);
      imprime_lista(li);
      libera_lista(li);
      return 0;
      break;

    case -1:
     while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_chave(li, -1);
      imprime_lista(li);
      //libera_lista(li);
      return 0;
      break;

    case 2:
     while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_chave(li,3);
      imprime_lista(li);
      //libera_lista(li);
      return 0;
      break;

    case -2:
     while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_chave(li,-3);
      imprime_lista(li);
      //libera_lista(li);
      return 0;
      break;

    case 3:
     while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_ciclica(li);
      imprime_lista(li);
      libera_lista(li);
      break;

    case -3:
     while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_ciclica_inverso(li);
      imprime_lista(li);
      break;

    case 4:
       while((c=getchar())!='\n'){ 
        insere_lista_final(li2,c); //loop para insercao da key no fim da lista
      }
      while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_ciclica_5key(li, li2);
      imprime_lista(li);
      libera_lista(li);
      libera_lista(li2);
      break;
      
    case -4:
      while((c=getchar())!='\n'){ 
        insere_lista_final(li2,c); //loop para insercao da key no fim da lista
      }
      while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      modif_lista_ciclica_5keyd(li, li2);
      imprime_lista(li);
      libera_lista(li);
      libera_lista(li2);
      break;
      

      case 5:
      while((c=getchar())!='\n'){ 
        insere_lista_final(li2,c); //loop para insercao da key no fim da lista
      }
      while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      while(contador<=tamanho_lista(li)/4){
      insere_caracter(li,contador);
      contador++;
      }
      modifica_inserido(li,li2);
      imprime_lista(li);
      libera_lista(li);
      libera_lista(li2);
      break;

      case -5:
      while((c=getchar())!='\n'){ 
        insere_lista_final(li2,c); //loop para insercao da key no fim da lista
      }
      while((c=getchar())!='\n' && c!=13){ 
        insere_lista_final(li, c); //loop para insercao de caracteres no fim da lista
      }
      remover_elemento(li);
      modif_lista_ciclica_5keyd(li, li2);
      imprime_lista(li);
      libera_lista(li);
      libera_lista(li2);
      break;
  }

  
}