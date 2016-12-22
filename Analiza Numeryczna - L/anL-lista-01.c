#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
	x_0 = 1
	x_1 = 1/7
	x_(n+2) = -34/7 x_(n+1) + 5/7 x_n
*/

double ex1(int n) {
	double x_0 = 1.0;
	double x_1 = 1.0/7.0;
	double x_n = x_0;

	if( n == 0 ) return x_0;
	if( n == 1 ) return x_1;

	for (int i=2; i<=	n; i++) {
		x_n = (-34.0/7.0) * x_1 + (5.0 / 7.0) * x_0;
		x_0 = x_1;
		x_1 = x_n;
	}
	return x_n;
}


double ex5(double x) {
	const double a[8] = 
		{
			1,					// a0
			1.999999993788,		// a1
			1,
			0.399659100019,		// a3
			1,
			0.666669470507,		// a5
			1,
			0.300974506336		// a7
		};

	double res =0;
	for (int k=0; k<=3; k++) 
		res += a[2*k+1] * pow(  ((x - sqrt(2.0)/2.0) / (x + sqrt(2.0)/2.0)), 2.0*k+1.0);
	return -1.0/2.0 * log(2) + res;
}



float ex7(int n) {
	if (n == 0 )
		return log(6.0/5.0);
	return 1.0/n - 5.0 * ex7(n-1);
}


int main() {

	//for(int n=0; n<25; n++) 
	//	printf("x(%d) = %.50f\n", n, ex1(n)) ;

	double x = 0.75;
	printf("myln (%.25f) \t= %.25f\n ln (%.25f) \t= %.25f\n\n\n", x, ex5(x), x, log(x));

	for(int n=1; n<=20; n++)
		printf("I(%d) = %.25f\n", n, ex7(n));
	return 0;
}