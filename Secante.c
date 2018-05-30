#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*   CIC 250 - Matematica Computacional
     Exercício Prático 03 - 21/03/18
     2018000434 - Rafael Greca Vieira
     Calculo de raizes reais de funcoes reais - Método da Secante
*/

double funcao(double x){ //modificar essa parte para alterar a função
    return sin(x) + cos(1 + x*x) - 1;
}

int main()
{
    double x, x1, x2, precisao1, precisao2;
    int c=0; //contador de iterações
    int iteracoes; //quantidade de iteracoes digitadas pelo usuario

    printf("Entre com as aproximacoes iniciais: ");
    scanf("%lf %lf",&x,&x1);
    printf("Entre com a primeira precisao: ");
    scanf("%lf",&precisao1);
    printf("Entre com a segunda precisao: ");
    scanf("%lf",&precisao2);
    printf("Digite a quantidade de iteracoes: ");
    scanf("%d",&iteracoes);
    printf("\n\n");

    while(c < iteracoes){ //critério de parada onde o número de iterações tem que ser menor que 51
        x2 = x1 - (funcao(x1)/(funcao(x1) - funcao(x))) * (x1 - x);

        if(fabs(funcao(x)) < precisao1 || fabs(x1 - x) < precisao2 || fabs(x2 - x1) < precisao2){
            break;
        }

        x = x1;
        x1 = x2;

        c++;
    }

    printf("Raiz encontrada em: %lf\nQuantidade de iteracoes: %d\n",x2,c);
    return 0;
}
