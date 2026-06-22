#include "trabalho_5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct NoAdj {
    int v;
    int peso;
    int visitado;
    struct NoAdj *next;
};

struct vertice{
    int indice;
    NoAdj* arestas;
    vertice* next;
};


vertice* inserir_vertice(vertice* vertice_origem, int valor){
    vertice* vert = vertice_origem;
    if(vert != NULL){
        while(vert->next != NULL){
            if(vert->indice == valor){
                return vertice_origem;
            }
            vert = vert->next;
        }
        if(vert->indice == valor){
            return vertice_origem;
        }

        vertice* vert_inserido = malloc(sizeof(vertice));
        vert_inserido->indice = valor;
        vert_inserido->arestas = NULL;
        vert_inserido->next = NULL;

        vert->next = vert_inserido;
        return vertice_origem;
    }

    vertice* vert_inserido = malloc(sizeof(vertice));
    vert_inserido->indice = valor;
    vert_inserido->arestas = NULL;
    vert_inserido->next = NULL;

    return vert_inserido;
}

void inserir_arestas(vertice* vertice_origem, int vert1, int vert2, int peso){
    //1 caso - > arestas = NULL (nenhuma aresta ainda)
    //2 caso - > já tem pelo menos 1 aresta arestas != NULL
    //inserção no final da lista de arestas

    //checar se vertices existem

    vertice* vert = vertice_origem;
    vertice* vert_iterador = vertice_origem;
    NoAdj* aresta_auxiliar_1 = NULL;
    int vert1_check = 0, vert2_check = 0, aresta1_check = 0, aresta2_check = 0;

    if(vertice_origem == NULL){
        return;
    }
    if(vert1 == vert2){
        return;
    }
    do{
        if(vert->indice == vert1){
            aresta_auxiliar_1 = vert->arestas;
            vert1_check = 1;
            while(aresta_auxiliar_1 != NULL){
                if(aresta_auxiliar_1->v == vert2){
                    aresta1_check = 1;
                    break;
                }
                aresta_auxiliar_1 = aresta_auxiliar_1->next;
            }

        }
        if(vert->indice == vert2){
            aresta_auxiliar_1 = vert->arestas;
            vert2_check = 1;
            while(aresta_auxiliar_1 != NULL){
                if(aresta_auxiliar_1->v == vert1 ){
                    aresta2_check = 1;
                    break;
                }
                aresta_auxiliar_1 = aresta_auxiliar_1->next;
            }
        }

        vert = vert->next;
    }while(vert != NULL);

    if(vert1_check == 1 && vert2_check == 1 && aresta1_check == 0 && aresta2_check == 0){

        do{
            if(vert_iterador->indice == vert1){
                vert = vert_iterador;
                if(vert->arestas != NULL){
                    NoAdj* aresta_auxiliar = vert->arestas;
                    while(aresta_auxiliar->next != NULL){
                        aresta_auxiliar = aresta_auxiliar->next;
                    }
                    NoAdj* nova_aresta = malloc(sizeof(NoAdj));
                    nova_aresta->v = vert2;
                    nova_aresta->next = NULL;
                    nova_aresta->peso = peso;
                    nova_aresta->visitado = 0;
                    aresta_auxiliar->next = nova_aresta;
                }
                else{
                    NoAdj* nova_aresta = malloc(sizeof(NoAdj));
                    nova_aresta->v = vert2;
                    nova_aresta->next = NULL;
                    nova_aresta->peso = peso;
                    nova_aresta->visitado = 0;
                    vert->arestas = nova_aresta;
                }

            }
            else if(vert_iterador->indice == vert2){
                vert = vert_iterador;
                if(vert->arestas != NULL){
                    NoAdj* aresta_auxiliar = vert->arestas;
                    while(aresta_auxiliar->next != NULL){
                        aresta_auxiliar = aresta_auxiliar->next;
                    }
                    NoAdj* nova_aresta = malloc(sizeof(NoAdj));
                    nova_aresta->v = vert1;
                    nova_aresta->next = NULL;
                    nova_aresta->peso = peso;
                    nova_aresta->visitado = 0;
                    aresta_auxiliar->next = nova_aresta;
                }
                else{
                    NoAdj* nova_aresta = malloc(sizeof(NoAdj));
                    nova_aresta->v = vert1;
                    nova_aresta->next = NULL;
                    nova_aresta->peso = peso;
                    nova_aresta->visitado = 0;
                    vert->arestas = nova_aresta;
                }
            }

            vert_iterador = vert_iterador->next;
        }while(vert_iterador != NULL);
    }

    
}

