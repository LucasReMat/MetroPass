#ifndef PROJECTHEADER_H_INCLUDED
#define PROJECTHEADER_H_INCLUDED

#define MAX_ITENS 100

typedef struct {
    int idCartao;
    char nomePassageiro[100];
    time_t horarioEntrada;
    time_t horarioSaida;
    int estacaoEntrada;
    int estacaoSaida;
} Passageiro;

#endif // PROJECTHEADER_H_INCLUDED
