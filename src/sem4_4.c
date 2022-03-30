#include <omp.h>
#include <stdio.h>

int main() {
    int a = 1;

#pragma omp parallel
    {
        int id = omp_get_thread_num();
#pragma omp single
        {
            a += 10;
            printf("id=%d, a=%d\n", id, a);
        }
    }
    printf("a=%d\n", a);

    return 0;
}

