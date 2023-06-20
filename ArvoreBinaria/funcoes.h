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


typedef struct noArvBin{
    //estrutura da arvore
    Jogos *jogo;
    struct noArvBin *esq;
    struct noArvBin *dir;
}NoArv;

typedef NoArv *PNoArvBin;

//manipulando jogos
Jogos* carregaDados( char *fileName, int *tam ); 
Jogos* criaAcervo( int capacidade ); 

#endif