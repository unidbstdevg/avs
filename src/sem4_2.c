#include <omp.h>
#include <stdio.h>

int main() {
    int w = 0;

    {

#pragma omp parallel sections lastprivate (w)
        {
#pragma omp section
            {
                int id = omp_get_thread_num();
                printf("sect.1; id=%d\n", id);
                w = id + 1;
            }
#pragma omp section
            {
                int id = omp_get_thread_num();
                printf("sect.2; id=%d\n", id);
                w = id + 1;
            }
#pragma omp section
            {
                int id = omp_get_thread_num();
                printf("sect.3; id=%d\n", id);
                w = id + 1;
            }
        }
    }

    printf("master. w=%d\n", w);

    return 0;
}

