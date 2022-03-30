#include <omp.h>
#include <stdio.h>

int N = 3;

void print_table(int (*a)[N], const char* name);

int main() {
    int i, j, k;
    int a[N][N];
    int b[N][N];
    int c[N][N];

    /* int c[N][N] = malloc(N * N * sizeof(int)); */

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++) {
            a[i][j] = i + 1;
            b[i][j] = j + 1;
            c[i][j] = 0;
        }
    print_table(a, "a");
    print_table(b, "b");

#pragma omp parallel firstprivate(a,b) private(i, j, k) num_threads(8)
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();

        printf("id = %d\n", id);
#pragma omp for
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                for(k = 0; k < N; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    print_table(c, "c");

    return 0;
}


void print_table(int (*a)[N], const char* name) {
    char buf[4096];
    char* target = buf;
    target += sprintf(target, "table %s\n", name);

    int i;
    int j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            target += sprintf(target, "%d ", a[i][j]);
        }
        target += sprintf(target, "\n");
    }

    target += sprintf(target, "\n");
    printf(buf);
}
