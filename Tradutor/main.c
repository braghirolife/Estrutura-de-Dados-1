#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAVL.h" 



int main(void) {
  int acessos;
  char palavra_pt_br[26];
  char palavra_eng[26];
  int seletor;
  char palavra_busca[26];
  int marcador = 0;
  FILE *fp = fopen("dict.txt","rt");
  ArvAVL *Arv_AVL = cria_ArvAVL();
  while(!feof(fp)){
    fscanf(fp,"%d",&acessos);
    fscanf(fp,"%s",palavra_eng);
    fscanf(fp,"%s",palavra_pt_br);
    insere_ArvAVL(Arv_AVL, palavra_pt_br, palavra_eng, acessos);
  }
  scanf("%d",&seletor);
  scanf("%s",palavra_busca);
  while(seletor != -1){
    if (seletor == 0){
      preOrdem_ArvAVL_traducao(Arv_AVL, palavra_busca);
    }
    if (seletor > 0){
      //preOrdem_ArvAVL_acessos(Arv_AVL, palavra_busca, seletor);
      emOrdem_ArvAVL(Arv_AVL, palavra_busca, seletor,&marcador);
    }
    scanf("%d",&seletor);
    if(seletor != -1){
      scanf("%s",palavra_busca);
    }
  }
}