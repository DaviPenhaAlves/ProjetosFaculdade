# Calculadora de 20 Operações em C

> Programa de linha de comando em C, com menu interativo, que reúne 20
> operações matemáticas, geométricas e de conversão de unidades.

---

## Índice

1. [Descrição do projeto](#descrição-do-projeto)
2. [Objetivo](#objetivo)
3. [Funcionalidades implementadas](#funcionalidades-implementadas)
4. [As 20 funções desenvolvidas](#as-20-funções-desenvolvidas)
5. [Bibliotecas utilizadas](#bibliotecas-utilizadas)
6. [Organização do código](#organização-do-código)
7. [Conceitos de programação aplicados](#conceitos-de-programação-aplicados)
8. [Tratamento de erros](#tratamento-de-erros)
9. [Instruções de compilação e execução](#instruções-de-compilação-e-execução)
10. [Exemplos de uso](#exemplos-de-uso)
11. [Identificação do estudante](#identificação-do-estudante)

---

## Descrição do projeto

Este projeto é uma **calculadora multifuncional em linguagem C**, executada
via terminal. Ao rodar o programa, o usuário vê um menu numerado de 0 a 20 e
escolhe qual operação deseja realizar. O programa lê os dados necessários,
executa o cálculo e imprime o resultado na tela — e volta a exibir o menu
para uma nova operação, repetindo esse ciclo até que o usuário escolha
encerrar o programa (opção `0`).

O código foi desenvolvido de forma **modular**, separado em múltiplos
arquivos `.c` e `.h`, cada um com uma responsabilidade específica (entrada
de dados, exibição de menu, cálculos), em vez de concentrar tudo em um
único `main()`.

## Objetivo

O objetivo do projeto é colocar em prática, em um programa único e
funcional, os principais fundamentos da linguagem C trabalhados em sala:

- Uso de **variáveis** e **tipos de dados** (`int`, `double`);
- **Entrada e saída de dados** formatada (`scanf`, `printf`);
- **Estruturas condicionais** (`switch...case`, `if...else`);
- **Estruturas de repetição** (`while`, `do...while`);
- **Funções** e **modularização** de código em múltiplos arquivos;
- Uso da biblioteca **`math.h`** para cálculos matemáticos mais avançados
  (potenciação e verificação de domínio numérico);
- **Tratamento de erros**, incluindo divisão por zero, opções inválidas,
  entrada de dados não numérica e restrições de domínio matemático.

## Funcionalidades implementadas

- Menu interativo, numerado e recorrente (aparece novamente após cada
  operação).
- 20 operações diferentes, descritas na seção seguinte.
- Leitura de dados validada: se o usuário digitar uma letra em vez de um
  número, o programa avisa e pede o valor novamente, sem travar.
- Tratamento de erros matemáticos (divisão por zero e operações fora do
  domínio dos números reais).
- Encerramento controlado do programa pela opção `0`, com mensagem de
  despedida.

## As 20 funções desenvolvidas

| Nº | Função no código               | Operação                                    |
|----|----------------------------------|----------------------------------------------|
| 1  | `calcularIMC`                   | Calcula o IMC e classifica o resultado        |
| 2  | `calcularAreaFiguras`           | Área de quadrado/retângulo, círculo ou triângulo |
| 3  | `calcularSoma`                  | Soma de dois números                          |
| 4  | `calcularSubtracao`             | Subtração de dois números                     |
| 5  | `calcularMultiplicacao`         | Multiplicação de dois números                 |
| 6  | `calcularDivisao`               | Divisão de dois números (com proteção contra divisão por zero) |
| 7  | `calcularMediaAritmetica`       | Média aritmética entre dois números           |
| 8  | `calcularPorcentagem`           | Porcentagem de um valor                       |
| 9  | `calcularRegraDeTres`           | Regra de três simples (A:B :: C:X)            |
| 10 | `celsiusParaFahrenheit`         | Conversão de Celsius para Fahrenheit          |
| 11 | `fahrenheitParaCelsius`         | Conversão de Fahrenheit para Celsius          |
| 12 | `calcularPerimetroRetangulo`    | Perímetro de um retângulo                     |
| 13 | `calcularVolumeCubo`            | Volume de um cubo                             |
| 14 | `calcularJurosSimples`          | Cálculo de juros simples                      |
| 15 | `calcularDesconto`              | Valor final de um produto com desconto        |
| 16 | `calcularVelocidadeMedia`       | Velocidade média (distância / tempo)          |
| 17 | `calcularConsumoCombustivel`    | Consumo de combustível (km/l)                 |
| 18 | `verificarParOuImpar`           | Verifica se um número inteiro é par ou ímpar  |
| 19 | `maiorEntreDoisNumeros`         | Identifica o maior entre dois números         |
| 20 | `calcularPotencia`              | Potenciação (com verificação de domínio)      |

Cada uma dessas funções está implementada em `src/operacoes.c` e é chamada
a partir do `switch` em `src/main.c` de acordo com a opção escolhida pelo
usuário.

## Bibliotecas utilizadas

| Biblioteca | Uso no projeto |
|---|---|
| `stdio.h`  | Entrada e saída padrão: `printf()` para exibir menus e resultados, `scanf()` para ler os dados digitados pelo usuário. |
| `math.h`   | Cálculos matemáticos: `pow()` (potenciação, usada no IMC, na área do círculo, no volume do cubo e na operação de potência) e `isnan()` (verifica se um resultado de `pow()` é um número real válido, usado no tratamento de domínio da operação de potência). |

A biblioteca `math.h` exige a flag `-lm` na hora da compilação (ver seção
de [instruções de compilação](#instruções-de-compilação-e-execução)).

## Organização do código

O projeto está dividido em quatro módulos dentro da pasta `src/`, cada um
com um arquivo de cabeçalho (`.h`) e um arquivo de implementação (`.c`):

```
calculadora/
├── src/
│   ├── main.c          → função main(): laço principal e switch de opções
│   ├── menu.c / .h      → exibição do menu na tela
│   ├── utils.c / .h     → leitura validada de int/double (scanf com tratamento de erro)
│   └── operacoes.c / .h → implementação das 20 operações, uma função por opção
├── Makefile             → automatiza a compilação do projeto
└── README.md            → esta documentação
```

**Por que separar em módulos assim?**

- **`menu`** — cuida apenas de exibir texto na tela. Se o menu mudar de
  visual no futuro, só esse arquivo precisa ser alterado.
- **`utils`** — isola a leitura de dados do teclado. Centraliza a
  validação de entrada (o que evita repetir o mesmo tratamento de erro em
  20 funções diferentes).
- **`operacoes`** — concentra toda a lógica matemática. Cada operação do
  menu é uma função independente, o que facilita leitura, manutenção e
  eventuais testes isolados de cada cálculo.
- **`main`** — não faz cálculo nenhum. Apenas orquestra: mostra o menu, lê
  a opção e chama a função correspondente. Isso deixa o fluxo do programa
  fácil de acompanhar em poucas linhas.

Esse tipo de separação por responsabilidade é o que caracteriza a
**modularização** de um projeto em C, permitindo que cada arquivo seja
entendido (e modificado) sem precisar ler o programa inteiro.

## Conceitos de programação aplicados

- **Variáveis e tipos de dados** — uso de `int` para valores inteiros
  (opções de menu, números pares/ímpares) e `double` para valores
  decimais (pesos, medidas, valores monetários), sempre com tipo
  adequado ao dado representado.

- **Entrada e saída de dados** — toda interação com o usuário é feita via
  `scanf()` (entrada) e `printf()` (saída), incluindo mensagens
  descritivas antes de cada leitura para orientar o que deve ser digitado.

- **Estruturas condicionais** — o `switch...case` em `main.c` direciona a
  execução para a função certa conforme a opção escolhida; internamente,
  várias funções usam `if...else` para tomar decisões (por exemplo, a
  classificação do IMC ou a verificação de divisão por zero).

- **Estruturas de repetição** — o `while(continuar)` em `main.c` mantém o
  menu sendo exibido até que o usuário escolha `0`; já o `do...while` em
  `utils.c` repete a leitura de um valor enquanto a entrada digitada não
  for um número válido, evitando que o programa trave com dado inválido.

- **Funções** — cada uma das 20 operações do menu foi implementada como
  uma função própria (`void`, sem retorno), responsável por ler seus
  próprios dados, calcular e exibir o resultado. Isso evita um `main()`
  gigante e torna o código reaproveitável.

- **Biblioteca `math.h`** — usada para potenciação (`pow()`) em cálculos
  como IMC, área do círculo, volume do cubo e potência, e para verificar
  se um resultado matemático é válido (`isnan()`) nos casos em que a
  potenciação foge do domínio dos números reais (base negativa com
  expoente fracionário).

## Tratamento de erros

| Situação | Como é tratada |
|---|---|
| Divisão por zero | Verificada antes de dividir nas operações de divisão, regra de três, velocidade média e consumo de combustível. |
| Opção de menu inválida | O `switch` possui uma cláusula `default` que avisa o usuário quando o número digitado não corresponde a nenhuma opção. |
| Entrada não numérica | `lerInteiro()` e `lerReal()` (em `utils.c`) verificam o retorno do `scanf()`; se a leitura falhar, o buffer de entrada é limpo e o valor é solicitado novamente. |
| Restrição de domínio matemático | Na potência: `0` elevado a expoente negativo é rejeitado (equivale a uma divisão por zero); base negativa com expoente fracionário é detectada com `isnan()`, pois o resultado não é um número real. No IMC e nas áreas: valores de altura, raio, base ou lado menores ou iguais a zero são rejeitados antes do cálculo. |

## Instruções de compilação e execução

**Pré-requisito:** ter o `gcc` instalado.

### Opção 1 — usando o Makefile (recomendado)

```bash
# compilar
make

# compilar e já executar
make run

# remover o binário gerado
make clean
```

### Opção 2 — compilando manualmente

```bash
gcc -Wall -Wextra -std=c99 src/main.c src/menu.c src/utils.c src/operacoes.c -o calculadora -lm
./calculadora
```

> ⚠️ A flag `-lm` é obrigatória: ela liga a biblioteca matemática usada
> pelas funções `pow()` e `isnan()`. Sem ela, a compilação falha com erro
> de referência indefinida.

## Exemplos de uso

**Exemplo 1 — Cálculo de IMC (opção 1):**

```
Digite uma opção: 1
Digite seu peso (Kg): 70
Digite sua altura (cm): 175
Seu IMC é 22.86
Seu peso está normal.
```

**Exemplo 2 — Divisão por zero (opção 6):**

```
Digite uma opção: 6
Digite o dividendo: 10
Digite o divisor: 0
Não é possível dividir por zero.
```

**Exemplo 3 — Potência fora do domínio real (opção 20):**

```
Digite uma opção: 20
Digite a base: -8
Digite o expoente: 0.5
Operação fora do domínio real (base negativa com expoente fracionário).
```

**Exemplo 4 — Entrada inválida (opção 3):**

```
Digite uma opção: 3
Digite o primeiro número: abc
Entrada inválida. Digite um número (ex: 10 ou 10.5).
Digite o primeiro número: 5
Digite o segundo número: 7
Resultado: 12.00
```

**Exemplo 5 — Encerrando o programa (opção 0):**

```
Digite uma opção: 0
Obrigado pelo seu tempo!!
Calculadora encerrada. Obrigado por utilizar!
```

## Identificação do estudante

- **Nome:** Davi
- **Instituição:** UDF
- **Disciplina/Projeto:** Programação em C — Calculadora de 20 operações
