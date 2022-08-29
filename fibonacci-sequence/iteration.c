#include <stdio.h>
#include <time.h>

int main(void) {
    clock_t start_t, end_t;
    double total_t;

    int iterations = 0, a = 1, b = 0, result = 0;
    
    printf("Type a number: ");
    scanf("%d", &iterations);

    start_t = clock();

    if(iterations >= 3) {
        for(int i = 1; i < iterations; i++) {
            result = a + b;
            b = a;
            a = result;
            printf("%d, ", result);
        }
        end_t = clock();
    }
    else {
        printf("The number must be greater than or equal to 3");
    }

    total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nCPU cost time: %.2f", total_t);
}