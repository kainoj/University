#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

double WX[] = {0,3.5, 25, 25, -5, -5, 15, -0.5, 19.5, 7, 1.5};
double WY[] = {0, 36, 25, 1.5, 3, 33, 11,   35, 15.5, 0, 10.5};

double wagi[] = {1, 6, 4, 2, 3, 4, 2, 1, 5, 4, 1};

//double wagi[] = {1,6,4,-2,3,4,2,1,5,4,1};
const int n=11;

int factorial(int n) {
	int s=1;
	for(int i=1;i<=n;i++)
		s*=i;
	return s;
}

int newtonSymbol(int n, int k) {
	int s=1;
	for(int i=n; i>= (n-k+1); i--)
		s*=i;
	return s/factorial(k);
}


double bernstein(int n, int k, double t) {
	return 1.0*newtonSymbol(n,k) * pow(t,1.0*k) * pow(1.0-t, 1.0*(n-k));
}

int main() {

	double x;
	double y;
	int M = 10000;
	double tmp;

	/*for(int i=0; i<=M; i++) {
		double t=(1.0*i)/(1.0*M);
		printf("%f\t%f\n", t, bernstein(5,0, t));
	}*/
	for(int j=0; j<=M; j++) {
		x=y=0;
		double mianownik=0;
		
		for(int i=0; i<n; i++) {
			//printf("%f \t%f\n", WX[i], WY[i]);
			tmp = wagi[i]*bernstein(n,i, (1.0*j)/(1.0*M));
		 	//printf("tmp= %f\n", tmp );
			x+= WX[i]*tmp;
			y+= WY[i]*tmp;
			mianownik+=tmp;
			//printf("mianownik: %f\n",mianownik);
		}
		x /= mianownik;
		y /= mianownik;

		//printf("####################mianownik: %f\n",mianownik);
		printf("%f\t%f\n", x,y );
	}

	return 0;
}