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

    return pow(14,2*x);
}

double integral(double x){
    double e = 2.71;
    //entre com a integral da funcao

    return (480/pow(x,6));
}

double derivadaQuarta(double x){
    double e = 2.71;
    //entre com a derivada quarta da funcao

    return (pow(2,(2*x)+1) * 49 * log(14) * pow(log(196),3));
}

double maior(double x[], int subintervalos){
    int i;
    double aux, maior = 0;

    for(i=0; i<=2; i++){
        aux = fabs(derivadaQuarta(x[i]));

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

    h = (b - a)/2;

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
    for(i=0; i<=2; i++){
        printf("|%lf      |       %lf|\n",x[i],y[i]);
    }
    printf(" ------------------------------\n");
    printf("\n");

    for(i=0; i<=2; i++){
        if(i == 0){
            it += y[i];
        }

        if(i == 2){
            it += y[i];
            it = it * h/3;
        }

        if(i == 1){
            it += 4 * y[i];
        }

    }

    printf("It = %lf\n\n",it);


    max = maior(x,2);

    printf("f'(x) em %lf eh: %.3lf\n",a,integral(a));
    printf("f'(x) em %lf eh: %.3lf\n",b,integral(b));

    printf("f''(x) em %lf eh: %.3lf\n",a,derivadaQuarta(a));
    printf("f''(x) em %lf eh: %.3lf\n",b,derivadaQuarta(b));

    error = (pow(h,5)/90) * max;
    printf("Erro = %lf \n",error);

}
