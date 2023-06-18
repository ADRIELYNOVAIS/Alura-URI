#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

int main() {
    int tam = 10;
    Jogos *acervo = carregaDados("../../Data/dataSetEquipe2.csv", &tam);
    TPilhaEncadeada* pilha = criarPilhaEncadeada();

    printf("Inserindo Elementos na pilha:\n");
    for (int i = 0; i < tam; i++) {
        empilhar(pilha, &acervo[i]);
    }
    prtPilha(pilha);


    printf("Removendo Elementos da pilha e colocando em uma fila:\n");
    int i =0, cont = 0;
    while(i <tam){
        Jogos* jogos = desempilhar(pilha, &pilha->topo);
        while(jogos != NULL){
            insereNaFila(jogos);
        }
        cont +=1;
        i++;
    }

    printf("Inserindo um elemento no meio da pilha:\n");
    int meio = cont/2;
    for (int i = 0; i < tam + 1; i++) {
        Jogos* jogos = removeDaFila();
        while(jogos != NULL){
            if(i != meio){
                empilhar(pilha, jogos);
            } else{
                int n =1;
                Jogos *novoAcervo = carregaDados("../../Data/dataSetEquipe2.csv", &n);
                empilhar(pilha, &novoAcervo[i]);
            }  
        }
    }
    prtPilha(pilha);
    return 0;
}
