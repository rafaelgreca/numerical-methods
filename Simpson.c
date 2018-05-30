#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//CIC250 - Calculo Numérico para Computação
//Exercicio Pratico 11 - 23/05/18
//2018000434 - Rafael Greca Vieira
//Integração pelo método de Simpson 1/3

double funcao(double x){
    double e = 2.71;
    //entre com a funcao

    return (pow(x,2) * exp(x));
}

double derivadaQuarta(double x){
    double e = 2.71;
    //entre com a derivada quarta da funcao

    return (exp(x) * (pow(x,2) + 8*x + 12));
}

double maior(double x[], int m){
    int i;
    double aux, maior = 0;

    for(i=0; i<=m; i++){
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
    int subintervalos, i=0, m;

    printf("Digite o valor de a e b, respectivamente: ");
    scanf("%lf %lf",&a,&b);
    printf("Digite a quantidade de subintervalos: ");
    scanf(" %d",&subintervalos);

    //alterar essa parte caso ele passe o valor de 2n direto (2 * subintervalos)
    //a fórmula ficará => h = (b - a)/subintervalos
    //e trocar o 'm' por 'subintervalos' na função maior e nos dois for abaixo

    h = (b - a)/(2 * subintervalos);

    m = 2 * subintervalos;

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

    //imprime os valores de x e y
    printf("\nTabela de valores X e Y: \n");
    printf(" ------------------------------");
    printf("\n|   x          |           y   |\n");
    printf("-------------------------------\n");
    for(i=0; i<=m; i++){
        printf("|%.3lf         |       %.6lf|\n",x[i],y[i]);
    }
    printf(" ------------------------------\n");
    printf("\n");

    //calcula o valor da área
    for(i=0; i<=m; i++){
        if(i == 0){
            it += y[i];
        }

        if(i == m){
            it += y[i];
            it = it * h/3;
        }

        if(i > 0 && i < m){
            if(i % 2 == 0){
                it += 2 * y[i];
            }else{
                it += 4 * y[i];
            }
        }

    }

    printf("It = %lf\n\n",it);

    //recebe o maior valor do intervalo na derivada a quarta da função
    max = maior(x,m);


    printf("f(iv) (x) em %lf eh: %.5lf\n",a,derivadaQuarta(a));
    printf("f(iv) (x) em %lf eh: %.5lf\n",b,derivadaQuarta(b));
    printf("\n");

    error = (pow(h,4)/180) * (b - a) * max;
    printf("Erro = %.8lf \n",error);

}
