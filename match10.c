#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    srand(time(0));
    int n, m;
    int e = 0;
    int selec1 = 0;
    int selec2 = 0;
    int selec3 = 0;
    int selec4 = 0;
    int sum10 = 0, count = 0, counter;
    bool flag;
    printf("Ingrese el ancho que desea para la tabla: ");
    scanf("%d", &m);
    printf("Ingrese la altura que desea para la tabla: ");
    scanf("%d", &n);

    int match[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            match[i][j] = rand() % 10;
        }
    }
    printf("\n");
    do {
        printf("\nTurno %d\n", e + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("[%d,%d]\t", i, j);
                printf("%d\t", match[i][j]);
            }
            printf("\n");
        }
        int array[2];
        printf("Seleccione la fila del numero a elegir: ");
        scanf("%d", &selec1);
        printf("Seleccione la columna a elegir: ");
        scanf("%d", &selec2);
        printf("%d y %d\n", selec1, selec2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == selec1 && j == selec2) {
                    array[1] = match[i][j];
                }
            }
        }
        do {
            flag = 0;
            printf("Seleccione la fila del segundo numero a elegir: ");
            scanf("%d", &selec3);
            printf("Seleccione la columna a elegir: ");
            scanf("%d", &selec4);
            printf("%d y %d\n", selec3, selec4);

            if (selec3 > selec1 + 1 && selec4 > selec2 + 1 ||
                selec3 < selec1 - 1 && selec4 < selec2 - 1) {
                printf("\nNo puedes elegir numeros que no esten adjuntos\n");
                flag = 1;
                printf("\n");
            } else {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == selec3 && j == selec4) {
                            array[2] = match[i][j];

                            break;
                        }
                    }
                }
            }
        } while (flag >= 1);
        sum10 = 0;
        for (int i = 1; i <= 2; i++) {
            sum10 += array[i];
            printf("%d\n\t", sum10);
        }
        printf("%d", sum10);
        if (sum10 == 10) {
            printf("\nHa encontrado una pareja que da 10!\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == selec1 && j == selec2) {
                        match[i][j] = 0;
                        if (i == selec3 && j == selec4) {
                            match[i][j] = 0;
                        }
                    }
                }
            }
        } else {
            printf("\nNo ha encontrado una pareja que da 10\n");
        }
        count++;
    } while (n * m > count);
    return 0;
}