#include <stdio.h>
#include <string.h>

// Definição da estrutura para agrupar os dados
struct Produto {
    int id;
    char nome[50];
};

int main() {
    struct Produto lista[10];
    int opcao, i, idBusca, encontrado;

    // Inicializa todos os IDs com 0 (indicando vazio)
    for(i = 0; i < 10; i++) {
        lista[i].id = 0;
    }

//Como nao sei quantas vezes se repetirá o processo de testes, usarei o Do While
    do {
        printf("\n===== MENU PRODUTOS =====\n");
        printf("1 - Inclusao\n2 - Consulta\n3 - Alteracao\n4 - Exclusao\n5 - Listar todos\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Inclusão
                encontrado = 0;
                for(i = 0; i < 10; i++) {
                    if(lista[i].id == 0) {
                        printf("Digite o ID: ");
                        scanf("%d", &lista[i].id);
                        printf("Digite o Nome: ");
                        scanf(" %[^\n]s", lista[i].nome); // Lê string com espaços
                        printf("Cadastrado com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("Lista cheia!\n");
                break;

            case 2: // Consulta
                printf("ID para busca: ");
                scanf("%d", &idBusca);
                encontrado = 0;
                for(i = 0; i < 10; i++) {
                    if(lista[i].id == idBusca && lista[i].id != 0) {
                        printf("Encontrado na posicao %d: %s\n", i, lista[i].nome);
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("Nao encontrado.\n");
                break;

            case 3: // Alteração
                printf("ID para alterar: ");
                scanf("%d", &idBusca);
                encontrado = 0;
                for(i = 0; i < 10; i++) {
                    //o ponto aqui usado em lista[i].id é um operador de acesso a membro, como se eu estive usando um terminal CMD
                    //eu coloco o ponto para dizer que é este aqui que quero acessar
                    if(lista[i].id == idBusca && lista[i].id != 0) {
                        printf("Novo Nome: ");
                        //scanf feito com um método novo para mim, ele funciona para ler mensagens compostas exemplo: "Feijão Fradinho" 
                        //ele limpa o espaço do começo e o espaço final
                        scanf(" %[^\n]s", lista[i].nome);
                        printf("Alterado!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("ID nao localizado.\n");
                break;

            case 4: // Exclusão
                printf("ID para excluir: ");
                scanf("%d", &idBusca);
                encontrado = 0;
                for(i = 0; i < 10; i++) {
                    if(lista[i].id == idBusca && lista[i].id != 0) {
                        lista[i].id = 0; // "Remove" marcando como vazio
                        printf("Excluido com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("ID nao localizado.\n");
                break;

            case 5: // Listar
                printf("\n--- Produtos Cadastrados ---\n");
                for(i = 0; i < 10; i++) {
                    if(lista[i].id != 0) {
                        printf("[%d] ID: %d | Nome: %s\n", i, lista[i].id, lista[i].nome);
                    }
                }
                break;
        }
    } while(opcao != 0);

    return 0;
}