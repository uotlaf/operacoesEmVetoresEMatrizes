#include "conversoes.h"
#include <stdio.h>  // NULL
#include <stdlib.h> // malloc

#ifndef CONVERSOES_C_
#define CONVERSOES_C_

float** vetorToMatriz(float* vetor , int linhas, int colunas ) {
    if (vetor == NULL)
        return NULL;
    
    float** resultado = (float**)malloc(sizeof(float)*linhas);

    if (resultado == NULL)
        return NULL;


    for (int i = 0; i < linhas; i++) {
        resultado[i] = (float*)malloc(sizeof(float) * colunas);

        if (resultado == NULL)
            return NULL;

        for (int j = 0; j < colunas; j++) {
            // Obj -> linhaXcoluna = (colunas*i) + j
            resultado[i][j] = vetor[(colunas*i)+j];
        }
    }

    return resultado;
}

float*  matriztoVetor(float** matriz, int linhas, int colunas) {
    if (matriz == NULL) {
        return NULL;
    }

    int tamanho_final = linhas * colunas;
    float* resultado = (float*)malloc(sizeof(float)* tamanho_final);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[(colunas*i)+j] = matriz[i][j];
        }
    }

    return resultado;
}

#endif