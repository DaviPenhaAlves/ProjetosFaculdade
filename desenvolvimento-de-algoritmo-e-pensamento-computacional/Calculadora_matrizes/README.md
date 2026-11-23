# Calculadora de Matrizes em C

**Autor:** Davi, UDF

## Objetivo

Desenvolver, em linguagem C, uma calculadora de matrizes que realiza soma, subtração, multiplicação e divisão, controlada por um menu interativo. O código é modularizado em arquivos com responsabilidades separadas.

## Funcionalidades

- Escolha da quantidade de matrizes (de 2 a 10).
- Exibição automática da matriz resultante após cada operação.
- Cadastro das matrizes, cada uma com seu próprio tamanho (até 10x10).
- Soma, subtração, multiplicação e divisão entre todas as matrizes informadas.
- Exibição da matriz solução.
- Validação de todas as entradas e mensagens claras para operações impossíveis.

## Menu principal

| Opção | Ação |
|---|---|
| 1 | Escolher a quantidade de matrizes |
| 2 | Informar as matrizes (só funciona depois da opção 1) |
| 3 | Soma de matrizes |
| 4 | Subtração de matrizes |
| 5 | Multiplicação de matrizes |
| 6 | Divisão de matrizes |
| 7 | Apresentar a matriz solução |
| 0 | Sair |

### Ordem de uso

1. Use a **opção 1** para definir quantas matrizes serão usadas.
2. Use a **opção 2** para digitar o tamanho e os elementos de cada matriz.
3. Escolha uma operação nas **opções 3 a 6**. A matriz resultante já é exibida logo após o cálculo.
4. Use a **opção 7** sempre que quiser ver a matriz solução de novo.
5. Faça novas operações com as mesmas matrizes, escolha outra quantidade (opção 1) ou saia (opção 0).

Se a ordem não for respeitada, o programa avisa o que falta fazer. Ao escolher uma nova quantidade de matrizes (opção 1), as matrizes e o resultado anteriores são descartados.

## Como as operações funcionam

Com mais de duas matrizes, a operação é feita da primeira para a última. Por exemplo, com três matrizes e soma: `(M1 + M2) + M3`.

| Operação | Regra |
|---|---|
| Soma e subtração | As matrizes devem ter o mesmo número de linhas e de colunas |
| Multiplicação | O número de colunas da primeira deve ser igual ao número de linhas da segunda |
| Divisão | `A ÷ B` é calculado como `A × inversa(B)`. A matriz `B` deve ser quadrada, ter inversa (determinante diferente de zero) e as colunas de `A` devem ser iguais às linhas de `B` |

Se alguma regra não for cumprida, o programa informa o motivo e em qual matriz o problema ocorreu, sem alterar o resultado anterior.

A inversa é calculada pelo método de Gauss-Jordan (monta-se `[A | I]` e aplicam-se operações nas linhas até a esquerda virar a identidade).

## Estrutura do projeto

```
calculadora_matrizes/
├── main.c         # menu e controle do fluxo do programa
├── matriz.h/.c    # struct Matriz, leitura e exibição
├── operacoes.h/.c # soma, subtração, multiplicação, divisão e inversa
├── entrada.h/.c   # leitura e validação de números digitados
└── README.md
```

| Módulo | Responsabilidade |
|---|---|
| `entrada` | Lê inteiros e decimais do teclado, repetindo a pergunta até a entrada ser válida. Aceita vírgula ou ponto como separador decimal |
| `matriz` | Define a struct `Matriz` (linhas, colunas e dados), pede os elementos ao usuário e imprime a matriz |
| `operacoes` | Contém as quatro operações e a inversão de matriz. Retorna códigos de erro em vez de imprimir mensagens |
| `main` | Mostra o menu, guarda o estado (quantidade, matrizes, resultado) e chama os demais módulos |

## Funções implementadas

### `entrada.c` — leitura e validação

| Função | O que faz |
|---|---|
| `ler_linha` (interna) | Lê uma linha do teclado, remove o *enter* e descarta o excesso se a linha for muito longa. Encerra o programa se a entrada acabar |
| `ler_inteiro` | Pede um número inteiro dentro de um intervalo e repete até ser válido |
| `ler_decimal` | Pede um número real, aceitando vírgula ou ponto |

### `matriz.c` — dados da matriz

