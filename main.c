#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "projectHeader.h"
#include "dataHandler.c"
#include "dataMaker.c"

int main()
{
    int opcao;
    inicializacao();

    testeData();

    // cadastrarEstacao(2);

    //imprimindo dados de teste
    printf("Passageiros:\n");
    int i = 0;
    while(i < 2){
        printf("\t%d: %s\n", vp_passageiros[i]->idCartao, vp_passageiros[i]->nomePassageiro);
        i++;
    }

    printf("Estacoes:\n");
    i = 0;
    while(i < 2){
        printf("\t%d: %s\n", vp_estacoes[i]->id, vp_estacoes[i]->nomeEstacao);
        i++;
    }
        
    printf("\n--------------------------------------\n\n");

    registrarEntrada(0, 0);
    registrarSaida(0, 1);
    registrarEntrada(1, 0);
    registrarSaida(1, 1);

    gerarRelatorio(0);
    gerarfluxoEstacao(0);
    
    
    do{
        
        printf("Menu Principal \n");
        printf("--------------------------------------\n");
        printf("1. Ver Passageiros \n");
        printf("2. Ver Estacoes \n");
        printf("3. Gerar Relatorio \n");
        printf("4. Gerar Fluxo das Estacoes \n");
        printf("5. Sair do Programa \n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

    
    switch (opcao)
    {
    case 1:
        printf("Passageiros:\n");
        int i = 0;
        while(i < 2){
            printf("\t%d: %s\n", vp_passageiros[i]->idCartao, vp_passageiros[i]->nomePassageiro);
            i++;
    }
        break;
    
    case 2:
        printf("Estacoes:\n");
        i = 0;
        while(i < 2){
            printf("\t%d: %s\n", vp_estacoes[i]->id, vp_estacoes[i]->nomeEstacao);
            i++;
        }
        break;

    case 3:
        gerarRelatorio(0);
        break;
    
    case 4:
        gerarfluxoEstacao(0);
        break;
    case 5:
        printf("Programa encerrado");
        break;
        default:
        printf("opcao invalida");
}
}while (opcao != 5);
return 0;
}
