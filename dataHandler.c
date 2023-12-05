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


/**
 * Registra uma entrada em uma estação. esta ação aumenta o numero total de visitantes e visitantes atuais da estação, além disso
 * também registra a estação de entrada de um passageiro e o horario que o mesmo o fez.
 * @param idPassageiro o id do cartão do passageiro
 * @param idEstacao o id da estação visitada
 */
void registrarEntrada(int idPassageiro, int idEstacao)
{
    time_t momentoVisita = time(NULL);
    struct tm momentoVisitaTm = *localtime(&momentoVisita);
    
    // cadastrando visita nos dados da estacao
    vp_estacoes[idEstacao]->visitantesTotais++;

    // cadastrar entrada na estação
    int posicaoFluxo = vp_fluxos[idEstacao]->contadorArray;

    vp_fluxos[idEstacao]->tipoAcao[posicaoFluxo] = 0;

    vp_fluxos[idEstacao]->dia[posicaoFluxo] = momentoVisitaTm.tm_mday;
    vp_fluxos[idEstacao]->mes[posicaoFluxo] = momentoVisitaTm.tm_mon + 1;
    vp_fluxos[idEstacao]->hora[posicaoFluxo] = momentoVisitaTm.tm_hour;

    //cadastrar entrada no passageiro
    int posicaoVisita = vp_passageiros[idPassageiro]->visitas;

    vp_passageiros[idPassageiro]->estacaoVisitada[posicaoVisita] = idEstacao;
    vp_passageiros[idPassageiro]->idFluxoAcao[posicaoVisita] = posicaoFluxo;

    //somando 1 aos contadores
    vp_fluxos[idEstacao]->contadorArray += 1;
    vp_passageiros[idPassageiro]->visitas += 1;
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
    struct tm momentoVisitaTm = *localtime(&momentoVisita);

    // cadastrar entrada na estação
    int posicaoFluxo = vp_fluxos[idEstacao]->contadorArray;

    vp_fluxos[idEstacao]->tipoAcao[posicaoFluxo] = 1;

    vp_fluxos[idEstacao]->dia[posicaoFluxo] = momentoVisitaTm.tm_mday;
    vp_fluxos[idEstacao]->mes[posicaoFluxo] = momentoVisitaTm.tm_mon + 1;
    vp_fluxos[idEstacao]->hora[posicaoFluxo] = momentoVisitaTm.tm_hour;

    //cadastrar entrada no passageiro
    int posicaoVisita = vp_passageiros[idPassageiro]->visitas;

    vp_passageiros[idPassageiro]->estacaoVisitada[posicaoVisita] = idEstacao;
    vp_passageiros[idPassageiro]->idFluxoAcao[posicaoVisita] = posicaoFluxo;

    //somando 1 aos contadores
    vp_fluxos[idEstacao]->contadorArray += 1;
    vp_passageiros[idPassageiro]->visitas += 1;
}

/**
 * Exibe uma lista dos passageiros cadastrados no sistema
*/

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

/**
 * Exibe uma lista das estações cadastradas no sistema
*/

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
 * @param mesInicial valor inicial do intervalo na qual será usada para a busca dos dados para o relatório.
 * @param mesFinal valor final do intervalo na qual será usada para a busca dos dados para o relatório.
 * Também exibe todas as estações cadastradas e suas informações.
 */
void gerarRelatorio(int idPassageiro, int mesInicial, int mesFinal)
{
    int posicaoVisita = vp_passageiros[idPassageiro]->visitas;

    printf("------------------------------------\n");
    printf("RELATORIO\n");
    printf("------------------------------------\n");
    printf("Nome: %s\n", vp_passageiros[idPassageiro]->nomePassageiro);
    printf("ID: %d\n", vp_passageiros[idPassageiro]->idCartao);

    for (int i = 0; i < posicaoVisita; i++)
    {
        int estacaoVisitada = vp_passageiros[idPassageiro]->estacaoVisitada[i];
        int idFluxoAcao = vp_passageiros[idPassageiro]->idFluxoAcao[i];

        int tipoAcao = vp_fluxos[estacaoVisitada]->tipoAcao[idFluxoAcao];

        if(vp_fluxos[estacaoVisitada]->mes[idFluxoAcao] >= mesInicial && vp_fluxos[estacaoVisitada]->mes[idFluxoAcao] <= mesFinal){
            switch (tipoAcao)
            {
                case 0:
                    printf("Entrada:\n");
                    break;
                
                case 1:
                    printf("Saida:\n");
                    break;
                
                default:
                    printf("ERROR TIPO DE AÇÃO INVALIDO!!!");
                    break;
            }

            printf
            (
                "\tHorario: %dh - %d/%d\n", 
                vp_fluxos[estacaoVisitada]->hora[idFluxoAcao], vp_fluxos[estacaoVisitada]->dia[idFluxoAcao], vp_fluxos[estacaoVisitada]->mes[idFluxoAcao]
            );

            printf("\tEstacao: %s\n", vp_estacoes[estacaoVisitada]->nomeEstacao);
        }
        
    }

    printf("------------------------------------\n");
}

/**
 * Função que mostra o fluxo da estacao escolhida com o total de entrada, total de saida e o total de ambos, com um looping para gerar o fluxo de cada estacao individual
 * @param idEstacao o id da estação escolhida
*/
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