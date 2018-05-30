#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*CIC 250 - C�lculo Num�rico para Computa��o
  Exerc�cio Pr�tico 02 - 14/03/18
  Nome: Rafael Greca Vieira
  N�mero da Matr�cula: 2018000434
  Calculo de raizes reais de funcoes reais - M�todo de Posi��o Falsa*/

double funcao(double x){   //modifique esse espa�o para trocar a fun��o
    double e = 2.718;
    return (x - sin(x)); //funcao
}

int main(){

    double a,b,precisao,x,M;
    int c=0;   //numero de itera��es

    printf("Digite o valor para A e B: ");
    scanf("%lf %lf",&a,&b);
    printf("Digite a precisao: ");
    scanf("%lf",&precisao);
    printf("\n\n");

    if (funcao(a) * funcao(b) > 0){
        printf("Nao eh poss�vel calcular a raiz!\n"); //n�o existe um ponto entre a e b que � zero de f(x)
        return 0;
    }
    else{
     while(c < 51){ //um dos casos de parada � que o n�mero de itera��o tem que ser menor que 51
        M = funcao(a);
        x = (a*funcao(b) - b*funcao(a))/(funcao(b) - funcao(a));   //calcula a media ponderada entre a e b com peso |funcao(b)| e |funcao(a)|

         if(M * funcao(x) > 0){
            a = x;  //se funcao(a) (ou M) multiplicado pela funcao(x) for maior que zero, 'a' recebe o valor de X
         }else{
            b = x;
         }
        //printf("C = %d; A = %lf\n",c,a);

        if(fabs(b - a) < precisao){
            break;  //se o valor absoluto de b - a for menor que a precis�o, sair do while
        }

         c++;  //soma mais uma itera��o
     }
    }

    printf("Numero de iteracoes: %d\nRaiz encontrada em: %lf\n",c,x);
    return (EXIT_SUCCESS);
}


