#include <stdio.h>

int main(void){
	unsigned long int maior, n1, n2, res;
	char operacao;

	scanf("%ld", &maior);

	scanf("%ld %c %ld", &n1, &operacao, &n2);

	if (operacao == '+'){
		res = n1 + n2;
	}
	else if (operacao == 'X'){
		res = n1 * n2;
	}

	if (res > maior){
		printf("overflow\n");
	}
	else {
		printf("no overflow\n");
	}

	return 0;
}
