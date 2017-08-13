/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Método de Horner
 * Fecha: 25-01-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa esta basado en el metodo de Horner\ny evalua funciones polinomiales dado un valor de x.\n");
	int n, j, k;
	float p, x, err1, err2;
	p = 0;
	n = arrayDegree()+1;
	float coef[n];
	for (j = 0; j < n; j++) {
		printf("Ingrese el valor del coeficiente de la variable de grado %d:\n", j);
		scanf("%f", &coef[j]);
	}
	//Impresion de polinomio
	printf("El polinomio a evaluar es: ");
	for (k = 0; k < n; k++) {
            if (k != n-1) {
                printf("(%.2f)x^%d + ", coef[k], k);
            } else {
                printf("(%.2f)x^%d", coef[k], k);
            }
	}
	printf("\n");
	//
	printf("Ingrese el valor de x: \n");
	scanf("%f", &x);

	for (j = n-1; j >= 0; j = j-1) {
		p = coef[j] + x*p;
	}

	printf("El resultado de la ecuacion evaluada en x es: %.4f\n", p);
	err1 = fabs((p - truncf(p))/p);
	err2 = fabs((p - roundf(p))/p);
	printf("El valor truncado es %.4f\n", truncf(p));
	printf("El error relativo con truncamiento es: %f\n", err1);
	printf("El valor redondeado es %.4f\n", roundf(p));
	printf("El error relativo con redondeo es: %f\n", err2);
	return 0;
}

int arrayDegree() {
	int e;
	printf("Ingrese el grado de la ecuacion:\n");
	scanf("%d", &e);
	return e;
}
