#ifndef OPERACOES_H
#define OPERACOES_H

#include "matriz.h"

/* Codigos das operacoes */
#define OP_SOMA          1
#define OP_SUBTRACAO     2
#define OP_MULTIPLICACAO 3
#define OP_DIVISAO       4

/* Codigos de retorno */
#define OK                0
#define ERRO_DIMENSOES    1   /* tamanhos incompativeis */
#define ERRO_SEM_INVERSA  2   /* matriz nao tem inversa (determinante = 0) */

/* Cada funcao calcula "a op b" e guarda em r. Retornam OK ou um codigo de erro. */
int somar(const Matriz *a, const Matriz *b, Matriz *r);
int subtrair(const Matriz *a, const Matriz *b, Matriz *r);
int multiplicar(const Matriz *a, const Matriz *b, Matriz *r);
int dividir(const Matriz *a, const Matriz *b, Matriz *r);   /* a x inversa de b */

/* Escolhe a funcao certa pelo codigo da operacao. */
int aplicar_operacao(int operacao, const Matriz *a, const Matriz *b, Matriz *r);

/* Texto explicando o codigo de erro. */
const char *mensagem_erro(int codigo);

#endif
