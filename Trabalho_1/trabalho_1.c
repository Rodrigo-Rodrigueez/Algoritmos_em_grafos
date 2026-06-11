#include "trabalho_1.h"
#include <stdio.h>
#include <stdlib.h>

matriz* criar_matriz(int n_linhas, int n_colunas) {

    matriz* matriz_nova = (matriz*) malloc(sizeof(matriz));
    
    matriz_nova->n_linhas = n_linhas;
    matriz_nova->n_colunas = n_colunas;
    matriz_nova->inicio = NULL;

    return matriz_nova;
}

void insere_elemento(matriz* m, int id_linha, int id_coluna, int valor){
  
    if(m == NULL){
        return;
    }
    else if(id_linha < 1 || id_linha > m->n_linhas || id_coluna < 1 || id_coluna > m->n_colunas){
        printf("Posicao (%d, %d) fora dos limites da matriz. Elemento nao inserido.\n", id_linha, id_coluna);
        return;
    }
    else{
        matriz* matriz_atual = m;
        if(m->inicio == NULL){
            coluna* nova_coluna = (coluna*) malloc(sizeof(coluna));
            nova_coluna->ID_Coluna = id_coluna;
            nova_coluna->proximo = NULL;

            celula* nova_celula = (celula*) malloc(sizeof(celula));
            nova_celula->linha = id_linha;
            nova_celula->valor = valor;
            nova_celula->proximo = NULL;

            nova_coluna->inicio = nova_celula;
            matriz_atual->inicio = nova_coluna;
        }
        else{
            coluna* coluna_atual = matriz_atual->inicio;
            coluna* coluna_anterior = NULL;
            while(coluna_atual->proximo != NULL && coluna_atual->ID_Coluna < id_coluna){
                coluna_anterior = coluna_atual;
                coluna_atual = coluna_atual->proximo;
            }

            if(coluna_atual->ID_Coluna == id_coluna){
                celula* celula_atual = coluna_atual->inicio;
                celula* celula_anterior = NULL;
                while(celula_atual->proximo != NULL && celula_atual->linha < id_linha){
                    celula_anterior = celula_atual;
                    celula_atual = celula_atual->proximo;
                }

                if(celula_atual->linha == id_linha){
                    celula_atual->valor = valor;

                }
                else if(celula_atual->linha > id_linha){
                    celula* nova_celula = (celula*) malloc(sizeof(celula));
                    nova_celula->linha = id_linha;
                    nova_celula->valor = valor;
                    nova_celula->proximo = celula_atual;
                    if(celula_anterior != NULL){
                        celula_anterior->proximo = nova_celula;
                    }
                    else{
                        coluna_atual->inicio = nova_celula;
                    }
                }
                else{
                    celula* nova_celula = (celula*) malloc(sizeof(celula));
                    nova_celula->linha = id_linha;
                    nova_celula->valor = valor;
                    nova_celula->proximo = NULL;
                    celula_atual->proximo = nova_celula;
                }

                
            }
            else if(coluna_atual->ID_Coluna > id_coluna){
                coluna* nova_coluna = (coluna*) malloc(sizeof(coluna));
                celula* nova_celula = (celula*) malloc(sizeof(celula));
                nova_celula->linha = id_linha;
                nova_celula->valor = valor;
                nova_celula->proximo = NULL;

                nova_coluna->inicio = nova_celula;
                
                nova_coluna->ID_Coluna = id_coluna;
                nova_coluna->proximo = coluna_atual;
                if(coluna_anterior != NULL){
                    coluna_anterior->proximo = nova_coluna;
                }
                else{
                    matriz_atual->inicio = nova_coluna;
                }
                    
                
            }
            else if(coluna_atual->ID_Coluna < id_coluna){
                coluna* nova_coluna = (coluna*) malloc(sizeof(coluna));
                nova_coluna->ID_Coluna = id_coluna;
                nova_coluna->proximo = NULL;
                coluna_atual->proximo = nova_coluna;
                

                celula* nova_celula = (celula*) malloc(sizeof(celula));
                nova_celula->linha = id_linha;
                nova_celula->valor = valor;
                nova_celula->proximo = NULL;

                nova_coluna->inicio = nova_celula;
            }
        }
    }
}

