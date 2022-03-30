#include <omp.h>
#include <stdio.h>

int main() {
    int c = 0;
    int a = 1;
    int b = 2;

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        // teper eta sekciya tozhe vsegda bydet vipolnyatsya v id=0
#pragma omp master
        {
            a += 1;
            printf("id=%d, a=%d\n", id, a);
        }
#pragma omp master
        {
            b += 2;
            printf("id=%d, b=%d\n", id, b);
        }
#pragma omp critical
        {
            c += 1;
            printf("id=%d, c=%d\n", id, c);
        }
    }
    // a = a + 1
    printf("a=%d, b=%d, c=%d\n", a, b, c);

    return 0;
}

