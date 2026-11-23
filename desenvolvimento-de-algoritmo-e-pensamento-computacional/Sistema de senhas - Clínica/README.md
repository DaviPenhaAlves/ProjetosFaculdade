# Sistema de Senhas de Atendimento — Clínica de Especialidades Médicas

**Autor:** Davi — UDF

## Objetivo

Desenvolver, em linguagem C, um sistema de gerenciamento de senhas de atendimento de uma clínica de especialidades médicas. O atendente informa os dados do paciente, o sistema identifica automaticamente a categoria de atendimento (Urgente, Preferencial ou Normal), emite uma senha sequencial e um painel mostra qual senha está sendo atendida.

As categorias e as faixas etárias seguem as regras didáticas do enunciado da atividade, e não uma reprodução integral da legislação de atendimento prioritário nem uma classificação médica de risco.

## Funcionalidades

- **Registro de senhas:** o atendente informa gênero, idade, gestação (quando aplicável), lactação, necessidade especial e condição de obesidade.
- **Classificação automática** da categoria de atendimento.
- **Numeração sequencial independente** para cada categoria (`U001`, `P001`, `N001`...).
- **Registro de atendimento:** chama sempre a próxima senha, respeitando a precedência entre as categorias.
- **Painel de atendimento** sempre visível, com a senha atual e a quantidade de pacientes aguardando.
- **Validação** de todas as entradas.

## Categorias de senha

| Código | Categoria | Condição |
|---|---|---|
| N | Normal | Pacientes sem condições de prioridade cadastradas |
| P | Preferencial | Gestantes, lactantes, pessoas com necessidades especiais, pessoas obesas, mulheres com 60 anos ou mais e homens com 65 anos ou mais |
| U | Urgente | Pacientes com idade superior a 80 anos |

A classificação segue esta ordem:

1. Se a idade for **maior que 80**, a senha é **U**.
2. Senão, se o paciente for gestante, lactante, tiver necessidade especial ou obesidade, ou se for mulher com 60 anos ou mais ou homem com 65 anos ou mais, a senha é **P**.
3. Caso contrário, a senha é **N**.

A categoria urgente tem precedência sobre a preferencial, que tem precedência sobre a normal. A numeração é independente em cada categoria (N001, N002; P001, P002; U001, U002).

## Menu

```
01 - Retirar senha
02 - Registrar atendimento
00 - Sair
```

- **01 – Retirar senha:** pergunta, nesta ordem, o gênero, a idade, se está gestante e se é lactante (só para o gênero feminino), se possui necessidade especial e se possui condição de obesidade. Ao final, mostra a senha e a categoria.
- **02 – Registrar atendimento:** chama a próxima senha da fila e a exibe no painel.
- **00 – Sair:** encerra o programa.

### Painel de atendimento

O painel aparece no topo de toda tela do menu, para mostrar sempre a senha que será atendida:

```
============ PAINEL DE ATENDIMENTO ============
Senha em atendimento: U001
Pacientes aguardando: 4
===============================================
```

Enquanto nenhuma senha tiver sido chamada, o painel mostra `---`.

## Decisões do projeto

O enunciado deixa alguns pontos em aberto. Veja como foram resolvidos:

1. **Ordem de chamada:** todas as senhas `U` primeiro, depois as `P` e por último as `N`. Dentro de cada categoria, vale a ordem de chegada (a menor numeração é chamada antes).
2. **Gênero:** apenas `F` (feminino) ou `M` (masculino), pois as regras de idade do enunciado são definidas para mulheres e homens.
3. **Gestante e lactante:** essas perguntas só são feitas quando o gênero é feminino.
4. **Limites de idade:** "superior a 80 anos" significa 81 ou mais. Já "60 anos ou mais" e "65 anos ou mais" incluem a idade citada. Assim, uma pessoa com exatamente 80 anos não é urgente, mas é preferencial pela idade.
5. **Dados do paciente:** o enunciado não pede o nome, então o sistema não o solicita, e o painel mostra apenas a senha.
6. **Opção de sair:** foi incluída a opção `00 – Sair`, pois o enunciado não prevê uma forma de encerrar o programa.

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
| `entrada` | Lê números e opções de letra (F/M, S/N), repetindo a pergunta até a resposta ser válida |
| `senhas` | Guarda os pacientes, classifica (U/P/N), gera o número da senha e decide quem é o próximo a ser chamado |
| `main` | Mostra o menu e o painel, e liga as opções do menu às funções dos outros módulos |

