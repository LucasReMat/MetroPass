#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "projectHeader.h"

/**
 * Limpa os vetores de ponteiros vp_estacoes e vp_passageiros preenchendo ambos com a informção NULL
*/
void inicializacao(){
    int i;

    for (i=0; i<MAX_ITENS; i++){
        vp_estacoes[i] = NULL;
        vp_passageiros[i] = NULL;
    }

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
 * cadastra um novo passageiro no vetor de passageiros.
 * caso o ID do mesmo já tenha sigo utilizado a função IMPRIME uma mensagem de error.
 * @param id o numero de identificação do passageiro
*/
void cadastrarEstacao(int id){
    if(vp_estacoes[id] == NULL){
        //Criando o ponteiro para o passageiro no vetor de passageiros
        vp_estacoes[id] = (p_estacao)malloc(sizeof(Estacao));
        fflush(stdin);

        vp_estacoes[id]->idEstacao = id;

        printf("Digite o nome da estacao:\n");
        gets(vp_estacoes[id]->nomeEstacao);
    }

    else{
        printf("ERROR! ID DE PASSAGEIRO JÁ CADASTRADO!");
    }
}