int consulta_elemento(matriz* m, int id_linha, int id_coluna){
    if(m != NULL){
        matriz* matriz_atual = m;
        if(m->inicio != NULL){
            coluna* coluna_atual = matriz_atual->inicio;

            while(coluna_atual != NULL && coluna_atual->ID_Coluna < id_coluna){
                coluna_atual = coluna_atual->proximo;
            }
            if(coluna_atual == NULL || coluna_atual->ID_Coluna != id_coluna){
                //printf("Posicao (%d, %d) Valor: 0\n", id_linha, id_coluna);
                return 0;
            }
            celula* celula_atual = coluna_atual->inicio;

            while(celula_atual != NULL && celula_atual->linha < id_linha){
                celula_atual = celula_atual->proximo;
            }

            if(celula_atual == NULL || celula_atual->linha != id_linha){
                return 0;
            }
            
            if(coluna_atual->ID_Coluna == id_coluna && celula_atual->linha == id_linha){
                //printf("Posicao (%d, %d) Valor: %d\n", id_linha, id_coluna, celula_atual->valor);
                return celula_atual->valor;
            }
            else{
                //printf("Posicao (%d, %d) Valor: 0\n", id_linha, id_coluna);
                return 0;
            }
        }

    }
    return 0;
}

void imprime_matriz(matriz* m){
    
    if(m != NULL){
        matriz* matriz_atual = m;
        
        if(m->inicio != NULL){

            for(int i=1; i <= m->n_linhas; i++){
                coluna *coluna_inicio = matriz_atual->inicio;
                celula *celula_atual = coluna_inicio->inicio;
                for(int j=1; j <= m->n_colunas; j++){
                    if(coluna_inicio->ID_Coluna == j){
                        if(celula_atual != NULL && celula_atual->linha == i){
                            printf("%d ", celula_atual->valor);
                            celula_atual = celula_atual->proximo;
                        }
                        else if(celula_atual != NULL && celula_atual->linha < i){
                            while(celula_atual->proximo != NULL && celula_atual->linha < i){
                                celula_atual = celula_atual->proximo;
                            }
                            if(celula_atual != NULL && celula_atual->linha == i){
                                printf("%d ", celula_atual->valor);
                                if(celula_atual->proximo != NULL){
                                    celula_atual = celula_atual->proximo;
                                }
                            }
                            else{
                                printf("0 ");
                            }
                        }
                        else {
                            printf("0 ");
                        }
                        if(coluna_inicio->proximo != NULL && coluna_inicio->ID_Coluna <= j){
                            coluna_inicio = coluna_inicio->proximo;
                            celula_atual = coluna_inicio->inicio;
                        }
                    } 
                    else {
                        printf("0 ");
                    }
                }
                printf("\n");
            }
        }
        else{
            
            for(int i=1; i <= m->n_linhas; i++){
                for(int j=1; j <= m->n_colunas; j++){
                    printf("0 ");
                }
                printf("\n");
            }
        }

    }
}

///////////////////////////////////////////////////////////////////////////

//Funções do trabalho

//01
//função auxiliar Apaga_cel_col(coluna* c);
void Apaga_cel_col(coluna* c){
    if(c != NULL){
        celula* celula_atual = c->inicio;
        while(celula_atual != NULL){
            celula* celula_para_apagar = celula_atual;
            celula_atual = celula_atual->proximo;
            free(celula_para_apagar);
        }
        free(c);
    }
}

void Apaga_matriz(matriz** m){
    if (m == NULL || *m == NULL) {
        return;
    }

    coluna* coluna_atual = (*m)->inicio;
    while (coluna_atual != NULL) {
        coluna* coluna_para_apagar = coluna_atual;
        coluna_atual = coluna_atual->proximo;
        Apaga_cel_col(coluna_para_apagar);
    }

    free(*m);
    *m = NULL;
}

//02
void Cria_transposta(matriz* m, matriz* transposta){
    if(m != NULL && transposta != NULL){
        coluna* coluna_atual = m->inicio;
        if(m->n_linhas == transposta->n_colunas && m->n_colunas == transposta->n_linhas){
            while(coluna_atual != NULL){
                celula* celula_atual = coluna_atual->inicio;
                while(celula_atual != NULL){
                    insere_elemento(transposta, coluna_atual->ID_Coluna, celula_atual->linha, celula_atual->valor);
                    celula_atual = celula_atual->proximo;
                
                }
                coluna_atual = coluna_atual->proximo;
            }
        }
    }
}

//03

