#include <omp.h>
#include <stdio.h>

int main() {
    int N = 20;
    int a[N], b[N], c[N], i;
    int x = 0;

    for(i = 0; i < N; i++) {
        a[i] = i + 1;
        b[i] = i - 1;
    }
#pragma omp parallel firstprivate(a,b,N) private(i) num_threads(5)
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();

#pragma omp for lastprivate(x)
        for(i = 0; i < N; i++) {
            c[i] = a[i] + b[i];
            x = id + 1;
            printf("rank=%d, c[%d]=%d\n", id, i, c[i]);
        }
    }

    for(i = 0; i < N; i++) {
        printf("c[%d]=%d\n", i, c[i]);
    }
    printf("x=%d\n", x);

    return 0;
}

