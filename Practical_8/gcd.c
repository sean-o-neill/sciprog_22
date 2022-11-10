
// Iterative and recursive versions of Euclid's algorithm.

#include <stdio.h>


int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);


int main(void){

  int a, b, ierror;

  printf("Please input two positive integers:\n");
  ierror = scanf("%d %d", &a, &b); // for error checking
  if (ierror != 2){
    printf("Please enter TWO integers!");
    return 1; //make sure user inputs two integers
  }
  
  //make sure the numbers are positive
  if (a <= 0 || b <= 0){ 
    printf("These numbers should be POSITIVE!");
  }
  
  //Call the functions
  printf("IterativeGCD(%d, %d) = %d\n\n", a, b, iterativeGCD(a, b));
  printf("RecursiveGCD(%d, %d) = %d\n", a, b, recursiveGCD(a, b));

  return 0;
}

// iterative algorithm
int iterativeGCD(int a, int b){
  int temp;
  while (b != 0){
    temp = b;
    b = a % b;
    a = temp;
  } 
  return a;
}

// recursive algorithm
int recursiveGCD(int a, int b){
  if (b == 0){
    return a;
  }
  else {
    return(recursiveGCD(b, a % b));
  }


}
