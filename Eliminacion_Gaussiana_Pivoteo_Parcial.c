/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Eliminacion Gaussiana con Pivoteo Parcial Escalado
 * Fecha: 23-02-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa realiza operaciones de suma y multiplicacion de matrices.\n");
	int m1, n1;
	int i, j, k, aux3;
	float piv, rmax, smax, r, aux, suma;
	printf("Ingrese la cantidad de filas de la matriz 1\n");
	scanf("%d", &m1);
	printf("Ingrese la cantidad de columnas de la matriz 1\n");
	scanf("%d", &n1);
	printf("Introduzca los valores de la matriz, seguidos por los valores del vector b\n");
	float matrix1[m1][n1];
	float array1[n1];
	float S[n1];
	float results[n1];
	int L[m1];
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
            scanf("%f", &aux);
			matrix1[i][j] = aux;
		}
	}
	for (i=0; i<n1; i++) {
		scanf("%f", &aux);
		array1[i] = aux;
	}
	printf("Matriz:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
			printf("%.2f     ", matrix1[i][j]);
		}
		printf("|    %.2f", array1[i]);
		printf("\n");
	}

	/* Smax */
	for (i=0; i<m1; i++) {
		L[i] = i;
		smax = 0;
		for (j=0; j<n1; j++) {
			if (fabs(matrix1[i][j]) > smax) {
				smax = matrix1[i][j];
			}
		}
		S[i] = smax;
	}

	/* Rmax */
	for (k=0; k<n1-1; k++) {
		rmax = 0;
		for (i=k; i<n1; i++) {
			r = fabs((matrix1[(L[i])][k])/(S[(L[i])]));
			if (r > rmax) {
				rmax = r;
				j = i;
			}
		}
		aux3 = L[k];
		L[k] = L[j];
		L[j] = aux3;

		for (i=k+1; i<n1; i++) {
			piv = (matrix1[(L[i])][k])/(matrix1[(L[k])][k]);
			for (j=k; j<n1; j++) {
				matrix1[(L[i])][j] = (matrix1[(L[i])][j] - (piv*matrix1[(L[k])][j]));
			}
			array1[(L[i])] = (array1[(L[i])] - (piv*array1[(L[k])]));
		}
	}

	results[n1-1] = array1[L[n1-1]]/matrix1[L[n1-1]][n1-1];

    for (i=n1-2; i >= 0; i--) {
        suma = array1[L[i]];
        for (j=i+1; j<n1; j++) {
            suma = suma - (matrix1[L[i]][j]*results[j]);
        }
        results[i] = suma/matrix1[L[i]][i];
	}

    printf("\nMatriz Aumentada:\n");
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
