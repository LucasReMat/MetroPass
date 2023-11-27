#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "projectHeader.h"
#include "dataHandler.c"

void registrarEntrada(Passageiro* passageiros, Estacao* estacaoVisitada){

}

int main()
{
    inicializacao();

    //cadastrando dados de teste
    int i = 0;
    while(i++ < 3){
        cadastrarPassageiro(i);
    }

    i = 0;
    while(i++ < 2){
        cadastrarEstacao(i);
    }

    //imprimindo dados de teste
    printf("Passageiros:\n");
    i = 0;
    while(i++ < 3){
        printf("\t%d: %s\n", vp_passageiros[i]->idCartao, vp_passageiros[i]->nomePassageiro);
    }

    printf("Estacoes:\n");
    i = 0;
    while(i++ < 2){
        printf("\t%d: %s\n", vp_estacoes[i]->idEstacao, vp_estacoes[i]->nomeEstacao);
    }

    return 0;
}
