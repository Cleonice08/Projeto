/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
   int quantidadeFazendeiro, numeroFazendeiro, tipoPulverizacao;
   float areaAserPulverizada, valorTotalAreaPulverizada, desconto, valorTotalDesconto;

   printf("\n Digite a quantidade de Fazendeiros:");
   scanf("%d", &quantidadeFazendeiro);

   for(int i = 0; i < quantidadeFazendeiro; i++) {
    printf("\n Digite o numero do fazendeiro:");
    scanf("%d", &numeroFazendeiro);
    printf("\n Digite a area a ser Pulverizada:");
    scanf("%f", &areaAserPulverizada);
    while (tipoPulverizacao < 1 || tipoPulverizacao > 4){
        printf("\n Digite o tipo de Pulverizacao:");
        scanf("%d", &tipoPulverizacao);
    }

    switch(tipoPulverizacao) {
    case 1 :
      valorTotalAreaPulverizada = areaAserPulverizada * 700;
      break;
    case 2 :
        valorTotalAreaPulverizada = areaAserPulverizada * 1200;
        break;
    case 3 :
        valorTotalAreaPulverizada = areaAserPulverizada * 1600;
        break;
    default:
        valorTotalAreaPulverizada = areaAserPulverizada * 2300;

    }

    valorTotalDesconto = valorTotalAreaPulverizada;

    if(areaAserPulverizada > 300) {
        desconto = 0.075 * valorTotalDesconto;
        valorTotalDesconto = valorTotalDesconto - desconto;
    }

    if(valorTotalAreaPulverizada > 300000) {
        desconto = 0.13 * valorTotalDesconto;
        valorTotalDesconto = valorTotalDesconto - desconto;
    }

    printf("\n Numero: %i | Valor Total : %.2f | Conta: %.2f ",
           numeroFazendeiro,
           valorTotalAreaPulverizada,
           valorTotalDesconto);

    tipoPulverizacao = 0;
   }





   return 0;
}
*/
