#include <stdio.h>
#include "utils.h"

void limparBufferEntrada(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta os caracteres restantes na linha */
    }
}

int lerInteiro(const char *mensagem)
{
    int valor;
    int leituraOk;

    do {
        printf("%s", mensagem);
        leituraOk = scanf("%d", &valor);
        limparBufferEntrada();

        if (leituraOk != 1) {
            printf("Entrada inválida. Digite um número inteiro.\n");
        }
    } while (leituraOk != 1);

    return valor;
}

double lerReal(const char *mensagem)
{
    double valor;
    int leituraOk;

    do {
        printf("%s", mensagem);
        leituraOk = scanf("%lf", &valor);
        limparBufferEntrada();

        if (leituraOk != 1) {
            printf("Entrada inválida. Digite um número (ex: 10 ou 10.5).\n");
        }
    } while (leituraOk != 1);

    return valor;
}
