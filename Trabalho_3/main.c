#include "trabalho_3.h"
#include <stdio.h>

int main(void) {

    // =========================================================
    // g1: arestas 1-2, 1-3, 1-4, 2-3
    // Conexo: sim (1 componente)
    // Euleriano: nao (vertices 1 e 4 com grau impar)
    // Ciclos: 1 (V=4, E=4 -> E-V+1=1)
    // =========================================================
    vertice* g1 = NULL;
    g1 = inserir_vertice(g1, 1);
    g1 = inserir_vertice(g1, 2);
    g1 = inserir_vertice(g1, 3);
    g1 = inserir_vertice(g1, 4);
    inserir_arestas(g1, 1, 2, 10);
    inserir_arestas(g1, 1, 3, 20);
    inserir_arestas(g1, 1, 4, 30);
    inserir_arestas(g1, 2, 3, 40);

    // =========================================================
    // g2: caminho 1-2-3-4-5
    // Conexo: sim (1 componente)
    // Euleriano: nao (vertices 1 e 5 com grau impar)
    // Ciclos: 0 (V=5, E=4 -> E-V+1=0)
    // =========================================================
    vertice* g2 = NULL;
    g2 = inserir_vertice(g2, 1);
    g2 = inserir_vertice(g2, 2);
    g2 = inserir_vertice(g2, 3);
    g2 = inserir_vertice(g2, 4);
    g2 = inserir_vertice(g2, 5);
    inserir_arestas(g2, 1, 2, 10);
    inserir_arestas(g2, 2, 3, 20);
    inserir_arestas(g2, 3, 4, 30);
    inserir_arestas(g2, 4, 5, 40);

    // =========================================================
    // g3: 3 componentes desconexas
    //   Comp A: path 1-2-3        (V=3, E=2 -> 0 ciclos)
    //   Comp B: aresta 4-5        (V=2, E=1 -> 0 ciclos)
    //   Comp C: vertice isolado 6 (V=1, E=0 -> 0 ciclos)
    // Conexo: nao (3 componentes)
    // Euleriano: nao (desconexo)
    // Ciclos: nenhuma componente possui ciclos
    // =========================================================
    vertice* g3 = NULL;
    g3 = inserir_vertice(g3, 1);
    g3 = inserir_vertice(g3, 2);
    g3 = inserir_vertice(g3, 3);
    g3 = inserir_vertice(g3, 4);
    g3 = inserir_vertice(g3, 5);
    g3 = inserir_vertice(g3, 6);
    inserir_arestas(g3, 1, 2, 10);
    inserir_arestas(g3, 2, 3, 20);
    inserir_arestas(g3, 4, 5, 30);

    // =========================================================
    // g4: 3 componentes desconexas
    //   Comp 0: triangulo 1-2-3-1       (V=3, E=3 -> 1 ciclo)
    //   Comp 1: path 4-5-6              (V=3, E=2 -> 0 ciclos)
    //   Comp 2: quadrado 7-8-9-10-7     (V=4, E=4 -> 1 ciclo)
    // Conexo: nao (3 componentes)
    // Euleriano: nao (desconexo)
    // Ciclos: comp0->1, comp1->0, comp2->1
    // =========================================================
    vertice* g4 = NULL;
    g4 = inserir_vertice(g4, 1);
    g4 = inserir_vertice(g4, 2);
    g4 = inserir_vertice(g4, 3);
    g4 = inserir_vertice(g4, 4);
    g4 = inserir_vertice(g4, 5);
    g4 = inserir_vertice(g4, 6);
    g4 = inserir_vertice(g4, 7);
    g4 = inserir_vertice(g4, 8);
    g4 = inserir_vertice(g4, 9);
    g4 = inserir_vertice(g4, 10);
    inserir_arestas(g4, 1, 2, 10);
    inserir_arestas(g4, 2, 3, 20);
    inserir_arestas(g4, 3, 1, 30);
    inserir_arestas(g4, 4, 5, 40);
    inserir_arestas(g4, 5, 6, 50);
    inserir_arestas(g4, 7, 8, 60);
    inserir_arestas(g4, 8, 9, 70);
    inserir_arestas(g4, 9, 10, 80);
    inserir_arestas(g4, 10, 7, 90);

    // =========================================================
    // g5:  1-2-3-4-1
    // Conexo: sim (1 componente)
    // Euleriano: sim (todos os vertices com grau 2)
    // Ciclos: 1 (V=4, E=4 -> E-V+1=1)
    // =========================================================
    vertice* g5 = NULL;
    g5 = inserir_vertice(g5, 1);
    g5 = inserir_vertice(g5, 2);
    g5 = inserir_vertice(g5, 3);
    g5 = inserir_vertice(g5, 4);
    inserir_arestas(g5, 1, 2, 10);
    inserir_arestas(g5, 2, 3, 20);
    inserir_arestas(g5, 3, 4, 30);
    inserir_arestas(g5, 4, 1, 40);

    // =========================================================
    // grafo 1-2-3-4-5-1
    // Conexo: sim (1 componente)
    // Euleriano: sim (todos os vertices com grau 2)
    // Ciclos: 1 (V=5, E=5 -> E-V+1=1)
    // =========================================================
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

    vertice* grafos[6] = {g1, g2, g3, g4, g5, grafo};
    const char* nomes[6] = {"g1", "g2", "g3", "g4", "g5", "grafo"};
    int selecionado = 5;
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
        printf("10. Sair\n");
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
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 10);

    for (int i = 0; i < 6; i++)
        liberar_grafo(grafos[i]);

    return 0;
}
