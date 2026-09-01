#include <stdio.h>
#include <math.h>
#include "operacoes.h"
#include "utils.h"

void calcularIMC(void)
{
    double peso, altura, imc;

    peso = lerReal("Digite seu peso (Kg): ");
    altura = lerReal("Digite sua altura (cm): ");

    /* Tratamento de domínio: altura não pode ser zero (divisão por zero) */
    if (altura <= 0) {
        printf("Altura inválida. O valor deve ser maior que zero.\n");
        return;
    }

    imc = peso / pow(altura / 100, 2);
    printf("Seu IMC é %.2lf\n", imc);

    if (imc <= 18.5) {
        printf("Tu estás desnutrido.\n");
    } else if (imc <= 24.9) {
        printf("Seu peso está normal.\n");
    } else if (imc <= 29.9) {
        printf("Você está com sobrepeso.\n");
    } else if (imc <= 34.9) {
        printf("Você está com obesidade grau I.\n");
    } else {
        printf("Você está com obesidade grau II ou mais.\n");
    }
}

void calcularAreaFiguras(void)
{
    int forma = lerInteiro("Digite a forma que deseja saber a área: 1 - quadrado/retângulo 2 - círculo 3 - triângulo\n");

    switch (forma) {
        case 1: {
            double largura = lerReal("Digite a largura: ");
            double altura = lerReal("Digite a altura: ");

            if (largura < 0 || altura < 0) {
                printf("Medidas não podem ser negativas.\n");
                return;
            }
            printf("Área: %.2lf\n", largura * altura);
            break;
        }
        case 2: {
            double raio = lerReal("Digite o raio: ");

            if (raio < 0) {
                printf("O raio não pode ser negativo.\n");
                return;
            }
            printf("Área: %.2lf\n", 3.14 * pow(raio, 2));
            break;
        }
        case 3: {
            double base = lerReal("Digite o valor da base: ");
            double altura = lerReal("Digite o valor da altura: ");

            if (base < 0 || altura < 0) {
                printf("Medidas não podem ser negativas.\n");
                return;
            }
            printf("Área: %.2lf\n", (base * altura) / 2);
            break;
        }
        default:
            printf("Forma inválida.\n");
            break;
    }
}

void calcularSoma(void)
{
    double n1 = lerReal("Digite o primeiro número: ");
    double n2 = lerReal("Digite o segundo número: ");
    printf("Resultado: %.2lf\n", n1 + n2);
}

void calcularSubtracao(void)
{
    double n1 = lerReal("Digite o primeiro número: ");
    double n2 = lerReal("Digite o segundo número: ");
    printf("Resultado: %.2lf\n", n1 - n2);
}

void calcularMultiplicacao(void)
{
    double n1 = lerReal("Digite o primeiro número: ");
    double n2 = lerReal("Digite o segundo número: ");
    printf("Resultado: %.2lf\n", n1 * n2);
}

void calcularDivisao(void)
{
    double n1 = lerReal("Digite o dividendo: ");
    double n2 = lerReal("Digite o divisor: ");

    /* Tratamento de erro: divisão por zero */
    if (n2 == 0) {
        printf("Não é possível dividir por zero.\n");
        return;
    }
    printf("Resultado: %.2lf\n", n1 / n2);
}

void calcularMediaAritmetica(void)
{
    double n1 = lerReal("Digite o primeiro número: ");
    double n2 = lerReal("Digite o segundo número: ");
    printf("Média: %.2lf\n", (n1 + n2) / 2);
}

void calcularPorcentagem(void)
{
    double valor = lerReal("Digite o valor: ");
    double porcentagem = lerReal("Digite a porcentagem: ");
    printf("Resultado: %.2lf\n", (valor * porcentagem) / 100);
}

void calcularRegraDeTres(void)
{
    double a1, b1, c1, x;

    printf("Regra de três: A está para B assim como C está para X.\n");
    a1 = lerReal("Digite A: ");
    b1 = lerReal("Digite B: ");
    c1 = lerReal("Digite C: ");

    /* Tratamento de erro: A não pode ser zero (divisão por zero) */
    if (a1 == 0) {
        printf("O valor de A não pode ser zero.\n");
        return;
    }

    x = (b1 * c1) / a1;
    printf("Resultado de X: %.2lf\n", x);
}

