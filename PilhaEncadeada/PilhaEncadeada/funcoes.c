#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


Jogos *carregaDados(char *fileName, int *tam)
{

    int i = 0;
    char sep[1], str[2000], *ok;
    sep[0] = ',';
    Jogos *acervo;
    FILE *fp;
    fp = fopen(fileName, "r");
    acervo = criaAcervo(*tam);

    if (fp == NULL)
    {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    ok = fgets(str, 2000, fp); // Pega cabeçalho

    if (!ok)
    {
        printf("Erro ao o cabeçalho do CSV!!!");
        exit(1);
    }

    while (!feof(fp) && i < *tam)
    {
        ok = fgets(str, 2000, fp); // pega a linha do CSV

        if (ok)
        {
            char *campo;

            // APP ID
            campo = strtok(str, sep); // pega a string até a primeira ','
            acervo[i].appId = atoi(campo);

            // TITLE
            campo = strtok(NULL, sep);
            int pos = 0;
            while (campo[pos] != 15 && pos < strlen(campo))
                pos++;
            campo[pos] = '\0';
            acervo[i].title = (char *)malloc(strlen(campo));
            strcpy(acervo[i].title, campo);

            // Data release
            campo = strtok(NULL, sep);
            pos = 0;
            while (campo[pos] != 15 && pos < strlen(campo))
                pos++;
            campo[pos] = '\0';
            acervo[i].dataRelease = (char *)malloc(strlen(campo));
            strcpy(acervo[i].dataRelease, campo);

            // WINDOWS
            campo = strtok(NULL, sep);
            acervo[i].win = (char *)malloc(strlen(campo));
            strcpy(acervo[i].win, campo);

            // MAC
            campo = strtok(NULL, sep);
            acervo[i].mac = (char *)malloc(strlen(campo));
            strcpy(acervo[i].mac, campo);

            // LINUX
            campo = strtok(NULL, sep);
            acervo[i].LINUX = (char *)malloc(strlen(campo));
            strcpy(acervo[i].LINUX, campo);

            // RATING
            campo = strtok(NULL, sep);
            pos = 0;
            while (campo[pos] != 15 && pos < strlen(campo))
                pos++;
            campo[pos] = '\0';
            acervo[i].rating = (char *)malloc(strlen(campo));
            strcpy(acervo[i].rating, campo);

            // POSITIVE RATIO
            campo = strtok(NULL, sep);
            acervo[i].positiveRatio = atoi(campo);

            // USER REVIEWS
            campo = strtok(NULL, sep);
            acervo[i].userReviews = atoi(campo);

            // PRICE FINAL
            campo = strtok(NULL, sep);
            acervo[i].priceFinal = atof(campo);

            // PRICE ORIGINAL
            campo = strtok(NULL, sep);
            acervo[i].priceOriginal = atof(campo);

            // DISCOUNT
            campo = strtok(NULL, sep);
            acervo[i].discount = atof(campo);

            i++;
        }
    }

    return acervo;
}

Jogos *criaAcervo(int capacidade)
{

    Jogos *acervo;

    acervo = (Jogos *)malloc((capacidade + 1) * sizeof(Jogos));

    return acervo;
}

TPilhaEncadeada* criarPilhaEncadeada() {
    TPilhaEncadeada *pilha = (TPilhaEncadeada*)malloc(sizeof(TPilhaEncadeada));
    pilha->topo = NULL;
    return pilha;
}

void empilhar(TPilhaEncadeada* pilha, Jogos* jogos) {
    TNo* novoNo = (TNo*)malloc(sizeof(TNo));
    novoNo->jogos = jogos;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

Jogos* desempilhar(TPilhaEncadeada* pilha, Jogos* jogos) {
    if (pilha->topo != NULL) {
        TNo* noRemovido = pilha->topo; //ptr aponta pra o topo
        jogos = noRemovido->jogos; //
        pilha->topo = noRemovido->prox; //topo recebe o proximo
        free(noRemovido);
        return jogos;
    } else {
        return NULL;
    }
}

void prtPilha(TPilhaEncadeada* pilha){
    TNo* no = pilha->topo;
    while(no != NULL){
        printf("%d ", no->jogos->appId);
        no = no->prox;
    }
}

int insereNaFila(Jogos *jogos){

    TNo* fila = (TNo*) malloc(sizeof(TNo));
    if(fila != NULL) {
        fila->jogos = jogos;
        fila->prox = NULL;   
        return 1;
    } else return 0;
}

Jogos* removeDaFila(){
    TPilhaEncadeada* pilha;
    TNo* no = pilha->topo;
    if(no != NULL){
        return no;
        free(no);
    } else {
        free(no);
        return NULL;
    } 
}

