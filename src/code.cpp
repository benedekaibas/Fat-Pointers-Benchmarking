#include <iostream>
using namespace std;

#define N 20000
#define THREADS_NB omp_get_max_threads()


// Microbenchmarking in c++

void int_arrays(double *a, double *b){
    memset(a, 0, N * sizeof(a));
    memset(b, 0, N * sizeof(b));

    for (int i = 0; i < N; i++){
        a[i] += 1.0;
        b[i] += 1.0;
    }

}

double func2 (double i, double j){
    double res = 0.0;

    while (i / j > 0.0){
        res += i / j;
        i -= 0.1;
        j -= 0.000003;
    }
    return res;

}

