#include <stdio.h>
#include <stdlib.h>
#include "trabalho_1.h"

static void mostrar_menu(void) {
	printf("\n=== TESTE T2 - MATRIZ ESPARSA ===\n");
	printf("1 - Criar matriz\n");
	printf("2 - Inserir elemento\n");
	printf("3 - Consultar elemento\n");
	printf("4 - Imprimir matriz\n");
	printf("5 - Apagar matriz\n");
	printf("6 - Criar transposta\n");
	printf("7 - Somar matrizes\n");
	printf("8 - Multiplicar matrizes\n");
	printf("0 - Sair\n");
	printf("Opcao: ");
}

static void inicia_vetor_zero(int* vetor, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		vetor[i] = 0;
	}
}

static int check_vetor(int* vetor, int tamanho, int posicao){
	if(posicao < tamanho && posicao >= 0){
		if(vetor[posicao] == 0){
			return 0;
		}else if(vetor[posicao] == 1){
			return 1;
		}
	}
	return 0;
}
static int check_posicao_vetor(int* vetor, int tamanho){
	for (int i = 0; i < tamanho; i++) {
		if(vetor[i] == 0){
			return i;
		}
	}
	return -1;
}
static void mostra_vetor(int* vetor, int tamanho){
	for (int i = 0; i < tamanho; i++) {
		if(vetor[i] == 1){
			printf("%d ", i+1);
		}
	}
	printf("\n");
}