void visualizar_grafo(vertice* vertice_origem){

    if(vertice_origem != NULL){
        vertice* vertice_auxiliar = vertice_origem;
        do{
            NoAdj* auxiliar_arestas = vertice_auxiliar->arestas;
            printf("%d", vertice_auxiliar->indice);
            while(auxiliar_arestas != NULL){
                printf(" -(%d)->%d", auxiliar_arestas->peso, auxiliar_arestas->v);
                auxiliar_arestas = auxiliar_arestas->next;
            }
            printf("\n");
            vertice_auxiliar = vertice_auxiliar->next;
            if(vertice_auxiliar != NULL){
                printf("|\n");
                printf("v\n");
            }
        }while(vertice_auxiliar != NULL);

    }
}


void remover_aresta(vertice* vertice_origem, int vert1, int vert2){
    //1 caso - > ultima aresta
    //2 caso - > aresta intermediaria
    //3 caso - > unica aresta

    //checar se vertices existem

    vertice* vert = vertice_origem;
    vertice* vert_iterador = vertice_origem;
    NoAdj* aresta_auxiliar_anterior = NULL;
    NoAdj* aresta_auxiliar_atual = NULL;
    int vert1_check = 0, vert2_check = 0;

    if(vertice_origem == NULL){
        return;
    }

    do{
        if(vert->indice == vert1){
            vert1_check = 1;
        }
        if(vert->indice == vert2){
            vert2_check = 1;
        }

        vert = vert->next;
    }while(vert != NULL);

    if(vert1_check == 1 && vert2_check == 1){
        vert = vertice_origem;

        do{
            if(vert_iterador->indice == vert1){
                vert = vert_iterador;

                if(vert->arestas != NULL && vert->arestas->v == vert2){
                    NoAdj* temp = vert->arestas;
                    vert->arestas = vert->arestas->next;
                    free(temp);
                }
                else if(vert->arestas != NULL){
                    aresta_auxiliar_atual = vert->arestas;
                    aresta_auxiliar_anterior = vert->arestas;
                    while(aresta_auxiliar_atual->next != NULL && aresta_auxiliar_atual->v != vert2){
                        aresta_auxiliar_anterior = aresta_auxiliar_atual;
                        aresta_auxiliar_atual = aresta_auxiliar_atual->next;
                    }
                    if(aresta_auxiliar_atual->next != NULL && aresta_auxiliar_atual->v == vert2){
                        NoAdj* temp = aresta_auxiliar_atual;
                        aresta_auxiliar_anterior->next = aresta_auxiliar_atual->next;
                        free(temp);
                    }else if(aresta_auxiliar_atual->v == vert2){
                        free(aresta_auxiliar_atual);
                        aresta_auxiliar_anterior->next = NULL;
                        aresta_auxiliar_anterior = NULL;
                    }
                }
                aresta_auxiliar_anterior = NULL;
                aresta_auxiliar_atual = NULL;
                

            }
            else if(vert_iterador->indice == vert2){
                vert = vert_iterador;
                if(vert->arestas != NULL && vert->arestas->v == vert1){
                    NoAdj* temp = vert->arestas;
                    vert->arestas = vert->arestas->next;
                    free(temp);
                }
                else if(vert->arestas != NULL){
                    aresta_auxiliar_atual = vert->arestas;
                    aresta_auxiliar_anterior = vert->arestas;
                    while(aresta_auxiliar_atual->next != NULL && aresta_auxiliar_atual->v != vert1){
                        aresta_auxiliar_anterior = aresta_auxiliar_atual;
                        aresta_auxiliar_atual = aresta_auxiliar_atual->next;
                    }
                    if(aresta_auxiliar_atual->next != NULL && aresta_auxiliar_atual->v == vert1){
                        NoAdj* temp = aresta_auxiliar_atual;
                        aresta_auxiliar_anterior->next = aresta_auxiliar_atual->next;
                        free(temp);
                    }else if(aresta_auxiliar_atual->v == vert1){
                        free(aresta_auxiliar_atual);
                        aresta_auxiliar_anterior->next = NULL;
                        aresta_auxiliar_anterior = NULL;
                    }
                }
                aresta_auxiliar_anterior = NULL;
                aresta_auxiliar_atual = NULL;
            }

            vert_iterador = vert_iterador->next;
        }while(vert_iterador != NULL);
    }

    
}

