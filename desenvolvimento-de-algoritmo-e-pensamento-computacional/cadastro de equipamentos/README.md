# Cadastro de Equipamentos

Programa simples em linguagem C para cadastrar equipamentos, consultar os registros salvos e encerrar a execução.

## Funcionalidades

- **Cadastrar equipamento:** solicita nome, código e localização.
- **Listar equipamentos:** mostra os registros gravados no arquivo `equipamentos.txt`.
- **Salvar os dados:** acrescenta os novos cadastros ao arquivo de texto, preservando os registros anteriores.
- **Encerrar:** finaliza o programa ao selecionar a opção 3.

## Como funciona

O programa utiliza funções de manipulação de arquivos da linguagem C:

- `fopen()` abre o arquivo para leitura ou gravação.
- `fprintf()` escreve os dados cadastrados.
- `fgets()` lê os dados digitados e percorre as linhas do arquivo.
- `fclose()` fecha o arquivo após o uso.

O arquivo `equipamentos.txt` é criado automaticamente na pasta de execução quando o primeiro equipamento é cadastrado.

## Como compilar e executar

### Windows — GCC (MinGW/MSYS2)

1. Salve `cadastro_de_equipamentos.c` e abra o terminal na pasta do arquivo.
2. Compile:

   ```bash
   gcc cadastro_de_equipamentos.c -o cadastro_de_equipamentos
   ```

3. Execute no Prompt de Comando:

   ```bash
   cadastro_de_equipamentos.exe
   ```

   No terminal do VS Code ou em um terminal semelhante, também pode ser necessário usar:

   ```bash
   ./cadastro_de_equipamentos.exe
   ```

### Linux

```bash
gcc cadastro_de_equipamentos.c -o cadastro_de_equipamentos
./cadastro_de_equipamentos
```

É necessário ter o GCC instalado.

## Exemplo de uso

```text
===== MENU =====
1 - Cadastrar equipamento
2 - Listar equipamentos cadastrados
3 - Sair e gerar txt
Escolha: 1
Nome: Notebook Dell
Codigo: EQ001
Localizacao: Laboratorio 1
Cadastrado com sucesso!

===== MENU =====
1 - Cadastrar equipamento
2 - Listar equipamentos cadastrados
3 - Sair e gerar txt
Escolha: 2

===== EQUIPAMENTOS CADASTRADOS =====

Nome: Notebook Dell
Codigo: EQ001
Localizacao: Laboratorio 1
------------------------

===== MENU =====
1 - Cadastrar equipamento
2 - Listar equipamentos cadastrados
3 - Sair e gerar txt
Escolha: 3
Encerrando o programa...
```

## Exemplo do arquivo `equipamentos.txt`

Após cadastrar dois equipamentos, o conteúdo pode ficar assim:

```text
Nome: Notebook Dell
Codigo: EQ001
Localizacao: Laboratorio 1
------------------------
Nome: Projetor Epson
Codigo: EQ002
Localizacao: Sala 203
------------------------
```

## Observações

- O arquivo é aberto no modo `a` (acréscimo), então novos cadastros são adicionados ao final e não apagam os anteriores.
- A opção 2 apenas exibe o conteúdo do arquivo; ela não altera os registros.
- A opção 3 encerra o programa. O arquivo é gerado durante o cadastro, não apenas ao sair.
- Execute o programa na mesma pasta em que deseja manter `equipamentos.txt`, pois o caminho do arquivo é relativo à pasta de execução.

## Limitações do código atual

- O programa não valida se o usuário digitou uma opção válida.
- Se houver erro ao abrir o arquivo para gravação, o código atual não verifica esse erro.
- O texto do menu diz “Sair e gerar txt”, mas o arquivo já é criado/atualizado no momento do cadastro.
