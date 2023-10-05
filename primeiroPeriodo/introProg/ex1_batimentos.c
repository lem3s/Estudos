#include <stdio.h>

int main(){
	int idade;
	float batimentos;
	scanf("%d", &idade);
	batimentos = idade*(365.25*24*60*60);
	printf("O CORACAO BATEU %.2f VEZES\n", batimentos);


	return 0;
}
