#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_telefone 20
#define TAM_email 50
#define TAM_NOME 50
#define TAM_email 50
#define TAM_empresa 50
#define TAM_observacao 120

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_telefone];
    char email[TAM_email];
    char cidade[TAM_cidade];
    char empresa[TAM_empresa];
    char observacao[TAM_observacao];
} Contato;

Contato agenda[MAX_CONTATOS];
int num_contatos = 0;

void limparTela(void);
void cabecalho(void);
void menu(void);
void limparBuffer(void);

int main(void){
    int opcao;

    do{
        limparTela();
        cabecalho();
        menu();

        printf("Escolha uma opção: ");
        scanf("%i", &opcao);
        limparBuffer();

        switch(opcao){
            case 1: incluirContato(); break;
            case 2: listarContatos(); break;
            case 3: buscarContato(); break;
            case 4: excluirContato(); break;
            case 5: editarContato(); break;
            case 6: ordenarContatos(); break;
            case 7: 
            printf("Saindo do programa...\n\n");
            break;
            default: 
            printf("Opção inválida! Tente novamente.\n");
        }
    }while(opcao != 7);

    return 0;
}

void limparTela(void) {
    system("cls||clear");
}

void cabecalho(void) {
    printf("=====================================\n");
    printf("         AGENDA DE CONTATOS         \n");
    printf("=====================================\n");
}

void menu(void) {
    printf("1. Incluir contato\n");
    printf("2. Listar contatos\n");
    printf("3. Buscar contato\n");
    printf("4. Excluir contato\n");
    printf("5. Editar contato\n");
    printf("6. Ordenar contatos\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}