void celsiusParaFahrenheit(void)
{
    double celsius = lerReal("Digite a temperatura em Celsius: ");
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("Temperatura em Fahrenheit: %.2lf\n", fahrenheit);
}

void fahrenheitParaCelsius(void)
{
    double fahrenheit = lerReal("Digite a temperatura em Fahrenheit: ");
    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("Temperatura em Celsius: %.2lf\n", celsius);
}

void calcularPerimetroRetangulo(void)
{
    double largura = lerReal("Digite a largura do retângulo: ");
    double altura = lerReal("Digite a altura do retângulo: ");

    if (largura < 0 || altura < 0) {
        printf("Medidas não podem ser negativas.\n");
        return;
    }
    printf("Perímetro: %.2lf\n", 2 * (largura + altura));
}

void calcularVolumeCubo(void)
{
    double lado = lerReal("Digite o lado do cubo: ");

    if (lado < 0) {
        printf("O lado não pode ser negativo.\n");
        return;
    }
    printf("Volume: %.2lf\n", pow(lado, 3));
}

void calcularJurosSimples(void)
{
    double capital = lerReal("Digite o capital: ");
    double taxa = lerReal("Digite a taxa de juros em porcentagem: ");
    double tempo = lerReal("Digite o tempo: ");
    double juros = capital * (taxa / 100) * tempo;
    printf("Juros simples: %.2lf\n", juros);
}

void calcularDesconto(void)
{
    double valor = lerReal("Digite o valor do produto: ");
    double desconto = lerReal("Digite o desconto em porcentagem: ");
    double final_valor = valor - (valor * desconto / 100);
    printf("Valor final: %.2lf\n", final_valor);
}

void calcularVelocidadeMedia(void)
{
    double distancia = lerReal("Digite a distância em km: ");
    double tempo = lerReal("Digite o tempo em horas: ");

    /* Tratamento de erro: tempo não pode ser zero */
    if (tempo == 0) {
        printf("O tempo não pode ser zero.\n");
        return;
    }
    printf("Velocidade média: %.2lf km/h\n", distancia / tempo);
}

void calcularConsumoCombustivel(void)
{
    double distancia = lerReal("Digite a distância percorrida em km: ");
    double litros = lerReal("Digite a quantidade de litros consumidos: ");

    /* Tratamento de erro: litros não pode ser zero */
    if (litros == 0) {
        printf("A quantidade de litros não pode ser zero.\n");
        return;
    }
    printf("Consumo: %.2lf km/l\n", distancia / litros);
}

void verificarParOuImpar(void)
{
    int numero = lerInteiro("Digite um número inteiro: ");

    if (numero % 2 == 0) {
        printf("O número é par.\n");
    } else {
        printf("O número é ímpar.\n");
    }
}

void maiorEntreDoisNumeros(void)
{
    double n1 = lerReal("Digite o primeiro número: ");
    double n2 = lerReal("Digite o segundo número: ");

    if (n1 > n2) {
        printf("O maior número é: %.2lf\n", n1);
    } else if (n2 > n1) {
        printf("O maior número é: %.2lf\n", n2);
    } else {
        printf("Os dois números são iguais.\n");
    }
}

void calcularPotencia(void)
{
    double base = lerReal("Digite a base: ");
    double expoente = lerReal("Digite o expoente: ");
    double potencia;

    /* Tratamento de domínio: 0 elevado a expoente negativo é indefinido
     * (equivale a divisão por zero) */
    if (base == 0 && expoente < 0) {
        printf("Operação indefinida: 0 elevado a expoente negativo.\n");
        return;
    }

    potencia = pow(base, expoente);

    /* Tratamento de domínio: base negativa com expoente não inteiro
     * gera um resultado que não é um número real (pow retorna NaN) */
    if (isnan(potencia)) {
        printf("Operação fora do domínio real (base negativa com expoente fracionário).\n");
        return;
    }

    printf("Resultado: %.2lf\n", potencia);
}
