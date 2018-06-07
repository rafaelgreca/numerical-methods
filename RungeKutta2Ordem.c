#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcao(double x, double y){
    //insira a função aqui
    return (x - y + 2);
}

int main()
{
    double x0, y0, a, b, h, resulanterior, y, xi;
    int n, i;

    printf("Entre com os valores de x0 e y0, respectivamente (Exemplo: y(0) = 2 | x0 = 0 e y0 = 2): ");
    scanf(" %lf %lf",&x0,&y0);
    printf("Entre com os valores de a e b do intervalo, respectivamente: ");
    scanf(" %lf %lf",&a,&b);
    printf("Entre com a quantidade de subintervalos que deseja: ");
    scanf("%d",&n);
    printf("\n\n");

    h = (b-a)/n;

    resulanterior = y0;
    xi = x0;

    for(i=0; i<n; i++){

        y = resulanterior + ((h/2) * (funcao(xi,resulanterior) + funcao(xi + h, resulanterior + (h * funcao(xi,resulanterior)))));

        resulanterior = y;
        xi += h;

        printf("y%d = %.9lf\n",i+1,y);
    }

    printf("\nResultado:\ny%d = %.9lf e x%d = %.3lf\n\n",n,y,n,b);

    return 0;
}