## Funções implementadas

### `entrada.c` — leitura e validação

| Função | O que faz |
|---|---|
| `ler_linha` (interna) | Lê uma linha do teclado, remove o *enter* e descarta o excesso se a linha for maior que o espaço disponível. Encerra o programa se a entrada acabar |
| `ler_inteiro` | Pede um número inteiro dentro de um intervalo e repete até ser válido |
| `ler_opcao` | Pede uma única letra dentre as válidas (ex.: `FM` ou `SN`) e devolve em maiúscula |

### `senhas.c` — regras do sistema

| Função | O que faz |
|---|---|
| `idade_preferencial` (interna) | Informa se a idade dá direito à senha preferencial: mulher com 60 anos ou mais ou homem com 65 anos ou mais |
| `classificar_paciente` (interna) | Decide a categoria da senha: `U`, `P` ou `N` |
| `gerar_numero` (interna) | Devolve o próximo número da senha, com um contador para cada categoria |
| `limite_atingido` | Informa se a lista de pacientes está cheia |
| `adicionar_paciente` | Classifica o paciente, gera a senha e o guarda na lista |
| `procurar_proximo_do_tipo` (interna) | Acha o primeiro paciente de uma categoria que ainda não foi chamado |
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

- `struct Paciente`: guarda idade, gênero, gestação, lactação, necessidade especial, obesidade, categoria da senha, número e se já foi atendido.
- Vetor de `Paciente` (até 1000), mantido em ordem de chegada.
- Três contadores, um para cada categoria de senha.
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
Genero (F=feminino, M=masculino): F
Idade: 30
Esta gestante? (S/N): S
Esta lactante? (S/N): N
Possui alguma necessidade especial? (S/N): N
Possui condicao de obesidade? (S/N): N

Senha retirada com sucesso!
Senha: P001
Categoria: Preferencial
```

Depois de retirar outras senhas, ao escolher a opção 2:

```
Escolha uma opcao: 2

Chamando proximo paciente: senha U001

============ PAINEL DE ATENDIMENTO ============
Senha em atendimento: U001
Pacientes aguardando: 1
===============================================
```

## Casos de teste

| Paciente | Senha esperada |
|---|---|
| Homem, 85 anos | `U001` (Urgente) |
| Mulher, 81 anos | `U002` (Urgente) |
| Mulher, 30 anos, gestante | `P001` (Preferencial) |
| Mulher, 25 anos, lactante | `P002` (Preferencial) |
| Homem, 40 anos, com necessidade especial | `P003` (Preferencial) |
| Homem, 30 anos, com obesidade | `P004` (Preferencial) |
| Homem, 65 anos, sem outras condições | `P005` (Preferencial pela idade) |
| Homem, 64 anos, sem outras condições | `N001` (Normal) |
| Mulher, 60 anos, sem outras condições | `P006` (Preferencial pela idade) |
| Mulher, 59 anos, sem outras condições | `N002` (Normal) |
| Homem, 80 anos, sem outras condições | `P007` (não é urgente, pois 80 não é superior a 80) |

| Cenário | Resultado esperado |
|---|---|
| Cadastrar os pacientes acima e usar a opção 02 repetidamente | Ordem de chamada: `U001`, `U002`, depois todas as `P` na ordem de numeração, depois as `N` |
| Opção 02 sem ninguém aguardando | Mensagem "Nenhum paciente aguardando atendimento." |
| Idade com letras ou fora de 0 a 120 | Pede a idade de novo |
| Gênero diferente de F ou M | Pede o gênero de novo |
| Resposta diferente de S ou N | Pede a resposta de novo |
| Gênero masculino | As perguntas sobre gestação e lactação não são feitas |

## Limites e observações

- O sistema guarda até 1000 senhas por execução.
- Os dados ficam apenas na memória: ao encerrar o programa, nada é salvo.
- Os números de senha são exibidos com três dígitos (`001`, `002`...). Só se uma mesma categoria chegasse à senha 1000 é que o número apareceria com quatro dígitos.
- As respostas de letra (gênero e S/N) devem ser digitadas com uma única letra, em maiúscula ou minúscula.
