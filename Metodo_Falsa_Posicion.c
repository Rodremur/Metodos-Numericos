/*-------------------------------------------------------
 * Tarea de Métodos Númericos: Método de la Falsa Posición
 * Fecha: 08-02-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <math.h>
#include <tgmath.h>
int main(int argc, char const *argv[])
{
	printf("Rodrigo Reyes Murillo\nEste programa esta basado en el metodo de la falsa posicion\ny encuentra la raiz de una ecuacion.\n");
	double e, p0, p1, p2, eval, eval2, eval3, error;
	int i, j, k, n, n2, iter;
	error = 100;
	iter = 0;

	printf("Ingrese que funcion desea resolver:\n1. x^4 - 64 = 0\n2. f(x) = cosx - x\n");
	scanf("%d", &k);
	printf("Ingrese p0: \n");
	scanf("%lf", &p0);
	printf("Ingrese p1: \n");
	scanf("%lf", &p1);
	printf("Ingrese el error minimo: \n");
	scanf("%lf", &e);

	switch(k) {
		case 1 :
			printf("\nx^4 - 64 = 0\n\n");
			while (error >= e) {
				//Evaluacion
				eval = powf(p0, 4) - 64;
				printf("p0 = %lf\n", p0);
				printf("f(p0) = %lf\n\n", eval);
				eval2 = powf(p1, 4) - 64;
				printf("p1 = %lf\n", p1);
				printf("f(p1) = %lf\n\n", eval2);
				if (eval * eval2 > 0) {
                    printf("La raiz no se encuentra en el intervalo.\n");
                    return 0;
				}
				//Calculo del siguiente punto
				p2 = p1-((eval2*(p1-p0))/(eval2 - eval));
				eval3 = powf(p2, 4) - 64;
				//Asignacion del nuevo intervalo
				if ((eval * eval3) < 0) {
					if (p2 < p1) {
						p1 = p2;
					} else {
						p1 = p0;
						p0 = p2;
					}
				} else if ((eval2 * eval3) < 0) {
					if (p2 < p0) {
						p0 = p2;
					} else {
                        p0 = p1;
                        p1 = p2;
					}
				} else {
                    p0=p1;
                    p1=p2;
				}
				//Calculo del error
				if (p1 == p2) {
					error = fabs((p1 - p0)/p1);
				}
				if (p0 == p2) {
					error = fabs((p0 - p1)/p0);
				}
				iter += 1;
			}
			printf("La raiz de la ecuacion es: %lf con un error de %lf y %d iteraciones.\n", p1, error, iter);
			break;
		case 2 :
			p0 = (p0 * 3.14159265) / 180.0;
			p1 = (p1 * 3.14159265) / 180.0;
			printf("\nf(x) = cosx - x\n\n");
		    while (error >= e) {
		    	//Evaluacion
				eval = cos(p0) - p0;
				printf("p0 = %lf\n", p0);
				printf("f(p0) = %lf\n\n", eval);
				eval2 = cos(p1) - p1;
				printf("p1 = %lf\n", p1);
				printf("f(p1) = %lf\n\n", eval2);
				if (eval * eval2 > 0) {
                    printf("La raiz no se encuentra en el intervalo.\n");
                    return 0;
				}
				//Calculo del siguiente punto
				p2 = p1-((eval2*(p1-p0))/(eval2 - eval));
				eval3 = cos(p2) - p2;
				//Asignacion del nuevo intervalo
				if ((eval * eval3) < 0) {
					if (p0 < p2) {
						p1 = p2;
					} else {
						p1 = p0;
						p0 = p2;
					}
				} else if ((eval2 * eval3) < 0) {
					if (p1 < p2) {
					    p0 = p1;
						p1 = p2;
					} else {
                        p0 = p2;
					}
				} else {
                    p0=p1;
                    p1=p2;
				}
				//Calculo del error
				if (p1 == p2) {
					error = fabs((p1 - p0)/p1);
				}
				if (p0 == p2) {
					error = fabs((p0 - p1)/p0);
				}
				iter += 1;
		    }
		    printf("La raiz de la ecuacion es: %lf con un error de %lf y %d iteraciones.\n", p1, error, iter);
			break;
		default :
			printf("Eleccion invalida.\n");
			break;
	}
	return 0;
}
