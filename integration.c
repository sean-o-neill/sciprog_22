#include <stdio.h>
#include <math.h>

// declaring variables
float a, b, first_part, sum, integral_value;
int N;
float pi =  M_PI;

// declaring function to compute the integration via trapezoidal rule
float trapezoidal_integration(float start, float end, int N, float arr[N+1]);

int main(void) {
	a = 0;
	b = pi/3.;
	N = 12;
	float interval = (b-a)/N; // setting the space between each of the N+1 integration points
	float array[N+1]; // declaring an array of size N + 1 to store the area enclosed in each interval
	int i;
	for(i = 0; i < N+1; i++){ // for loop to calculate the values to be used by the integration function
		array[i] = tan(interval * i);		
	} 
	integral_value = trapezoidal_integration(a,b,N,array);
	printf("The computed integral is approximately equal to %lf \n", integral_value);
	printf("The analytical answer is %lf \n", logf(2));

	return 0;
}

// function that calculates the integral using trapezoidal rule
float trapezoidal_integration(float start, float end, int N, float arr[N+1] ){
	float sum = 0; 
	sum += arr[0] + arr[N]; // sum first and last elements in trapezoidal rule
	int i;
	for (i = 1; i < N; i++){
		sum += 2 * arr[i]; //sum all elements in trapezoidal rule with a coefficient of 2
	}
	
	return (end-start)*sum/(float) (2*N); // return the approximate value of the integral
}