| Função | O que faz |
|---|---|
| `ler_matriz` | Pergunta o tamanho e cada elemento da matriz |
| `mostrar_matriz` | Imprime a matriz na tela, com duas casas decimais |

### `operacoes.c` — cálculos

| Função | O que faz |
|---|---|
| `somar` | Soma duas matrizes de mesmo tamanho |
| `subtrair` | Subtrai duas matrizes de mesmo tamanho |
| `multiplicar` | Multiplica duas matrizes (colunas da primeira = linhas da segunda) |
| `inverter` (interna) | Calcula a inversa de uma matriz quadrada pelo método de Gauss-Jordan |
| `dividir` | Calcula `A ÷ B` como `A × inversa(B)` |
| `absoluto` (interna) | Devolve o valor absoluto de um número |
| `aplicar_operacao` | Escolhe a função certa (soma, subtração, multiplicação ou divisão) pelo código da operação |
| `mensagem_erro` | Converte o código de erro em um texto para o usuário |

### `main.c` — interface

| Função | O que faz |
|---|---|
| `mostrar_menu` | Exibe as opções do menu |
| `escolher_quantidade` | Opção 1: define quantas matrizes serão usadas |
| `informar_matrizes` | Opção 2: lê todas as matrizes (exige a opção 1 antes) |
| `calcular` | Opções 3 a 6: aplica a operação entre todas as matrizes, guarda o resultado e o exibe |
| `apresentar_resultado` | Opção 7: mostra a matriz solução |
| `main` | Repete o menu até o usuário escolher sair e chama a função da opção escolhida |

## Estruturas utilizadas

- `struct Matriz`: guarda o número de linhas, o de colunas e os valores em uma matriz de `double` (até 10x10).
- Vetor de `Matriz` (até 10), para guardar as matrizes informadas.
- Códigos de erro definidos com `#define` para as operações inválidas.
- Estruturas de decisão (`if`, `switch`) e de repetição (`while`, `for`, `do-while`).

## Como compilar e executar

É necessário ter o compilador `gcc` instalado.

```bash
gcc -std=c99 -Wall -Wextra -o calculadora main.c matriz.c operacoes.c entrada.c
```

Execução:

```bash
./calculadora        # Linux e macOS
calculadora.exe      # Windows (MinGW)
```

## Exemplo de uso

Soma de duas matrizes 2x2, `[[1, 2], [3, 4]]` e `[[5, 6], [7, 8]]`:

```
Escolha uma opcao: 1
Quantidade de matrizes (2 a 10): 2
Ok! Agora use a opcao 2 para informar as 2 matrizes.

Escolha uma opcao: 2

--- MATRIZ 1 ---
Numero de linhas: 2
Numero de colunas: 2
Elemento [1][1]: 1
Elemento [1][2]: 2
Elemento [2][1]: 3
Elemento [2][2]: 4

--- MATRIZ 2 ---
Numero de linhas: 2
Numero de colunas: 2
Elemento [1][1]: 5
Elemento [1][2]: 6
Elemento [2][1]: 7
Elemento [2][2]: 8

Matrizes informadas com sucesso!

Escolha uma opcao: 3
Calculo realizado!

--- MATRIZ SOLUCAO (2x2) ---
     6.00     8.00
    10.00    12.00
```

### Resultados esperados para as mesmas matrizes

| Operação | Resultado |
|---|---|
| Soma | `[[6, 8], [10, 12]]` |
| Subtração | `[[-4, -4], [-4, -4]]` |
| Multiplicação | `[[19, 22], [43, 50]]` |
| Divisão | `[[3, -2], [2, -1]]` |

## Tratamento de erros

- Opção 2 antes da 1: pede para escolher a quantidade primeiro.
- Operação antes de informar as matrizes: pede para usar a opção 2.
- Opção 7 sem resultado: avisa que ainda não há resultado.
- Tamanhos incompatíveis: informa que a operação não é possível com aquelas dimensões.
- Divisão por matriz sem inversa: informa que o determinante é zero.
- Entradas inválidas (letras, valores fora do intervalo): a pergunta é repetida.

## Limites e observações

- Cada matriz pode ter no máximo 10 linhas e 10 colunas.
- São aceitas de 2 a 10 matrizes por vez.
- Os valores são números reais (`double`) e o resultado é exibido com duas casas decimais.
- Os dados ficam apenas na memória: ao encerrar o programa, nada é salvo.
