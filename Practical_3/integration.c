#include <stdio.h>
#include <math.h>

double a, b, first_part, sum, total, x, integral_value, the_log, difference;
int N, i;
double pi = 3.14159;

int main(void) {
	a = 0;	
	b = pi/(double) 3;
	// Add the first and last terms in the trapezoidal rule
	first_part = tan(0) + tan(pi/(double) 3);  

	N = 12; // the number of points from 0 to pi/3
 
	// Create the interval for integration
	double interval = (pi /(double) (3 * (N)));
	double x = interval;
	
	//for loop to calculate the rest of the values in the trapezoidal rule 
	sum = 0;
	for (i = 1;i <  N; i++) {
		sum += 2 * tan(x); 
		x += interval; 	     	
	};
	total = first_part + sum; // adding the first and last terms to the rest of the sum
	integral_value = ((b-a)/(double)(2*N))*total; // the approximation of the integral
	
	the_log = logf(2.); // computing ln(2) to compare the approximation to the analytical value

	difference = fabs(the_log - integral_value); // difference between actual and approximated integral value
	
	// printing out the calculated values and differences
	printf("The computed integral is approximately equal to %lf \n", integral_value);
	printf("The analytical answer is %lf \n",the_log);
	printf("The difference between the two is %lf \n", difference);

}

