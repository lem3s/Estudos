#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

    cliente_t *ptr = malloc(1000 * sizeof(cliente_t));

    printf("%p\n", ptr);
    
    return 0;
}