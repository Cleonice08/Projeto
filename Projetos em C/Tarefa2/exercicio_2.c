#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n, quantidadeMultiplo = 0;
    float produtosImpares = 1, somaElementosVetor = 0, maiorElementoPar = INT_MIN,
            mediaArtmetica = 0, segundoMenorElemento = INT_MAX, menorElmento = INT_MAX, somaElementos = 0;

    printf("\n Digite a quantidade de elementos:");
    scanf("%d", &n);

    int numeros[n];

    for(int i = 0; i < n; i++) {
       printf("\n Digite um numero:");
       scanf("%d", &numeros[i]);
    }

    for(int i = 0; i < n; i++) {
        if(numeros[i] % 2 == 1) {
            produtosImpares *= numeros[i];
        }else{
            if(numeros[i] > maiorElementoPar){
                maiorElementoPar = numeros[i];
            }
        }


        if(numeros[i] % 2 == 0 || numeros[i] % 3 == 0) {
            mediaArtmetica += numeros[i];
            quantidadeMultiplo++;
        }


        if(numeros[i] < menorElmento ) {
            segundoMenorElemento = menorElmento;
            menorElmento = numeros[i];
        }else if(numeros[i] < segundoMenorElemento){
            segundoMenorElemento = numeros[i];
        }


        somaElementos += numeros[i];

    }

    for(int i = 0; i < n; i++) {
        somaElementos *= numeros[i];

    }
    printf("\n Produtos dos elementos impares: %.2f", produtosImpares);
    printf("\n Maior elemento par: %.2f", maiorElementoPar);
    printf("\n Media Aritmetica e: %.2f", mediaArtmetica / quantidadeMultiplo);
    printf("\n Segundo menor elemento: %.2f", segundoMenorElemento);
    printf("\n O produto da soma: %.2f", somaElementos);
    return 0;
}