//1 caso - > 1° vertice
//2 caso - > vertice intermediario
//3 caso - > ultimo vertice
vertice* remover_vertice(vertice* vertice_origem, int index){
    if(vertice_origem != NULL){
        NoAdj* aresta_auxiliar = NULL;
        vertice* vert_iterador = vertice_origem;
        
        if(vert_iterador->indice == index){
            
            aresta_auxiliar = vert_iterador->arestas;
            do{
                NoAdj* prox_aresta = aresta_auxiliar->next;
                remover_aresta(vertice_origem, vert_iterador->indice, aresta_auxiliar->v);
                aresta_auxiliar = prox_aresta;
                
            }while(aresta_auxiliar != NULL);
            vertice_origem = vert_iterador->next;
            free(vert_iterador);
            return vertice_origem;
        }

        vertice* vertice_anterior = vert_iterador;
        
        while(vert_iterador->next != NULL && vert_iterador->indice != index){
            vertice_anterior = vert_iterador;
            vert_iterador = vert_iterador->next;
        }
        if(vert_iterador->next != NULL && vert_iterador->indice == index){
            
            aresta_auxiliar = vert_iterador->arestas;
            do{
                NoAdj* prox_aresta = aresta_auxiliar->next;
                remover_aresta(vertice_origem, index, aresta_auxiliar->v);
                aresta_auxiliar = prox_aresta;
                
            }while(aresta_auxiliar != NULL);
            vertice_anterior->next = vert_iterador->next;
            free(vert_iterador);
        }else if(vert_iterador->indice == index){
            
            aresta_auxiliar = vert_iterador->arestas;
            do{
                NoAdj* prox_aresta = aresta_auxiliar->next;
                remover_aresta(vertice_origem, index, aresta_auxiliar->v);
                aresta_auxiliar = prox_aresta;
                
                
            }while(aresta_auxiliar != NULL);
            vertice_anterior->next = NULL;
            free(vert_iterador);
        }


    }

    return vertice_origem;
}

void liberar_grafo(vertice* vertice_origem){
    vertice* vert_atual = vertice_origem;
    while(vert_atual != NULL){
        NoAdj* aresta_atual = vert_atual->arestas;
        while(aresta_atual != NULL){
            NoAdj* prox_aresta = aresta_atual->next;
            free(aresta_atual);
            aresta_atual = prox_aresta;
        }
        vertice* prox_vert = vert_atual->next;
        free(vert_atual);
        vert_atual = prox_vert;
    }
}

int grau_vertice(vertice* vertice_origem, int vertice_index){
    vertice* vert = vertice_origem;
    while(vert != NULL){
        if(vert->indice == vertice_index){
            NoAdj* aresta_auxiliar = vert->arestas;
            int grau = 0;
            while(aresta_auxiliar != NULL){
                grau++;
                aresta_auxiliar = aresta_auxiliar->next;
            }
            printf("Grau do vertice %d: %d\n", vertice_index, grau);
            return grau;
        }
        vert = vert->next;
    }
    printf("Vertice %d nao encontrado.\n", vertice_index);
    return -1;
}


