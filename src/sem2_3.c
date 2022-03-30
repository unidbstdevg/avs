#include <omp.h>
#include <stdio.h>

int main() {
    int a = 1;
    int b = 10;
    int c = 100;

#pragma omp parallel private(c) shared(b) firstprivate(a) num_threads(4)
    {
        int id = omp_get_thread_num();

        /* c равно 1 */
        /* b равно 10 */
        /* c равно 0 */
        printf("beg id=%d     a=%d, b=%d, c=%d\n", id, a, b, c);

        c = a + id;
        printf("id=%d     b=%d\n", id, b);
        b = b + 1;
        a = 22;

        printf("end id=%d     a=%d, b=%d, c=%d\n", id, a, b, c);
        /* c равно id + a, так как a = 1, то c = id + 1 */
        /* b равно сумме своего предыдущего значения с a,
         *      так как a = 1, то b += 1 */
        /* a равно 22 */
    }

    printf("res a=%d, b=%d, c=%d\n", a, b, c);

    /* a не меняется так как firstprivate */
    /* b равно 10 + количество нитей
     *      (при условии что не происходило "гонки" нитей) */
    /* c не меняется так как private */

    return 0;
}

