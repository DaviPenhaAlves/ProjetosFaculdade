#ifndef SENHAS_H
#define SENHAS_H

#define MAX_PACIENTES 1000
#define TAM_NOME 100
#define IDADE_URGENTE 80   /* acima desta idade o atendimento e urgente */

typedef struct {
    char nome[TAM_NOME];
    int idade;
    char genero;               /* 'F', 'M' ou 'O' */
    int gestante;              /* 1 = sim, 0 = nao */
    int necessidade_especial;  /* 1 = sim, 0 = nao */
    char tipo;                 /* 'U', 'P' ou 'N' (definido pelo sistema) */
    int numero;                /* numero da senha dentro do tipo (definido pelo sistema) */
    int atendido;              /* 1 = ja foi chamado */
} Paciente;

/* 1 se nao cabe mais nenhum paciente. */
int limite_atingido(void);

/* Classifica o paciente (U, P ou N), gera o numero da senha e guarda na lista.
   Retorna o paciente guardado, ou NULL se a lista estiver cheia. */
const Paciente *adicionar_paciente(Paciente novo);

/* Chama o proximo paciente: primeiro U, depois P, depois N (ordem de chegada em cada tipo).
   Retorna o paciente chamado, ou NULL se ninguem estiver aguardando. */
const Paciente *chamar_proximo(void);

/* Quantidade de pacientes que ainda nao foram chamados. */
int contar_aguardando(void);

/* "Urgente", "Preferencial" ou "Normal". */
const char *nome_do_tipo(char tipo);

#endif
