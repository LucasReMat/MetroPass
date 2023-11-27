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
/**
 * O ponteiro para a struct Passageiro que registra os dados de transito e informações de id dos passageiros que passam pela estação.
 * @param idCartao Argumento identificador do Passageiro
 * @param nomePassageiro Nome completo do passageiro
 * @param horarioEntrada Horario que o passageiro entrou no metro
 * @param horarioSaida Horario que o passageiro deixou o metro
 * @param estacaoEntrada Estacao pela qual o passageiro entrou
 * @param estacaoSaida Estacao pelaa qual o passageiro saiu
*/
typedef Passageiro *p_passageiro;

typedef struct 
{
    int id;
    char nomeEstacao[MAX_ITENS_NOMES];
    int visitantesTotais;
} Estacao;
/**
 * O ponteiro para a Struct Estacao que armazena os dados das estações disponiveis
 * @param id O parametro identificador da estação
 * @param nomeEstacao O nome completo ta estação
 * @param visitantesTotais O total de visitantes que passaram pela estação (visitantes repetidos anida aumentam este numero)
*/
typedef Estacao *p_estacao;

p_passageiro vp_passageiros[MAX_ITENS];
p_estacao vp_estacoes[MAX_ITENS];

#endif // PROJECTHEADER_H_INCLUDED
