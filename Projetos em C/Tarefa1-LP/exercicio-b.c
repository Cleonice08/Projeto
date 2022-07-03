#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int i, n, a, b, c;
    float s, sinal;

    printf("\n Digite o numero de termos:");
    scanf("%d", &n);

    i = 1;
    a = 1;
    b = 3;
    c = 3;
    s = 0;

    sinal = -1.0;

    printf("\n soma:");
    while(i <= n)
    {
        s = s + sinal * a/b;
        if(sinal > 0 )
            printf("\n + %d/%d", a, b);
        else printf("\n - %d/%d", a, b);

        a = (i + 3) * (i + 3) * (i + 3);
        b = b + 2;
        c++;
        if((i % 2) == 0) sinal = -sinal;
        i++;
    }
    printf("\n A soma dos %d termos e: %.2f", n, s);

    return 0;
}
