#ifndef SENHAS_H
#define SENHAS_H

#define MAX_PACIENTES 1000

/* Regras de idade do enunciado */
#define IDADE_URGENTE 80              /* urgente: idade superior a 80 anos */
#define IDADE_PREFERENCIAL_MULHER 60  /* preferencial: mulheres com 60 anos ou mais */
#define IDADE_PREFERENCIAL_HOMEM 65   /* preferencial: homens com 65 anos ou mais */

typedef struct {
    int idade;
    char genero;               /* 'F' ou 'M' */
    int gestante;              /* 1 = sim, 0 = nao */
    int lactante;              /* 1 = sim, 0 = nao */
    int necessidade_especial;  /* 1 = sim, 0 = nao */
    int obesidade;             /* 1 = sim, 0 = nao */
    char tipo;                 /* 'U', 'P' ou 'N' (definido pelo sistema) */
    int numero;                /* numero da senha dentro da categoria (definido pelo sistema) */
    int atendido;              /* 1 = ja foi chamado */
} Paciente;

/* 1 se nao cabe mais nenhum paciente. */
int limite_atingido(void);

/* Classifica o paciente (U, P ou N), gera o numero da senha e guarda na lista.
   Retorna o paciente guardado, ou NULL se a lista estiver cheia. */
const Paciente *adicionar_paciente(Paciente novo);

/* Chama o proximo paciente: primeiro U, depois P, depois N (ordem de chegada em cada categoria).
   Retorna o paciente chamado, ou NULL se ninguem estiver aguardando. */
const Paciente *chamar_proximo(void);

/* Quantidade de pacientes que ainda nao foram chamados. */
int contar_aguardando(void);

/* "Urgente", "Preferencial" ou "Normal". */
const char *nome_do_tipo(char tipo);

#endif
