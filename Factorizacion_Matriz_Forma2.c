/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Factorización de Matrices Forma 2
 * Fecha: 17-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa realiza la factorizacion de matriz obteniendo U y L\n");
	int m1, n1;
	int i, j, k, h;
	float piv, suma, aux;
	printf("Ingrese la cantidad de filas de la matriz 1\n");
	scanf("%d", &m1);
	printf("Ingrese la cantidad de columnas de la matriz 1\n");
	scanf("%d", &n1);
	printf("Introduzca los valores de la matriz, seguidos por los valores del vector b\n");
	float matrix1[m1][n1];
	float matrixL[m1][n1];
	float matrixaux[m1][n1];
	float matrix3[m1][m1];
	float array1[n1];
	float results[n1];
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
            scanf("%f", &aux);
			matrix1[i][j] = aux;
		}
	}
	for (i=0; i<m1; i++) {
		scanf("%f", &aux);
		array1[i] = aux;
	}
	for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++){
                matrixL[i][j] = 0;
            }
        }
    for (i=0; i<m1; i++) {
            matrixL[i][i] = 1;
    }
    for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
			matrix3[i][j] = 0;
		}
	}
	printf("Matriz:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
			printf("%.2f     ", matrix1[i][j]);
		}
		printf("|    %.2f", array1[i]);
		printf("\n");
	}

	for (k=0; k<n1-1; k++) {
        /*Inicializando matriz L*/
		for (i=0; i<m1; i++) {
            for (j=0; j<m1; j++){
                matrixL[i][j] = 0;
            }
        }
        for (i=0; i<m1; i++) {
                matrixL[i][i] = 1;
        }

        for (i=k+1; i<n1; i++) {
            piv = (matrix1[i][k])/(matrix1[k][k]);
            matrixL[i][k] = -piv;
            for (j=k; j<n1; j++) {
                matrix1[i][j] = matrix1[i][j] - (piv*matrix1[k][j]);
            }
            array1[i] = array1[i] - (piv*array1[k]);
        }
        printf("M%d:\n", k+1);
        for (i=0; i<m1; i++) {
            for (j=0; j<n1; j++) {
                printf("%.2f     ", matrixL[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        //Multiplicacion
        if (k > 0) {
        	for (i=0; i<m1; i++) {
                for (j=0; j<m1; j++) {
                    for (h=0; h<m1; h++) {
                        matrix3[i][j] = matrix3[i][j] + matrixL[i][h] * matrixaux[h][j];
                    }
                }
            }
        }
        for (i=0; i<m1; i++) {
            for (j=0; j<n1; j++) {
                matrixaux[i][j] = matrixL[i][j];
            }
        }
	}

	printf("M\n");
	for (i=0; i<m1; i++) {
        for (j=0; j<n1; j++) {
            printf("%.2f     ", matrix3[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    results[n1-1] = array1[n1-1]/matrix1[n1-1][n1-1];

	for (i=n1-2; i >= 0; i--) {
        suma = array1[i];
        for (j=i+1; j<n1; j++) {
            suma = suma - (matrix1[i][j]*results[j]);
        }
        results[i] = suma/matrix1[i][i];
	}



    printf("\nU:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
			printf("%.2f     ", matrix1[i][j]);
		}
		printf("|    %.2f", array1[i]);
		printf("\n");
	}

	printf("\nSolucion de X\n");
	for (i=0; i<n1; i++) {
        printf("X%d: %.2f   ", i+1, results[i]);
	}
	return 0;
}
