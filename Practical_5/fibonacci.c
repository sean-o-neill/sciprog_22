#include <stdio.h>

int N;
void fibonacci(int *x, int *y);
int x = 0, y = 1;



int main(void){
  // get user to enter how many Fibonacci numbers they wish to see
  printf("Enter the number of Fibonacci sequence numbers you require:  ");
  scanf("%d", &N);
  int i;
  printf("%d, %d, ", x, y);
  // loop to calculate the sequence
  for (i = 0; i < N-2; i++){
  
  fibonacci(&x, &y); 
  
  }


  return 0;
}

// function that is passed into by reference to update the fibonacci number
void fibonacci(int *x, int *y){
  int z = *y + *x;
  *x = *y;
  *y = z;
  printf("%d, ", *y); 
}
