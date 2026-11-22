#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "entrada.h"

/* Le uma linha inteira do teclado e tira o "enter" do final. */
static void ler_linha(const char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    if (fgets(destino, tamanho, stdin) == NULL) {
        printf("\nFim da entrada. Encerrando.\n");
        exit(0);
    }

    size_t pos = strcspn(destino, "\n");
    if (destino[pos] == '\n') {
        destino[pos] = '\0';
    } else {
        /* a linha era maior que o espaco: joga fora o resto */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

int ler_inteiro(const char *mensagem, int minimo, int maximo) {
    char linha[80];
    char *fim;

    while (1) {
        ler_linha(mensagem, linha, sizeof(linha));

        long valor = strtol(linha, &fim, 10);
        int digitou_numero = (fim != linha);
        while (isspace((unsigned char)*fim)) fim++;   /* ignora espacos no fim */

        if (digitou_numero && *fim == '\0' && valor >= minimo && valor <= maximo)
            return (int)valor;

        printf("Entrada invalida. Digite um numero entre %d e %d.\n", minimo, maximo);
    }
}

double ler_decimal(const char *mensagem) {
    char linha[80];
    char *fim;

    while (1) {
        ler_linha(mensagem, linha, sizeof(linha));

        for (int i = 0; linha[i] != '\0'; i++)        /* troca virgula por ponto */
            if (linha[i] == ',') linha[i] = '.';

        double valor = strtod(linha, &fim);
        int digitou_numero = (fim != linha);
        while (isspace((unsigned char)*fim)) fim++;

        if (digitou_numero && *fim == '\0')
            return valor;

        printf("Entrada invalida. Digite um numero (ex.: 2.5).\n");
    }
}
