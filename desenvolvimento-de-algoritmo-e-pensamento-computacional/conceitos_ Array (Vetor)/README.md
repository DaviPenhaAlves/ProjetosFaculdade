# Atividade de Vetores em C

**Aluno:** Davi
**Instituição:** UDF

## Objetivo

Desenvolver um programa em linguagem C que aplique os conceitos de arrays (vetores), estruturas de repetição, estruturas condicionais, entrada de dados e operações matemáticas, a partir da leitura de 20 números inteiros digitados pelo usuário.

## Descrição da lógica utilizada

1. Um vetor de 20 posições (`int vetor[20]`) é preenchido com um laço `for`, lendo cada número digitado pelo usuário via `scanf`.
2. Em um único laço `for` que percorre o vetor, o programa calcula simultaneamente:
   - a **soma dos múltiplos de 3** (`vetor[i] % 3 == 0`);
   - a **soma e a quantidade de números pares** (`vetor[i] % 2 == 0`), usadas depois para calcular a média;
   - a **quantidade de positivos** (`> 0`) e **negativos** (`< 0`) — o valor `0` não é contado em nenhuma das duas categorias;
   - o **maior e o menor valor**, comparando cada elemento com os valores atuais de `maior` e `menor` (inicializados com o primeiro elemento do vetor).
3. Antes de calcular a média dos pares, o programa verifica se `qtdPares > 0`. Caso não existam números pares no vetor, ele exibe uma mensagem informando isso em vez de dividir por zero.
4. Ao final, o programa exibe todos os resultados calculados e imprime todos os elementos armazenados no vetor.

## Como compilar e executar

Requer um compilador C (ex.: `gcc`).

```bash
gcc -Wall -o vetores vetores.c
./vetores
```

No Windows (usando MinGW), o executável gerado será `vetores.exe`:

```bash
gcc -Wall -o vetores vetores.c
vetores.exe
```

## Exemplo de entrada e saída

**Entrada** (20 números digitados um por um):
```
3 -6 9 12 -15 18 21 -24 27 30 1 2 4 5 7 8 10 11 -1 0
```

**Saída:**
```
--- RESULTADOS ---
Soma dos multiplos de 3: 75
Media dos pares: 5.40
Quantidade de positivos: 15
Quantidade de negativos: 4
Maior valor: 30
Menor valor: -24

--- ELEMENTOS DO VETOR ---
3 -6 9 12 -15 18 21 -24 27 30 1 2 4 5 7 8 10 11 -1 0
```

## Captura de tela

*(Adicionar aqui um print da execução do programa no terminal antes de subir para o GitHub.)*
