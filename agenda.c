#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_telefone 20
#define TAM_email 50
#define TAM_NOME 50
#define TAM_cidade 50
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
void pausar(void);

void incluirContato(void);
void listarContatos(void);
void buscarContato(void);
void excluirContato(void);
void editarContato(void);
void ordenarContatos(void);

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
            pausar();
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
    printf("6. Ordenar contatos alfabeticamente\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void pausar(void){
    printf("\n Pressione ENTER para continuar... \n");
    getchar();
}

void incluirContato(void) {
    limparTela();
    cabecalho();

    if (num_contatos >= MAX_CONTATOS) {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
        pausar();
        return;
    }

    printf("=== Incluir Contato ===\n");
    Contato novo_contato;

    printf("Digite o nome: ");
    fgets(novo_contato.nome, TAM_NOME, stdin);
    novo_contato.nome[strcspn(novo_contato.nome, "\n")] = '\0'; // Remove o newline

    printf("Digite o telefone: ");
    fgets(novo_contato.telefone, TAM_telefone, stdin);
    novo_contato.telefone[strcspn(novo_contato.telefone, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(novo_contato.email, TAM_email, stdin);
    novo_contato.email[strcspn(novo_contato.email, "\n")] = '\0';

    printf("Digite a cidade: ");
    fgets(novo_contato.cidade, TAM_cidade, stdin);
    novo_contato.cidade[strcspn(novo_contato.cidade, "\n")] = '\0';

    printf("Digite a empresa: ");
    fgets(novo_contato.empresa, TAM_empresa, stdin);
    novo_contato.empresa[strcspn(novo_contato.empresa, "\n")] = '\0';

    printf("Digite uma observação: ");
    fgets(novo_contato.observacao, TAM_observacao, stdin);
    novo_contato.observacao[strcspn(novo_contato.observacao, "\n")] = '\0';

    agenda[num_contatos++] = novo_contato;
    printf("Contato adicionado com sucesso!\n");
    pausar();
}

void listarContatos(void) {
    limparTela();
    cabecalho();

    if (num_contatos == 0) {
        printf("Nenhum contato cadastrado!\n");
        pausar();
        return;
    }

    printf("=== Lista de Contatos ===\n");
    for (int i = 0; i < num_contatos; i++) {
        printf("Contato %i:\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Email: %s\n", agenda[i].email);
        printf("Cidade: %s\n", agenda[i].cidade);
        printf("Empresa: %s\n", agenda[i].empresa);
        printf("Observação: %s\n", agenda[i].observacao);
        printf("-----------------------------------\n");
    }
    pausar();
}

void buscarContato(void) {
    limparTela();
    cabecalho();

    if (num_contatos == 0) {
        printf("Nenhum contato cadastrado!\n");
        pausar();
        return;
    }

    char nome_busca[TAM_NOME];
    printf("Digite o nome do contato a ser buscado: ");
    fgets(nome_busca, TAM_NOME, stdin);
    nome_busca[strcspn(nome_busca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome_busca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            printf("Cidade: %s\n", agenda[i].cidade);
            printf("Empresa: %s\n", agenda[i].empresa);
            printf("Observação: %s\n", agenda[i].observacao);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado!\n");
    }
    pausar();
}

void excluirContato(void) {
    limparTela();
    cabecalho();

    if (num_contatos == 0) {
        printf("Nenhum contato cadastrado!\n");
        pausar();
        return;
    }

    char nome_excluir[TAM_NOME];
    printf("Digite o nome do contato a ser excluído: ");
    fgets(nome_excluir, TAM_NOME, stdin);
    nome_excluir[strcspn(nome_excluir, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome_excluir) == 0) {
            for (int j = i; j < num_contatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            num_contatos--;
            printf("Contato excluído com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado!\n");
    }
    pausar();
}

void editarContato(void) {
    limparTela();
    cabecalho();

    if (num_contatos == 0) {
        printf("Nenhum contato cadastrado!\n");
        pausar();
        return;
    }

    char nome_editar[TAM_NOME];
    printf("Digite o nome do contato a ser editado: ");
    fgets(nome_editar, TAM_NOME, stdin);
    nome_editar[strcspn(nome_editar, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < num_contatos; i++) {
        if (strcmp(agenda[i].nome, nome_editar) == 0) {
            printf("Contato encontrado. Digite os novos dados:\n");

            printf("Digite o nome: ");
            fgets(agenda[i].nome, TAM_NOME, stdin);
            agenda[i].nome[strcspn(agenda[i].nome, "\n")] = '\0';

            printf("Digite o telefone: ");
            fgets(agenda[i].telefone, TAM_telefone, stdin);
            agenda[i].telefone[strcspn(agenda[i].telefone, "\n")] = '\0';

            printf("Digite o email: ");
            fgets(agenda[i].email, TAM_email, stdin);
            agenda[i].email[strcspn(agenda[i].email, "\n")] = '\0';

            printf("Digite a cidade: ");
            fgets(agenda[i].cidade, TAM_cidade, stdin);
            agenda[i].cidade[strcspn(agenda[i].cidade, "\n")] = '\0';

            printf("Digite a empresa: ");
            fgets(agenda[i].empresa, TAM_empresa, stdin);
            agenda[i].empresa[strcspn(agenda[i].empresa, "\n")] = '\0';

            printf("Digite uma observação: ");
            fgets(agenda[i].observacao, TAM_observacao, stdin);
            agenda[i].observacao[strcspn(agenda[i].observacao, "\n")] = '\0';

            printf("Contato editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado!\n");
    }
    pausar();
}

void ordenarContatos(void) {
    limparTela();
    cabecalho();

    if (num_contatos == 0) {
        printf("Nenhum contato cadastrado!\n");
        pausar();
        return;
    }

    for (int i = 0; i < num_contatos - 1; i++) {
        for (int j = 0; j < num_contatos - i - 1; j++) {
            if (strcmp(agenda[j].nome, agenda[j + 1].nome) > 0) {
                Contato temp = agenda[j];
                agenda[j] = agenda[j + 1];
                agenda[j + 1] = temp;
            }
        }
    }

    printf("Contatos ordenados alfabeticamente por nome!\n");
    pausar();
}


