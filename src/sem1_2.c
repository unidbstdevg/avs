#include <omp.h>
#include <stdio.h>

int main() {
    omp_set_num_threads(2);
#pragma omp parallel
    {
        printf("Paral 1\n");
    }

#pragma omp parallel num_threads(4)
    {
        printf("Paral 2\n");
    }

    return 0;
}

