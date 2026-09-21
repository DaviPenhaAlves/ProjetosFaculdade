# Desafio de Monitoramento de Temperatura

## 1. Identificação

- **Aluno:** DAVI PENHA SERRA ALVES
- **Disciplina:** Algoritmo e Pensamento Computacional
- **Professora:** Profa. Karla Sartin
- **Projeto:** Desafio de Monitoramento de Temperatura
- **Linguagem:** C

---

## 2. Objetivo

Este projeto tem como finalidade simular um sistema simples de monitoramento de temperatura. O programa recebe leituras digitadas pelo usuário e verifica se cada uma delas ultrapassa um limite pré-definido.

O problema a ser resolvido é identificar uma situação de risco: quando o ambiente permanece acima do limite por **três leituras seguidas**, o programa interrompe o monitoramento automaticamente e apresenta um relatório com o resumo das medições.

---

## 3. Funcionamento do programa

### 3.1 Limite de temperatura

O limite é definido no início do código, na variável `limite`, com o valor de **30 °C**. Uma temperatura é considerada acima do limite somente quando é **maior que 30 °C**. Portanto, uma leitura de exatamente 30 °C é tratada como dentro do limite.

### 3.2 Realização das leituras

O usuário informa os dados pelo teclado, em duas etapas:

1. Primeiro, informa a **quantidade de temperaturas** que deseja registrar.
2. Em seguida, o programa solicita as temperaturas **uma de cada vez**, indicando o número da leitura (por exemplo: "Digite a temperatura 3:").

As leituras se repetem até que a quantidade informada seja atingida ou até que ocorra o encerramento automático.

### 3.3 Valores inválidos

O programa valida as duas entradas:

| Entrada | Considerada inválida quando |
|---|---|
| Quantidade de medições | Não é um número inteiro (por exemplo, letras) ou é menor ou igual a zero |
| Temperatura | Não é um número (por exemplo, letras) ou está fora da faixa de -90 °C a 60 °C |

Quando uma entrada é inválida, o programa:

1. exibe uma mensagem de erro explicando o problema;
2. descarta o que foi digitado, limpando o buffer do teclado;
3. solicita a mesma informação novamente.

Uma temperatura inválida **não é contabilizada**: o número da leitura permanece o mesmo até que um valor válido seja informado. Dessa forma, o programa nunca trava nem interrompe a execução por causa de uma entrada incorreta.

### 3.4 Temperaturas acima do limite

Após cada leitura válida, o programa compara a temperatura com o limite (`temperatura > limite`). Se ela for maior, o programa:

- exibe a mensagem **"ALERTA: Temperatura acima do limite!"**;
- soma 1 ao contador de temperaturas consecutivas acima do limite e mostra o valor atual desse contador.

Se a temperatura estiver dentro do limite, o programa apenas exibe a mensagem "Temperatura dentro do limite.".

### 3.5 Temperaturas consecutivas

A contagem é feita pela variável `consecutivas`:

- a cada temperatura acima do limite, o contador aumenta em 1;
- quando aparece uma temperatura dentro do limite, o contador **volta para zero**, pois a sequência foi interrompida.

Assim, o contador só chega a 3 se as três leituras acima do limite ocorrerem uma logo após a outra. Leituras altas separadas por uma leitura normal não são somadas.

### 3.6 Encerramento do monitoramento

O monitoramento termina em uma de duas situações:

- **Encerramento normal:** todas as medições solicitadas pelo usuário foram realizadas.
- **Encerramento automático:** foram registradas três temperaturas consecutivas acima do limite. Nesse caso, o programa exibe a mensagem "ENCERRAMENTO AUTOMATICO!" e não solicita as leituras restantes.

Em ambos os casos, o programa apresenta um **relatório final** com:

- quantidade de medições realizadas;
- maior temperatura registrada;
- menor temperatura registrada;
- temperatura média;
- status geral: **ALERTA**, se a média for maior que o limite, ou **NORMAL**, caso contrário.

---

