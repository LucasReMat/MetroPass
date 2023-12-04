#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "projectHeader.h"

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
        vp_passageiros[id]->visitas = 0;

        printf("Digite o nome do passageiro:\n");
        gets(vp_passageiros[id]->nomePassageiro);
    }

    else{
        printf("ERROR! ID DE PASSAGEIRO JA CADASTRADO!");
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

        //criando estacao no monitoramento de fluxos
        vp_fluxos[id] = (p_fluxo)malloc(sizeof(Fluxo));

        vp_fluxos[id]->idEstacao = id;
        vp_fluxos[id]->contadorArray = 0;

        printf("CRIADO COM SUCESSO: %d\n\n", vp_fluxos[id]->idEstacao);
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

        vp_fluxos[i] = (p_fluxo)malloc(sizeof(Fluxo));
        vp_fluxos[i]->idEstacao = i;
        vp_fluxos[i]->contadorArray = 0;
    }

    strcpy(vp_estacoes[0]->nomeEstacao, "Estacao Alberto");
    strcpy(vp_estacoes[1]->nomeEstacao, "Estacao Bazille");
}