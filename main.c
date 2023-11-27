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

int main()
{
    inicializacao();

    return 0;
}
