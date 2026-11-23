# Sistema de Senhas de Atendimento — Clínica de Especialidades Médicas

**Autor:** Davi — UDF

## Objetivo

Desenvolver, em linguagem C, um sistema de gerenciamento de senhas de atendimento de uma clínica de especialidades médicas. O paciente informa seus dados, o sistema classifica o atendimento (Urgente, Preferencial ou Normal), gera a senha e um painel mostra qual senha está sendo atendida.

## Funcionalidades

- Retirada de senha com cadastro do paciente (nome, idade, gênero, gestação e necessidade especial).
- Classificação automática do tipo de atendimento.
- Numeração sequencial das senhas, separada por tipo (`U001`, `P001`, `N001`...).
- Registro de atendimento, chamando sempre a próxima senha da fila.
- Painel de atendimento sempre visível, com a senha atual e a quantidade de pacientes aguardando.
- Validação de todas as entradas.

## Tipos de senha

| Código | Tipo de atendimento | Critério |
|---|---|---|
| U | Urgente | Idosos com mais de 80 anos |
| P | Preferencial | Gestantes e pessoas com necessidades especiais |
| N | Normal | Atendimento normal |

A classificação segue esta ordem: primeiro verifica se a idade é maior que 80 (U); se não for, verifica se é gestante ou possui necessidade especial (P); caso contrário, é N.

## Menu

```
01 - Retirar senha
02 - Registrar atendimento
00 - Sair
```

- **01 – Retirar senha:** pergunta o nome, a idade, o gênero, se está gestante (apenas se o gênero for feminino) e se possui alguma necessidade especial. Ao final, mostra a senha gerada.
- **02 – Registrar atendimento:** chama a próxima senha da fila e a exibe no painel.
- **00 – Sair:** encerra o programa. Esta opção foi acrescentada, pois o enunciado não prevê uma forma de sair.

### Painel de atendimento

O painel aparece no topo de toda tela do menu, para mostrar sempre a senha que será atendida:

```
============ PAINEL DE ATENDIMENTO ============
Senha em atendimento: U001 - Joao
Pacientes aguardando: 4
===============================================
```

Enquanto nenhuma senha tiver sido chamada, o painel mostra `---`.

## Decisões do projeto

O enunciado deixa três pontos em aberto. Veja como foram resolvidos:

1. **Numeração:** cada tipo tem seu próprio contador. A primeira senha urgente é `U001`, a primeira preferencial é `P001` e a primeira normal é `N001`, independentemente da ordem de chegada entre os tipos.
2. **Ordem de chamada:** o enunciado não diz quem é chamado primeiro. Foi adotada a ordem de prioridade: todas as senhas `U` primeiro, depois as `P` e por último as `N`. Dentro de cada tipo, vale a ordem de chegada (a menor numeração é chamada antes).
3. **Opção de sair:** foi incluída a opção `00 – Sair`.

## Estrutura do projeto

```
sistema_senhas_clinica/
├── main.c        # menu, painel e telas do programa
├── senhas.h/.c   # struct Paciente, classificação, geração de senhas e fila
├── entrada.h/.c  # leitura e validação do que o usuário digita
└── README.md
```

| Módulo | Responsabilidade |
|---|---|
| `entrada` | Lê números, nome e opções de letra (F/M/O, S/N), repetindo a pergunta até a resposta ser válida |
| `senhas` | Guarda os pacientes, classifica (U/P/N), gera o número da senha e decide quem é o próximo a ser chamado |
| `main` | Mostra o menu e o painel, e liga as opções do menu às funções dos outros módulos |

## Funções implementadas

### `entrada.c` — leitura e validação

| Função | O que faz |
|---|---|
| `ler_linha` (interna) | Lê uma linha do teclado, remove o *enter* e descarta o excesso se a linha for maior que o espaço disponível. Encerra o programa se a entrada acabar |
| `ler_inteiro` | Pede um número inteiro dentro de um intervalo e repete até ser válido |
| `ler_nome` | Pede o nome e repete se ficar vazio ou só com espaços |
| `ler_opcao` | Pede uma única letra dentre as válidas (ex.: `FMO` ou `SN`) e devolve em maiúscula |

### `senhas.c` — regras do sistema

