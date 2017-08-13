/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Metodo Gauss-Seidel
 * Fecha: 09-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa resuelve un sistema de ecuaciones lineales\ncon el metodo de Gauss-Seidel\n");
	int m1;
	int i, j, k;
	float aux, sum, e, error, maxerr;
	printf("Ingrese la cantidad de filas y columnas de la matriz\n");
	scanf("%d", &m1);
	printf("Introduzca los valores de la matriz, seguidos por los valores del vector b\n");
	float matrix1[m1][m1];
	float array1[m1];
	float variables[m1];
	float var2[m1];
	error = 100;
	for (i=0; i<m1; i++) {
		for (j=0; j<m1; j++) {
            scanf("%f", &aux);
			matrix1[i][j] = aux;
		}
	}
	for (i=0; i<m1; i++) {
		scanf("%f", &aux);
		array1[i] = aux;
	}

	printf("Introduzca los valores iniciales de las variables para la sustitucion\n");
	for (i=0; i<m1; i++) {
		scanf("%f", &aux);
		variables[i] = aux;
	}

	printf("Ingrese el error minimo\n");
	scanf("%d", &e);

	printf("Matriz:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<m1; j++) {
			printf("%.2f     ", matrix1[i][j]);
		}
		printf("|    %.2f", array1[i]);
		printf("\n");
	}

	/*Checar si la matriz es diagonalmente dominante*/
	for (i = 0; i < m1; i++) {
		sum = 0;
		for (j = 0; j < m1; j++) {
			if (j != i) {
				sum += fabs(matrix1[i][j]);
			}
		}
		if (sum > fabs(matrix1[i][i])) {
			printf("La matrix no es diagonalmente dominante\n");
			return 0;
		}
	}

	while (error > e) {
		for (i = 0; i < m1; i++) {
			aux = array1[i];
			for (j = m1-1; j >= 0; j--) {
				if (j != i) {
					aux = aux - (matrix1[i][j]*variables[j]);
				}
			}
			aux = aux/matrix1[i][i];
			var2[i] = aux;
			error = fabs(variables[i] - var2[i]);
			variables[i] = var2[i];
		}
	}


	printf("\nSolucion de X\n");
	for (i=0; i<m1; i++) {
        printf("X%d: %.2f   ", i+1, var2[i]);
	}
	return 0;
}
