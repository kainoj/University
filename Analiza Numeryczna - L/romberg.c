#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double x) {
	return x*x;
}

double fun2(double x) {
	return 2017*x*x*x*x*x*x - 2016*x*x*x*x*x + 2015*x*x -2014;
}



double mypow(int x, int a) {
	int res = 1;
	for(int i=0; i<a; i++)
		res*=x;
	return res;
}

double T_0k(int k, double (*f)(double), double a, double b) {
	k = mypow(2, k);
	double sum = 0;
	double hk = (b-a)/(k*1.0);
	sum += 0.5*f(a);
	for(int i=1; i<k-1; i++)
		sum += f(a + i*hk);
	sum += 0.5*f(b);

	return hk*sum;
}


double romberg(double a, double b,  double (*f)(double), int m) {

	double **T= malloc( (m+1) * sizeof(double));
	for(int i=0; i<=m; i++)
		T[i] = malloc((m+1)*sizeof(double));

	for(int i=0; i<=m; i++)
		for(int j=0; j<=m; j++)
			T[i][j] = 0;

	
	for(int j=0; j<=m; j++) {
		T[0][j] = T_0k(j, f, a, b);
		printf("%f\n", T[0][j]);
	}	

	double four = 4.0;
	for(int i=1; i<=m; i++) {
		for(int j=i; j<=m; j++) {
			T[i][j] =  (four* T[i-1][j] - T[i-1][j-1]) / ( four-1); 
			printf("%.10f\n", T[i][j]);
		}
		printf("#########33\n");


		four*=4.0;

	}


	return 2.0;

}



int main() {
	printf("%.10f\n", romberg(0.0, 1.0, fun, 15));

	printf("%.10f\n", romberg(-2.0, 3.0, fun2, 15));

	return 0;
}




/*


double romberg(double a, double b,  double (*f)(double), int m) {
	double **T= malloc( (m+1) * sizeof(double));
	for(int i=0; i<=m; i++)
		T[i] = malloc((m+1)*sizeof(double));

	T[0][0] = 0.5 * ( f(a) + f(b) );	// T_1

	double n = 1.0, hn;
	for(int i=1; i<=m; i++) {		// filling the rest of 1st col
		T[i][0] = 0;
		hn = (b-a)/n;
		for(int j=1; j<n; j++) {	// M_n(f)
			T[i][0] += f(a + 0.5*(2*j-1)*hn);
		}
		T[i][0]*=hn;
		T[i][0]+=T[i-1][0];
		T[i][0]*=0.5;
		n *= 2.0;
		printf("%f\n", T[i][0]);
	}

	printf("=========================\n\n");
	double four = 4.0;

		for( int i=1; i<=m; i++) {

		for(int j=m; j>=i ; j--) {
			T[j] = ( four*T[j] -  T[j-1] ) / (four-1);
		}	
		four *= 4.0;


		for(int j=0; j<15; j++)
			printf("%.5f\t", T[j]);
		printf("\n");

	}
	printf("=============================\n" );

	return T[0][m];
}*/
