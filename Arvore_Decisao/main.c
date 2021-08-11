#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArvoreBinaria.h"



int main()
{
ArvBin* raiz = cria_ArvBin();
char arvore[90], aux1[24],aux2[24],aux3[24];
int i = 0, j = 0, flag_primeira_insercao = 0;
int contador_nodos = 0, contador_sem_filho = 0;
scanf("%s %s %s",aux1,aux2,aux3);
while((strcmp(aux1,"X") !=0 || strcmp(aux2,"X") != 0 || strcmp(aux3,"X") != 0 )){
  if(flag_primeira_insercao == 0){
  insere_ArvBin(raiz, aux1, 1);
  insere_ArvBin(raiz, aux2, 1);
  insere_ArvBin(raiz, aux3, 2);
  strcpy(aux1," ");
  strcpy(aux2," ");
  strcpy(aux3," ");
  }
  if(flag_primeira_insercao == 1){
    Insere_Procura_preOrdem_ArvBin(raiz, aux1, aux2, aux3);
    strcpy(aux1," ");
    strcpy(aux2," ");
    strcpy(aux3," ");
  }
  flag_primeira_insercao = 1;
scanf("%s %s %s",aux1,aux2,aux3);
}
preOrdem_ArvBin(raiz,&contador_nodos,&contador_sem_filho);
printf("%d %d",contador_nodos,contador_sem_filho);  
libera_ArvBin(raiz);
return 0;
  

}

