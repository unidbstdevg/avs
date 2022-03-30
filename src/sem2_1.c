#include <omp.h>
#include <stdio.h>

int main() {
    int a = 199;
    printf("in master before paral, a=%d\n", a);

/* #pragma omp parallel private(a) num_threads(4) */
/* #pragma omp parallel firstprivate(a) num_threads(4) */
/* для num_thread(1000) уже появляются баги */
#pragma omp parallel shared(a) num_threads(4)
    {
        int id = omp_get_thread_num();
        printf("beg id=%d paral block, a=%d\n", id, a);

        a += id;

        printf("end id=%d paral block, a=%d\n", id, a);
    }

    printf("in master after paral, a=%d\n", a);

    return 0;
}

