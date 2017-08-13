/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Interpolación Lagrange
 * Fecha: 31-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa utiliza el metodo de interpolacion de lagrange\npara un conjunto de puntos de x y y.\n");
	int n, i, j;
	double mult, divi, x, fx;
	printf("Ingrese la cantidad de puntos del conjunto al que se le aplicara el metodo.\n");
	scanf("%d", &n);
	printf("Ingrese la x a evaluar.\n");
	scanf("%lf", &x);
	double array_x[n];
	double array_y[n];
	double L[n];
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

	//Calculo de multiplicadores
	for (i = 0; i < n; i++) {
		mult = 1;
		divi = 1;
		for (j = 0; j < n; j++) {
			if (j != i) {
				mult = mult * (x - array_x[j]);
				divi = divi * (array_x[i] - array_x[j]);
			}
		}
		L[i] = mult/divi;
	}

	for (i = 0; i < n; i++) {
		fx += L[i]*array_y[i];
	}

	printf("Multiplicadores de Lagrange:\n");
	for (i = 0; i < n; i++) {
		printf("L%d(x): %.2lf\n",i, L[i]);
	}
	printf("f(%.2lf)= %.4lf", x, fx);

	return 0;
}
