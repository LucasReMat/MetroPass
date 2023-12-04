# Sobre o projeto

O MetroPass é um programa desenvolvido em C feito para a disciplina de Linguagens de Programação (segundo semestre do curso de Análise e Desenvolvimento de Sistemas, FATEC Mogi Mirim).

O programa consiste em uma simulação de controle e registro de entrada e saída de passageiros em uma estação de metrô, além de fornecer relatórios de fluxo em intervalos de tempo.

# Bibliotecas em C utilizadas

- #include <stdio.h> (Input e Output)
- #include <stdlib.h> (Possui funções envolvendo alocação de memória, controle de processos, conversões e outras.)
- #include <time.h> (Manipulação de unidades de tempo)
- #include <string.h> (Fornece funções, macros e definições da biblioteca padrão da linguagem de programação C para manipulação de cadeias de caracteres e regiões de memória)

# Estrutura do projeto 

- dataHandler: Registra uma entrada em uma estação. Esta ação aumenta o número total de visitantes e visitantes atuais da estação, além disso também registra a estação de entrada de um passageiro e o horário que o mesmo o fez. Ademais, gera um relatório sobre um passageiro escolhido e o fluxo de uma estação.
- dataMaker: Cadastra um novo passageiro ou uma nova estação.
- menu: Menu para escolher entre as opções: cadastrar passageiros, cadastrar estações, registrar entrada, registrar saída, ver passageiros, ver estações, gerar relatório, gerar fluxo das estações ou sair do programa.

# Como executar o projeto

- Baixar arquivos do GitHub com o GitClone
- Executar utilizando a IDE preferida do usuário

# Autores

Jonas Soares, Lucas Reis, Lucca Pinz, Mateus Montedioca, Pedro Donato
