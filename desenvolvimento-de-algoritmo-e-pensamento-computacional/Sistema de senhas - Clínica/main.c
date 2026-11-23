#include <stdio.h>
#include "senhas.h"
#include "entrada.h"

/* Ultimo paciente chamado (NULL = ninguem foi chamado ainda) */
static const Paciente *senha_no_painel = NULL;

static void mostrar_painel(void) {
    printf("\n============ PAINEL DE ATENDIMENTO ============\n");
    if (senha_no_painel == NULL)
        printf("Senha em atendimento: ---\n");
    else
        printf("Senha em atendimento: %c%03d - %s\n",
               senha_no_painel->tipo, senha_no_painel->numero, senha_no_painel->nome);
    printf("Pacientes aguardando: %d\n", contar_aguardando());
    printf("===============================================\n");
}

static void mostrar_menu(void) {
    printf("\n----------------- MENU -----------------\n");
    printf("01 - Retirar senha\n");
    printf("02 - Registrar atendimento\n");
    printf("00 - Sair\n");
}

static void retirar_senha(void) {
    Paciente novo = {0};

    if (limite_atingido()) {
        printf("Limite de senhas atingido.\n");
        return;
    }

    printf("\n--- RETIRAR SENHA ---\n");
    ler_nome("Nome: ", novo.nome, TAM_NOME);
    novo.idade = ler_inteiro("Idade: ", 0, 120);
    novo.genero = ler_opcao("Genero (F=feminino, M=masculino, O=outro): ", "FMO");

    /* so pergunta sobre gestacao se for mulher */
    if (novo.genero == 'F')
        novo.gestante = (ler_opcao("Esta gestante? (S/N): ", "SN") == 'S');
    else
        novo.gestante = 0;

    novo.necessidade_especial = (ler_opcao("Possui alguma necessidade especial? (S/N): ", "SN") == 'S');

    const Paciente *guardado = adicionar_paciente(novo);

    printf("\nSenha retirada com sucesso!\n");
    printf("Paciente: %s\n", guardado->nome);
    printf("Senha: %c%03d\n", guardado->tipo, guardado->numero);
    printf("Tipo de atendimento: %s\n", nome_do_tipo(guardado->tipo));
}

static void registrar_atendimento(void) {
    const Paciente *chamado = chamar_proximo();

    if (chamado == NULL) {
        printf("\nNenhum paciente aguardando atendimento.\n");
        return;
    }

    senha_no_painel = chamado;
    printf("\nChamando proximo paciente: senha %c%03d\n", chamado->tipo, chamado->numero);
}

int main(void) {
    int opcao;

    do {
        mostrar_painel();
        mostrar_menu();
        opcao = ler_inteiro("Escolha uma opcao: ", 0, 2);

        switch (opcao) {
            case 1: retirar_senha();        break;
            case 2: registrar_atendimento(); break;
            case 0: printf("Encerrando o sistema.\n"); break;
        }
    } while (opcao != 0);

    return 0;
}
