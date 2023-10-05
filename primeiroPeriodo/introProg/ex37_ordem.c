#include <stdio.h>

int main(){

  int n1, n2, n3, a, b, c;
  char ordem[3] = "";

  scanf("%d %d %d\n", &n1, &n2, &n3);
  scanf("%c %c %c", &ordem[0], &ordem[1], &ordem[2]);

  //printf("ordem[0] = %c\n", ordem[0]);
  //printf("ordem[1] = %c\n", ordem[1]);
  //printf("ordem[2] = %c\n", ordem[2]);

  if (n1 < n2 && n1 < n3){
    a = n1;
    if (n2 < n3){
      b = n2;
      c = n3;
    }else if (n3 < n2){
      b = n3;
      c = n2;
    }else{
      b = n2;
      c = n3;
    }

  } else if (n2 < n1 && n2 < n3){
    a = n2;
    if (n1 < n3){
      b = n1;
      c = n3;
    }else if (n3 < n1){
      b = n3;
      c = n1;
    }else{
      b = n1;
      c = n3;
    }
  }
  
  else if (n3 < n1 && n3 < n2){
    a = n3;
    if (n1 < n2){
      b = n1;
      c = n2;
    }else if (n2 < n1){
      b = n2;
      c = n1;
    }else{
      b = n1;
      c = n2;
    }
  }

  //printf("%d < %d < %d\n", a, b, c);

  switch(ordem[0]){
    case ('A'):
      printf("%d ", a);
      break;
    case ('B'):
      printf("%d ", b);
      break;
    case ('C'):
      printf("%d ", c);
      break;
  }
  switch(ordem[1]){
    case ('A'):
      printf("%d ", a);
      break;
    case ('B'):
      printf("%d ", b);
      break;
    case ('C'):
      printf("%d ", c);
      break;
  }
  switch(ordem[2]){
    case ('A'):
      printf("%d\n", a);
      break;
    case ('B'):
      printf("%d\n", b);
      break;
    case ('C'):
      printf("%d\n", c);
      break;
  }

  return 0;
}
