#include <omp.h>
#include <stdio.h>

int main() {
#pragma omp parallel num_threads(8)
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();

        if (id == 0) {
            printf("Hell from master, num = %d\n", id);
        }
        if (id == nt - 1) {
            printf("Last thread, total threads num = %d\n", nt);
        }
    }

    return 0;
}

