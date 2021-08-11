//Arquivo ListaDinEncad.h



typedef struct elemento* Lista;
typedef struct elemento2* Lista2;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, char c);
int insere_lista_inicio(Lista* li, char c);
int insere_lista_ordenada(Lista* li, char c);
int tamanho_lista(Lista* li);
int imprime_lista(Lista* li);
int modif_lista_chave(Lista *li, int key);
int modif_lista_ciclica(Lista *li);
int modif_lista_ciclica_inverso(Lista *li);
int modif_lista_ciclica_5key(Lista *li, Lista *li2);
int insere_lista2_final(Lista2* li2, char dado_chave);
int modif_lista_ciclica_5keyd(Lista *li, Lista *li2);
int insere_lista_5key(Lista *li, Lista*li2);
int insere_caracter(Lista *li, int contador);
int modifica_inserido(Lista *li, Lista *li2);
int remover_elemento(Lista* li);