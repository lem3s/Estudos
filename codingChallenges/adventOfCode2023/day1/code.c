#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  if (argc != 2){
    printf("Usage: %s <filemane>\n", argv[0]);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "r");

  if (input_file == NULL){
    printf("The program couldn't find the file\n");

    return 2;
  }

  char aux[200];
  char strs[1000][200];

  int i = 0, j, k;

  while (!feof(input_file)){
    fscanf(input_file, "%s", strs[i++]);
  }
  int n = i - 1;

  int leftN = 0, rightN = 0, sum = 0;

  for (i = 0; i < n; i++){
    printf("%s\n", strs[i]);
    for (j = 0; j <= strlen(strs[i]); j++){
      if (strs[i][j] >= '0' && strs[i][j] <= '9'){
        leftN = strs[i][j] - '0';
        break;
      }
    }

    for (j = strlen(strs[i]); j >= 0; j--){
      if (strs[i][j] >= '0' && strs[i][j] <= '9'){
        rightN = strs[i][j] - '0';
        break;
      }
    }

    printf("%d %d\n", leftN, rightN);

    sum += leftN * 10 + rightN;
  }

  printf("Sum: %d\n", sum);

  return 0;
}
