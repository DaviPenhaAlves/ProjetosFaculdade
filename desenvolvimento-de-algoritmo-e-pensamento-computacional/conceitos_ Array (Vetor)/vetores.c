#include <stdio.h>

int main() {
    int vetor[20];
    int i;
    int somaMult3 = 0;
    int somaPares = 0, qtdPares = 0;
    int positivos = 0, negativos = 0;
    int maior, menor;

    for (i = 0; i < 20; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (i = 0; i < 20; i++) {
        if (vetor[i] % 3 == 0) {
            somaMult3 = somaMult3 + vetor[i];
        }

        if (vetor[i] % 2 == 0) {
            somaPares = somaPares + vetor[i];
            qtdPares++;
        }

        if (vetor[i] > 0) {
            positivos++;
        }
        if (vetor[i] < 0) {
            negativos++;
        }

        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    printf("\n--- RESULTADOS ---\n");
    printf("Soma dos multiplos de 3: %d\n", somaMult3);

    /* evita divisao por zero se nao houver pares */
    if (qtdPares > 0) {
        printf("Media dos pares: %.2f\n", (float) somaPares / qtdPares);
    } else {
        printf("Media dos pares: nao existem numeros pares\n");
    }

    printf("Quantidade de positivos: %d\n", positivos);
    printf("Quantidade de negativos: %d\n", negativos);
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    printf("\n--- ELEMENTOS DO VETOR ---\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
