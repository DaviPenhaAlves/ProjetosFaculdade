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

### Softwares necessários

- **Compilador GCC**, que transforma o `vetores.c` em um programa executável:
  - **Windows:** instalar o [MSYS2](https://www.msys2.org/) e, no terminal do MSYS2, executar `pacman -S mingw-w64-ucrt-x86_64-gcc`. Depois, adicionar a pasta `C:\msys64\ucrt64\bin` ao PATH do Windows.
  - **Linux (Ubuntu/Debian):** `sudo apt install gcc`
  - **macOS:** `xcode-select --install`
- **Terminal:** PowerShell ou Prompt de Comando (Windows), ou o terminal do Linux/macOS. O terminal integrado do VS Code também funciona.
- **Alternativa sem instalar nada:** um compilador online, como o [OnlineGDB](https://www.onlinegdb.com/online_c_compiler).

Para verificar se o GCC está instalado, execute:

```bash
gcc --version
```

### Passo a passo

1. Baixe ou clone este repositório e abra o terminal **na pasta onde está o arquivo `vetores.c`**.
2. Compile o programa:
   ```bash
   gcc vetores.c -o vetores
   ```
   Se não aparecer nenhuma mensagem, a compilação deu certo e o executável foi criado.
3. Execute o programa:
   - **Windows (PowerShell):**
     ```powershell
     .\vetores.exe
     ```
   - **Linux/macOS:**
     ```bash
     ./vetores
     ```
4. Digite os 20 números inteiros, um por vez, pressionando Enter após cada um. Ao final, o programa exibe os resultados e todos os elementos do vetor.

### Problemas comuns

- **`gcc` não é reconhecido:** o GCC não está instalado ou não foi adicionado ao PATH. Confira a seção "Softwares necessários".
- **`Permission denied` ao compilar (Windows):** o `vetores.exe` está aberto ou em execução. Feche o programa e compile novamente.

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

![Execução do programa](print.png)
