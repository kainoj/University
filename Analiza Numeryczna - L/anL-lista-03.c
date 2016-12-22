#include <stdlib.h>
#include <stdio.h>
#include <math.h>



// roots - in a smart way
void ex2(float a, float b, float c) {
	float x1, x2;
	float t1 = b*b;
	float t2 = 4.0*a*c;

	if( t1 < t2 ) {
		printf("No solution exists\n");
		return;
	}

	if( t1 == t2 ) {
		printf("One solution: %f\n", -b/(2.0*a));
		return;
	}

	if(b<0) {
		x1 = b - sqrt(t1-t2);
	}
	else {
		x1 = b + sqrt(t1-t2);
	}
	x1 = -x1/(2.0*a);
	x2 = c / (a*x1);
	printf("Two solutions: \n\t%.25f\n\t%.25f\n\n", x1, x2 );

}

// roots - in a dumb way
void ex2b(float a, float b, float c) {
	b= -b;
	float delta = sqrt(b*b- 4.0*a*c);
	printf("Dumb way:\n\t%.25f\n\t%.25f\n", (b+delta)/(2.0*a), (b-delta)/(2.0*a));

}

// Solving:
// xxx + 3qx - 2r = 0
// q,r > 0
// Cardano - Tatraglii formula

double ex3(double q, double r) {
	float sq = sqrt(q*q*q + r*r);
	float a = r, b = r;

	a = a + sq;
	b = b - sq;

	printf("a = %.25f \n", a);
	printf("b = %.25f \n", b);
	a = pow(a, 1.0/3.0);
	b = pow(b, 1.0/3.0);


printf("a = %f \n", a);
	printf("b = %f \n", b);


	return a+b;
}






int main() {

	float a = 0.001;
	float b = -10000.0;
	float c = 0.001;

	ex2(a, b, c);
	ex2b(a, b, c);

	double q = 100000;
	double r = 1;

	//printf("%f", pow(-8, 1.0/3.0));
	printf("\nSolution: %.25f\n", ex3(q, r));
	return 0;
}