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

void percorreArvOrd(PNoArvBin arv, int type) {
    if (arv != NULL) {
        switch (type) {
            case 1:
                // pre ordem
                printf("%d ", arv->jogo->appId);
                percorreArvOrd(arv->esq, 1);
                percorreArvOrd(arv->dir, 1);
                break;
            case 2:
                //ordem
                percorreArvOrd(arv->esq, 2);
                printf("%d ", arv->jogo->appId);
                percorreArvOrd(arv->dir, 2);
                break;
            case 3:
                //pos ordem
                percorreArvOrd(arv->esq, 3);
                percorreArvOrd(arv->dir, 3);
                printf("%d ", arv->jogo->appId);
                break;
            default:
                printf("%d ", arv->jogo->appId);
                percorreArvOrd(arv->esq, 0);
                percorreArvOrd(arv->dir, 0);
                break;
        }
    }
}

void printArv(PNoArvBin arv) {
    if (arv != NULL) {
        printArv(arv->esq);
        printf("(%d)  ", arv->jogo->appId);
        printArv(arv->dir);
    }
}

PNoArvBin percorreArv(PNoArvBin arv) {
    if (arv != NULL) {
        if (arv->esq == NULL && arv->dir != NULL) {
            PNoArvBin aux = arv->dir;
            return aux;
        } else if (arv->dir == NULL && arv->esq != NULL) {
            PNoArvBin aux = arv->esq;
            return aux;
        } else if (arv->dir != NULL && arv->esq != NULL) {
                if (arv->esq != NULL) {
                    return percorreArv(arv->esq);
                } else {  return percorreArv(arv->dir);   }
            }
    } else {  return NULL; }
}

void percorreArvOrd(PNoArvBin arv, int type) {
    if (arv != NULL) {
        switch (type) {
            case 1:
                // pre ordem
                printf("%d ", arv->jogo->appId);
                percorreArvOrd(arv->esq, 1);
                percorreArvOrd(arv->dir, 1);
                break;
            case 2:
                //ordem
                percorreArvOrd(arv->esq, 2);
                printf("%d ", arv->jogo->appId);
                percorreArvOrd(arv->dir, 2);
                break;
            case 3:
                //pos ordem
                percorreArvOrd(arv->esq, 3);
                percorreArvOrd(arv->dir, 3);
                printf("%d ", arv->jogo->appId);
                break;
            default:
                printf("%d ", arv->jogo->appId);
                percorreArvOrd(arv->esq, 0);
                percorreArvOrd(arv->dir, 0);
                break;
        }
    }
}

PNoArvBin newArvBin(){
    PNoArvBin arv =  malloc(sizeof(PNoArvBin));
    arv->dir = NULL;
    arv->esq = NULL;
    return arv;
}

PNoArvBin insereNoArvBin(PNoArvBin arv, Jogos jogo){
    if(arv == NULL){
        arv = newArvBin();
        arv->jogo = jogo.appId;
    }else if(jogo.appId < arv->jogo->appId){
        arv->esq = insereNoArvBin(arv->esq, jogo);
    }else if (jogo.appId> arv->jogo->appId){
        arv->dir = insereNoArvBin(arv->dir, jogo);
    }
    return arv;
}

PNoArvBin removeDaArv(PNoArvBin arv, int key) {
    if (arv != NULL) {
        if (arv->jogo->appId == key) {
        if (arv->esq == NULL && arv->dir == NULL) {
            free(arv);
            return NULL;
        } else if (arv->esq == NULL) {
            PNoArvBin aux = arv->dir;
            free(arv);
            return aux;
        } else if (arv->dir == NULL) {
            PNoArvBin aux = arv->esq;
            free(arv);
            return aux;
        } else {
            PNoArvBin aux = percorreArv(arv->esq);
            arv->jogo = aux->jogo;
            arv->esq = removeDaArv(arv->esq, aux->jogo->appId);
        }
        } else if (key < arv->jogo->appId) {
            arv->esq = removeDaArv(arv->esq, key);
        } else {
            arv->dir = removeDaArv(arv->dir, key);
        }
    } else { return NULL; }
    return arv;
}

