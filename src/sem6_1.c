#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define n 10000000

int main() {
    double *x;
    x = (double*)malloc(n*sizeof(double));
    int i;

    double c = 0, xx;
    double time1 = omp_get_wtime();
#pragma omp parallel for reduction(+ : c) private (i) num_threads(10)
    for(i = 0; i < n; i++)
    {
        x[i] = 1.0 + i;
        xx = x[i] * x[i];
        c += 1.0/xx + 1.0/(xx * xx);
    }
    double time2 = omp_get_wtime();
    printf("sum=%f, time=%f\n", c, time2-time1);

    return 0;
}

