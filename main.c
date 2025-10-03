#include <stdio.h>
#include <stdlib.h>

#define N 3

int main (void) {

    int arr[N] = {};
    
    for (size_t i = 0; i <= N; i++) {
        arr[i] = i + 10;
    }
    
    fprintf(stdout, "Hello world\n");

    for (size_t i = 0; i < N; i++) {
        fprintf(stdout, "  %2d", arr[i]);
    }
    
    return EXIT_SUCCESS;
}
