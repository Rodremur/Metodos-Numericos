/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Bisección
 * Fecha: 25-01-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int i, n, j, k, cota;
	float p1, p2, x1, x2, err1, err2, tol, eval;
	p1 = 0;
	p2 = 0;
	err1 = 100;
	n = arrayDegree()+1;
	float coef[n];
	for (j = 0; j < n; j++) {
		printf("Ingrese el valor del coeficiente de la variable de grado %d:\n", j);
		scanf("%f", &coef[j]);
	}
	//Impresion de polinomio
	printf("La ecuacion es: ");
	for (k = 0; k < n; k++) {
            if (k != n-1) {
                printf("(%.2f)x^%d + ", coef[k], k);
            } else {
                printf("(%.2f)x^%d", coef[k], k);
            }
	}
	printf("\n");
	//
	printf("Ingrese el valor del inicio del intervalo: \n");
	scanf("%f", &x1);
	printf("Ingrese el valor del final del intervalo: \n");
	scanf("%f", &x2);
	printf("Ingrese la tolerancia de error: \n");
	scanf("%f", &tol);
	printf("Ingrese la cota maxima de iteraciones: \n");
	scanf("%f", &cota);

	for (j = n-1; j >= 0; j = j-1) {
		p1 = coef[j] + x1*p1;
	}

	for (j = n-1; j >= 0; j = j-1) {
		p2 = coef[j] + x2*p2;
	}

	if (p1 == 0) {
		printf("El valor de la raiz es: %.4f\n", x1);
		return 0;
	}
	if (p2 == 0) {
		printf("El valor de la raiz es: %.4f\n", x2);
		return 0;
	}

	if (p1 * p2 > 0) {
		printf("No hay cambio de signo en el intervalo por lo que no se puede encontrar una raiz\n");
		return 0;
	}
	printf("El resultado de la ecuacion evaluada en %.4f es: %.4f\n", x1, p1);
	printf("El resultado de la ecuacion evaluada en %.4f es: %.4f\n", x2, p2);

	//inician iteraciones
	float mid[50];
	i = 1;
	mid[i] = (x1 + x2)/2;
	eval = 0;
	for (j = n-1; j >= 0; j = j-1) {
		eval = coef[j] + mid[i]*eval;
	}
	if (eval == 0) {
		printf("El valor de la raiz es: %.4f\n", mid[i]);
		return 0;
	}
	while (err1 > tol) {
		if (i > cota) {
			printf("Se ha llegado a la cota máxima de iteraciones sin poder encontrar la raiz.\n");
			printf("El valor mas cercano es: %.4f con un error de %.4f\n", mid[i], err1);
			return 0;
		}
		if (eval * p1 < 0) {
			if (mid[i] < x1) {
				x2 = x1;
				x1 = mid[i];
			}
			else
			{
				x2 = mid[i];
			}
		}
		if (eval * p2 < 0) {
			if (mid[i] < x2) {
				x1 = x2;
				x1 = mid[i];
			}
			else
			{
				x1 = mid[i];
			}
		}

		i = i+1;
		p1 = 0;
		p2 = 0;

        for (j = n-1; j >= 0; j = j-1) {
            p1 = coef[j] + x1*p1;
        }

        for (j = n-1; j >= 0; j = j-1) {
            p2 = coef[j] + x2*p2;
        }

		mid[i] = (x1 + x2)/2;
		eval = 0;
		for (j = n-1; j >= 0; j = j-1) {
            eval = coef[j] + mid[i]*eval;
        }
		if (eval == 0) {
			printf("El valor de la raiz es: %.4f\n", mid[i]);
			return 0;
		}

		err1 = fabs((mid[i] - mid[i-1])/mid[i]);
	}

	printf("La raiz de la ecuacion es: %.4f con un error de %.4f", mid[i], err1);
	return 0;
}

int arrayDegree() {
	int e;
	printf("Ingrese el grado de la ecuacion:\n");
	scanf("%d", &e);
	return e;
}
