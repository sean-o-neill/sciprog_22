int isMagicSquare(int **square, const int n){
  if (n < 0) return 0; //need n positive
  
  // declare variables needed 
  int magic_num = 0;
  int off_diag_sum = 0;
  int i, j;
  
  // find magic number and sum of off diagonal elements
  for (i = 0; i < n; i++){
    magic_num += square[i][i];
    off_diag_sum += square[i][n- i - 1];
  }

  //stop if the magic_num and off_diag_sum aren't equal
  if (off_diag_sum != magic_num) return 0;

  //find row and column sums
  for (i = 0; i < n; i++){
    int rowSum = 0;
    int colSum = 0;

    for (j = 0; j < n; j++){
      rowSum += square[i][j];
      colSum += square[j][i];
    }

    if (rowSum != magic_num || colSum != magic_num) return 0;
  }
  return 1; // return 1 only if the square is magic
}
