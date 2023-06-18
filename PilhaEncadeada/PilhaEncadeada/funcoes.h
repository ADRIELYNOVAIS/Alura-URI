#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {

    int appId;
    char *title;
    char *dataRelease;
    char *win;
    char *mac;
    char *LINUX;
    char *rating;
    int positiveRatio;
    int userReviews;
    float priceFinal;
    float priceOriginal;
    float discount;

} Jogos;

typedef struct No{
    Jogos* jogos;
    struct No* prox;
}TNo;

typedef struct Pilha {
    TNo* topo;
} TPilhaEncadeada;


Jogos* carregaDados( char *fileName, int *tam ); 
Jogos* criaAcervo( int capacidade ); 

TPilhaEncadeada *criarPilhaEncadeada();
void empilhar( TPilhaEncadeada *pilha, Jogos* jogos );
Jogos* desempilhar(TPilhaEncadeada* pilha, Jogos* jogos);
void prtPilha(TPilhaEncadeada* pilha);
int insereNaFila(Jogos *jogos);
Jogos* removeDaFila();

#endif