#include "funcoes.h"
#include <unistd.h> // Sleep
#include <stdio.h>  // NULL
#include <stdlib.h> // malloc

int main(){
    int matriza_lin, matriza_col;
    int matrizb_lin, matrizb_col;
    int cont = 1, resposta;
    char* lixo;
    float* matriza = NULL, *matrizb = NULL, *resultado = NULL, *transposta = NULL;

    do{
        // Limpa a tela
        printf("\033[2J \033[H");

        // Menu principal
        printf("\n -MENU-\n");
        printf("1.Ler a Matriz A\n");
        printf("2.Ler a matriz B\n");
        printf("3.Multiplicar a matriz A pela matriz B\n");
        printf("4.Calcular a transposta da matriz A\n");
        printf("5.Multiplicar a matriz A pela transposta da matriz B\n");
        printf("0.Para sair\n");
        printf("Digite a operação que deseja: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1: // Fazer Matriz A
                printf("Digite a altura da matriz A: ");
                scanf("%d", &matriza_lin);

                printf("Digite a largura da matriz A: ");
                scanf("%d", &matriza_col);

                if (matriza != NULL) { // Limpa e retorna o vetor para o padrão
                    free(matriza);
                    matriza = NULL;
                }

                matriza = (float*)malloc(sizeof(float)*matriza_lin*matriza_col);

                if (matriza == NULL) {
                    printf("Matriz A não pôde ser alocada! Saindo...");
                    exit(1);
                }

                // Bota os valores no vetor. Linha por linha
                for (int i = 0; i < matriza_lin; i++) {
                    for (int j = 0; j < matriza_col; j++) {
                        printf("Digite o valor da posição %d:%d da matriz A: ", i, j);
                        scanf("%f", &matriza[(matriza_col*i)+j]);
                    }
                }
                break;

            case 2: // Fazer Matriz B
                printf("Digite a altura da matriz B: ");
                scanf("%d", &matrizb_lin);

                printf("Digite a largura da matriz B: ");
                scanf("%d", &matrizb_col);

                if (matrizb != NULL) { // Limpa e retorna o vetor para o padrão
                    free(matrizb);
                    matrizb = NULL;
                }

                matrizb = (float*)malloc(sizeof(float)*matrizb_lin*matrizb_col);

                if (matrizb == NULL) {
                    printf("Matriz B não pôde ser alocada! Saindo...");
                    exit(1);
                }

                // Bota os valores no vetor. Linha por linha
                for (int i = 0; i < matrizb_lin; i++) { 
                    for (int j = 0; j < matrizb_col; j++) {
                        printf("Digite o valor da posição %d:%d da matriz B: ", i, j);
                        scanf("%f", &matrizb[(matrizb_col*i)+j]);
                    }
                }
                break;

            case 3: // Multiplicar matriz a pela b
                if (matriza == NULL || matrizb == NULL) {
                    printf("Matriz não configurada!\n");
                    sleep(2);
                    break;
                }

                resultado = MultiplicarMatriz(matriza, matrizb, matriza_lin, matriza_col, matrizb_lin, matrizb_col);
                if (resultado == NULL) {
                    printf("Erro");
                    sleep(2);
                    break;
                }
                printf("Concluído com sucesso!\n");
                printf("Resultado: \n");

                // Imprime o resultado 
                for (int i = 0; i < matriza_lin; i++) {
                    for (int j = 0; j < matrizb_col; j++) {
                        printf("%f ", resultado[(matrizb_col*i)+j]);
                    }
                       printf("\n");
                }


                printf("Pressione um botão para continuar\n");
                while(getchar() != '\n'); // Limpa o stdin
                getchar(); // Espera a pessoa digitar ENTER
                break;

            case 4:
                if (matriza == NULL) {
                    printf("Matriz não configurada!\n");
                    sleep(2);
                    break;
                }

                if (resultado != NULL) { // Limpa e retorna o vetor para o padrão
                    free(resultado);
                    resultado = NULL;
                }

                resultado = TranspostadeMatriz(matriza, matriza_lin, matriza_col);

                if (resultado == NULL) {
                    printf("Erro");
                    sleep(2);
                    break;
                }
                
                printf("Concluído com sucesso!\n");
                printf("Resultado: \n");

                // Imprime o resultado
                for (int i = 0; i < matriza_col; i++) {
                    for (int j = 0; j < matriza_lin; j++) {
                        printf("%f ", resultado[(matriza_lin*i)+j]);
                    }
                       printf("\n");
                }

                printf("Pressione um botão para continuar\n");
                while(getchar() != '\n'); // Limpa o stdin
                getchar(); // Espera a pessoa digitar ENTER
                break;

            case 5:
                if (matriza == NULL || matrizb == NULL) {
                    printf("Matriz não configurada!\n");
                    sleep(2);
                    break;
                }

                // Limpa e retorna os vetores para o padrão
                if (transposta != NULL) {
                    free(transposta);
                    transposta != NULL;
                }

                if (resultado != NULL) { 
                    free(resultado);
                    resultado = NULL;
                }


                transposta = TranspostadeMatriz(matrizb, matrizb_lin, matrizb_col);
                resultado = MultiplicarMatriz(matriza, transposta, matriza_lin, matriza_col, matrizb_col, matrizb_lin);

                if (resultado == NULL) {
                    printf("Erro");
                    sleep(2);
                    break;
                }
                
                printf("Concluído com sucesso!\n");
                printf("Resultado: \n");

                // Imprime o resultado
                for (int i = 0; i < matriza_lin; i++) {
                    for (int j = 0; j < matrizb_col; j++) {
                        printf("%f ", resultado[(matrizb_col*i)+j]);
                    }
                       printf("\n");
                }

                printf("Pressione um botão para continuar\n");
                while(getchar() != '\n'); // Limpa o stdin
                getchar(); // Espera a pessoa digitar ENTER
                break;


            case 0:
                printf("Saindo");
                cont=0;
                break;

            default:
                printf("Nenhum item selecionado\n");
                sleep(2);
                break;
        }
    }while (cont);
}