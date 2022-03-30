#include <omp.h>
#include <stdio.h>

int main() {
    int i;
    int N = 15;
    int X[N];

    for(i = 0; i < N; i++) {
        X[i] = 10;
    }
#pragma omp parallel firstprivate(N) private(i) num_threads(5)
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();

#pragma omp for
        for(i = 0; i < N; i++) {
            X[i] += nt;
            printf("rank=%d, i=%d\n", id, i);
        }
    }

    for(i = 0; i < N; i++) {
        printf("X[%d]=%d\n", i, X[i]);
    }

    return 0;
}

