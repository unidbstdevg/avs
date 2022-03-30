#include <omp.h>
#include <stdio.h>

int main() {
    printf("Only master(no slaves) start\n");
#pragma omp parallel
    {
        printf("Paral block\n");
    }

    printf("Only master(still no slaves) continue\n");
    return 0;
}

