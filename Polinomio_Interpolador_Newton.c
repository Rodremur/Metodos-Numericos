/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Polinomio Interpolador de Newton
 * Fecha: 18-04-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <math.h>

void print_matrix(int n1, int n2, double mat[n1][n2]) {
	int i, j;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n2; j++) {
			printf("%.4lf     ", mat[i][j]);
		}
		printf("\n");
	}
}

double horner(int n1, double a[n1], double x, double arrx[n1]) {
    int i;
    double res = 0;
    double array_s[n1];
    array_s[n1-1] = a[n1-1];
    for (i = n1-2; i >= 0; i--) {
    	array_s[i] = a[i] + array_s[i+1]*(x - arrx[i]);
    }
    return array_s[0];
}

int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa utiliza el metodo de polinomio interpolador de Newton\npara un conjunto de puntos de x.\n");
	int n, i, j, f;
	double x, fx;
	printf("Ingrese la cantidad de puntos del conjunto al que se le aplicara el metodo.\n");
	scanf("%d", &n);
	printf("Ingrese la x a evaluar.\n");
	scanf("%lf", &x);
	printf("Seleccione funcion a utilizar:\n1. f(x) = ln(x)\n2. Ingresar puntos de y manualmente\n");
	scanf("%d", &f);
	double array_x[n];
	double array_y[n];
	double m1[n][n+1];
	double array_a[n];
	double results[n];
	fx = 0;

	for (i = 0; i < n; i++) {
        for (j = 0; j < n+1; j++) {
            m1[i][j] = 0;
        }
	}

	printf("Ingrese los puntos en x: \n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &array_x[i]);
	}

	printf("x: [ ");
	for (i = 0; i < n; i++) {
		printf("%.2lf ", array_x[i]);
	}
	printf("]\n");

	//Calculo de y
	switch(f) {
		case 1:
			for (i = 0; i < n; i++) {
				array_y[i] = log(array_x[i]);
			}
        case 2:
            printf("Ingrese los puntos en y: \n");
            for (i = 0; i < n; i++) {
                scanf("%lf", &array_y[i]);
            }
	}

	printf("y: [ ");
	for (i = 0; i < n; i++) {
		printf("%.2lf ", array_y[i]);
	}

	//Entrada de primera y segunda columna de matriz
	for (i = 0; i < n; i++) {
		m1[i][0] = array_x[i];
		m1[i][1] = array_y[i];
	}

	//Calculo del triangulo inferior
	for (j = 2; j < n+1; j++) {
		for (i = j-1; i < n; i++) {
			m1[i][j] = (m1[i][j-1] - m1[i-1][j-1])/(m1[i][0]-m1[i-(j-1)][0]);
		}
	}

	//Definir arreglo de coeficientes a
	for (i = 0; i < n; i++) {
        array_a[i] = m1[i][i+1];
	}

	//Evaluacion
	fx = horner(n, array_a, x, array_x);

	printf("\nMatriz:\n");
	print_matrix(n, n+1, m1);

	printf("a: [ ");
	for (i = 0; i < n; i++) {
		printf("%.4lf ", array_a[i]);
	}
	printf("]\n");

    /*
	printf("\nSolucion de a\n");
	for (i = 0; i < n; i++) {
        printf("a%d: %.2lf   ", i, results[i]);
	}*/

	printf("\nPolinomio de Newton\n");
	printf("P%d(X)\n", n);
	for (i = 0; i < n; i++) {
            if (i == n-1) {
                printf("%lf", array_a[i]);
                for (j = 0; j < n; j++)
                    printf(")");
            } else {
                printf("(%lf + (x - %.2lf)*", array_a[i], array_x[i]);
            }
	}
	printf("\n");


	printf("\nf(%.2lf)= %lf", x, fx);
	return 0;
}