void Soma_matrizes(matriz* m1, matriz* m2, matriz* resultado){

    if(m1 != NULL && m2 != NULL && resultado != NULL){
        coluna* coluna_atual_1 = m1->inicio;
        coluna* coluna_atual_2 = m2->inicio;
        if(m1->n_colunas == m2->n_colunas && m1->n_linhas == m2->n_linhas){ 
            while(coluna_atual_1 != NULL && coluna_atual_2 != NULL){
                
                celula* celula_atual_1 = coluna_atual_1->inicio;
                celula* celula_atual_2 = coluna_atual_2->inicio;
                if(coluna_atual_1->ID_Coluna == coluna_atual_2->ID_Coluna){
                    while(celula_atual_1 != NULL && celula_atual_2 != NULL){
                        if(celula_atual_1->linha == celula_atual_2->linha){
                            insere_elemento(resultado, celula_atual_1->linha, coluna_atual_1->ID_Coluna, celula_atual_1->valor + celula_atual_2->valor);
                            celula_atual_1 = celula_atual_1->proximo;
                            celula_atual_2 = celula_atual_2->proximo;
                        }
                        else if(celula_atual_1->linha < celula_atual_2->linha){
                            insere_elemento(resultado, celula_atual_1->linha, coluna_atual_1->ID_Coluna, celula_atual_1->valor);
                            celula_atual_1 = celula_atual_1->proximo;
                        }
                        else{
                            insere_elemento(resultado, celula_atual_2->linha, coluna_atual_2->ID_Coluna, celula_atual_2->valor);
                            celula_atual_2 = celula_atual_2->proximo;
                        }
                    }

                    while(celula_atual_2 != NULL){
                        insere_elemento(resultado, celula_atual_2->linha, coluna_atual_2->ID_Coluna, celula_atual_2->valor);
                        celula_atual_2 = celula_atual_2->proximo;
                    }

                    while(celula_atual_1 != NULL){
                        insere_elemento(resultado, celula_atual_1->linha, coluna_atual_1->ID_Coluna, celula_atual_1->valor);
                        celula_atual_1 = celula_atual_1->proximo;
                    } 
                    coluna_atual_1 = coluna_atual_1->proximo;
                    coluna_atual_2 = coluna_atual_2->proximo;
                }
                else if(coluna_atual_1->ID_Coluna < coluna_atual_2->ID_Coluna){
                    while(celula_atual_1 != NULL){
                        insere_elemento(resultado, celula_atual_1->linha, coluna_atual_1->ID_Coluna, celula_atual_1->valor);
                        celula_atual_1 = celula_atual_1->proximo;
                    }
                    coluna_atual_1 = coluna_atual_1->proximo; 
                }
                else{
                    while(celula_atual_2 != NULL){
                        insere_elemento(resultado, celula_atual_2->linha, coluna_atual_2->ID_Coluna, celula_atual_2->valor);
                        celula_atual_2 = celula_atual_2->proximo;
                    } 
                    coluna_atual_2 = coluna_atual_2->proximo;
                }


                
            }

            while(coluna_atual_2 != NULL){
                celula* celula_atual_2 = coluna_atual_2->inicio;
                while(celula_atual_2 != NULL){
                    insere_elemento(resultado, celula_atual_2->linha, coluna_atual_2->ID_Coluna, celula_atual_2->valor);
                    celula_atual_2 = celula_atual_2->proximo;
                }
                coluna_atual_2 = coluna_atual_2->proximo;
            }

            while(coluna_atual_1 != NULL){
                celula* celula_atual_1 = coluna_atual_1->inicio;
                while(celula_atual_1 != NULL){
                    insere_elemento(resultado, celula_atual_1->linha, coluna_atual_1->ID_Coluna, celula_atual_1->valor);
                    celula_atual_1 = celula_atual_1->proximo;
                }
                coluna_atual_1 = coluna_atual_1->proximo;
            }
        }
    }

}

//04

void Multiplica_matrizes(matriz* m1, matriz* m2, matriz* resultado){

    if(m1 != NULL && m2 != NULL && resultado != NULL){

        if(m1->n_colunas == m2->n_linhas && m1->n_linhas == resultado->n_linhas && m2->n_colunas == resultado->n_colunas){

            int valor_total = 0;
            
            for(int i=1; i <= resultado->n_linhas; i++){

                for(int j=1; j <= resultado->n_colunas; j++){
                    
                    for(int k=1; k <= m1->n_colunas; k++){
                        int valor_m1 = consulta_elemento(m1, i, k);
                        int valor_m2 = consulta_elemento(m2, k, j);
                        if(valor_m1 != 0 && valor_m2 != 0){
                            valor_total += valor_m1 * valor_m2;
                        }
                    }
                    if(valor_total != 0){
                        insere_elemento(resultado, i, j, valor_total);
                    }
                    valor_total = 0;

                }
            }
        }
    }
    
}