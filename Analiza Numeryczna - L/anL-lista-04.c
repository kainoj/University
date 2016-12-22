#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double f(double x) {
	return x* pow(M_E, -x) - 0.06064;
}


double f2(double x) {
	return x*x - 4.0;
}

double f3(double x) {
	return pow(x, 3.0) + 8.0*sin(2.0*x-5.0);
}

double bisection(double a, double b, int n, double (*f)(double)) {
	double s;

	for(int i=0; i<n; i++) {
		s = a/2.0 + b/2.0;
		//printf("a = %f \t b = %f \t s = %f\n", a,b,s);
		if ( f(a)* f(s) <= 0 ) {
			b = s;
		}
		else {a=s;}
	}
	return a/2.0+b/2.0;
}

void ex3()  {
	printf("===== ex 3 =====\n");
	// ex 3
	// root of f: α = 0.0646926359947960
	double alpha = 0.0646926359947960;
	double res;
	for(int i=0; i<=30; i++) {
		res = bisection(0,1,i, f);
		printf("i = %d \t||  res = %.16f \t || e = %.16f\n", i, res, fabs(res - alpha));
	}	
}


void ex4() {
	printf("===== ex 4 =====\n");
	// compute roots of f3 with error <= 10^-5
	// based on hand drawn plot
	// 1st root is in (-1, 0) → iterate floor(log2(1/10^-5)) = 17 times
	// 2nd root is in (0,  1) → iterate 17 times
	// 3rd root is in (1,  2) → iterate 17 times

	// but iterating 20 times'd be also good :>
	printf("1st root:\t%.10f\n", bisection(-1,0,20,f3));
	printf("2nd root:\t%.10f\n", bisection(0, 1,20,f3));
	printf("3rd root:\t%.10f\n", bisection(1, 2,20,f3));	
}

void ex5() {
	printf("\n===== ex 5 =====\n");
	// Newton method - computing 1/R.
	//
	// Used function: f(x) = R - 1/x.
	// f(x) / f'(x) = x(xR-1)
	//
	double x = -0.1; //x0
	double R = -0.5;
	for(int i=0; i<40; i++) {
		x = x*(2-x*R);
		printf("x(%d) = %f \n",i, x );
	}

	printf("1/%f =  %.50f \n", R, x);
}

void ex6() {
	printf("\n===== ex 6 =====\n");
	// Computing 1/sqrt(a) using Newton Method
	// The function: f(x) = a - 1/x^2
	// Thus the formula is: x := 0.5 x(3-x^2*a)

	double x=0.58;
	double a=9;
	for(int i=0; i<20; i++) {
		x = 0.5*x*(3-x*x*a);
		printf("x(%d) = %f \n",i, x );
	}

	printf("1/sqrt(%f) =  %.50f \n", a, x);

}


void ex7() {
	double x = (0.70710678118+1)/2.0;
	double a = 0.5;

	
	for (int i=0; i<10; i++)  {
		printf("%d \t || %f\n", i, x);
		x = 0.5 *(x + a/x);

	}
	printf("sqrt(%f) = %.20f\n", a, x);
		
}


int main() {
	//ex3();
	//ex4();
	//ex5();
	//ex7();

	ex6();
	
	return 0;
}


