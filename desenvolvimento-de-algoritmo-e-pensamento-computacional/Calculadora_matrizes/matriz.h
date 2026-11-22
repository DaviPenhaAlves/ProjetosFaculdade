#ifndef MATRIZ_H
#define MATRIZ_H

#define MAX_TAM 10   /* tamanho maximo: 10 linhas x 10 colunas */

typedef struct {
    int linhas;
    int colunas;
    double dados[MAX_TAM][MAX_TAM];
} Matriz;

/* Pergunta o tamanho e os elementos da matriz. */
void ler_matriz(Matriz *m, int numero);

/* Mostra a matriz na tela. */
void mostrar_matriz(const Matriz *m);

#endif
