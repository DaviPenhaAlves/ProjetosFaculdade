#include <stddef.h>
#include "senhas.h"

/* Lista de pacientes (na ordem em que retiraram a senha) */
static Paciente pacientes[MAX_PACIENTES];
static int total = 0;

/* Um contador para cada tipo de senha */
static int contador_u = 0;
static int contador_p = 0;
static int contador_n = 0;

/* Regra do enunciado:
   U = mais de 80 anos | P = gestante ou necessidade especial | N = os demais */
static char classificar_paciente(int idade, int gestante, int necessidade_especial) {
    if (idade > IDADE_URGENTE) return 'U';
    if (gestante || necessidade_especial) return 'P';
    return 'N';
}

/* Cada tipo tem sua propria numeracao: U001, U002... P001, P002... N001, N002... */
static int gerar_numero(char tipo) {
    if (tipo == 'U') {
        contador_u++;
        return contador_u;
    }
    if (tipo == 'P') {
        contador_p++;
        return contador_p;
    }
    contador_n++;
    return contador_n;
}

int limite_atingido(void) {
    return total >= MAX_PACIENTES;
}

const Paciente *adicionar_paciente(Paciente novo) {
    if (limite_atingido())
        return NULL;

    novo.tipo = classificar_paciente(novo.idade, novo.gestante, novo.necessidade_especial);
    novo.numero = gerar_numero(novo.tipo);
    novo.atendido = 0;

    pacientes[total] = novo;
    total++;
    return &pacientes[total - 1];
}

/* Procura o primeiro paciente de um tipo que ainda nao foi chamado.
   Retorna a posicao na lista ou -1 se nao achar. */
static int procurar_proximo_do_tipo(char tipo) {
    for (int i = 0; i < total; i++) {
        if (pacientes[i].tipo == tipo && !pacientes[i].atendido)
            return i;
    }
    return -1;
}

const Paciente *chamar_proximo(void) {
    const char ordem[] = {'U', 'P', 'N'};

    for (int k = 0; k < 3; k++) {
        int i = procurar_proximo_do_tipo(ordem[k]);
        if (i != -1) {
            pacientes[i].atendido = 1;
            return &pacientes[i];
        }
    }
    return NULL;
}

int contar_aguardando(void) {
    int quantidade = 0;
    for (int i = 0; i < total; i++)
        if (!pacientes[i].atendido)
            quantidade++;
    return quantidade;
}

const char *nome_do_tipo(char tipo) {
    if (tipo == 'U') return "Urgente";
    if (tipo == 'P') return "Preferencial";
    return "Normal";
}
