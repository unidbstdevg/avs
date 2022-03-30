#include <omp.h>
#include <stdio.h>

int main() {
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();

        printf("hell from thread %d\n", id);
        if (id == 0) {
            printf("Num of threads: %d\n", nt);
        }
    }

    return 0;
}

