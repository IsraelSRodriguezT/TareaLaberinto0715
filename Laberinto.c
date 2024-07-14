#include <stdio.h>
void bucle(int filas, int columnas, int matriz[filas][columnas]){ //Procedimiento para imprimir la matriz resultante
    printf("Laberinto:\n");
    for(int i=0;i<filas;i++){ //Bucle for para indicarle a la matriz en que posicion de fila debe de estar
        printf("|"); //Para empezar a imprimir los (|)
        for(int j=0;j<columnas;j++){ //Bucle for para indicarle a la matriz en que posicion de columna debe de estar
            if(matriz[i][j]==0){
                printf("%c|", 178); //Para el caso de que si se cumple la condicion, que se imprima el valor de la matriz
            }else if(matriz[i][j]==1){
                printf("  ");
            }else if(matriz[i][j]==2){
                printf(" %c", 158);
            }else{
                printf(" |");
            }
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
}
int main(){
    printf("Bienvenido al programa para mostrar un laberinto\n");
    int filas=8;
    int columnas=18;
    int matriz[8][18]=
    { {0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
      {0,2,2,0,0,2,2,2,2,1,0,0,2,2,2,2,0,0},
      {0,0,2,2,0,2,0,0,2,0,0,2,2,0,0,2,2,0},
      {0,0,0,2,2,2,0,0,2,2,2,2,0,0,0,0,2,2},
      {0,1,1,1,0,1,1,0,1,0,1,0,0,1,1,1,0,0},
      {0,0,0,1,0,0,0,0,0,0,1,1,1,1,0,1,1,0},
      {0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,0},
      {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    bucle(filas,columnas,matriz); //Si se cumple la condicion, que se llame al procedimiento que imprime la matriz resultante
    return 0;
}