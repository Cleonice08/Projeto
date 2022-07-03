/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, n;
    float mediaGeo = 1, maior10 = 0, menor10 = 0, igual10 = 0;

    printf("\n Digite o numeros de elementos: ");
    scanf("%d",  &n);

    int numeros[n];

    for(i = 0; i < n; i++){
        printf("\n Digite um numero:");
        scanf("%d", &numeros[i]);
        if(numeros[i] %2 == 0 || numeros[i] %3 == 0 ){
            mediaGeo = exp(1.0 / numeros[i] * log(mediaGeo));
        }

        if(numeros[i] > 10){
            maior10++;
        }else if(numeros[i] < 10){
            menor10++;
        }else{
            igual10++;
        }
    }
    printf("\n A media Geometrica e %d: %.2f", n, mediaGeo);
    printf("\n Maior 10: %.2f  Menor10 %.2f  igual10 %.2f:",
           100 * n / maior10, n * menor10 / 100, n * igual10 / 100);

    return 0;
}

*/
