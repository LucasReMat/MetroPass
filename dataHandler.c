#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "projectHeader.h"

/**
 * Limpa os vetores de ponteiros vp_estacoes e vp_passageiros preenchendo ambos com a informação NULL
*/
void inicializacao(){
    int i;

    for (i=0; i<MAX_ITENS; i++){
        vp_estacoes[i] = NULL;
        vp_passageiros[i] = NULL;
    }

}

void menuPrincipal() {
    printf("------------------------------------\n");
    printf("SISTEMA DE CONTROLE\n");
    printf("------------------------------------\n");
}

/**
 * cadastra um novo passageiro no vetor de passageiros.
 * caso o ID do mesmo já tenha sigo utilizado a função IMPRIME uma mensagem de error.
 * @param id o numero de identificação do passageiro
*/
void cadastrarPassageiro(int id){
    if(vp_passageiros[id] == NULL){
        //Criando o ponteiro para o passageiro no vetor de passageiros
        vp_passageiros[id] = (p_passageiro)malloc(sizeof(Passageiro));
        fflush(stdin);

        vp_passageiros[id]->idCartao = id;

        printf("Digite o nome do passageiro:\n");
        gets(vp_passageiros[id]->nomePassageiro);
    }

    else{
        printf("ERROR! ID DE PASSAGEIRO JÁ CADASTRADO!");
    }
}

/**
 * cadastra uma novo estação no vetor de estações.
 * caso o ID do mesmo já tenha sigo utilizado a função IMPRIME uma mensagem de error.
 * @param id o numero de identificação da estação
*/
void cadastrarEstacao(int id){
    if(vp_estacoes[id] == NULL){
        //Criando o ponteiro para o passageiro no vetor de passageiros
        vp_estacoes[id] = (p_estacao)malloc(sizeof(Estacao));
        fflush(stdin);

        vp_estacoes[id]->id = id;

        printf("Digite o nome da estacao:\n");
        gets(vp_estacoes[id]->nomeEstacao);
    }

    else{
        printf("ERROR! ID DE ESTACAO JÁ CADASTRADO!");
    }
}

/**
 * Gera dados para os testes, gera 5 passageiros e 2 estações
*/
void testeData(){
    //cadastrando passageiros
    for (int i = 0; i < 2; i++)
    {
        vp_passageiros[i] = (p_passageiro)malloc(sizeof(Passageiro));
        vp_passageiros[i]->idCartao = i;
    }

    strcpy(vp_passageiros[0]->nomePassageiro, "Lucas");
    strcpy(vp_passageiros[1]->nomePassageiro, "Jonas");
    // strcpy(vp_passageiros[2]->nomePassageiro, "Lucca");
    // strcpy(vp_passageiros[3]->nomePassageiro, "Mat");
    // strcpy(vp_passageiros[4]->nomePassageiro, "Pedro");

    //Cadastrando estações
    for (int i = 0; i < 2; i++)
    {
        vp_estacoes[i] = (p_estacao)malloc(sizeof(Estacao));
        vp_estacoes[i]->id = i;
    }

    strcpy(vp_estacoes[0]->nomeEstacao, "Estacao Alberto");
    strcpy(vp_estacoes[1]->nomeEstacao, "Estacao Bazille");
}

/**
 * Registra uma entrada em uma estação. esta ação aumenta o numero total de visitantes e visitantes atuais da estação, além disso
 * também registra a estação de entrada de um passageiro e o horario que o mesmo o fez.
 * @param idPassageiro o id do cartão do passageiro 
 * @param idEstacao o id da estação visitada
*/
void registrarEntrada(int idPassageiro, int idEstacao){
    time_t momentoVisita = time(NULL);

    //cadastrando visita nos dados da estacao
    vp_estacoes[idEstacao]->visitantesTotais++;

    //cadastrando visita nos dados do passageiro
    vp_passageiros[idPassageiro]->horarioEntrada = momentoVisita;
    vp_passageiros[idPassageiro]->estacaoEntrada = idEstacao;

    // printf("%s", ctime(&vp_passageiros[idPassageiro]->horarioEntrada));
    // printf("%s entrou na estacao: %s\n\n", vp_passageiros[idPassageiro]->nomePassageiro, vp_estacoes[idEstacao]->nomeEstacao);
}

/**
 * Registra uma saida em uma estação, esta ação não afeta o numero total de visitantes. 
 * diminui os visitantes atuais da estação de origem e aumenta os da estação de chegada.
 * @param idPassageiro o id do cartão do passageiro 
 * @param idEstacao o id da estação visitada
*/
void registrarSaida(int idPassageiro, int idEstacaoDeChegada){
    time_t momentoVisita = time(NULL);

    vp_estacoes[idEstacaoDeChegada]->visitantesTotais++;

    //cadastrando visita nos dados do passageiro
    vp_passageiros[idPassageiro]->horarioSaida = momentoVisita;
    vp_passageiros[idPassageiro]->estacaoSaida= idEstacaoDeChegada;

    // printf("%s", ctime(&vp_passageiros[idPassageiro]->horarioSaida));
    // printf("%s saiu na estacao: %s\n\n", vp_passageiros[idPassageiro]->nomePassageiro, vp_estacoes[idEstacaoDeChegada]->nomeEstacao);
}

/**
 * Gera um relatório exibindo todos os passageiros cadastrados e suas informações.
 * Também exibe todas as estações cadastradas e suas informações.
*/
void gerarRelatorio() {
    int tamVp_passageiros = sizeof(vp_passageiros) / sizeof(vp_passageiros[0]);

    printf("------------------------------------\n");
    printf("Passageiros\n");
    printf("------------------------------------\n");
    for (int idPassageiro = 0; idPassageiro < tamVp_passageiros; idPassageiro++) {
        printf("Nome: %s\n", vp_passageiros[idPassageiro]->nomePassageiro);
        printf("ID: %d\n", vp_passageiros[idPassageiro]->idCartao);

        printf("Entrada:\n");
        printf("   Horario: %s", ctime(&vp_passageiros[idPassageiro]->horarioEntrada));
        printf("   Estacao: %s\n", vp_estacoes[vp_passageiros[idPassageiro]->estacaoEntrada]->nomeEstacao);

        printf("Saida:\n");
        printf("   Horario: %s", ctime(&vp_passageiros[idPassageiro]->horarioSaida));
        printf("   Estacao: %s\n", vp_estacoes[vp_passageiros[idPassageiro]->estacaoSaida]->nomeEstacao);

        printf("\n");
    }
}