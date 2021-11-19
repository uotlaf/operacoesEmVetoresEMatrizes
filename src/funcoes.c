#include "funcoes.h"
#include <stdio.h> // NULL
#include <stdlib.h> // malloc


float* MultiplicarMatriz(  float* vetora, float* vetorb, 
                            int vetora_lin, int vetora_col, 
                            int vetorb_lin, int vetorb_col) {

    // Testes top
    if (vetora == NULL || vetorb == NULL)
        return NULL;

    if (vetora_lin <= 0 || vetora_col <= 0 || vetorb_lin <= 0 || vetorb_col <= 0)
        return NULL;

    int resulta, resultb; // Auxiliares
    float* resultado = (float*)malloc(sizeof(float)*vetora_lin*vetorb_col);

    if (resultado == NULL )
        return NULL;

    for (int i = 0; i < vetora_lin; i++) {
        for (int j = 0; j < vetorb_col; j++) {
            resultado[(vetorb_col *i)+ j] = 0; // Limpa o vetor
            for (int k = 0; k <= vetora_lin;k++) {
                // vetor[linha + offset]
                resulta = vetora[(vetora_col*i) + k];
                resultb = vetorb[(vetorb_col*k) + j];

                resultado[(vetorb_col * i) + j] += resulta * resultb; 
            }
        }
    }

    return resultado;
}



float* TranspostadeMatriz(float* vetor, int linhas, int colunas) {

    if (vetor == NULL || linhas <= 0 || colunas <= 0)
        return NULL;

    float* resultado = (float*)malloc(sizeof(float)* linhas * colunas);

    if (resultado == NULL)
        return NULL;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[((linhas*j) + i)] = vetor[(colunas* i) + j];
        }
    }

    return resultado;
}
