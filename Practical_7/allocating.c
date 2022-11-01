#include <stdio.h>
#include <stdlib.h>

// function that allocates a dynamic array of ints using malloc
int *allocatearray(int n){

  int *p;
  p = (int *)  malloc(n * sizeof(int));
  return p;
}

// set every element of the array equal to one
void fillwithones(int *array, int n){

  int i;
  for (i = 0; i < n; i++){
    array[i] = 1; 

  }

}

// print the array to the screen
void printarray(int *array, int n){

  int i;
  for (i = 0; i < n; i++){
    printf("a[%d] = %d\n", i, array[i]);
  }

}


int main(void){

  int length, *a;

  // user input for the size of the array
  printf("Enter the size of the array:\n");
  scanf("%d", &length); 
 
  a = allocatearray(length);
  fillwithones(a, length);
  printarray(a, length); 

  return 0;
}
