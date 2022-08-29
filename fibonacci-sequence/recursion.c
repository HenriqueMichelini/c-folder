#include <stdio.h>
#include <time.h>

int a = 1, b = 0, result = 0, index = 0;

void fibonacci(int iterations) {
    if (index < iterations)
    {
        result = a + b;
        b = a;
        a = result;
        printf("%d, ", result);
        index++;
        fibonacci(iterations);
    }
}

int main(void) {
    clock_t start_t, end_t;
    double total_t;

    int iterations;

    printf("Type a number: ");
    scanf("%d", &iterations);

    start_t = clock();

    if(iterations >= 3) {
        fibonacci(iterations);
    }
    else {
        printf("The number must be greater than or equal to 3");
    }

    end_t = clock();

    total_t = (double) (end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nCPU cost time: %.2f", total_t);
}