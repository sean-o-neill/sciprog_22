#include <stdio.h>
#include <math.h>

float a, b, first_part, sum, integral_value;
int N;
float pi =  M_PI;

float trapezoidal_integration(float start, float end, int N, float arr[N+1]);

int main(void) {
	a = 0;
	b = pi/3.;
	N = 12;
	float interval = (b-a)/N;
	float array[N+1];
	int i;
	for(i = 0; i < N+1; i++){
		array[i] = tan(interval * i);		
	}
	integral_value = trapezoidal_integration(a,b,N,array);
	printf("The computed integral is approximately equal to %lf \n", integral_value);
	printf("The analytical answer is %lf \n", logf(2));

	return 0;
}


float trapezoidal_integration(float start, float end, int N, float arr[N+1] ){
	float sum = 0;
	sum += arr[0] + arr[N];
	int i;
	for (i = 1; i < N; i++){
		sum += 2 * arr[i];
	}
	
	return (end-start)*sum/(float) (2*N);
}

