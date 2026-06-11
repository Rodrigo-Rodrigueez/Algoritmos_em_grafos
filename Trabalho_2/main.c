#include "trabalho_2.h"
#include <stdio.h>

int main(void) {
    vertice *grafo = NULL;
    int opcao = 0;

    grafo = inserir_vertice(grafo, 1);
    grafo = inserir_vertice(grafo, 2);
    grafo = inserir_vertice(grafo, 3);
    grafo = inserir_vertice(grafo, 4);
    grafo = inserir_vertice(grafo, 5);
    grafo = inserir_vertice(grafo, 6);
    grafo = inserir_vertice(grafo, 7);
    grafo = inserir_vertice(grafo, 8);
    grafo = inserir_vertice(grafo, 9);

    inserir_arestas(grafo, 1, 2);
    inserir_arestas(grafo, 1, 6);
    inserir_arestas(grafo, 6, 4);
    inserir_arestas(grafo, 4, 2);
    inserir_arestas(grafo, 4, 5);
    inserir_arestas(grafo, 4, 7);
    inserir_arestas(grafo, 9, 7);
    inserir_arestas(grafo, 7, 8);
    inserir_arestas(grafo, 3, 2);
    inserir_arestas(grafo, 3, 5);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir Vertices\n");
        printf("2. Inserir Arestas\n");
        printf("3. Visualizar Grafo\n");
        printf("4. Remover Vertices\n");
        printf("5. Remover Arestas\n");
        printf("6. Sai\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            return 1;
        }
        switch (opcao) {
            case 1: {
                int v = 0;
                printf("Vertice: ");
                if (scanf("%d", &v) == 1) {
                    grafo = inserir_vertice(grafo, v);
                }
                break;
            }
            case 2: {
                int v1 = 0;
                int v2 = 0;
                printf("Vertice 1: ");
                if (scanf("%d", &v1) != 1) {
                    break;
                }
                printf("Vertice 2: ");
                if (scanf("%d", &v2) != 1) {
                    break;
                }
                inserir_arestas(grafo, v1, v2);
                break;
            }
            case 3:
                visualizar_grafo(grafo);
                break;
            case 4: {
                int v = 0;
                printf("Vertice: ");
                if (scanf("%d", &v) == 1) {
                    grafo = remover_vertice(grafo, v);
                }
                break;
            }
            case 5: {
                int v1 = 0;
                int v2 = 0;
                printf("Vertice 1: ");
                if (scanf("%d", &v1) != 1) {
                    break;
                }
                printf("Vertice 2: ");
                if (scanf("%d", &v2) != 1) {
                    break;
                }
                remover_aresta(grafo, v1, v2);
                break;
            }
            case 6:
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
