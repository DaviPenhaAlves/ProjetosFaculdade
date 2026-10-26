#include <stdio.h>

int main(){
    FILE *arquivo;
    char nome[100];
    char codigo[50];
    char local[100];
    char linha[100];
    int opcao;
    
    do{
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos cadastrados\n");
        printf("3 - Sair e gerar txt\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            printf("Nome: ");
            fgets(nome, sizeof(nome), stdin);

            printf("Codigo: ");
            fgets(codigo, sizeof(codigo), stdin);

            printf("Localizacao: ");
            fgets(local, sizeof(local), stdin);

            arquivo = fopen("equipamentos.txt", "a");
            fprintf(arquivo, "Nome: %s", nome);
            fprintf(arquivo, "Codigo: %s", codigo);
            fprintf(arquivo, "Localizacao: %s", local);
            fprintf(arquivo, "------------------------\n");
            fclose(arquivo);

            printf("Cadastrado com sucesso!\n");
    }
    
    if (opcao == 2) {
            arquivo = fopen("equipamentos.txt", "r");

            if (arquivo == NULL) {
                printf("\nNenhum equipamento cadastrado ainda.\n");
            } else {
                printf("\n===== EQUIPAMENTOS CADASTRADOS =====\n\n");

                while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                    printf("%s", linha);
                }

                fclose(arquivo);
            }
        }

    } while (opcao != 3);

    printf("Encerrando o programa...\n");
    return 0;
}