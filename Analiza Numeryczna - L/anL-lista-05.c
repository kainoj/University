#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double g0(double x) { return x*x*x-8; }
double g1(double x) { return 3*x*x;}
double g2(double x) { return 6*x;}

double h0(double x) { return x*x - 4*x + 4; }
double h1(double x) { return 2*x - 4.0; }
double h2(double x) { return 2.0; }

double i0(double x) { return x*x*x*x -8.0*x;};
double i1(double x) { return 4*x*x*x -8.0;}
double i2(double x) { return 12*x*x; }

double j0(double x) { return x*x*x*x*x - 32; }
double j1(double x) { return 5*x*x*x*x; }
double j2(double x) { return 20*x*x*x; }

/*double k0(double x) { return 2 - 1.0/x; }
double k1(double x) { return 1.0/ (x*x); }
double k2(double x) { return -2.0/(x*x*x); }*/


double alfa = 2.0; //miejsce zerowe - dla kadej funkcji g,h,i,j


double olver(int n,double x, double (*f0)(double), double (*f1)(double), double (*f2)(double) ) {
	
	double e0, e1, e2;
	e0 = e1 = e2 = x;

	for( int i=0; i<n; i++) {
		printf("i = %d \t x = %.10f \n", i, x);
		x = x - f0(x) / f1(x) - 0.5 * ( f2(x) / f1(x) ) * (f0(x) *f0(x)/ (f1(x)*f1(x))  );
	
		e0 = e1;
		e1 = e2;
		e2 = x ;
		if( e2 -alfa < 0.0001 	 ) break;
	}
	// rzeczywistym miejscem zeroweym w każdym przypadku jest 2
	printf("%f %f %f %f\n", e0, e1, e2, x);
	double p = ( log(   fabs( (e1-alfa) / (e2-alfa )  )) / (log( fabs( (e0-alfa)/(e1-alfa) )))); // TODO
	printf("p = %.10f\n", p );


//	p = ( log(   fabs( (e2-alfa) / (e1-alfa )  )) / (log( fabs( (e1-alfa)/(e0-alfa) )))); // TODO
//	printf("p = %.10 f\n\n#########\n\n", p );

	printf("\n\n#####\n\n");
	return x;
}


int main() {

	int n = 15;
	double x = 100;
	// printf("%.10f\n\n",  olver(n, x, g0, g1, g2));

	// printf("%.10f\n\n",  olver(n, x, h0, h1, h2));
 
	// printf("%.10f\n\n",  olver(n, x, i0, i1, i2));


	olver(n, x, g0, g1, g2);
	olver(n, x, h0, h1, h2);
	olver(n, x, i0, i1, i2);
	olver(n, x, j0, j1, j2);

	return 0;
}


