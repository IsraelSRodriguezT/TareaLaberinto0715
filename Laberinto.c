#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para usleep
#include <time.h>   // Para srand y rand

#define FILAS 13
#define COLUMNAS 25

void imprimirLaberinto(int laberinto[FILAS][COLUMNAS]) {
    system("clear"); // Para Unix/Linux/MacOS, use "cls" en Windows
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (laberinto[i][j] == 1) {
                printf("1");
            } else if (laberinto[i][j] == 2) {
                printf("H");
            } else if (laberinto[i][j] == 3) {
                printf("X");
            } else if (laberinto[i][j] == 4) {
                printf("*");
            } else if (laberinto[i][j] == 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
    usleep(200000); // Pausa de 200ms
}

int encontrarSalida(int laberinto[FILAS][COLUMNAS], int x, int y, int *movimientos) {
    if (x < 0 || x >= COLUMNAS || y < 0 || y >= FILAS || laberinto[y][x] == 1 || laberinto[y][x] == 2 || laberinto[y][x] == 4) {
        return 0;
    }
    if (laberinto[y][x] == 3) {
        return 1;
    }
    
    laberinto[y][x] = 4; // Marca el camino recorrido
    imprimirLaberinto(laberinto);
    (*movimientos)++;

    // Moverse en las 4 direcciones
    if (encontrarSalida(laberinto, x + 1, y, movimientos) ||
        encontrarSalida(laberinto, x - 1, y, movimientos) ||
        encontrarSalida(laberinto, x, y + 1, movimientos) ||
        encontrarSalida(laberinto, x, y - 1, movimientos)) {
        return 1;
    }
    
    laberinto[y][x] = 0; // Desmarca el camino si no se encuentra la salida
    imprimirLaberinto(laberinto);
    return 0;
}

int main() {
    FILE *laberintotext; 
    laberintotext = fopen("laberintotext.txt", "w");
    printf("Bienvenido al programa para mostrar un laberinto\n");

    int matriz[FILAS][COLUMNAS];
    srand(time(NULL));

    // Inicialización del laberinto
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            if (i == 0 || j == 0 || i == (FILAS - 1) || j == (COLUMNAS - 1)) {
                matriz[i][j] = 2; // Paredes externas
                if ((i == 1 && j == 0) || (i == (FILAS - 2) && j == (COLUMNAS - 1))) {
                    matriz[i][j] = 3; // Salidas
                }
            } else {
                matriz[i][j] = 0; // Espacios vacíos
            }
        }
    }

    // Generación de paredes aleatorias
    float densidad = 1.0; // Densidad de paredes (1.0 significa que cada celda tiene una pared)
    int Fparedes = (int)(densidad * FILAS * COLUMNAS / 4);
    
    for (int i = 0; i < Fparedes; i++) {
        int x = rand() % (COLUMNAS - 2);
        x = (x / 2) * 2 + 1;
        int y = rand() % (FILAS - 1);
        y = (y / 2) * 2;
        if (matriz[y][x] == 0) {
            matriz[y][x] = 1; // Poner una pared
            for (int j = 0; j < Fparedes; j++) {
                int mx[4] = {x, x, x + 2, x - 2};
                int my[4] = {y + 2, y - 2, y, y};
                int r = rand() % 4;
                if (my[r] >= 0 && my[r] < FILAS && mx[r] >= 0 && mx[r] < COLUMNAS && matriz[my[r]][mx[r]] == 0) {
                    matriz[my[r]][mx[r]] = 1; // Poner una pared
                    matriz[my[r] + (y - my[r]) / 2][mx[r] + (x - mx[r]) / 2] = 1; // Poner una pared
                }
            }
        }
    }

    // Ubicación de bloques en la salida
    for (int i = 0; i < 2; i++) {
        int bloqran;
        do {
            bloqran = rand() % (COLUMNAS - 1);
        } while (bloqran <= 3 || bloqran >= 22);
        if (i == 0) {
            matriz[1][bloqran] = 1; // Poner una pared
        } else {
            matriz[11][bloqran] = 1; // Poner una pared
        }
        int bloqran2;
        do {
            bloqran2 = rand() % (FILAS - 1);
        } while (bloqran2 <= 3 || bloqran2 >= 22 || bloqran2 == bloqran || bloqran2 == (bloqran - 1) || bloqran2 == (bloqran + 1));
        if (i == 0) {
            matriz[1][bloqran2] = 1; // Poner una pared
        } else {
            matriz[11][bloqran2] = 1; // Poner una pared
        }
    }

    matriz[1][1] = 0; // Espacio inicial del asterisco
    matriz[FILAS - 2][COLUMNAS - 2] = 0; // Espacio de la salida

    // Imprimir el laberinto inicial
   for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            if(matriz[i][j]==1){
                printf("1");
                fprintf(laberintotext, "1" );
            }else if(matriz[i][j]==2){
                printf("H");
                fprintf(laberintotext, "H");
            }else if(matriz[i][j]==3){
                printf("X");
                fprintf(laberintotext, "X");
            }else if(matriz[i][j]==0){
                printf(" ");
                fprintf(laberintotext, "0");
            }
        }
        printf("\n"); //Para hacer un salto de linea al momento de cambiar de fila
        fprintf(laberintotext, "\n");
        
    }
        fclose(laberintotext);
    int movimientos = 0;
    if (encontrarSalida(matriz, 1, 1, &movimientos)) {
        printf("El asterisco encontró la salida en %d movimientos.\n", movimientos);
    } else {
        printf("El asterisco no encontró la salida.\n");
    }

    return 0;
}
