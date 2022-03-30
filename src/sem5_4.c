#include <omp.h>
#include <stdio.h>

int main() {
    int a = 1;

#pragma omp parallel reduction(*:a)
    {
        int id = omp_get_thread_num();
        printf("id=%d, a=%d\n", id, a);
        a += id;
    }
    // a = symma 4lenov arifm progressii ot 1 do num_threads s shagom 1
    printf("a=%d\n", a);

    return 0;
}

