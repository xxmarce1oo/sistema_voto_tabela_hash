#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10 // Tamanho da tabela hash
#define NAME_SIZE 50  // Tamanho maximo do nome

// Estrutura para representar um contato
typedef struct Contato {
    char nome[NAME_SIZE];
    char telefone[15];
    struct Contato* prox; // Proximo contato na lista encadeada
} Contato;

// Tabela hash (vetor de ponteiros para listas encadeadas)
Contato* tabela[TABLE_SIZE];

// Funcao hash simples baseada na soma dos valores ASCII dos caracteres
unsigned int hash(char* nome) {
    unsigned int hash = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        hash += nome[i];
    }
    return hash % TABLE_SIZE;
}

// Adicionar contato
void adicionarContato(char* nome, char* telefone) {
    unsigned int indice = hash(nome);
    Contato* atual = tabela[indice];

    // Verifica se o contato já existe (para não permitir duplicidade de nomes)
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Contato com esse nome ja existe.\n");
            return;
        }
        atual = atual->prox;
    }

    // Se o nome não existe, adiciona o novo contato
    Contato* novoContato = (Contato*)malloc(sizeof(Contato));
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->telefone, telefone);
    novoContato->prox = tabela[indice];
    tabela[indice] = novoContato;
    printf("Contato adicionado com sucesso.\n");
}

// Buscar contato
void buscarContato(char* nome) {
    unsigned int indice = hash(nome);
    Contato* atual = tabela[indice];
    clock_t inicio = clock(); // Inicio da medicao de tempo

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            clock_t fim = clock(); // Fim da medicao de tempo
            double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
            printf("Telefone de %s: %s (tempo de busca: %.2f ms)\n", nome, atual->telefone, tempo);
            return;
        }
        atual = atual->prox;
    }

    // Caso o contato não seja encontrado
    printf("Contato nao encontrado.\n");
}

// Remover contato
void removerContato(char* nome) {
    unsigned int indice = hash(nome);
    Contato* atual = tabela[indice];
    Contato* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Contato removido com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    // Caso o contato não seja encontrado
    printf("Contato nao encontrado.\n");
}

// Mostrar todos os contatos
void exibirContatos() {
    int encontrou = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        Contato* atual = tabela[i];
        if (atual != NULL) {
            printf("Indice %d:\n", i);
            while (atual != NULL) {
                printf("  Nome: %s, Telefone: %s\n", atual->nome, atual->telefone);
                atual = atual->prox;
            }
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum contato encontrado.\n");
    }
}

// Menu principal
int main() {
    int opcao;
    char nome[NAME_SIZE];
    char telefone[15];

    // Inicializar tabela hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela[i] = NULL;
    }

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar contato por nome\n");
        printf("3 - Remover contato\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, NAME_SIZE, stdin);
                nome[strcspn(nome, "\n")] = 0; // Remover o '\n'
                printf("Telefone: ");
                fgets(telefone, 15, stdin);
                telefone[strcspn(telefone, "\n")] = 0;
                adicionarContato(nome, telefone);
                break;
            case 2:
                printf("Nome: ");
                fgets(nome, NAME_SIZE, stdin);
                nome[strcspn(nome, "\n")] = 0;
                buscarContato(nome);
                break;
            case 3:
                printf("Nome: ");
                fgets(nome, NAME_SIZE, stdin);
                nome[strcspn(nome, "\n")] = 0;
                removerContato(nome);
                break;
            case 4:
                exibirContatos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberar memoria
    for (int i = 0; i < TABLE_SIZE; i++) {
        Contato* atual = tabela[i];
        while (atual != NULL) {
            Contato* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    return 0;
}
