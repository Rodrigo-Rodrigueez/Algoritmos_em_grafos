#include "trabalho_2.h"
#include <stdio.h>
#include <stdlib.h>

struct NoAdj {
    int v;
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

void inserir_arestas(vertice* vertice_origem, int vert1, int vert2){
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
                if(aresta_auxiliar_1->v == vert1){
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
                    aresta_auxiliar->next = nova_aresta;
                }
                else{
                    NoAdj* nova_aresta = malloc(sizeof(NoAdj));
                    nova_aresta->v = vert2;
                    nova_aresta->next = NULL;
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
                    aresta_auxiliar->next = nova_aresta;
                }
                else{
                    NoAdj* nova_aresta = malloc(sizeof(NoAdj));
                    nova_aresta->v = vert1;
                    nova_aresta->next = NULL;
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
                printf("-> %d", auxiliar_arestas->v);
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

