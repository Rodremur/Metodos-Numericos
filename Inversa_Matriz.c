/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Inversa de Matriz
 * Fecha: 08-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa calcula la inversa de una matriz cuadrada de 3x3 si existe.\nTambien calcula 2 ejercicios especificos de su eleccion.\n");
	int m1, n1;
	int i, j, k, choice;
	float piv, piv2, piv3, aux, det;
	printf("El total de filas y columnas de la matriz sera 3 (una matriz cuadrada)\n");
	m1 = 3;
    printf("Ingrese que funcion desea realizar:\n1. Introducir matriz de 3x3\n\n2. [2 1 -2]\n   [1 1 -2]\n   [-1 0 1]\n\n3. [1 -1 0]\n   [1  0 2]\n   [1 -1 1]\n\n");
	float matrix1[m1][m1];
	float matrix2[m1][m1];
	float aux1[m1];
	float aux2[m1];
	float aux3[m1];
	float aux4[m1];
    scanf("%d", &choice);

    switch(choice) {

    case 1 : {
        printf("Introduzca los valores de la matriz:\n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                    scanf("%f", &aux);
                    matrix1[i][j] = aux;
                }
        }
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++){
                matrix2[i][j] = 0;
            }
        }
        for (i=0; i<m1; i++) {
            matrix2[i][i] = 1;
        }

        printf("Matriz:\n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                printf("%.2f     ", matrix1[i][j]);
            }
            printf("\n");
        }

        printf("Matriz de Identidad: \n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                printf("%.2f     ", matrix2[i][j]);
            }
            printf("\n");
        }

        det = (matrix1[0][0]*matrix1[1][1]*matrix1[2][2]) + (matrix1[0][1]*matrix1[1][2]*matrix1[2][0]) + (matrix1[0][2]*matrix1[1][0]*matrix1[2][1])
        - (matrix1[2][0]*matrix1[1][1]*matrix1[0][2]) - (matrix1[2][1]*matrix1[1][2]*matrix1[0][0]) - (matrix1[2][2]*matrix1[1][0]*matrix1[0][1]);

        if (det == 0) {
            printf("El determinante de la matriz es 0\n");
            return 0;
        }
        break;
    }
    case 2 : {
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++){
                matrix2[i][j] = 0;
            }
        }
        for (i=0; i<m1; i++) {
            matrix2[i][i] = 1;
        }

        matrix1[0][0] = 2; matrix1[0][1] = 1; matrix1[0][2] = -2;
        matrix1[1][0] = 1; matrix1[1][1] = 1; matrix1[1][2] = -2;
        matrix1[2][0] = -1; matrix1[2][1] = 0; matrix1[2][2] = 1;

        det = (matrix1[0][0]*matrix1[1][1]*matrix1[2][2]) + (matrix1[0][1]*matrix1[1][2]*matrix1[2][0]) + (matrix1[0][2]*matrix1[1][0]*matrix1[2][1])
        - (matrix1[2][0]*matrix1[1][1]*matrix1[0][2]) - (matrix1[2][1]*matrix1[1][2]*matrix1[0][0]) - (matrix1[2][2]*matrix1[1][0]*matrix1[0][1]);

        if (det == 0) {
            printf("El determinante de la matriz es 0\n");
            return 0;
        }

        printf("Matriz:\n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                printf("%.2f     ", matrix1[i][j]);
            }
            printf("\n");
        }

        printf("Matriz de Identidad: \n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                printf("%.2f     ", matrix2[i][j]);
            }
            printf("\n");
        }
        break;
    }
    case 3 : {
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++){
                matrix2[i][j] = 0;
            }
        }
        for (i=0; i<m1; i++) {
            matrix2[i][i] = 1;
        }

        matrix1[0][0] = 1; matrix1[0][1] = -1; matrix1[0][2] = 0;
        matrix1[1][0] = 1; matrix1[1][1] = 0; matrix1[1][2] = 2;
        matrix1[2][0] = 1; matrix1[2][1] = -1; matrix1[2][2] = 1;

        det = (matrix1[0][0]*matrix1[1][1]*matrix1[2][2]) + (matrix1[0][1]*matrix1[1][2]*matrix1[2][0]) + (matrix1[0][2]*matrix1[1][0]*matrix1[2][1])
        - (matrix1[2][0]*matrix1[1][1]*matrix1[0][2]) - (matrix1[2][1]*matrix1[1][2]*matrix1[0][0]) - (matrix1[2][2]*matrix1[1][0]*matrix1[0][1]);

        if (det == 0) {
            printf("El determinante de la matriz es 0\n");
            return 0;
        }

        printf("Matriz:\n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                printf("%.2f     ", matrix1[i][j]);
            }
            printf("\n");
        }

        printf("Matriz de Identidad: \n");
        for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++) {
                printf("%.2f     ", matrix2[i][j]);
            }
            printf("\n");
        }
        break;
    }
}

            for (k = 0; k < m1; k++) {
                if (matrix1[k][k] < 0) {
                    for (j = 0; j < m1; j++) {
                        matrix1[k][j] = -1*matrix1[k][j];
                        matrix2[k][j] = -1*matrix2[k][j];
                    }
                }
                if (matrix1[k][k] > 1) {
                    for (j = 0; j < m1; j++) {
                        aux1[j] = matrix1[k][j];
                        aux3[j] = matrix2[k][j];
                    }
                    if (matrix1[k+1][k] == 1) {
                        for (j = 0; j < m1; j++) {
                            aux2[j] = matrix1[k+1][j];
                            aux4[j] = matrix2[k+1][j];
                        }
                        for (j = 0; j < m1; j++) {
                        matrix1[k][j] = aux2[j];
                        matrix1[k+1][j] = aux1[j];
                        matrix2[k][j] = aux4[j];
                        matrix2[k+1][j] = aux3[j];
                    }
                    } else
                    if (matrix1[k+2][k] == 1) {
                        for (j = 0; j < m1; j++) {
                            aux2[j] = matrix1[k+2][j];
                            aux4[j] = matrix2[k+2][j];
                        }
                        for (j = 0; j < m1; j++) {
                        matrix1[k][j] = aux2[j];
                        matrix1[k+2][j] = aux1[j];
                        matrix2[k][j] = aux4[j];
                        matrix2[k+2][j] = aux3[j];
                    }
                    }
                }

                if (k == 0) {
                    piv = (matrix1[k+1][k])/(matrix1[k][k]);
                    piv2 = (matrix1[k+2][k])/(matrix1[k][k]);
                }
                if (k == 1) {
                    piv = (matrix1[k+1][k])/(matrix1[k][k]);
                    piv2 = (matrix1[k-1][k])/(matrix1[k][k]);
                }
                if (k == 2) {
                    piv = (matrix1[k-1][k])/(matrix1[k][k]);
                    piv2 = (matrix1[k-2][k])/(matrix1[k][k]);
                }

                for (j = 0; j < m1; j++) {
                    if (k == 0) {
                        matrix1[k+1][j] = matrix1[k+1][j] - (piv*matrix1[k][j]);
                        matrix2[k+1][j] = matrix2[k+1][j] - (piv*matrix2[k][j]);

                        matrix1[k+2][j] = matrix1[k+2][j] - (piv2*matrix1[k][j]);
                        matrix2[k+2][j] = matrix2[k+2][j] - (piv2*matrix2[k][j]);
                    }
                    if (k == 1) {
                        matrix1[k+1][j] = matrix1[k+1][j] - (piv*matrix1[k][j]);
                        matrix2[k+1][j] = matrix2[k+1][j] - (piv*matrix2[k][j]);

                        matrix1[k-1][j] = matrix1[k-1][j] - (piv2*matrix1[k][j]);
                        matrix2[k-1][j] = matrix2[k-1][j] - (piv2*matrix2[k][j]);
                    }
                    if (k == 2) {
                        matrix1[k-1][j] = matrix1[k-1][j] - (piv*matrix1[k][j]);
                        matrix2[k-1][j] = matrix2[k-1][j] - (piv*matrix2[k][j]);

                        matrix1[k-2][j] = matrix1[k-2][j] - (piv2*matrix1[k][j]);
                        matrix2[k-2][j] = matrix2[k-2][j] - (piv2*matrix2[k][j]);
                    }
                }
            }

    printf("\nMatriz Original a Identidad:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<m1; j++) {
			printf("%.2f     ", matrix1[i][j]);
		}
		printf("\n");
	}

    printf("\nMatriz Inversa:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<m1; j++) {
			printf("%.2f     ", matrix2[i][j]);
		}
		printf("\n");
	}
	return 0;
}
