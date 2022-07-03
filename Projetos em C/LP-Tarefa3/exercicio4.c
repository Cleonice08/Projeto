#include <stdio.h>
#include <stdlib.h>

//a)Media Aritmetica dos elementos do x(diagonal secundaria principal)
//b)produto dos elementos

int main() {
    int linha, coluna, quantidadeElementosDiagonal = 0;
    float media = 0, produto = 1;

    printf("\n Digite a quantidade de linhas: ");
    scanf("%d", &linha);

    printf("\n Digite a quantidade de colunas: ");
    scanf("%d", &coluna);

    int matriz[linha][coluna];

    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            printf("\n Digite um numero: ");
            scanf("%d", &matriz[i][j]);

            if(linha == coluna) {
                if(i == j || i + j == linha - 1) {
                    media+= matriz[i][j];
                    quantidadeElementosDiagonal++;
                }
            }

            produto *= matriz[i][j];
        }
    }

    printf("\n Produto dos elementos: %.2f", produto);

    if(linha != coluna) {
        printf("Nao possui diagonal");
    } else {
        printf("\nMedia Aritimetica: %.2f", media / quantidadeElementosDiagonal);
    }
    return 0;
}
