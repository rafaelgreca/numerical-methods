#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//CIC250 - Cálculo Numérico para Computação
//Exercício Prático 10 - 16/05/18
//2018000434 - Rafael Greca Vieira
//Integração pelo método dos trapézios

double funcao(double x){
    double e = 2.71;
    //entre com a funcao

    return (1 - (pow(exp(1),-2*x)));
}

double integral(double x){
    double e = 2.71;
    //entre com a integral da funcao

    return (x + (pow(exp(1),-2*x))/2);
}

double integralSegunda(double x){
    double e = 2.71;
    //entre com a integral segunda da funcao

    return ((pow(x,2))/2 - pow(exp(1),-2*x)/4);
}

double maior(double x[], int subintervalos){
    int i;
    double aux, maior = 0;

    for(i=0; i<subintervalos+1; i++){
        aux = fabs(integralSegunda(x[i]));

        if(aux > maior){
            maior = aux;
        }
    }

    return maior;
}

int main()
{
    double a, b, c, d , h, x[100], y[100], it=0, max, error;
    int subintervalos, i=0;

    printf("Digite o valor de a e b, respectivamente: ");
    scanf("%lf %lf",&a,&b);
    printf("Digite a quantidade de subintervalos: ");
    scanf(" %d",&subintervalos);

    h = (b - a)/subintervalos;

    printf("\nIntervalos que serao usados: \n");

    d = a;
    while(d < b){
        c = d + h;
        printf("%lf ",d);
        printf("%lf ",c);
        printf("\n");

        x[i] = d;
        y[i] = funcao(d);

        d += h;
        i++;
    }

    x[i] = c;
    y[i] = funcao(c);

    printf("\nTabela de valores X e Y: \n");
    printf(" ------------------------------");
    printf("\n|   x          |           y   |\n");
    printf("-------------------------------\n");
    for(i=0; i<subintervalos+1; i++){
        printf("|%lf      |       %lf|\n",x[i],y[i]);
    }
    printf(" ------------------------------\n");
    printf("\n");

    for(i=0; i<subintervalos+1; i++){
        if(i == 0){
            it += y[i];
        }

        if(i == subintervalos){
            it += y[i];
            it = it * h/2;
        }

        if(i > 0 && i < subintervalos){
            it += 2 * y[i];
        }

    }

    printf("It = %lf\n\n",it);


    max = maior(x,subintervalos);

    printf("f''(x) em %lf eh: %.3lf\n",a,integralSegunda(a));
    printf("f''(x) em %lf eh: %.3lf\n",b,integralSegunda(b));

    error = (pow(h,2)/12) * (b - a) * max;
    printf("Erro = %lf \n",error);

}
