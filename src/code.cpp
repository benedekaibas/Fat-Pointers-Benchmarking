#include <iostream>
using namespace std;

#define N 20000
#define THREADS_NB omp_get_max_threads()


// Microbenchmarking in c++

void int_arrays(doube *a, double *b){
    memset(a, 0, N * sizeof(a));
    memset(b, 0, N * sizeof(b));

    for (int i = 0; i < N; i++){
        a[i] += 1.0;
        b[i] += 1.0;
    }

}