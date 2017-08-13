/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Método de Mínimos Cuadrados
 * Fecha: 27-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa utiliza el metodo de minimos cuadrados para obtener la linea de ajuste\npara un conjunto de puntos de x y y.\n");
	int n, i;
	printf("Ingrese la cantidad de puntos del conjunto al que se le aplicara el metodo.\n");
	scanf("%d", &n);
	double array_x[n];
	double array_y[n];
	double array_xy[n];
	double suma_x, suma_y, suma_x2, suma_xy, m, b, media_x, media_y;
	suma_x = 0;
	suma_y = 0;
	suma_x2 = 0;
	suma_xy = 0;

	printf("Ingrese los puntos en x: \n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &array_x[i]);
	}
	printf("Ingrese los puntos en y: \n");
	for (i = 0; i < n; i++) {
		scanf("%lf", &array_y[i]);
	}

	for (i = 0; i < n; i++) {
		array_xy[i] = array_x[i] * array_y[i];
	}

	for (i = 0; i < n; i++) {
		suma_x += array_x[i];
		suma_y += array_y[i];
		suma_xy += array_xy[i];
		suma_x2 += pow(array_x[i], 2);
	}

	media_x = suma_x/n;
	media_y = suma_y/n;

	m = (suma_xy - ((suma_x*suma_y)/n))/(suma_x2 - (pow(suma_x, 2)/n));
	b = media_y - (media_x*m);

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

	printf("x^2: [ ");
	for (i = 0; i < n; i++) {
		printf("%.2lf ", pow(array_x[i], 2));
	}
	printf("]\n");

	printf("xy: [ ");
	for (i = 0; i < n; i++) {
		printf("%.2lf ", array_xy[i]);
	}
	printf("]\n");

	printf("Sumatoria x: %.2lf\n", suma_x);
	printf("Sumatoria y: %.2lf\n", suma_y);
	printf("Sumatoria x^2: %.2lf\n", suma_x2);
	printf("Sumatoria xy: %.2lf\n", suma_xy);
	printf("media x: %.3lf\n", media_x);
	printf("media y: %.3lf\n", media_y);

	printf("m: %.5lf\n", m);
	printf("b: %.5lf\n", b);
	printf("Ecuacion resultante como linea de ajuste:\n");
	printf("f(x)= %.5lfx + %.5lf\n", m, b);

	return 0;
}
