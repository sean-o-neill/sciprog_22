#include <stdio.h>
#include <math.h>

double arctanh1(const double x, const double delta);

double arctanh2(const double x);

int main(void){

  // get user to enter precision of MacLaurin series
  double delta, x;
  printf("Enter the precision for MacLaurin series\n");
  scanf("%lf", &delta);
  
  int length = 1000;
  double tan1[length]; // store the result of arctanh1 for each x
  double tan2[length]; // store the result of arctanh2 for each x
   
  int j = 0; //array index
  x= -0.9;
  while(x <= 0.9 && j < length){
    tan1[j] = arctanh1(x, delta);
    tan2[j] = arctanh2(x);
    printf("The difference at x = %lf between them is %.10f\n", x, fabs(tan1[j]-tan2[j]));
    j++;
    x = x + 0.1;

  }



  return 0;
}

// function to compute arctanh by MacLaurin series
double arctanh1(const double x, const double delta){

  double arctan = 0; //approximated result
  double elem, val;
  int n = 0; //sum parameter
  do {
    val = 2*n+1;
    elem = pow(x, val)/val;
    arctan += elem;
    n++;
  } while(fabs(elem) >= delta);

  return arctan;
}

// arctanh function to compare to
double arctanh2(const double x){
  return (log(1+x)-log(1-x))/2;
}
