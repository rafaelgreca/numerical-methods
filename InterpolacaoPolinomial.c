#include <stdio.h>
#include <stdlib.h>

#define l 5         //modificar esse espaço para alterar o número de linhas da matriz
#define c 6         //modificar esse espaço para alterar o número de colunas da matriz

/* CIC 250 - Cálculo Numérico para Computação
   Exercício Prático 06 - 11/04/18
   2018000434 - Rafael Greca Vieira
   Interpolação Polinomial
*/

void preencheMatriz(){
    double M[l][c];
    int i,j;

    for(i=0;i<l;i++){                       //essa funcao preenche a matriz
        for(j=0;j<c;j++){
            scanf("%lf",&M[i][j]);
        }
    }

    EliminacaoGauss(M);  //chama a funcao responsavel pela escalonamento da matriz

}

void EliminacaoGauss(double M[l][c]){

    int k, i, j, s;
    int aux1;
    double m, M2[l];

    for(aux1 = 0; aux1 < l ; aux1++){
        M2[aux1] = M[aux1][c-1];       //separa os coeficientes livres em um vetor
    }

    imprimeMatriz(M);
    printf("\n\n");

    for(k = 0; k < c; k++){
        for(i = k + 1; i < l; i++){

            m = (M[i][k]/M[k][k]);  //calcula o multiplicador
            M[i][k] = 0;  //zera o valor de a[i][k]
                          //exemplo: matriz | 1 1 1 1   |                                                              |1 1 1 1  |
                          //                | 1 -1 -1 1 |  m = a[1][0] / a[0][0] = 1/1 => m = 1 e zera a[1][0] ficando |0 -1 -1 1|
                          //                | 2 2 2 3   |                                                              |   ...   |

            for(j = k + 1; j < c; j++){
                M[i][j] = M[i][j] - (m * M[k][j]);  // a[1][1] = a[1][1] - (m * a[0][1])
                M2[j] = M2[j] - (m * M2[k]);        // M2[1] = M2[1] - (m * M2[0])
                //a[i][c-1] = M2[i] - (m * M2[k]);
            }

            imprimeMatriz(M);  //imprime a matriz a cada etapa realizada
            printf("\n\n");
        }
    }

    imprimeResultados(M);   //chama a funcao de imprimir os resultados da variável x

}

void imprimeResultados(double M[l][c]){
    int i, j, k;
    double a[l], s;

    a[l-1] = M[l-1][c-1]/ M[l-1][l-1];  //calcula o valor da variavel x[l-1] (ultima linha da matriz) e salva no vetor

    printf("Resolucao do sistema: \n\n");

    for(k = l - 1; k >= 0; k--){    //essa funcao tem como objetivo calcular o valor das outras variaveis entre x[l-2] a x[0]
        s = 0;
        for(j= k + 1; j < l; j++){
            s = s + M[k][j] * a[j];
            a[k] = ((M[k][j + 1] - s)/(M[k][k]));  //calcula e armazena o valor da variavel x[i] (x0,x1, etc..) no seu respectivo
        }                                          //lugar 'i' no vetor x
    }


    for(i=0;i<l;i++){
        printf("a%d = %lf\n",i,a[i]);       //imprime o valor das variaveis
    }

    printf("\n\n");
    imprimeFormula(a);
    printf("\n\n");
}

void imprimeFormula(double a[l]){
    int i;
    double k,z=0;

    printf("Formula de Interpolacao Polinomial: \n\n");
    printf("g(x) = ");

    for(i=0;i<l;i++){
        if(i==0){
            printf("%lf",a[i]);
        }else{
            if(a[i] > 0){
              printf(" + %lf x^%d" ,a[i],i);
            }else{
              printf(" %lf x^%d" ,a[i],i);
            }
        }
    }

    printf("\nDigite o valor de x para encontrar y: ");
    scanf("%lf",&k);

    for(i=0;i<l;i++){
        if(i==0){
            z += a[i];
        }else{
            z += a[i] * pow(k,i);
        }
    }

    printf("O valor de y eh: %lf\n\n",z);
}

void imprimeMatriz(double M[l][c]){
    int i,j;

    for(i=0;i<l;i++){               //imprime a matriz
        printf("\n");
        for(j=0;j<c;j++){
            printf("%lf ",M[i][j]);
      }
    }
}

int main()
{
    preencheMatriz(); //chama a funcao de preencher a matriz
    return(EXIT_SUCCESS);
    printf("\n\n");
}
