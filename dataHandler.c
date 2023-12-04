#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "projectHeader.h"

/**
 * Limpa os vetores de ponteiros vp_estacoes e vp_passageiros preenchendo ambos com a informação NULL
 */
void inicializacao()
{
    int i;

    for (i = 0; i < MAX_ITENS; i++)
    {
        vp_estacoes[i] = NULL;
        vp_passageiros[i] = NULL;
        vp_fluxos[i] = NULL;
    }
}

void menuPrincipal()
{
    printf("------------------------------------\n");
    printf("SISTEMA DE CONTROLE\n");
    printf("------------------------------------\n");
}

/**
 * Registra uma entrada em uma estação. esta ação aumenta o numero total de visitantes e visitantes atuais da estação, além disso
 * também registra a estação de entrada de um passageiro e o horario que o mesmo o fez.
 * @param idPassageiro o id do cartão do passageiro
 * @param idEstacao o id da estação visitada
 */
void registrarEntrada(int idPassageiro, int idEstacao)
{
    time_t momentoVisita = time(NULL);

    // cadastrando visita nos dados da estacao
    vp_estacoes[idEstacao]->visitantesTotais++;

    // cadastrando visita nos dados do passageiro
    vp_passageiros[idPassageiro]->horarioEntrada = momentoVisita;
    vp_passageiros[idPassageiro]->estacaoEntrada = idEstacao;

    // cadastrar entrada na estação
    int posicaoFluxo = vp_fluxos[idEstacao]->contadorArray;

    vp_fluxos[idEstacao]->tipoAcao[posicaoFluxo] = 0;
    vp_fluxos[idEstacao]->contadorArray += 1;

    // printf("%s", ctime(&vp_passageiros[idPassageiro]->horarioEntrada));
    // printf("%s entrou na estacao: %s\n\n", vp_passageiros[idPassageiro]->nomePassageiro, vp_estacoes[idEstacao]->nomeEstacao);
}

/**
 * Registra uma saida em uma estação, esta ação não afeta o numero total de visitantes.
 * diminui os visitantes atuais da estação de origem e aumenta os da estação de chegada.
 * @param idPassageiro o id do cartão do passageiro
 * @param idEstacao o id da estação visitada
 */
void registrarSaida(int idPassageiro, int idEstacao)
{
    time_t momentoVisita = time(NULL);

    vp_passageiros[idPassageiro]->horarioSaida = momentoVisita;
    vp_passageiros[idPassageiro]->estacaoSaida = idEstacao;

    // criando registro da ação no vetor de fluxos
    int posicaoFluxo = vp_fluxos[idEstacao]->contadorArray;

    vp_fluxos[idEstacao]->tipoAcao[posicaoFluxo] = 1;
    vp_fluxos[idEstacao]->contadorArray += 1;

    // printf("%s", ctime(&vp_passageiros[idPassageiro]->horarioSaida));
    // printf("%s saiu na estacao: %s\n\n", vp_passageiros[idPassageiro]->nomePassageiro, vp_estacoes[idEstacao]->nomeEstacao);
}

void verPassageiros()
{
    printf("Passageiros:\n");
    int i = 0;
    while (vp_passageiros[i] != NULL)
    {
        printf("\t%d: %s\n", vp_passageiros[i]->idCartao, vp_passageiros[i]->nomePassageiro);
        i++;
    }
}

void verEstacoes()
{
    printf("Estacoes:\n");
    int i = 0;
    while (vp_estacoes[i] != NULL)
    {
        printf("\t%d: %s\n", vp_estacoes[i]->id, vp_estacoes[i]->nomeEstacao);
        i++;
    }
}

/**
 * Gera um relatório exibindo todos os passageiros cadastrados e suas informações.
 * @param idPassageiro o id do cartão do passageiro.
 * Também exibe todas as estações cadastradas e suas informações.
 */
void gerarRelatorio(int idPassageiro)
{
    printf("------------------------------------\n");
    printf("RELATORIO\n");
    printf("------------------------------------\n");
    printf("Nome: %s\n", vp_passageiros[idPassageiro]->nomePassageiro);
    printf("ID: %d\n", vp_passageiros[idPassageiro]->idCartao);

    printf("Entrada:\n");
    printf("   Horario: %s", ctime(&vp_passageiros[idPassageiro]->horarioEntrada));
    printf("   Estacao: %s\n", vp_estacoes[vp_passageiros[idPassageiro]->estacaoEntrada]->nomeEstacao);

    printf("Saida:\n");
    printf("   Horario: %s", ctime(&vp_passageiros[idPassageiro]->horarioSaida));
    printf("   Estacao: %s\n", vp_estacoes[vp_passageiros[idPassageiro]->estacaoSaida]->nomeEstacao);

    printf("------------------------------------\n");
}
// Função que mostra o fluxo da estacao escolhida com o total de entrada, total de saida, e o total de ambos, com um looping para gerar o fluxo de cada estacao individual
void gerarfluxoEstacao(int idEstacao)
{
    int totalEntrada = 0, totalSaida = 0, total = 0;
    int tamanhoArr = (int)(vp_fluxos[idEstacao]->contadorArray);
    for (int i = 0; i < tamanhoArr; i++)
    {
        if (vp_fluxos[idEstacao]->tipoAcao[i] == 0)
        {
            totalEntrada++;
        }
        else
        {
            totalSaida++;
        }
        total = totalEntrada + totalSaida; 
        
    }
    printf("\n--------------------------------------\n");
    printf("Fluxo da estacao: %s", vp_estacoes[idEstacao]->nomeEstacao);
    printf("\n--------------------------------------\n\n");
    printf("Total entradas: %d \n", totalEntrada);
    printf("Total saidas: %d \n", totalSaida);
    printf("Total: %d \n", total);
    printf("\n--------------------------------------\n\n");
}