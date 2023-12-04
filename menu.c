#include "projectHeader.h"
#include "dataMaker.c"
#include "dataHandler.c"

void menu() {
  int opcao;
  int temp_id_passageiro;
  int temp_id_estacao;

  // menu para escolher as opcoes e usar o '5' para sair do programa
    while (opcao != 9)
    {

        printf("Menu Principal \n");
        printf("--------------------------------------\n");
        printf("1. Cadastrar Passageiros \n");
        printf("2. Cadastrar Estacoes \n");
        printf("3. Registrar Entrada \n");
        printf("4. Registrar Saida \n");
        printf("5. Ver Passageiros \n");
        printf("6. Ver Estacoes \n");
        printf("7. Gerar Relatorio \n");
        printf("8. Gerar Fluxo das Estacoes \n");
        printf("9. Sair do Programa \n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o ID do passageiro: ");
            scanf("%d", &temp_id_passageiro);

            cadastrarPassageiro(temp_id_passageiro);
            break;

        case 2:
            printf("Informe o ID da estacao: ");
            scanf("%d", &temp_id_estacao);

            cadastrarEstacao(temp_id_estacao);
            break;

        case 3:
            printf("Informe o ID do passageiro: ");
            scanf("%d", &temp_id_passageiro);

            printf("Informe o ID da estacao: ");
            scanf("%d", &temp_id_estacao);

            registrarEntrada(temp_id_passageiro, temp_id_estacao);
            break;

        case 4:
            printf("Informe o ID do passageiro: ");
            scanf("%d", &temp_id_passageiro);

            printf("Informe o ID da estacao: ");
            scanf("%d", &temp_id_estacao);

            registrarSaida(temp_id_passageiro, temp_id_estacao);
            break;

        case 5:
            verPassageiros();
            break;

        case 6:
            verEstacoes();
            break;

        case 7:
            printf("Informe o ID do passageiro: ");
            scanf("%d", &temp_id_passageiro);

            gerarRelatorio(temp_id_passageiro);
            break;

        case 8:
            printf("Informe o ID da estacao: ");
            scanf("%d", &temp_id_estacao);

            gerarfluxoEstacao(temp_id_estacao);
            break;

        case 9:
            printf("Programa encerrado");
            break;

        default:
            printf("opcao invalida");
        }
    }
}