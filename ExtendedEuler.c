#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double x, double y){
    //insira a função aqui
    return (1 - (y/x));
}

double derivadaSegundaFuncao(double x, double y){
    //insira a derivada segunda da função aqui
    return (-1 * (funcao(x,y)/x) + (y/pow(x,2)));
}

int main()
{
    double x0, y0, x, h, ant, antresul, d, resul = 0;

    printf("Digite o valor de x e seu valor de y (Exemplo: f(2) = 3/ x= 2, y=3): ");
    scanf(" %lf %lf",&x0,&y0);
    printf("Digite o valor de x que deseja encontrar o y(x): ");
    scanf(" %lf",&x);
    printf("Digite o tamanho de cada intervalo: ");
    scanf(" %lf",&h);
    printf("\n\n");

    while((float)x0 < (float)x){

        resul = y0 + funcao(x0,y0)* h + derivadaSegundaFuncao(x0,y0) * pow(h,2)/2;
        printf("y[%lf] = %lf\n",x0+h,resul);

        y0 = resul;
        x0 += h;

    }

    printf("\n\nResultado: %.8lf \n",resul);
}
