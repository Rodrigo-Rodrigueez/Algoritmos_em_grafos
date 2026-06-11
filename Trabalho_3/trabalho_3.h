typedef struct vertice vertice;
typedef struct NoAdj NoAdj;

vertice* inserir_vertice(vertice* vertice_origem, int valor);
void inserir_arestas(vertice* vertice_origem, int vert1, int vert2, int peso);
void visualizar_grafo(vertice* vertice_origem);
vertice* remover_vertice(vertice* vertice_origem, int index);
void remover_aresta(vertice* vertice_origem, int vert1, int vert2);
void liberar_grafo(vertice* vertice_origem);
int grau_vertice(vertice* vertice_origem, int vert);
int euleriano(vertice* vertice_origem);
int conexo(vertice* vertice_origem);
void ciclos(vertice* vertice_origem);