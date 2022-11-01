#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// Find e using Taylor expansion
int factorial(int n);

int main(void){
  
  int i, order; 
  double e, *terms;

  // Enter polynomial order
  printf("Please enter the required polynomial order\n");

  if(scanf("%d", &order) != 1){
  
    printf("Did not enter a valid number\n");
    return(1);
  }

  // create a dynamic array to store the terms
  terms = malloc(order * sizeof(double));
  for (i = 0; i < order; i++){

    terms[i] = 1.0/(double)factorial(i+1);
    printf("\ne term for order %d is %1.14lf\n", order, terms[i]);

  }
  
  e = 1.0;

  for(i = 0; i < order; i++){
    e = e + terms[i];

  }

  free(terms); // free the memory space held for the array
  
  printf("\ne is estimated as %.10lf, with difference %10lf.\n", e, e-exp(1.0));

  return 0;
}

//function that returns the factorial of 
int factorial(int n){

  if (n < 0){
    printf("Error: enter positive integer only");
    return(-1);
  }
 
  else if (n == 0){
    return(1);
  }

  else {
    return(n * factorial(n-1));
  
  }


}
