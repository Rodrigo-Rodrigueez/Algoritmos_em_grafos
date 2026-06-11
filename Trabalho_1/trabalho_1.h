
#define TRABALHO_1_H

typedef struct celula{
    int valor;
    int linha;
    struct celula *proximo;
}celula;

typedef struct coluna{
    int ID_Coluna;
    struct coluna *proximo;
    celula *inicio;
}coluna;

typedef struct matriz{
    int n_linhas;
    int n_colunas;
    coluna *inicio;
}matriz;

matriz* criar_matriz(int n_linhas, int n_colunas);
void insere_elemento(matriz* m, int id_linha, int id_coluna, int valor);
int consulta_elemento(matriz* m, int id_linha, int id_coluna);
void imprime_matriz(matriz* m);

//Funções do trabalho

//01 
void Apaga_cel_col(coluna* c);
void Apaga_matriz(matriz** m);

//02
void Cria_transposta(matriz* m, matriz* transposta);

//03
void Soma_matrizes(matriz* m1, matriz* m2, matriz* resultado);

//04
void Multiplica_matrizes(matriz* m1, matriz* m2, matriz* resultado);

