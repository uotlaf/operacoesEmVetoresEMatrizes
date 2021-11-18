// funcoes.h
// Funções para uso com matrizes

#ifndef FUNCOES_H
#define FUNCOES_H

float* MultiplicarMatriz(  float* vetora, float* vetorb, 
                            int vetora_lin, int vetora_col, 
                            int vetorb_lin, int vetorb_col); 

float* TranspostadeMatriz(float* vetor, int linhas, int colunas);

//float* CriarMatriz(int altura, int largura);


#endif // FUNCOES_H