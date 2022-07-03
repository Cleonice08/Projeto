/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define tam 100

void leituraMatriz(int x[tam][tam], int l, int c);
int menorImpar(int x[tam][tam], int l, int c);
void porcentagem(int x[tam][tam], int l, int c);
float mediaGeometrica(int x[tam][tam], int l, int c);
float produto(int x[tam][tam], int l, int c);
float mediaPonderada(int x[tam][tam], int l, int c);

int main()
{
    int matriz[tam][tam], l, c, i, j, MN;
    printf("\n Digite o valor de Linhas:");
    scanf("%d", &l);
    printf("\n Digite o valor de Colunas:");
    scanf("%d", &c);

    leituraMatriz(matriz, l, c);
    MN = menorImpar(matriz, l, c);
    printf("\n O menor impar e: %d", MN);
    porcentagem(matriz, l, c);
    float mediaG = mediaGeometrica(matriz, l, c);
    printf("\n Media Geometrica: %.2f", mediaG);
    float produtoE = produto(matriz, l, c);
    printf("\n Produto dos elementos: %.2f", produtoE);
    float media = mediaPonderada(matriz, l, c);
    printf("\n Media Ponderada: %.2f", media);


    return 0;
}

void leituraMatriz(int x[tam][tam], int l, int c)
{
    int i, j;
    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
    {
        printf("\n [%d][%d]:", i, j);
        scanf("%d", &x[i][j]);
    }

}

int menorImpar(int x[tam][tam], int l, int c)
{
    int i, j, menorImpar = INT_MAX;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(x[i][j] %2 == 1 && x[i][j] < menorImpar){
                menorImpar = x[i][j];
            }
        }
    }

    return menorImpar;
}

void porcentagem(int x[tam][tam], int l, int c)
{
    int MAIOR_ZERO = 0, MENOR_ZERO = 0, IGUAL_ZERO = 0;
    int i, j;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
             if(x[i][j] > 0){
                MAIOR_ZERO++;
             }else if(x[i][j] < 0) {
                MENOR_ZERO++;
             }else{
                IGUAL_ZERO++;
             }
        }
    }

    float porcentagemMaiorZero = 100.0 * MAIOR_ZERO/(l*c);
    float porcentagemMenorZero = 100.0 * MENOR_ZERO/(l*c);
    float porcentagemIgualZero = 100.0 * IGUAL_ZERO/(l*c);
    printf("\n Porcentagem dos elementos menor que zero: %.2f  Maior que zero: %.2f  Igual a zero: %.2f"
           , porcentagemMenorZero, porcentagemMaiorZero, porcentagemIgualZero);
}

float  mediaGeometrica(int x[tam][tam], int l, int c)
{
    int i, j;
    float resultadoMediaGeometrica = 1, n = 0;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(x[i][j] % 7 == 0){
                resultadoMediaGeometrica *= x[i][j];
                n++;
                resultadoMediaGeometrica = exp(1.0 / n * log(resultadoMediaGeometrica));
            }
        }
    }


    return resultadoMediaGeometrica;
}

float produto(int x[tam][tam], int l, int c)
{
    int i, j;
    float produtoResultado = 1;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            for(i = 1; i < l - 1; i++){
                for(j = 1; j < c - 1; j++){
                    produtoResultado *= x[i][j];
                }
            }
        }
    }


    return produtoResultado;
}

float mediaPonderada(int x[tam][tam], int l, int c)
{
    int i, j;
    float media = 0, pesos = 0;

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            media += (i + j + 1) * x[i][j];
            pesos += (i + j + 1);
        }
    }

    media = media / pesos;
    return media;
}

*/
