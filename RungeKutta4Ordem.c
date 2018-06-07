#include <stdio.h>
#include <stdlib.h>

double funcao(double x, double y){
    //insira aqui a função PVI
    return (y);
}

int main()
{
    double x0, y0, a, b, h, resulanterior, y, K1, K2, K3, K4, xi;
    int n, i;

    printf("Entre com os valores de x0 e y0, respectivamente (Exemplo: y(0) = 1 | x0 = 0 e y0 = 1): ");
    scanf(" %lf %lf",&x0,&y0);
    printf("Entre com os valores de a e b, respectivamente: ");
    scanf(" %lf %lf",&a,&b);
    printf("Digite a quantidade de subintervalos que deseja: ");
    scanf("%d",&n);
    printf("\n\n");

    h = (b - a)/n;
    resulanterior = y0;
    xi = x0;

    for(i=0; i<n; i++){

       K1 = funcao(xi,resulanterior);
       K2 = funcao(xi + (h/2), resulanterior + (h * K1)/2);
       K3 = funcao(xi + (h/2), resulanterior + (h * K2)/2);
       K4 = funcao(xi + h, resulanterior + (h * K3));

       y = resulanterior + (h/6) * (K1 + 2*K2 + 2*K3 + K4);

       printf("y%d = %.9lf\n",i+1,y);

       resulanterior = y;
       xi += h;
    }

    printf("\nResultado:\ny%d = %.9lf em x%d = %.3lf\n",n,y,n,b);

    return 0;
}
