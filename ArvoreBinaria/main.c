#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int main() {
    int tam = 10;
    Jogos *acervo = carregaDados("../../Data/dataSetEquipe2.csv", &tam);
    
    PNoArvBin arvBin = newArvBin();

    print("Inserindo elementos em uma arvore");
    for( int i = 0; i < tam; i++){
        insereNoArvBin(arvBin, &acervo[i]);
    }

    printf("Imprimindo os elementos da arvore");
    printArv(arvBin);


    printf("Removendo 5 elementos da arvore:");
    for( int i = 0; i < 5; i++ ){
       PNoArvBin aux = removeDaArv(arvBin, i);
    } 

    printArv(arvBin);  

    
}