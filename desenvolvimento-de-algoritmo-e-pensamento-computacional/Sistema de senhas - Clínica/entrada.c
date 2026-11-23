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

void ler_nome(const char *mensagem, char *destino, int tamanho) {
    while (1) {
        ler_linha(mensagem, destino, tamanho);

        /* o nome so vale se tiver pelo menos uma letra (nao so espacos) */
        for (int i = 0; destino[i] != '\0'; i++)
            if (!isspace((unsigned char)destino[i]))
                return;

        printf("O nome nao pode ficar vazio.\n");
    }
}

char ler_opcao(const char *mensagem, const char *validas) {
    char linha[40];

    while (1) {
        ler_linha(mensagem, linha, sizeof(linha));

        char *p = linha;
        while (isspace((unsigned char)*p)) p++;       /* pula espacos do comeco */

        if (*p != '\0') {
            char letra = (char)toupper((unsigned char)*p);
            char *resto = p + 1;
            while (isspace((unsigned char)*resto)) resto++;

            /* so vale se digitou uma letra e mais nada, e ela esta nas validas */
            if (*resto == '\0' && strchr(validas, letra) != NULL)
                return letra;
        }

        printf("Opcao invalida. Digite apenas uma destas letras: %s\n", validas);
    }
}
