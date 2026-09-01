#include <stdio.h>
#include "menu.h"
#include "utils.h"
#include "operacoes.h"

/*
 * main.c
 * Calculadora de 20 operações matemáticas.
 *
 * Uma estrutura de repetição: while(continuar) mantém o programa rodando
 * até que o usuário escolha a opção 0.
 *
 * Estrutura condicional: switch(opcao) direciona para a função
 * correspondente à operação escolhida.
 */

int main(void)
{
    int continuar = 1;
    int opcao;

    while (continuar) {
        exibirMenu();
        opcao = lerInteiro("");

        switch (opcao) {
            case 0:
                printf("Obrigado pelo seu tempo!!\n");
                continuar = 0;
                break;

            case 1:  calcularIMC();                break;
            case 2:  calcularAreaFiguras();        break;
            case 3:  calcularSoma();               break;
            case 4:  calcularSubtracao();          break;
            case 5:  calcularMultiplicacao();      break;
            case 6:  calcularDivisao();            break;
            case 7:  calcularMediaAritmetica();    break;
            case 8:  calcularPorcentagem();        break;
            case 9:  calcularRegraDeTres();        break;
            case 10: celsiusParaFahrenheit();      break;
            case 11: fahrenheitParaCelsius();      break;
            case 12: calcularPerimetroRetangulo(); break;
            case 13: calcularVolumeCubo();         break;
            case 14: calcularJurosSimples();       break;
            case 15: calcularDesconto();           break;
            case 16: calcularVelocidadeMedia();    break;
            case 17: calcularConsumoCombustivel(); break;
            case 18: verificarParOuImpar();        break;
            case 19: maiorEntreDoisNumeros();      break;
            case 20: calcularPotencia();           break;

            default:
                printf("Opção inválida. Escolha um número entre 0 e 20.\n");
                break;
        }
    }

    printf("Calculadora encerrada. Obrigado por utilizar!\n");
    return 0;
}