## 4. Estruturas de repetição

O programa utiliza as duas estruturas exigidas na atividade.

### 4.1 `do...while`: validação das entradas

Foi utilizado em dois pontos: na leitura da **quantidade de medições** e na leitura de **cada temperatura**.

**Justificativa:** nessas situações, o programa precisa pedir o valor pelo menos uma vez antes de saber se ele é válido. Como o `do...while` executa o bloco primeiro e verifica a condição depois, ele se adapta bem a esse caso: pede, confere e, se o valor for inválido, repete o pedido.

### 4.2 `while`: laço principal de leitura

Foi utilizado no laço que controla as leituras das temperaturas, com a condição:

```c
while (contador <= quantidade && consecutivas < 3)
```

**Justificativa:** a condição precisa ser verificada **antes** de cada leitura. Ela garante que o laço continue somente enquanto ainda houver medições a fazer e enquanto não tenham ocorrido três temperaturas consecutivas acima do limite. Assim, o próprio laço controla o encerramento automático, sem necessidade de comandos adicionais de interrupção.

### 4.3 `while`: limpeza do buffer

Um segundo `while` é utilizado após cada leitura com `scanf`, para descartar os caracteres que sobraram no teclado.

**Justificativa:** o número de caracteres a descartar é desconhecido e pode ser zero. Por isso, o teste deve ocorrer antes da execução do bloco, o que caracteriza o uso do `while`. Sem essa limpeza, um texto digitado no lugar de um número permaneceria no buffer e faria o programa repetir a leitura indefinidamente.

---

## 5. Como compilar e executar

**Requisito:** compilador GCC instalado.

1. Abra o terminal na pasta onde está o arquivo `monitoramento.c`.
2. Compile o programa:

```bash
gcc monitoramento.c -o monitoramento
```

3. Execute o programa:

- Linux ou macOS:

```bash
./monitoramento
```

- Windows:

```bash
.\monitoramento.exe
```

Também é possível copiar o código para um compilador C online e executá-lo normalmente.

---

## 6. Testes realizados

Foram realizados três cenários de teste. Todos utilizam o limite de 30 °C.

### Teste 1: entradas inválidas

**Entradas informadas:**

- Quantidade de medições: `abc`, depois `-3`, depois `2`.
- Primeira temperatura: `xyz`, depois `200`, depois `25`.
- Segunda temperatura: `28`.

**Resultado:** o programa rejeitou cada valor inválido, exibiu a mensagem de erro correspondente e solicitou uma nova entrada. Após receber valores válidos, o programa continuou normalmente até o relatório final.

**Evidência:** `evidencias/teste01.png`

### Teste 2: temperaturas acima do limite, mas não consecutivas

**Entradas informadas:** quantidade `5`; temperaturas `31`, `32`, `22`, `33` e `24`.

**Resultado:** as leituras de 31 °C e 32 °C geraram alerta e o contador chegou a 2. A leitura de 22 °C, dentro do limite, zerou o contador. A leitura de 33 °C reiniciou a contagem em 1, e a de 24 °C a zerou novamente. O programa **não** foi encerrado automaticamente e realizou as 5 medições, finalizando com o relatório (média de 28,40 °C, status NORMAL).

**Evidência:** `evidencias/teste02.png`

### Teste 3: três temperaturas consecutivas acima do limite

**Entradas informadas:** quantidade `6`; temperaturas `35`, `36` e `37`.

**Resultado:** o contador de consecutivas chegou a 3 na terceira leitura. O programa exibiu a mensagem "ENCERRAMENTO AUTOMATICO!" e finalizou o monitoramento sem solicitar as três leituras restantes. O relatório final registrou 3 medições, com média de 36,00 °C e status ALERTA.

**Evidência:** `evidencias/teste03.png`

---

## 7. Estrutura do repositório

```text
desafio-monitoramento/
│
├── monitoramento.c
├── README.md
│
└── evidencias/
    ├── teste01.png
    ├── teste02.png
    └── teste03.png
```