| Função | O que faz |
|---|---|
| `classificar_paciente` (interna) | Decide o tipo da senha: `U` (mais de 80 anos), `P` (gestante ou necessidade especial) ou `N` |
| `gerar_numero` (interna) | Devolve o próximo número da senha, com um contador para cada tipo |
| `limite_atingido` | Informa se a lista de pacientes está cheia |
| `adicionar_paciente` | Classifica o paciente, gera a senha e o guarda na lista |
| `procurar_proximo_do_tipo` (interna) | Acha o primeiro paciente de um tipo que ainda não foi chamado |
| `chamar_proximo` | Chama o próximo da fila, na ordem U, P, N, e o marca como atendido |
| `contar_aguardando` | Conta quantos pacientes ainda não foram chamados |
| `nome_do_tipo` | Converte `U`, `P` ou `N` em "Urgente", "Preferencial" ou "Normal" |

### `main.c` — interface

| Função | O que faz |
|---|---|
| `mostrar_painel` | Exibe a senha em atendimento e a quantidade de pacientes aguardando |
| `mostrar_menu` | Exibe as opções do menu |
| `retirar_senha` | Opção 01: pergunta os dados do paciente e mostra a senha gerada |
| `registrar_atendimento` | Opção 02: chama o próximo paciente e atualiza o painel |
| `main` | Repete o menu até o usuário escolher sair e chama a função da opção escolhida |

## Estruturas utilizadas

- `struct Paciente`: guarda nome, idade, gênero, gestação, necessidade especial, tipo da senha, número e se já foi atendido.
- Vetor de `Paciente` (até 1000), mantido em ordem de chegada.
- Três contadores, um para cada tipo de senha.
- Estruturas de decisão (`if`, `switch`) e de repetição (`while`, `for`, `do-while`).

## Como compilar e executar

É necessário ter o compilador `gcc` instalado.

```bash
gcc -std=c99 -Wall -Wextra -o clinica main.c senhas.c entrada.c
```

Execução:

```bash
./clinica         # Linux e macOS
clinica.exe       # Windows (MinGW)
```

Para usar no VS Code, abra a pasta do projeto, abra o terminal integrado (Ctrl + ') e rode os comandos acima. O botão de Run do VS Code compila apenas o arquivo aberto, por isso o projeto deve ser compilado pelo terminal.

## Exemplo de uso

```
============ PAINEL DE ATENDIMENTO ============
Senha em atendimento: ---
Pacientes aguardando: 0
===============================================

----------------- MENU -----------------
01 - Retirar senha
02 - Registrar atendimento
00 - Sair
Escolha uma opcao: 1

--- RETIRAR SENHA ---
Nome: Maria
Idade: 30
Genero (F=feminino, M=masculino, O=outro): F
Esta gestante? (S/N): S
Possui alguma necessidade especial? (S/N): N

Senha retirada com sucesso!
Paciente: Maria
Senha: P001
Tipo de atendimento: Preferencial
```

Depois de retirar outras senhas, ao escolher a opção 2:

```
Escolha uma opcao: 2

Chamando proximo paciente: senha P001

============ PAINEL DE ATENDIMENTO ============
Senha em atendimento: P001 - Maria
Pacientes aguardando: 1
===============================================
```

## Casos de teste

| Cenário | Resultado esperado |
|---|---|
| João, 85 anos, masculino | Senha `U001` (Urgente) |
| José, 90 anos, masculino (depois do João) | Senha `U002` (Urgente) |
| Maria, 30 anos, feminino, gestante | Senha `P001` (Preferencial) |
| Pedro, 40 anos, masculino, necessidade especial | Senha `P002` (Preferencial) |
| Ana, 25 anos, feminino, sem gestação e sem necessidade especial | Senha `N001` (Normal) |
| Paciente com exatamente 80 anos, sem outros critérios | Senha `N` (o critério é *mais de* 80 anos) |
| Cadastrar os cinco pacientes acima e usar a opção 02 cinco vezes | Ordem de chamada: `U001`, `U002`, `P001`, `P002`, `N001` |
| Opção 02 sem ninguém aguardando | Mensagem "Nenhum paciente aguardando atendimento." |
| Nome em branco | Pede o nome de novo |
| Idade com letras ou fora de 0 a 120 | Pede a idade de novo |
| Gênero diferente de F, M ou O | Pede o gênero de novo |
| Gênero masculino ou outro | A pergunta sobre gestação não é feita |

## Limites e observações

- O sistema guarda até 1000 senhas por execução.
- Os dados ficam apenas na memória: ao encerrar o programa, nada é salvo.
- Os números de senha são exibidos com três dígitos (`001`, `002`...). Só se um mesmo tipo chegasse à senha 1000 é que o número apareceria com quatro dígitos.
- As respostas de letra (gênero e S/N) devem ser digitadas com uma única letra, em maiúscula ou minúscula.
