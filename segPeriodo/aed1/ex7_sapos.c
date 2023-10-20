#include <stdio.h>

int main(void){
	int p, s, i;

	scanf("%d %d", &p, &s);

	int pedras[p];

	for(i=0; i<p; i++){
		pedras[i] = 0;
	}

	for(i=0; i < s; i++){
		int pedraini, pulo, pedraatual;
		scanf("%d %d", &pedraini, &pulo);
    pedraatual = pedraini;
    pedras[pedraini - 1] = 1;

    while (pedraatual + pulo <= p) {
      pedras[pedraatual + pulo - 1] = 1;
      pedraatual+= pulo;
    }
    
    pedraatual = pedraini;
    while (pedraatual - pulo > 0) {
      pedras[pedraatual - pulo - 1] = 1; 
      pedraatual-= pulo;
    }
	}

  for (i=0; i < p; i++){
    printf("%d\n", pedras[i]);
  }

	return 0;
}
