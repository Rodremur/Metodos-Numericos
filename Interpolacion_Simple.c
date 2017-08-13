/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Interpolación Simple
 * Fecha: 31-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <math.h>

void print_matrix(int n1, double mat[n1][n1], double array[n1]) {
	int i, j;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {
			printf("%.2lf     ", mat[i][j]);
		}
		printf("|    %.2lf", array[i]);
		printf("\n");
	}
}

void gauss_method(int n1, double matrix1[n1][n1], double array1[n1], double results[n1]) {
	int i, j, k;
	double piv, suma, aux;
	for (k = 0; k < n1-1; k++) {
        for (i = k+1; i < n1; i++) {
            piv = (matrix1[i][k])/(matrix1[k][k]);
            for (j = k; j < n1; j++) {
                matrix1[i][j] = matrix1[i][j] - (piv*matrix1[k][j]);
            }
            array1[i] = array1[i] - (piv*array1[k]);
        }
	}

    results[n1-1] = array1[n1-1]/matrix1[n1-1][n1-1];

	for (i = n1-2; i >= 0; i--) {
        suma = array1[i];
        for (j = i+1; j < n1; j++) {
            suma = suma - (matrix1[i][j]*results[j]);
        }
        results[i] = suma/matrix1[i][i];
	}
}

int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa utiliza el metodo de interpolacion simple\npara un conjunto de puntos de x y y.\n");
	int n, i, j;
	double x, fx;
	printf("Ingrese la cantidad de puntos del conjunto al que se le aplicara el metodo.\n");
	scanf("%d", &n);
	printf("Ingrese la x a evaluar.\n");
	scanf("%lf", &x);
	double array_x[n];
	double array_y[n];
	double m1[n][n];
	double ab[n];
	double results[n];
	fx = 0;

	printf("Ingrese los puntos en x: \n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &array_x[i]);
	}
	printf("Ingrese los puntos en y: \n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &array_y[i]);
	}

	printf("x: [ ");
	for (i = 0; i < n; i++) {
		printf("%.2lf ", array_x[i]);
	}
	printf("]\n");

	printf("y: [ ");
	for (i = 0; i < n; i++) {
		printf("%.2lf ", array_y[i]);
	}
	printf("]\n");

	//Calculo de matriz
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			m1[i][j] = pow(array_x[j], i);
		}
		ab[i] = array_y[i];
	}

	printf("\nMatriz:\n");
	print_matrix(n, m1, ab);

	gauss_method(n, m1, ab, results);

	printf("\nMatriz Aumentada:\n");
	print_matrix(n, m1, ab);

	printf("\nSolucion de a\n");
	for (i = 0; i < n; i++) {
        printf("a%d: %.2lf   ", i, results[i]);
	}

	for (i = 0; i < n; i++) {
		fx += results[i]*pow(x, i);
	}
	printf("\nf(%.2lf)= %.4lf", x, fx);
	return 0;
}
