#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    printf("Bienvenido al programa para mostrar un laberinto\n");
    int filas=8;
    int columnas=18;
    int matriz[8][18];
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(i==0||j==0||i==(filas-1)||j==(columnas-1)){
                matriz[i][j]=1;
            } else{
                matriz[i][j]=0;
            }
        }
    }
    float densidad=1; 
    densidad=(filas*columnas*densidad)/4;
    int Fparedes=densidad*8;
    srand(time(NULL));
    for(int i=0;i<densidad;i++){
        int x=rand()%(columnas-4)+2; // 2 - 16
        x=(x/2)*2;
        int y=rand()%(filas-4)+2; // 2 - 6
        y=(y/2)*2;
        matriz[y][x]=1;
        for(int j=0;j<Fparedes;j++){
            int mx[4]={x,x,x+2,x-2};
            int my[4]={y+2,y-2,y,y};
            int r=rand()%4;
            if(matriz[my[r]][mx[r]]==0){
                matriz[my[r]][mx[r]]=1;
                matriz[my[r]+(y-my[r])/2][mx[r]+(x-mx[r])/2]=1;
            }
        }
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]==1){
                printf("%c", 178);
            }else if(matriz[i][j]==0){
                printf(" ");
            }
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
    }
    return 0;
}