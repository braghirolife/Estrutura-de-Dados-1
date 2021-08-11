
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, char *caracter, int  i);
void preOrdem_ArvBin(ArvBin *raiz,int *contador_nodos, int* contador_sem_filhos);
int insere_ArvBin_condicao(ArvBin* raiz, char *caracter,char *aux, int i);

// Funcoes Adicionais
void Insere_Procura_preOrdem_ArvBin(ArvBin *raiz, char *aux,char *aux2,char *aux3);
void Procura_preOrdem_ArvBin_ins_dir(ArvBin *raiz, char *valor,char *aux, int *achou);
void Procura_preOrdem_ArvBin_ins_esq(ArvBin *raiz, char *valor,char *aux, int *achou);