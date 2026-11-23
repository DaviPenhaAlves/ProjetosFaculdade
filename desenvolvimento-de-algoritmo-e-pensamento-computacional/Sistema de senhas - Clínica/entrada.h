#ifndef ENTRADA_H
#define ENTRADA_H

/* Pede um numero inteiro entre minimo e maximo (repete ate ser valido). */
int ler_inteiro(const char *mensagem, int minimo, int maximo);

/* Pede UMA letra que esteja em "validas" (ex.: "FMO"). Retorna a letra em maiuscula. */
char ler_opcao(const char *mensagem, const char *validas);

#endif
