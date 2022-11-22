#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"
#define MAX_FILE_NAME 100

// find number of lines in the file
int get_num_lines(char filename[MAX_FILE_NAME]){
  FILE *fp;
  fp = fopen(filename, "r");
  int ch_read;
  int count = 0;
  while ((ch_read = fgetc(fp)) != EOF){
    if (ch_read == '\n') count++;
  }
  
  printf("Number of lines is: %d\n", count);
  fclose(fp);
  return count;

}

//main function
int main(void){
  FILE *f; 
  char filename[MAX_FILE_NAME];
  printf("Enter file name: ");
  scanf("%s", filename);

  // Get number of lines
  int n = get_num_lines(filename);
  f = fopen(filename, "r");
  
  // **magicsquare is an array of pointers which point to different arrays, 
  // which collectively form a 2D array.
  int i; 
  int **magicsquare = malloc(n * sizeof(int *));

  for (i = 0; i < n; i++){
    magicsquare[i] = malloc(n * sizeof(int));

  }

  // fill magicsquare arrays with the values from the input file
  int j;
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      fscanf(f, "%d", &magicsquare[i][j]);
 
    }
 
  }
  // check is the 2D array is magic
  int flag = isMagicSquare(magicsquare, n);
  if (flag == 1){
    printf("This square is magic!\n");
  }
  else printf("This square is not magic!\n");
  
  //free memory and close file
  for (i = 0; i < n; i++){
    free(magicsquare[i]);
  }
  free(magicsquare);
  fclose(f);
  return 0;
}


