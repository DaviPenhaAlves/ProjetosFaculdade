#include <stdio.h>
#include "matriz.h"
#include "operacoes.h"
#include "entrada.h"

#define MAX_MATRIZES 5

/* Dados do programa */
static Matriz matrizes[MAX_MATRIZES];
static int quantidade = 0;             /* 0 = ainda nao escolheu */
static int matrizes_informadas = 0;    /* 1 depois que a opcao 2 for feita */
static Matriz resultado;
static int tem_resultado = 0;          /* 1 depois de um calculo bem sucedido */

static void mostrar_menu(void) {
    printf("\n===== CALCULADORA DE MATRIZES =====\n");
    printf("1 - Escolher a quantidade de matrizes\n");
    printf("2 - Informar as matrizes\n");
    printf("3 - Soma de matrizes\n");
    printf("4 - Subtracao de matrizes\n");
    printf("5 - Multiplicacao de matrizes\n");
    printf("6 - Divisao de matrizes\n");
    printf("7 - Apresentar a matriz solucao\n");
    printf("0 - Sair\n");
}

static void escolher_quantidade(void) {
    quantidade = ler_inteiro("Quantidade de matrizes (2 a 5): ", 2, MAX_MATRIZES);

    /* mudou a quantidade: o que existia antes nao vale mais */
    matrizes_informadas = 0;
    tem_resultado = 0;
    printf("Ok! Agora use a opcao 2 para informar as %d matrizes.\n", quantidade);
}

static void informar_matrizes(void) {
    if (quantidade == 0) {
        printf("Escolha primeiro a quantidade de matrizes (opcao 1).\n");
        return;
    }

    for (int i = 0; i < quantidade; i++)
        ler_matriz(&matrizes[i], i + 1);

    matrizes_informadas = 1;
    tem_resultado = 0;
    printf("\nMatrizes informadas com sucesso!\n");
}

/* Faz a operacao entre todas as matrizes, da primeira para a ultima.
   Ex.: com 3 matrizes e soma: (M1 + M2) + M3 */
static void calcular(int operacao) {
    if (!matrizes_informadas) {
        printf("Informe as matrizes primeiro (opcao 2).\n");
        return;
    }

    Matriz acumulada = matrizes[0];
    Matriz temporaria;

    for (int i = 1; i < quantidade; i++) {
        int codigo = aplicar_operacao(operacao, &acumulada, &matrizes[i], &temporaria);
        if (codigo != OK) {
            printf("Nao foi possivel calcular com a matriz %d: %s\n", i + 1, mensagem_erro(codigo));
            return;
        }
        acumulada = temporaria;
    }

    resultado = acumulada;
    tem_resultado = 1;
    printf("Calculo realizado! Use a opcao 7 para ver a matriz solucao.\n");
}

static void apresentar_resultado(void) {
    if (!tem_resultado) {
        printf("Ainda nao ha resultado. Faca uma operacao (opcoes 3 a 6).\n");
        return;
    }

    printf("\n--- MATRIZ SOLUCAO (%dx%d) ---\n", resultado.linhas, resultado.colunas);
    mostrar_matriz(&resultado);
}

int main(void) {
    int opcao;

    do {
        mostrar_menu();
        opcao = ler_inteiro("Escolha uma opcao: ", 0, 7);

        switch (opcao) {
            case 1: escolher_quantidade();          break;
            case 2: informar_matrizes();            break;
            case 3: calcular(OP_SOMA);              break;
            case 4: calcular(OP_SUBTRACAO);         break;
            case 5: calcular(OP_MULTIPLICACAO);     break;
            case 6: calcular(OP_DIVISAO);           break;
            case 7: apresentar_resultado();         break;
            case 0: printf("Encerrando o programa.\n"); break;
        }
    } while (opcao != 0);

    return 0;
}
