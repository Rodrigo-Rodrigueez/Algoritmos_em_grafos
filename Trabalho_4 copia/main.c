#include "trabalho_4.h"
#include <stdio.h>

int main(void) {

    
    vertice* grafo = NULL;
    grafo = inserir_vertice(grafo, 1);
    grafo = inserir_vertice(grafo, 2);
    grafo = inserir_vertice(grafo, 3);
    grafo = inserir_vertice(grafo, 4);
    grafo = inserir_vertice(grafo, 5);
    inserir_arestas(grafo, 1, 2, 10);
    inserir_arestas(grafo, 2, 3, 20);
    inserir_arestas(grafo, 3, 4, 30);
    inserir_arestas(grafo, 4, 5, 40);
    inserir_arestas(grafo, 5, 1, 50);

    vertice* grafos[1] = {grafo};
    const char* nomes[6] = {"grafo"};
    int selecionado = 0;
    int opcao = 0;

    printf("=== Menu interativo ===\n");
    printf("Grafo ativo: %s\n", nomes[selecionado]);

    do {
        printf("\nMenu:\n");
        printf("0.  Selecionar grafo\n");
        printf("1.  Inserir Vertices\n");
        printf("2.  Inserir Arestas\n");
        printf("3.  Visualizar Grafo\n");
        printf("4.  Remover Vertices\n");
        printf("5.  Remover Arestas\n");
        printf("6.  Grau de um vertice\n");
        printf("7.  Verificar se o grafo e conexo\n");
        printf("8.  Verificar se o grafo e euleriano\n");
        printf("9.  Verificar ciclos por componente\n");
        printf("10. Algoritmo de Hierholzer (ciclo euleriano)\n");
        printf("11. Sair\n");
        printf("Escolha [grafo ativo: %s]: ", nomes[selecionado]);

        if (scanf("%d", &opcao) != 1) return 1;

        switch (opcao) {
            case 0: {
                printf("Grafos disponiveis:\n");
                for (int i = 0; i < 6; i++)
                    printf("  %d. %s\n", i, nomes[i]);
                printf("Selecione (0-5): ");
                int g = 0;
                if (scanf("%d", &g) == 1 && g >= 0 && g < 6) {
                    selecionado = g;
                    printf("Grafo ativo: %s\n", nomes[selecionado]);
                }
                break;
            }
            case 1: {
                int v = 0;
                printf("Vertice: ");
                if (scanf("%d", &v) == 1)
                    grafos[selecionado] = inserir_vertice(grafos[selecionado], v);
                break;
            }
            case 2: {
                int v1 = 0, v2 = 0, peso = 0;
                printf("Vertice 1: ");
                if (scanf("%d", &v1) != 1) break;
                printf("Vertice 2: ");
                if (scanf("%d", &v2) != 1) break;
                printf("Peso: ");
                if (scanf("%d", &peso) != 1) break;
                inserir_arestas(grafos[selecionado], v1, v2, peso);
                break;
            }
            case 3:
                visualizar_grafo(grafos[selecionado]);
                break;
            case 4: {
                int v = 0;
                printf("Vertice: ");
                if (scanf("%d", &v) == 1)
                    grafos[selecionado] = remover_vertice(grafos[selecionado], v);
                break;
            }
            case 5: {
                int v1 = 0, v2 = 0;
                printf("Vertice 1: ");
                if (scanf("%d", &v1) != 1) break;
                printf("Vertice 2: ");
                if (scanf("%d", &v2) != 1) break;
                remover_aresta(grafos[selecionado], v1, v2);
                break;
            }
            case 6: {
                int v = 0;
                printf("Vertice: ");
                if (scanf("%d", &v) == 1)
                    grau_vertice(grafos[selecionado], v);
                break;
            }
            case 7:
                conexo(grafos[selecionado]);
                break;
            case 8: {
                int result = euleriano(grafos[selecionado]);
                if (result == 1)
                    printf("O grafo possui circuito euleriano.\n");
                else
                    printf("O grafo nao e euleriano.\n");
                break;
            }
            case 9:
                ciclos(grafos[selecionado]);
                break;
            case 10:
                hierholzer(grafos[selecionado]);
                break;
            case 11:
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 11);

    for (int i = 0; i < 6; i++)
        liberar_grafo(grafos[i]);

    return 0;
}