static int encontrar_pos(int* indices, int n, int alvo) {
    for (int i = 0; i < n; i++)
        if (indices[i] == alvo) return i;
    return -1;
}

static void limpa_arestas(vertice* vertice_origem) {
    vertice* v = vertice_origem;
    while (v != NULL) {
        NoAdj* adj = v->arestas;
        while (adj != NULL) {
            adj->visitado = 0;
            adj = adj->next;
        }
        v = v->next;
    }
}
static void dfs(vertice* vertice_origem, int v_idx, int* indices, int* visitado, int* componente, int comp_id, int n, int* ciclos) {

    int pos = encontrar_pos(indices, n, v_idx);
    if (pos == -1 || visitado[pos]){
        return;
    }
    // marcar v como visitado
    visitado[pos] = 1;
    componente[pos] =  comp_id;

    vertice* v = vertice_origem;
    while (v != NULL && v->indice != v_idx){
        v = v->next;
    }
    if (v == NULL) return;

    //para cada vizinho w (adj->v)
    NoAdj* adj = v->arestas;
    while (adj != NULL) {
        int vizinho_pos = encontrar_pos(indices, n, adj->v);

        if (vizinho_pos != -1 && visitado[vizinho_pos] == 0) {
            // w não visitado -> visita aresta e recursiona
            adj->visitado = 1;
            // visitar aresta reversa w->v
            vertice* v2 = vertice_origem;
            while (v2 != NULL && v2->indice != adj->v) v2 = v2->next;
            if (v2 != NULL) {
                NoAdj* rev = v2->arestas;
                while (rev != NULL) {
                    if (rev->v == v_idx) { 
                        rev->visitado = 1; break; 
                    }
                    rev = rev->next;
                }
            }
            dfs(vertice_origem, adj->v, indices, visitado, componente, comp_id, n, ciclos);

        } 
        else if (adj->visitado == 0) {
            //  w visitado mas aresta ainda não visitada -> aresta de retorno
            adj->visitado = 1;
            // visitar aresta reversa w-v
            vertice* v2 = vertice_origem;
            while (v2 != NULL && v2->indice != adj->v) v2 = v2->next;
            if (v2 != NULL) {
                NoAdj* rev = v2->arestas;
                while (rev != NULL) {
                    if (rev->v == v_idx) { 
                        rev->visitado = 1; break; 
                    }
                    rev = rev->next;
                }
            }
            if(ciclos != NULL){
                ciclos[comp_id]++;
            }
            
        }

        adj = adj->next;
    }
}


int conexo(vertice* vertice_origem) {
    if (vertice_origem == NULL) return 0;

    int n = 0;
    vertice* v = vertice_origem;
    while (v != NULL) { 
        n++; 
        v = v->next;
    }

    int* indices    = malloc(n * sizeof(int));
    int* visitado   = malloc(n * sizeof(int));
    int* componente = malloc(n * sizeof(int));

    v = vertice_origem;
    for (int i = 0; i < n; i++) {
        indices[i] = v->indice;
        visitado[i] = 0;
        componente[i] = -1;
        v = v->next;
    }

    int num_componentes = 0;
    limpa_arestas(vertice_origem);

    for (int i = 0; i < n; i++) {
        if (visitado[i] == 0) {
            dfs(vertice_origem, indices[i], indices, visitado, componente, num_componentes, n, NULL);
            num_componentes++;
        }
    }

    free(indices);
    free(visitado);
    free(componente);

    if (num_componentes == 1)
        printf("O grafo e conexo.\n");
    else
        printf("O grafo nao e conexo. Possui %d componentes conexas.\n", num_componentes);

    return num_componentes;
}

int euleriano(vertice* vertice_origem){
    if(vertice_origem == NULL) {
        return -1;
    }

    int componentes = conexo(vertice_origem);
    if(componentes > 1) {
        return 0;
    }

    vertice* v = vertice_origem;
    while(v != NULL){
        int grau = 0;
        NoAdj* adj = v->arestas;
        while(adj != NULL){ 
            grau++; 
            adj = adj->next;
        }

        if(grau % 2 != 0) {
            return 0;
        }
        v = v->next;
    }
    return 1;
}

