#ifndef ENTRADA_H
#define ENTRADA_H

/* Pede um numero inteiro entre minimo e maximo (repete ate ser valido). */
int ler_inteiro(const char *mensagem, int minimo, int maximo);

/* Pede um texto que nao pode ficar vazio (usado para o nome). */
void ler_nome(const char *mensagem, char *destino, int tamanho);

/* Pede UMA letra que esteja em "validas" (ex.: "FMO"). Retorna a letra em maiuscula. */
char ler_opcao(const char *mensagem, const char *validas);

#endif
