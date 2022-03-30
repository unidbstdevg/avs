#include <omp.h>
#include <stdio.h>

int main() {
    int c = 0, d = 0;

    int a[10], b[5];
    int i = 0;
    for(i = 0; i < 10; i++) {
        a[i] = i;
        b[i/2] = i;

        printf("a[%d]=%d, b[%i]=%d\n", i, a[i], i/2, b[i/2]);
    }

#pragma omp parallel
    {
        int id = omp_get_thread_num();
#pragma omp sections
        {
            for(i = 0; i < 10; i++) {
                c += a[i];
            }
        }
#pragma omp sections
        {
            for(i = 0; i < 5; i++) {
                if(b[i] > d) {
                    d = b[i];
                }
            }
        }
    }
    printf("c=%d, d=%d\n", c, d);

    return 0;
}

