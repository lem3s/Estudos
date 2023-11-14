#include <stdio.h>

int main(void){

	int n, i, j, k, l, temp, vagoes;
	scanf("%d", &n);

	int arr[1000];
	int res[n];

	for (i=0; i < n; i++){
		res[i] = 0;
	}


	for (i=0; i < n; i++){
		scanf("%d", &vagoes);

		for (j=0; j < vagoes; j++){
			scanf("%d", &arr[j]);
		}
		
		for (k=0; k < vagoes - 1; k++){
			for (l=0; l < vagoes - 1 - k; l++){
				if (arr[l] > arr[l+1]){
					temp = arr[l];
					arr[l] = arr[l+1];
					arr[l+1] = temp;
					res[i]++;
				}
			}
		}
	}
	
	for (i=0; i < n; i++){
		printf("%d\n", res[i]);
	}

	return 0;
}
