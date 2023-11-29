#include <stdio.h>

int reverso(int n, int r);

int main(void){

	int n;
	scanf("%d", &n);

	int invertido = reverso(n, 0);

	printf("%d\n", invertido);

	return 0;
}

int reverso(int n, int r){

	if (n == 0){
		return r;
	}

	int ultimoDigito = n % 10;
	r = r * 10 + ultimoDigito;

	n = n / 10;

	return reverso(n, r);
}
