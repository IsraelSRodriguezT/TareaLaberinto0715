#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    printf("Bienvenido al programa para mostrar un laberinto\n");
    int filas=13;
    int columnas=25;
    int matriz[13][25];
    srand(time(NULL));
    int xentrada=rand()%(filas-1);
    int xsalida=rand()%(filas-1);
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(i==0||j==0||i==(filas-1)||j==(columnas-1)){
                matriz[i][j]=1;
                if((i==1&&j==0)||(i==(filas-1)&&j==(columnas-2))){
                    matriz[i][j]=2;
                }
            } else{
                matriz[i][j]=0;
            }
        }
    }
    float densidad=1; 
    densidad=(filas*columnas*densidad)/4;
    int Fparedes=densidad*8;
    for(int i=0;i<densidad;i++){
        int x=rand()%(columnas-2); // 2 - 16
        x=(x/2)*2+1;
        int y=rand()%(filas-1); // 2 - 6
        y=(y/2)*2;
        if (matriz[y][x] == 0) {
            matriz[y][x] = 1;
            for (int j = 0; j < Fparedes; j++) {
                int mx[4] = {x, x, x + 2, x - 2};
                int my[4] = {y + 2, y - 2, y, y};
                int r = rand() % 4;
                if (my[r] >= 0 && my[r] < filas && mx[r] >= 0 && mx[r] < columnas && matriz[my[r]][mx[r]] == 0) {
                    matriz[my[r]][mx[r]] = 1;
                    matriz[my[r] + (y - my[r]) / 2][mx[r] + (x - mx[r]) / 2] = 1;
                }
            }
        }
    }
    matriz[1][1]=0;
    matriz[filas-1][columnas-2]=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]==1){
                printf("%c", 178);
            }else if(matriz[i][j]==2){
                printf("X");
            }else if(matriz[i][j]==0){
                printf(" ");
            }
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
    return 0;
}