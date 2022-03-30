#include <omp.h>
#include <stdio.h>

int N = 3;

void print_table(int (*a)[N], const char* name);

int main() {
    int a=10, b=5, x, y, z;

#pragma omp parallel sections firstprivate (a,b)
    {
#pragma omp section
        {
            int id = omp_get_thread_num();
            x = a + b;
            printf("id=%d, x=%d\n", id, x);
        }
#pragma omp section
        {
            int id = omp_get_thread_num();
            y = a - b;
            printf("id=%d, y=%d\n", id, y);
        }
#pragma omp section
        {
            int id = omp_get_thread_num();
            z = a * b;
            printf("id=%d, z=%d\n", id, z);
        }
    }

    printf("master. x=%d, y=%d, z=%d\n", x, y, z);

    return 0;
}

