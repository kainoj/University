#include <stdio.h>


double data[][2] = {
	// X     Y
	{0,    68.0},
	{10.0, 67.1},
	{20.0, 66.4},
	{30.0, 65.6},
	{40.0, 64.6},
	{80.0, 61.8},
	{90.0, 61.0},
	{95.0, 60.0}
};

const int N=8;

int main() {
	
	double s1, s2, s3, s4, a, b;	
	s1 = s2 = s3 = s4 = 0;

	for(int i=0; i<N; i++) {
		s1 = s1 + data[i][0];
		s2 = s2 + data[i][0]*data[i][0];
		s3 = s3 + data[i][1];
		s4 = s4 + data[i][0]*data[i][1];;
	}

	printf("s1 = %f\n", s1);
	printf("s2 = %f\n", s2);
	printf("s3 = %f\n", s3);
	printf("s4 = %f\n", s4);

	a = (N*s4  - s1*s3) / (N*s2 - s1*s1);
	b = (s2*s3 - s1*s4) / (N*s2 - s1*s1);

	printf("a = %.10f\nb = %.10f\n", a, b);



	return 0;
}