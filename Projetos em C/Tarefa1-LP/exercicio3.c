/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n, a, b, c, i, d;
    float s, sinal;

    printf("\n Digite o termo:");
    scanf("%d", &n);

    i = 0;
    a = 1;
    b = 20;
    c = 4;
    s = 0;
    sinal = -1.0;

    printf("\n Soma:");
    while(i <= n)
    {
        s = s + sinal * a/b;
        if(sinal > 0)
            printf("\n + %d/%d", a, b);
        else printf("\n - %d/%d", a, b);

        b = a + b;
        a = (i + 2) * (i + 2) * (i + 2) * (i + 2);
        if((i % 3) == 2) sinal = -sinal;
        i++;

    }
    printf("\n A soma %d termos %.2f", n, s);




return 0;
}
*/
