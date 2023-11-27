#ifndef PROJECTHEADER_H_INCLUDED
#define PROJECTHEADER_H_INCLUDED

#define MAX_ITENS 100
#define MAX_ITENS_NOMES 80

typedef struct {
    int idCartao;
    char nomePassageiro[MAX_ITENS_NOMES];
    time_t horarioEntrada;
    time_t horarioSaida;
    int estacaoEntrada;
    int estacaoSaida;
} Passageiro;
typedef Passageiro *p_passageiro;

extern p_passageiro vp_passageiros[MAX_ITENS];

typedef struct 
{
    int idEstacao;
    char nomeEstacao[MAX_ITENS_NOMES];
    int visitantes;
    int visitantesAtuais;
} Estacao;
typedef Estacao *p_estacao;

extern p_estacao vp_estacoes[MAX_ITENS];


#endif // PROJECTHEADER_H_INCLUDED
