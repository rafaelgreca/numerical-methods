#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*CIC 250 - Cálculo Numérico para Computação
  Exercício Prático 02 - 14/03/18
  Nome: Rafael Greca Vieira
  Número da Matrícula: 2018000434
  Calculo de raizes reais de funcoes reais - Método de Posição Falsa*/

double funcao(double x){   //modifique esse espaço para trocar a função
    double e = 2.718;
    return (x - sin(x)); //funcao
}

int main(){

    double a,b,precisao,x,M;
    int c=0;   //numero de iterações

    printf("Digite o valor para A e B: ");
    scanf("%lf %lf",&a,&b);
    printf("Digite a precisao: ");
    scanf("%lf",&precisao);
    printf("\n\n");

    if (funcao(a) * funcao(b) > 0){
        printf("Nao eh possível calcular a raiz!\n"); //não existe um ponto entre a e b que é zero de f(x)
        return 0;
    }
    else{
     while(c < 51){ //um dos casos de parada é que o número de iteração tem que ser menor que 51
        M = funcao(a);
        x = (a*funcao(b) - b*funcao(a))/(funcao(b) - funcao(a));   //calcula a media ponderada entre a e b com peso |funcao(b)| e |funcao(a)|

         if(M * funcao(x) > 0){
            a = x;  //se funcao(a) (ou M) multiplicado pela funcao(x) for maior que zero, 'a' recebe o valor de X
         }else{
            b = x;
         }
        //printf("C = %d; A = %lf\n",c,a);

        if(fabs(b - a) < precisao){
            break;  //se o valor absoluto de b - a for menor que a precisão, sair do while
        }

         c++;  //soma mais uma iteração
     }
    }

    printf("Numero de iteracoes: %d\nRaiz encontrada em: %lf\n",c,x);
    return (EXIT_SUCCESS);
}


