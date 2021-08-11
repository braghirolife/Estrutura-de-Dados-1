

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, const char *pt_br,const char *eng, const int cont);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, char *data);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz,const char *busca,const int acessos,int *marcador);
void posOrdem_ArvAVL(ArvAVL *raiz);
void preOrdem_ArvAV_inserir(ArvAVL *raiz,ArvAVL *raiz2);
void posOrdem_ArvAVL_cont(ArvAVL *raiz,int ocorrencias);
void preOrdem_ArvAVL_traducao(ArvAVL *raiz,const char *busca);
void preOrdem_ArvAVL_acessos(ArvAVL *raiz,const char *busca,const int acessos);


