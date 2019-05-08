#include <stdio.h>
#include <omp.h>
#include <cstdint>
#include <time.h>
#include <malloc.h>
#include <cinttypes>

int m = 10000, n = 10000;
#define THREAD_BENCHMARK

double wtime ( )
{
  double value;

  value = ( double ) clock ( )
        / ( double ) CLOCKS_PER_SEC;

  return value;
}
/*
* matrix_vector_product: Compute matrix-vector product c[m] = a[m][n] * b[n]
*/
void matrix_vector_product(double *a, double *b, double *c, int m, int n)
{
	for (int i = 0; i < m; i++)
    {
		c[i] = 0.0;
		for (int j = 0; j < n; j++)
		{
            c[i] += a[i * n + j] * b[j];
		}
	}
}void run_serial()
{
	double *a, *b, *c;
	a = (double*)malloc(sizeof(*a) * m * n);
	b = (double*)malloc(sizeof(*b) * n);
	c = (double*)malloc(sizeof(*c) * m);
	for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
            a[i * n + j] = i + j;
        }
	}
	for (int j = 0; j < n; j++)
    {
        b[j] = j;
    }
	double t = wtime();
	matrix_vector_product(a, b, c, m, n);
	t = wtime() - t;
	printf("Elapsed time (serial): %.6f sec.\n", t);
	free(a);
	free(b);
	free(c);
}

/* matrix_vector_product_omp: Compute matrix-vector product c[m] = a[m][n] * b[n] */
void matrix_vector_product_omp(double *a, double *b, double *c, int m, int n)
{
#pragma omp parallel
	{
	    #ifdef THREAD_BENCHMARK
	    double t = omp_get_wtime();
	    #endif
		int nthreads = omp_get_num_threads();
		int threadid = omp_get_thread_num();
		int items_per_thread = m / nthreads;
		int lb = threadid * items_per_thread;
		int ub = (threadid == nthreads - 1) ? (m - 1) : (lb + items_per_thread - 1);
		#pragma omp for
		for (int i = lb; i <= ub; i++)
        {
			c[i] = 0.0;
			for (int j = 0; j < n; j++)
            {
                c[i] += a[i * n + j] * b[j];
			}
		}
		#ifdef THREAD_BENCHMARK
		t = omp_get_wtime() - t;
		#pragma omp critical
        printf("Thread %d items %d [%d - %d], time: %.6f\n", threadid, ub - lb + 1, lb, ub, t);
        #endif
	}
}

void run_parallel()
{
	double *a, *b, *c;
	// Allocate memory for 2-d array a[m, n]
	a = (double*)malloc(sizeof(*a) * m * n);
	b = (double*)malloc(sizeof(*b) * n);
	c = (double*)malloc(sizeof(*c) * m);
	for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
            a[i * n + j] = i + j;
        }
	}
	for (int j = 0; j < n; j++)
    {
        b[j] = j;
    }
	double t = wtime();
	matrix_vector_product_omp(a, b, c, m, n);
	t = wtime() - t;
	printf("Elapsed time (parallel): %.6f sec.\n", t);
	free(a);
	free(b);
	free(c);
}

int main(int argc, char **argv)
{
	printf("Matrix-vector product (c[m] = a[m, n] * b[n]; m = %d, n = %d)\n", m, n);
	printf("Memory used: %" PRIu32 " MiB\n", ((m * n + m + n) * sizeof(double)) >> 20);
	run_serial();
	run_parallel();
	return 0;
}