void ciclos(vertice* vertice_origem){
    
    if(vertice_origem == NULL){
        return;
    }

    int n = 0;
    vertice* v = vertice_origem;

    while(v != NULL){
        n++;
        v = v->next;
    }

    int *indices = malloc(n * sizeof(int));
    int *visitado = calloc(n, sizeof(int));
    int *componente = malloc(n * sizeof(int));
    int *ciclos = calloc(n, sizeof(int));

    v = vertice_origem;

    for(int i=0; i<n; i++){
        indices[i] = v->indice;
        componente[i] = -1;
        v = v->next;
    }

    limpa_arestas(vertice_origem);

    int num_componentes = 0;

    for(int i=0; i<n; i++){
        if(visitado[i] == 0){
            dfs(vertice_origem, indices[i], indices, visitado, componente, num_componentes, n, ciclos);
            num_componentes++;
        }
    }

    for(int i=0; i<num_componentes; i++){
        if(ciclos[i] > 0){
            printf("Componente %d tem %d ciclos.\n", i, ciclos[i]);
        }
        else{
            printf("Componente %d nao tem ciclos.\n", i);
        }
    }
        free(indices);
    free(visitado);
    free(componente);
    free(ciclos);
}

static vertice* encontrar_vertice(vertice* vertice_origem, int idx) {
    vertice* v = vertice_origem;
    while (v != NULL && v->indice != idx) {
        v = v->next;
    }
    return v;
}

// marca uma aresta nao visitada de v1->v2 e de v2->v1
static void marcar_aresta(vertice* vertice_origem, int v1, int v2) {
    vertice* va = encontrar_vertice(vertice_origem, v1);
    vertice* vb = encontrar_vertice(vertice_origem, v2);

    if (va != NULL) {
        NoAdj* adj = va->arestas;
        while (adj != NULL) {
            if (adj->v == v2 && !adj->visitado) {
                adj->visitado = 1;
                break;
            }
            adj = adj->next;
        }
    }
    if (vb != NULL) {
        NoAdj* adj = vb->arestas;
        while (adj != NULL) {
            if (adj->v == v1 && !adj->visitado) {
                adj->visitado = 1;
                break;
            }
            adj = adj->next;
        }
    }
}

static int tem_aresta_nao_visitada(vertice* vertice_origem, int idx) {
    vertice* v = encontrar_vertice(vertice_origem, idx);
    if (v == NULL) return 0;
    NoAdj* adj = v->arestas;
    while (adj != NULL) {
        if (!adj->visitado) {
            return 1;
        }
        adj = adj->next;
    }
    return 0;
}

// constroi uma cadeia fechada a partir de "inicio", seguindo arestas
// nao visitadas e marcando-as, ate retornar a "inicio"
static int* construir_cadeia(vertice* vertice_origem, int inicio, int* tamanho) {
    int capacidade = 4;
    int* cadeia = malloc(capacidade * sizeof(int));
    int n = 0;
    cadeia[n] = inicio;
    n++;

    int atual = inicio;
    do {
        vertice* v = encontrar_vertice(vertice_origem, atual);
        NoAdj* adj = v->arestas;
        while (adj != NULL && adj->visitado) {
            adj = adj->next;
        }
        if (adj == NULL) {
            break;
        }

        int proximo = adj->v;
        marcar_aresta(vertice_origem, atual, proximo);

        if (n == capacidade) {
            capacidade *= 2;
            cadeia = realloc(cadeia, capacidade * sizeof(int));
        }
        cadeia[n] = proximo;
        n++;
        atual = proximo;
    } while (atual != inicio);

    *tamanho = n;
    return cadeia;
}

