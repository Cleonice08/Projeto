/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fazendeiro, tipoPulverizacao, numeroFazendeiro;
    float areaSerPulverizada, desconto, totalArea, totalDesconto;

    printf("\n Digite a quantidade de Fazendeiros:");
    scanf("%d", &fazendeiro);

    for(int i = 0; i < fazendeiro; i++)
    {
        printf("\n Digite o numero do Fazendeiro:");
        scanf("%d", &fazendeiro);
        printf("\n Digite o tipo de Pulverizacao:");
        scanf("%d", &tipoPulverizacao);
        printf("\n Digite a Area a ser Pulverizada:");
        scanf("%f", &areaSerPulverizada);

    }

    if(tipoPulverizacao == 1){
        totalArea = areaSerPulverizada * 8000;
    }else if (tipoPulverizacao == 2){
        totalArea = areaSerPulverizada * 900;
    }else{
        totalArea = areaSerPulverizada * 1200;
    }

    totalDesconto = totalArea;

    if(areaSerPulverizada > 800) {
        desconto = 0.13 * totalDesconto;
        totalDesconto = totalDesconto - desconto;
    }

    if(areaSerPulverizada > 30000) {
        desconto = 0.06 * totalDesconto;
        totalDesconto = totalDesconto - desconto;
    }

    printf("\n Numero do Fazendeiro:%i | Valor Total: %.2f| Conta:%.2f",
           fazendeiro, totalArea, totalDesconto);

    tipoPulverizacao = 0;

    return 0;
}
*/
