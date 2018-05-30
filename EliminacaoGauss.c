#include <stdio.h>
#include <stdlib.h>

#define l 2 //define o número de linhas (modificar esse espaço para modificar a quantidade de linhas)
#define c 3  //define o número de colunas (modificar esse espaço para modificar a quantidade de colunas)

//CIC250 - Cálculo Numérico para Computação
//Exercício Pratico 04 - 28/03;2018
//2018000434 - Rafael Greca Vieira
//Resolução de sistemas lineares pelo método de Eliminação de Gauss


void preencheMatriz(){
    double a[l][c];
    int i,j;

    for(i=0;i<l;i++){                       //essa funcao preenche a matriz
        for(j=0;j<c;j++){
            scanf("%lf",&a[i][j]);
        }
    }

    EliminacaoGauss(a);  //chama a funcao responsavel pela escalonamento da matriz

}

void EliminacaoGauss(double a[l][c]){

    int k, i, j, s;
    int aux1;
    double m, M2[l];

    for(aux1 = 0; aux1 < l ; aux1++){
        M2[aux1] = a[aux1][c-1];       //separa os coeficientes livres em um vetor
    }

    imprimeMatriz(a);
    printf("\n\n");

    for(k = 0; k < c; k++){
        for(i = k + 1; i < l; i++){

            m = (a[i][k]/a[k][k]);  //calcula o multiplicador
            a[i][k] = 0;  //zera o valor de a[i][k]
                          //exemplo: matriz | 1 1 1 1   |                                                              |1 1 1 1  |
                          //                | 1 -1 -1 1 |  m = a[1][0] / a[0][0] = 1/1 => m = 1 e zera a[1][0] ficando |0 -1 -1 1|
                          //                | 2 2 2 3   |                                                              |   ...   |

            for(j = k + 1; j < c; j++){
                a[i][j] = a[i][j] - (m * a[k][j]);  // a[1][1] = a[1][1] - (m * a[0][1])
                M2[j] = M2[j] - (m * M2[k]);        // M2[1] = M2[1] - (m * M2[0])
                //a[i][c-1] = M2[i] - (m * M2[k]);
            }

            imprimeMatriz(a);  //imprime a matriz a cada etapa realizada
            printf("\n\n");
        }
    }

    imprimeResultados(a);   //chama a funcao de imprimir os resultados da variável x

}

void imprimeResultados(double a[l][c]){
    int i, j, k;
    double x[l], s;

    x[l-1] = a[l-1][c-1]/ a[l-1][l-1];  //calcula o valor da variavel x[l-1] (ultima linha da matriz) e salva no vetor

    printf("Resolucao do sistema: \n\n");

    for(k = l - 1; k >= 0; k--){    //essa funcao tem como objetivo calcular o valor das outras variaveis entre x[l-2] a x[0]
        s = 0;
        for(j= k + 1; j < l; j++){
            s = s + a[k][j] * x[j];
            x[k] = ((a[k][j + 1] - s)/(a[k][k]));  //calcula e armazena o valor da variavel x[i] (x0,x1, etc..) no seu respectivo
        }                                          //lugar 'i' no vetor x
    }


    for(i=0;i<l;i++){
        printf("x%d = %lf\n",i,x[i]);       //imprime o valor das variaveis
    }
    printf("\n\n");
}

void imprimeMatriz(double a[l][c]){
    int i,j;

    for(i=0;i<l;i++){               //imprime a matriz
        printf("\n");
        for(j=0;j<c;j++){
            printf("%lf ",a[i][j]);
      }
    }
}

int main()
{
    preencheMatriz(); //chama a funcao de preencher a matriz
    return(EXIT_SUCCESS);
    printf("\n\n");
}
