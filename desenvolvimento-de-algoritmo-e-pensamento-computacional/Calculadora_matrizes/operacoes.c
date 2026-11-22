#include "operacoes.h"

#define PRECISAO 0.000000001   /* abaixo disso, consideramos o numero igual a zero */

static double absoluto(double x) {
    return (x < 0) ? -x : x;
}

int somar(const Matriz *a, const Matriz *b, Matriz *r) {
    if (a->linhas != b->linhas || a->colunas != b->colunas)
        return ERRO_DIMENSOES;

    r->linhas = a->linhas;
    r->colunas = a->colunas;
    for (int i = 0; i < r->linhas; i++)
        for (int j = 0; j < r->colunas; j++)
            r->dados[i][j] = a->dados[i][j] + b->dados[i][j];
    return OK;
}

int subtrair(const Matriz *a, const Matriz *b, Matriz *r) {
    if (a->linhas != b->linhas || a->colunas != b->colunas)
        return ERRO_DIMENSOES;

    r->linhas = a->linhas;
    r->colunas = a->colunas;
    for (int i = 0; i < r->linhas; i++)
        for (int j = 0; j < r->colunas; j++)
            r->dados[i][j] = a->dados[i][j] - b->dados[i][j];
    return OK;
}

int multiplicar(const Matriz *a, const Matriz *b, Matriz *r) {
    /* colunas de A precisam ser iguais as linhas de B */
    if (a->colunas != b->linhas)
        return ERRO_DIMENSOES;

    r->linhas = a->linhas;
    r->colunas = b->colunas;
    for (int i = 0; i < r->linhas; i++) {
        for (int j = 0; j < r->colunas; j++) {
            double soma = 0;
            for (int k = 0; k < a->colunas; k++)
                soma += a->dados[i][k] * b->dados[k][j];
            r->dados[i][j] = soma;
        }
    }
    return OK;
}

/* Calcula a inversa de a (que precisa ser quadrada) pelo metodo de Gauss-Jordan.
   Retorna OK ou ERRO_SEM_INVERSA. */
static int inverter(const Matriz *a, Matriz *inversa) {
    int n = a->linhas;
    double aux[MAX_TAM][2 * MAX_TAM];   /* [ A | I ] */

    /* monta a matriz [ A | identidade ] */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aux[i][j] = a->dados[i][j];
            aux[i][n + j] = (i == j) ? 1 : 0;
        }
    }

    for (int col = 0; col < n; col++) {
        /* procura a linha com o maior valor na coluna (pivo) */
        int pivo = col;
        for (int i = col + 1; i < n; i++)
            if (absoluto(aux[i][col]) > absoluto(aux[pivo][col]))
                pivo = i;

        if (absoluto(aux[pivo][col]) < PRECISAO)
            return ERRO_SEM_INVERSA;

        /* troca a linha do pivo de lugar */
        for (int j = 0; j < 2 * n; j++) {
            double temp = aux[col][j];
            aux[col][j] = aux[pivo][j];
            aux[pivo][j] = temp;
        }

        /* divide a linha para o pivo virar 1 */
        double p = aux[col][col];
        for (int j = 0; j < 2 * n; j++)
            aux[col][j] = aux[col][j] / p;

        /* zera o resto da coluna */
        for (int i = 0; i < n; i++) {
            if (i != col) {
                double fator = aux[i][col];
                for (int j = 0; j < 2 * n; j++)
                    aux[i][j] = aux[i][j] - fator * aux[col][j];
            }
        }
    }

    /* o lado direito agora e a inversa */
    inversa->linhas = n;
    inversa->colunas = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inversa->dados[i][j] = aux[i][n + j];
    return OK;
}

int dividir(const Matriz *a, const Matriz *b, Matriz *r) {
    /* "A / B" em matrizes significa A x (inversa de B) */
    if (b->linhas != b->colunas || a->colunas != b->linhas)
        return ERRO_DIMENSOES;

    Matriz inversa;
    int codigo = inverter(b, &inversa);
    if (codigo != OK)
        return codigo;

    return multiplicar(a, &inversa, r);
}

int aplicar_operacao(int operacao, const Matriz *a, const Matriz *b, Matriz *r) {
    switch (operacao) {
        case OP_SOMA:          return somar(a, b, r);
        case OP_SUBTRACAO:     return subtrair(a, b, r);
        case OP_MULTIPLICACAO: return multiplicar(a, b, r);
        default:               return dividir(a, b, r);
    }
}

const char *mensagem_erro(int codigo) {
    if (codigo == ERRO_DIMENSOES)
        return "os tamanhos das matrizes sao incompativeis para esta operacao.";
    if (codigo == ERRO_SEM_INVERSA)
        return "a matriz divisora nao tem inversa (determinante igual a zero).";
    return "erro desconhecido.";
}
