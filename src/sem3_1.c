#include <omp.h>
#include <stdio.h>

int main() {
    int N = 20;
    int a[N], b[N], c[N], i;

    for(i = 0; i < N; i++) {
        a[i] = i + 1;
        b[i] = i - 1;
    }
    for(i = 0; i < N; i++) {
        printf("a[%d]=%d, b[%d]=%d\n", i, a[i], i, b[i]);
    }
#pragma omp parallel firstprivate(a, b, N) private(i) num_threads(4)
    {
        int id = omp_get_thread_num();

#pragma omp for
        for(i = 0; i < N; i++) {
            c[i] = a[i] + b[i];
            printf("rank=%d, calc iter i=%d\n", id, i);
        }
    }

    for(i = 0; i < N; i++) {
        printf("c[%d]=%d\n", i, c[i]);
    }

    return 0;
}

