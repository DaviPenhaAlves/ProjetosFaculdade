#ifndef UTILS_H
#define UTILS_H

/*
 * utils.h
 * Funções utilitárias de entrada de dados.
 * Isolam o tratamento de erro de leitura (scanf) do resto do programa.
 */

/* Limpa o buffer de entrada até encontrar '\n' ou EOF.
 * Necessário depois de uma leitura inválida (scanf que falhou). */
void limparBufferEntrada(void);

/* Lê um número inteiro do teclado, exibindo 'mensagem' como prompt.
 * Repete a leitura enquanto o usuário digitar algo que não seja um número. */
int lerInteiro(const char *mensagem);

/* Lê um número real (double) do teclado, exibindo 'mensagem' como prompt.
 * Repete a leitura enquanto o usuário digitar algo que não seja um número. */
double lerReal(const char *mensagem);

#endif
