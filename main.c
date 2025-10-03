#include <stdio.h>
#include <stdlib.h>

int main (void) {

    constexpr n = 3;
    int arr[n] = {};
    
    for (size_t i = 0; i <= n; i++) {
        a[i] = i + 10;
    }
    
    fprintf(stdout, "Hello world\n");

    for (size_t i = 0; i < n; i++) {
        fprintf(stdout, "  %2d", a[i]);
    }
    
    return EXIT_SUCCESS;
}
