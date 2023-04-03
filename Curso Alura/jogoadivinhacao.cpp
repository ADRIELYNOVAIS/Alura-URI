#include<iostream>
/*
std::cout << "Bem vindos ao jogo!";
standart - padrao para usar o cout
*/
using namespace std;
//não precisa usar o cout como está na linha 3, agora pode ser usado como na linha 12


int main(){

cout << "Bem vindos ao jogo!" <<endl;

cout << "Escolha seu nivel de dificuldade" <<endl;
cout << "Facil(F), Medio(M), Dificil(D)" <<endl;

char dificuldade;
cin >> dificuldade;

int numero_de_tentativas;

if(dificuldade =='F'){
    numero_de_tentativas = 15;
}
else if( dificuldade == 'M'){
    numero_de_tentativas = 10;
}
else{
    numero_de_tentativas = 5;
}

const int NUM_SECRETO = 15;
//nome de variaveis constante deve ser escrito em caixa altax

bool nao_acertou = true;
int tentativas = 0;

double pontos = 1000.0;

for( tentativas =1; tentativas<= numero_de_tentativas; tentativas++){

    int chute;
    cout << "Tentativas: " << tentativas;
    cout << "Qual seu chute?";
    cin >> chute; //recebe o valor da variavel chute

    double pontos_perdidos = abs(chute - NUM_SECRETO)/2.0; // avlro absoluto, ou seja, retorna um inteiro
    pontos = pontos - pontos_perdidos;

    bool acertou = chute == NUM_SECRETO;
    bool maior = chute > NUM_SECRETO;

    if( acertou ){
        cout <<"Acertou!";
        nao_acertou = false;
        break;
    }
    else if(maior){
        cout <<" seu chute foi maior do que o numero secreto";
    }
    else{
        cout << "seu chute foi menor do que o numero secreto";
    } 
}
    if(nao_acertou){
        cout << "Voce errou";
    }
    else{
    cout << "voce acertou";
    cout << "Sua pontuacao foi: " << pontos;
    }
    }

/* compilar : g++ jogoadivinhacao.cpp -o jogoadivinhacao.out 
   executar : jogoadivinhacao.out
*/