#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*   CIC 250 - Matematica Computacional
     Exercício Prático 03 - 21/03/18
     2018000434 - Rafael Greca Vieira
     Calculo de raizes reais de funcoes reais - Método de Newton-Raphson
*/

double funcao(double x){ //modificar essa parte para alterar a função
    return pow(2,x) - 2*x*x + 1;
}

double derivada(double x){ //modificar essa parte para alterar a derivada da função
    return pow(2,x)*log(2) - 4*x;
}

int main()
{
    double x, x1, precisao1, precisao2;
    int c=0; // contador de iterações
    int iteracoes; //quantidade de iterações digitadas pelo usuário

    printf("Entre com a aproximacao inicial: ");
    scanf("%lf",&x);
    printf("Entre com a primeira precisao: ");
    scanf("%lf",&precisao1);
    printf("Entre com a segunda precisao: ");
    scanf("%lf",&precisao2);
    printf("Digite a quantidade de iteracoes: ");
    scanf("%d",&iteracoes);
    printf("\n\n");

    while(c < iteracoes){ //critério de parada com número máximo de iterações
        x1 = x - (funcao(x)/derivada(x));

        if(fabs(x1 - x) < precisao2 || fabs(funcao(x)) < precisao1 || fabs(funcao(x1)) < precisao1){
            break;
        }

        x = x1;

        c++;
    }

    printf("Raiz encontrada em: %lf\nQuantidade de Iteracoes: %d\n",x1,c);
    return 0;
}
