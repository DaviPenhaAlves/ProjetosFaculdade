#ifndef ENTRADA_H
#define ENTRADA_H

/* Pede um numero inteiro entre minimo e maximo (repete ate ser valido). */
int ler_inteiro(const char *mensagem, int minimo, int maximo);

/* Pede um numero real (aceita 2.5 ou 2,5). */
double ler_decimal(const char *mensagem);

#endif
