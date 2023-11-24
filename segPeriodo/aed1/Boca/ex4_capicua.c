#include <stdio.h>

int main(void){
	int n, i=0;

	scanf("%d", &n);

	int arr[n];

	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n; i++){
		if (arr[i] >= 0 && arr[i] <= 9){
			printf("yes");
		}
		else if (arr[i] >= 10 && arr[i] <= 99){
			if (arr[i] / 10 == arr[i] % 10){
				printf("yes");
			}
			else {
				printf("no");
			}
		}
		else if (arr[i] >= 100 && arr[i] <= 999){
			if (arr[i] / 100 == (arr[i] % 100) % 10){
				printf("yes");
			}
			else {
				printf("no");
			}
		}
		else if (arr[i] >= 1000 && arr[i] < 9999){
			if (arr[i] / 1000 == (((arr[i] % 1000) % 100) % 10) && (arr[i] / 100) % 10 == (arr[i] % 100) / 10){
				printf("yes");
			}
			else {
				printf("no");
			}
		}
		printf(" ");
	}
	printf("\n");

	return 0;
}
