#include <stdio.h>

int main(void){
    int n, k, i=0, menor=2147483647;

    scanf("%d %d", &n, &k);

    int arr[k];

    for (i = 0; i < k; i++){
        arr[i] = 0;
    }

    for (i = 0; i < n; i++){
        int temp;

        scanf("%d", &temp);

        arr[temp-1]++;
    }

    for (i = 0; i < k; i++){
        if (arr[i] < menor){
            menor = arr[i];
        }
    }
    
    printf("%d\n", menor);
}