/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, c, i;
    float sinal, s;

    printf("\n Digite o numero de termos:");
    scanf("%d", &n);

    a = 8;
    b = 3;
    s = 0;
    sinal = -1.0;
    c = 0;
    i = 0;

    while (i <= n){
        s = s + sinal * a/b;
        if(sinal > 0)
            printf("\n + %d / %d", a, b);
        else printf("\n - %d / %d", a, b);
        a = (i + 3) * (i + 3) * (i + 3);
        b = b * 2 - c;
        c += 3;
        sinal = -sinal;
        i++;
    }
    printf("\n A soma do %d termos %.2f", n, s);
    return 0;
}
*/
