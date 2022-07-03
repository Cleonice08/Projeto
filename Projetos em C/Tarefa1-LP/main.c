/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int numeroConsumidor, quantidadeConsumidoskwh, codigoConsumidor = 0, consumidores;
    int industrial = 2, residencial = 1, comercial = 3;
    float preco, totalResidencial = 0, totalIndustrial = 0, totalComercial = 0,
          totalGeralConsumido = 0, totalConsumido, maiorConsumoIndustrial = INT_MIN,
          menorConsumo = INT_MAX, segundoMenorConsumo = INT_MIN;

    printf("\n Digite a quantidade de consumidores:\n");
    scanf("%d", &consumidores);

    for(int i = 0; i < consumidores; i++) {
        printf("\n Digite o preco do consumo:\n");
        scanf("%f", &preco);
        printf("\n Digite o numero do consumidor:\n");
        scanf("%d", &numeroConsumidor);
        printf("\n Digite a quantidade de kwh consumidos no mes:\n");
        scanf("%d", &quantidadeConsumidoskwh);
        while(codigoConsumidor < 1 || codigoConsumidor > 3) {
            printf("\n Digite o tipo de consumidor [1 - Residencial | 2 - Industrial | 3 - Comercial]:\n");
            scanf("%d", &codigoConsumidor);
        }
        totalConsumido = preco * quantidadeConsumidoskwh;
        totalGeralConsumido += totalConsumido;

        if(codigoConsumidor == industrial && totalConsumido >= maiorConsumoIndustrial) {
            maiorConsumoIndustrial = totalConsumido;
        }

        if(menorConsumo > totalConsumido) {
            segundoMenorConsumo = menorConsumo;
            menorConsumo = totalConsumido;

        } else if(segundoMenorConsumo > totalConsumido) {
            segundoMenorConsumo = totalConsumido;
        }

        totalResidencial += codigoConsumidor == residencial ? totalConsumido : 0;
        totalComercial += codigoConsumidor == comercial ? totalConsumido : 0;
        totalIndustrial += codigoConsumidor == industrial ? totalConsumido : 0;

        printf("Consumidor [%i] - Total KW a pagar: %.2f", numeroConsumidor, totalConsumido);
        codigoConsumidor = 0;
    }


    printf("\n Maior Consumo Industrial: %.2f", maiorConsumoIndustrial);
    printf("\n Total Consumo Residencial: %.2f", totalResidencial);
    printf("\n Media Geral: %.2f", totalGeralConsumido / consumidores);
    printf("\n Industrial [%]: %.2f, Residencial [%]: %.2f, Comercial [%]: %.2f",
           100.0 * totalIndustrial / totalGeralConsumido,
           100.0 * totalResidencial  / totalGeralConsumido,
           100.0 * totalComercial / totalGeralConsumido);

    printf("\n Menor Consumo: %.2f | Segundo Menor Consumo: %.2f", menorConsumo, segundoMenorConsumo);

    return 0;
}
*/
