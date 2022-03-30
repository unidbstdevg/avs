#include <omp.h>
#include <stdio.h>

#define N 30

int main() {
    int i = 0;
    int B[N];

    printf("Init B:\n");
    for(i = 0; i < N; i++) {
        B[i] = 1;
        printf("\tB[%d]=%d\n", i, B[i]);
    }
#pragma omp parallel  private(i) num_threads(3)
    {
        int id = omp_get_thread_num();

#pragma omp for
        for(i = 0; i < N; i++) {
            B[i] += i;
            printf("rank=%d, B[%d]=%d\n", id, i, B[i]);
        }
    }

    printf("Result B:\n");
    for(i = 0; i < N; i++) {
        printf("\tB[%d]=%d\n", i, B[i]);
    }

    return 0;
}

