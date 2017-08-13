/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Operaciones de Matrices
 * Fecha: 15-02-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa realiza operaciones de suma y multiplicacion de matrices.\n");
	int m1, n1, m2, n2;
	int i, j, k, op;
	printf("Ingrese la cantidad de filas de la matriz 1\n");
	scanf("%d", &m1);
	printf("Ingrese la cantidad de columnas de la matriz 1\n");
	scanf("%d", &n1);
	printf("Ingrese la cantidad de filas de la matriz 2\n");
	scanf("%d", &m2);
	printf("Ingrese la cantidad de columnas de la matriz 1\n");
	scanf("%d", &n2);
	printf("El programa genera ambas matrices con numeros aleratorios\n");
	int matrix1[m1][n1];
	int matrix2[m2][n2];
	int matrix3[100][100];
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
			matrix1[i][j] = rand() % 10;
		}
	}
	for (i=0; i<m2; i++) {
		for (j=0; j<n2; j++) {
			matrix2[i][j] = rand() % 10;
		}
	}
	printf("Matriz 1:\n");
	for (i=0; i<m1; i++) {
		for (j=0; j<n1; j++) {
			printf("%d     ", matrix1[i][j]);
		}
		printf("\n");
	}
	printf("Matriz 2:\n");
	for (i=0; i<m2; i++) {
		for (j=0; j<n2; j++) {
			printf("%d     ", matrix2[i][j]);
		}
		printf("\n");
	}
	printf("Escoja operacion a realizar:\n1. Suma\n2. Multiplicacion\n");
	scanf("%d", &op);
	switch(op) {
		case 1 :
			printf("Suma\n");
			if (m1 != m2 || n1 != n2) {
				printf("El tamaño de las matrices no concuerdan para esta operacion\n");
				return 0;
			}

			for (i=0; i<m1; i++) {
				for (j=0; j<n1; j++) {
					matrix3[i][j] = matrix2[i][j] + matrix1[i][j];
				}
			}
			//Impresion
			for (i=0; i<m1; i++) {
				for (j=0; j<n1; j++) {
					printf("%d     ", matrix3[i][j]);
				}
				printf("\n");
			}
			break;
		case 2 :
			printf("Multiplicacion\n");
			if (n1 != m2) {
				printf("El tamaño de las matrices no concuerdan para esta operacion\n");
				return 0;
			}
			for (i=0; i<m1; i++) {
				for (j=0; j<n1; j++) {
					for (k=0; k<n2; k++) {
						matrix3[i][j] = matrix3[i][j] + matrix1[i][k] * matrix2[k][j];
					}
				}
			}
			//Impresion
			for (i=0; i<m1; i++) {
				for (j=0; j<n2; j++) {
					printf("%d     ", matrix3[i][j]);
				}
				printf("\n");
			}
			break;
		default :
			printf("Eleccion invalida.\n");
			break;
	}
	return 0;
}