int main(void) {
	matriz** m = NULL;
	int* vetor_matrizes = NULL;
	
	m = (matriz**) malloc(15 * sizeof(matriz*));
	vetor_matrizes = (int*) malloc(15 * sizeof(int));
	inicia_vetor_zero(vetor_matrizes, 15);

	for(int i=0; i<15; i++){
		m[i] = NULL;
	}
	int opcao = -1;

	printf("Programa de teste para os prototipos de trabalho_1.h\n");

	// Matrizes de testes

	// m[0] (6x7) conforme matriz de exemplo enviada:
	// [2 0  0 0  0  0  0 ]
	// |0 0  0 0  0 45 13 |
	// |0 0  0 0 89  0  0 |
	// |0 0 12 0  0  0  0 |
	// |0 0  0 0  0  0  0 |
	// [0 0  0 0  3  0  0 ]
	m[0] = criar_matriz(6, 7);
	vetor_matrizes[0] = 1;
	insere_elemento(m[0], 1, 1, 2);
	insere_elemento(m[0], 2, 6, 45);
	insere_elemento(m[0], 2, 7, 13);
	insere_elemento(m[0], 3, 5, 89);
	insere_elemento(m[0], 4, 3, 12);
	insere_elemento(m[0], 6, 5, 3);

	// m[1] (6x7) - cópia de m[0]:
	m[1] = criar_matriz(6, 7);
	vetor_matrizes[1] = 1;
	insere_elemento(m[1], 1, 1, 2);
	insere_elemento(m[1], 2, 6, 45);
	insere_elemento(m[1], 2, 7, 13);
	insere_elemento(m[1], 3, 5, 89);
	insere_elemento(m[1], 4, 3, 12);
	insere_elemento(m[1], 6, 5, 3);

	// m[2] (2x3):
	// [1 2 0]
	// [0 1 3]
	m[2] = criar_matriz(2, 3);
	vetor_matrizes[2] = 1;
	insere_elemento(m[2], 1, 1, 1);
	insere_elemento(m[2], 1, 2, 2);
	insere_elemento(m[2], 2, 2, 1);
	insere_elemento(m[2], 2, 3, 3);

	// m[3] (3x2):
	// [1 0]
	// [4 1]
	// [0 2]
	m[3] = criar_matriz(3, 2);
	vetor_matrizes[3] = 1;
	insere_elemento(m[3], 1, 1, 1);
	insere_elemento(m[3], 2, 1, 4);
	insere_elemento(m[3], 2, 2, 1);
	insere_elemento(m[3], 3, 2, 2);

	// m[4] (2x2) = m[2] x m[3], esperado:
	// [9 2]
	// [4 7]
	m[4] = criar_matriz(2, 2);
	vetor_matrizes[4] = 1;
	insere_elemento(m[4], 1, 1, 9);
	insere_elemento(m[4], 1, 2, 2);
	insere_elemento(m[4], 2, 1, 4);
	insere_elemento(m[4], 2, 2, 7);
	

	do {
		int linhas;
		int colunas;
		int id_linha;
		int id_coluna;
		int valor;
		int indice_matriz_1;
		int indice_matriz_2;
		int indice_matriz_resultado = 0;

		mostrar_menu();
		if (scanf("%d", &opcao) != 1) {
			printf("Entrada invalida. Encerrando.\n");
			return 1;
		}

		switch (opcao) {
			case 1:
				printf("Indice de matrizes disponiveis: ");
				mostra_vetor(vetor_matrizes, 15);
				printf("Indice da matriz (1-15): ");
				scanf("%d", &indice_matriz_1);
				if(indice_matriz_1 < 1 || indice_matriz_1 > 15){
					printf("Indice invalido. Escolha um indice entre 1 e 15.\n");
					break;
				}
				else if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					vetor_matrizes[indice_matriz_1-1] = 1;
					
				}
				else{
					printf("Matriz ja criada. Escolha outro indice.\n");
					break;
				}
				printf("Numero de linhas: ");
				scanf("%d", &linhas);
				printf("Numero de colunas: ");
				scanf("%d", &colunas);
				m[indice_matriz_1-1] = criar_matriz(linhas, colunas);
				printf("criar_matriz chamada com sucesso.\n");
				break;

			case 2:
				printf("Indice da matriz disponivel (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				printf("Linha: ");
				scanf("%d", &id_linha);
				printf("Coluna: ");
				scanf("%d", &id_coluna);
				printf("Valor: ");
				scanf("%d", &valor);
				insere_elemento(m[indice_matriz_1-1], id_linha, id_coluna, valor);
				printf("insere_elemento chamada com sucesso.\n");
				break;

			case 3:
				printf("Indice da matriz disponivel (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				printf("Linha: ");
				scanf("%d", &id_linha);
				printf("Coluna: ");
				scanf("%d", &id_coluna);
				int valor_retornado = consulta_elemento(m[indice_matriz_1-1], id_linha, id_coluna);
				printf("Valor retornado: %d\n", valor_retornado);
				break;

			case 4:
				printf("Indice da matriz disponivel (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}
				imprime_matriz(m[indice_matriz_1-1]);
				break;

			case 5:
				printf("Indice da matriz disponivel (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				Apaga_matriz(&m[indice_matriz_1-1]);
				vetor_matrizes[indice_matriz_1-1] = 0;
				printf("Matriz apagada com sucesso.\n");
				break;
			case 6:
				printf("Indice da matriz disponivel (1 matriz) (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				indice_matriz_resultado = check_posicao_vetor(vetor_matrizes, 15);
				if(indice_matriz_resultado == -1){
					printf("Limite de matrizes atingido. Impossivel criar matriz resultado.\n");
					break;
				}
				
				m[indice_matriz_resultado] = criar_matriz(m[indice_matriz_1-1]->n_colunas, m[indice_matriz_1-1]->n_linhas);
				vetor_matrizes[indice_matriz_resultado] = 1;	
				Cria_transposta(m[indice_matriz_1-1], m[indice_matriz_resultado]);
				printf("Cria_transposta chamada com sucesso (matriz numero: %d).\n", indice_matriz_resultado+1);

				break;

			case 7:
				printf("Indice da matriz disponivel (1 matriz) (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				printf("Indice da matriz disponivel (2 matriz) (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_2);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_2-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				if(m[indice_matriz_1-1]->n_linhas != m[indice_matriz_2-1]->n_linhas || m[indice_matriz_1-1]->n_colunas != m[indice_matriz_2-1]->n_colunas){
					printf("Matrizes de dimensoes diferentes. Impossivel somar.\n");
					break;
				}

				indice_matriz_resultado = check_posicao_vetor(vetor_matrizes, 15);
				if(indice_matriz_resultado == -1){
					printf("Limite de matrizes atingido. Impossivel criar matriz resultado.\n");
					break;
				}
				
				m[indice_matriz_resultado] = criar_matriz(m[indice_matriz_1-1]->n_linhas, m[indice_matriz_1-1]->n_colunas);
				vetor_matrizes[indice_matriz_resultado] = 1;	
				Soma_matrizes(m[indice_matriz_1-1], m[indice_matriz_2-1], m[indice_matriz_resultado]);
				printf("Soma_matrizes chamada com sucesso (matriz numero: %d).\n", indice_matriz_resultado+1);



				break;
			case 8:
				printf("Indice da matriz disponivel (1 matriz) (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_1);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_1-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				printf("Indice da matriz disponivel (2 matriz) (1-15): ");
				mostra_vetor(vetor_matrizes, 15);
				scanf("%d", &indice_matriz_2);
				if(check_vetor(vetor_matrizes, 15, indice_matriz_2-1) == 0){
					printf("Matriz nao criada. Escolha um indice disponivel.\n");
					break;
				}

				if(m[indice_matriz_1-1]->n_colunas != m[indice_matriz_2-1]->n_linhas){
					printf("Matrizes com dimensoes incompativeis para multiplicacao. Impossivel multiplicar.\n");
					break;
				}

				indice_matriz_resultado = check_posicao_vetor(vetor_matrizes, 15);
				if(indice_matriz_resultado == -1){
					printf("Limite de matrizes atingido. Impossivel criar matriz resultado.\n");
					break;
				}
				m[indice_matriz_resultado] = criar_matriz(m[indice_matriz_1-1]->n_linhas, m[indice_matriz_2-1]->n_colunas);
				vetor_matrizes[indice_matriz_resultado] = 1;
				Multiplica_matrizes(m[indice_matriz_1-1], m[indice_matriz_2-1], m[indice_matriz_resultado]);
				printf("Multiplica_matrizes chamada com sucesso (matriz numero: %d).\n", indice_matriz_resultado+1);
				break;
			case 0:
				printf("Encerrando.\n");
				break;

			default:
				printf("Opcao invalida.\n");
				break;
		}
	} while (opcao != 0);

	return 0;
}
