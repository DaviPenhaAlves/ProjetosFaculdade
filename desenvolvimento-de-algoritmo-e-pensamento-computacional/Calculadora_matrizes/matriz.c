#include <stdio.h>
#include "matriz.h"
#include "entrada.h"

void ler_matriz(Matriz *m, int numero) {
    printf("\n--- MATRIZ %d ---\n", numero);
    m->linhas = ler_inteiro("Numero de linhas: ", 1, MAX_TAM);
    m->colunas = ler_inteiro("Numero de colunas: ", 1, MAX_TAM);

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            char mensagem[40];
            sprintf(mensagem, "Elemento [%d][%d]: ", i + 1, j + 1);
            m->dados[i][j] = ler_decimal(mensagem);
        }
    }
}

void mostrar_matriz(const Matriz *m) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            double valor = m->dados[i][j];
            if (valor > -0.005 && valor < 0.005) valor = 0;   /* evita mostrar -0.00 */
            printf("%9.2f", valor);
        }
        printf("\n");
    }
}
