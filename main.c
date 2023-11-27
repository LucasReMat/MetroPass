#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "projectHeader.h"
#include "dataHandler.c"

int main()
{
    inicializacao();

    testeData();

    //imprimindo dados de teste
    printf("Passageiros:\n");
    int i = 0;
    while(i < 5){
        printf("\t%d: %s\n", vp_passageiros[i]->idCartao, vp_passageiros[i]->nomePassageiro);
        i++;
    }

    printf("Estacoes:\n");
    i = 0;
    while(i < 2){
        printf("\t%d: %s\n", vp_estacoes[i]->idEstacao, vp_estacoes[i]->nomeEstacao);
        i++;
    }

    return 0;
}
