#include <stdio.h>

int main() {

    // Configurações do monitoramento 
    float limite = 30;        
    float tempMinima = -90;  
    float tempMaxima = 60;    

    // Variáveis de controle 
    int quantidade;           // quantas leituras o usuário quer fazer
    int contador = 1;         // número da leitura atual
    int consecutivas = 0;     // temperaturas seguidas acima do limite
    int lido;                 // guarda o retorno do scanf (1 = leu certo)
    int c;                    // usado para limpar o buffer do teclado

    // Variáveis do relatório final 
    float temperatura;
    float soma = 0;
    float maior = -9999;
    float menor = 9999;
    float media;
    int totalMedicoes;

    printf("========================================\n");
    printf("     SISTEMA DE MONITORAMENTO\n");
    printf("========================================\n\n");

    // ETAPA 1: pede a quantidade de medições e valida a entrada.    
    do {
        printf("Quantas temperaturas deseja registrar? ");
        lido = scanf("%d", &quantidade);

        // Descarta o que sobrou no teclado. Sem isso, se o usuário
        // digitar letras, o scanf leria o mesmo texto para sempre.
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        if (lido != 1) {
            // scanf não conseguiu ler um número inteiro
            printf("ERRO: Digite apenas numeros inteiros.\n\n");
            quantidade = 0;   // garante que o laço continue
        } else if (quantidade <= 0) {
            printf("ERRO: A quantidade deve ser maior que zero.\n\n");
        }

    } while (quantidade <= 0);

    printf("\nLimite de temperatura: %.0f graus\n\n", limite);

    // ETAPA 2: leitura das temperaturas.
    while (contador <= quantidade && consecutivas < 3) {

        do {
            printf("Digite a temperatura %d: ", contador);
            lido = scanf("%f", &temperatura);

            // Limpa o teclado para não travar em caso de texto
            while ((c = getchar()) != '\n' && c != EOF) {
            }

            if (lido != 1) {
                printf("ERRO: Digite apenas numeros. Exemplo: 28.5\n\n");
            } else if (temperatura < tempMinima || temperatura > tempMaxima) {
                printf("ERRO: Informe uma temperatura entre %.0f e %.0f graus.\n\n",
                       tempMinima, tempMaxima);
                lido = 0;   // força a repetição da leitura
            }

        } while (lido != 1);

        // Acumula os dados do relatório
        soma += temperatura;

        if (temperatura > maior) {
            maior = temperatura;
        }

        if (temperatura < menor) {
            menor = temperatura;
        }

        // Verifica se a temperatura está acima do limite
        if (temperatura > limite) {
            consecutivas++;  

            printf("ALERTA: Temperatura acima do limite!\n");
            printf("Temperaturas acima consecutivas: %d\n", consecutivas);

        } else {
            // Temperatura normal quebra a sequência: zera o contador
            consecutivas = 0;

            printf("Temperatura dentro do limite.\n");
        }

        contador++;
        printf("\n");
    }

    // O contador termina uma unidade à frente da última leitura feita
    totalMedicoes = contador - 1;

    // ETAPA 3: se o laço parou por 3 temperaturas seguidas acima
    // do limite, exibe a mensagem de encerramento automático.
    if (consecutivas == 3) {
        printf("========================================\n");
        printf("ENCERRAMENTO AUTOMATICO!\n");
        printf("Foram registradas 3 temperaturas\n");
        printf("consecutivas acima de %.0f graus.\n", limite);
        printf("========================================\n");
    }

    // ETAPA 4: relatório final
    media = soma / totalMedicoes;

    printf("\n========================================\n");
    printf("           RELATORIO FINAL\n");
    printf("========================================\n");

    printf("Quantidade de medicoes: %d\n", totalMedicoes);
    printf("Maior temperatura: %.2f C\n", maior);
    printf("Menor temperatura: %.2f C\n", menor);
    printf("Temperatura media: %.2f C\n", media);

    if (media > limite) {
        printf("Status: ALERTA\n");
    } else {
        printf("Status: NORMAL\n");
    }

    printf("========================================\n");

    return 0;
}
