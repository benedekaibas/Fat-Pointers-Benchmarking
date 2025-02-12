#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#define N 20000
#define THREADS_NB omp_get_max_threads()

void init_arrays(double *a, double *b) {
  memset(a, 0, N * sizeof(a));
  memset(b, 0, N * sizeof(b));
  for (int i = 0; i < N; i++) {
    a[i] += 1.0;
    b[i] += 1.0;
  }
}

double func2(double i, double j) {
  double res = 0.0;

  while (i / j > 0.0) {
    res += i / j;
    i -= 0.1;
    j -= 0.000003;
  }
  return res;
}

double single_thread(double *a, double *b) {
  double res = 0;
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i == j) continue;
      res += func2(a[i], b[j]);
    }
  }
  return res;
}

double multi_threads(double *a, double *b) {
  double res = 0;
  int i, j;
  #pragma omp parallel for private(j) num_threads(THREADS_NB) reduction(+:res)
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (i == j) continue;
      res += func2(a[i], b[j]);
    }
  }
  return res;
}

int main(void) {
  double *a, *b;
  a = (double *)calloc(N, sizeof(double));
  b = (double *)calloc(N, sizeof(double));
  init_arrays(a, b);

  clock_t start_time = clock();
  double res = single_thread(a, b);
  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  printf("Default:  Done with %f in %f sd\n", res, elapsed_time);

  start_time = clock();
  res = multi_threads(a, b);
  elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  printf("With OMP: Done with %f in %f sd\n", res, elapsed_time / THREADS_NB);
}