void hierholzer(vertice* vertice_origem) {
    if (vertice_origem == NULL) {
        printf("Grafo vazio.\n");
        return;
    }

    if (euleriano(vertice_origem) != 1) {
        printf("O grafo nao possui ciclo euleriano.\n");
        return;
    }

    limpa_arestas(vertice_origem);

    vertice* inicio = vertice_origem;
    while (inicio != NULL && inicio->arestas == NULL) {
        inicio = inicio->next;
    }
    if (inicio == NULL) {
        printf("O grafo nao possui arestas.\n");
        return;
    }

    int tamC;
    int* C = construir_cadeia(vertice_origem, inicio->indice, &tamC);

    int i = 0;
    while (i < tamC) {
        if (tem_aresta_nao_visitada(vertice_origem, C[i])) {
            int tamH;

            int* H = construir_cadeia(vertice_origem, C[i], &tamH); //novo ciclo

            int novo_tam = tamC + tamH - 1;
            int* novo = malloc(novo_tam * sizeof(int));

            memcpy(novo, C, (i + 1) * sizeof(int)); //copia C até o ciclo H comeca
            memcpy(novo + i + 1, H + 1, (tamH - 1) * sizeof(int));// copia H para C
            memcpy(novo + i + tamH, C + i + 1, (tamC - i - 1) * sizeof(int));//copia o restante de C

            free(C);
            free(H);
            C = novo;
            tamC = novo_tam;
            i = 0;
        } else {
            i++;
        }
    }

    printf("Ciclo euleriano: ");
    for (int j = 0; j < tamC; j++) {
        printf("%d", C[j]);
        if (j < tamC - 1) printf(" -> ");
    }
    printf("\n");

    free(C);
}

void prim(vertice* vertice_origem, int raiz) {
    if (vertice_origem == NULL) {
        printf("Grafo vazio.\n");
        return;
    }

    int n = 0;
    vertice* v = vertice_origem;
    while (v != NULL) { n++; v = v->next; }

    int* indices = malloc(n * sizeof(int));
    int* key     = malloc(n * sizeof(int));
    int* pi      = malloc(n * sizeof(int));
    int* inQ     = malloc(n * sizeof(int));

    // linhas 1-3: key[u] = INF, π[u] = NIL
    v = vertice_origem;
    for (int i = 0; i < n; i++) {
        indices[i] = v->indice;
        key[i]     = INT_MAX;
        pi[i]      = -1;
        inQ[i]     = 1;
        v = v->next;
    }

    // linha 4: key[r] = 0
    int raiz_pos = encontrar_pos(indices, n, raiz);
    if (raiz_pos == -1) raiz_pos = 0;
    key[raiz_pos] = 0;

    // linha 6: enquanto Q != vazio
    for (int count = 0; count < n; count++) {

        // linha 7: u = EXTRACT-MIN(Q)
        int u_pos = -1;
        for (int i = 0; i < n; i++) {
            if (inQ[i] && (u_pos == -1 || key[i] < key[u_pos]))
                u_pos = i;
        }
        if (u_pos == -1) break;

        inQ[u_pos] = 0;
        int u_idx = indices[u_pos];

        // linha 8: para cada v em Adj[u]
        vertice* u_vert = encontrar_vertice(vertice_origem, u_idx);
        if (u_vert == NULL) continue;

        NoAdj* adj = u_vert->arestas;
        while (adj != NULL) {
            int v_pos = encontrar_pos(indices, n, adj->v);

            // linha 9: se v in Q e w(u,v) < key[v]
            if (v_pos != -1 && inQ[v_pos] && adj->peso < key[v_pos]) {
                pi[v_pos]  = u_idx;     // linha 10: π[v] = u
                key[v_pos] = adj->peso; // linha 11: key[v] = w(u,v)
            }
            adj = adj->next;
        }
    }

    int total = 0;
    printf("Arvore Geradora Minima (Prim, raiz=%d):\n", indices[raiz_pos]);
    for (int i = 0; i < n; i++) {
        if (pi[i] != -1) {
            printf("  %d -- %d  (peso: %d)\n", pi[i], indices[i], key[i]);
            total += key[i];
        }
    }
    printf("Peso total da AGM: %d\n", total);

    free(indices);
    free(key);
    free(pi);
    free(inQ);
}
