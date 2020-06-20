#include "openmp.h"

double wtime (void)
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
}double run_serial(const int m, const int n)
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
	free(a);
	free(b);
	free(c);

	return t;
}

/* matrix_vector_product_omp: Compute matrix-vector product c[m] = a[m][n] * b[n] */
void matrix_vector_product_omp(double *a, double *b, double *c, int m, int n)
{
#pragma omp parallel
	{
	    #ifdef THREAD_SPLIT
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
		#ifdef THREAD_SPLIT
		t = omp_get_wtime() - t;
		#pragma omp critical
        printf("Thread %d items %d [%d - %d], time: %.6f\n", threadid, ub - lb + 1, lb, ub, t);
        #endif
	}
}

double run_parallel(const int m, const int n)
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
	free(a);
	free(b);
	free(c);

	return t;
}

// Function to apply
template<typename Type>
void f(Type& x)
{
    x = std::sin(x)+std::exp(std::cos(x))/std::exp(std::sin(x));
}

// Parallel for
template<typename Iterator, class Function>
void parallel_for(const Iterator& first, const Iterator& last, Function&& f, const int nthreads = 1)
{
    const unsigned int group = ((last-first)/std::abs(nthreads));
    std::vector<std::thread> threads;
    threads.reserve(nthreads);
    Iterator it = first;
    for (; it < last-group; it += group)
    {
        threads.push_back(std::thread([=,&f](){std::for_each(it, std::min(it+group, last), f);}));
    }
    std::for_each(it, last, f); // last steps while we wait for other threads

    std::for_each(threads.begin(), threads.end(), [](std::thread& x){x.join();});
}

BenchmarkInfo_t run_parallel_for(const unsigned int nthreads, const unsigned int len)
{
    double x = 0;
    std::vector<double> v(len);
    std::iota(v.begin(), v.end(), 0);

    double t = wtime();
    parallel_for(v.begin(), v.end(), f<double>, nthreads);
	for (unsigned int i = 0; i < len; ++i) x += v[i];
	t = wtime() - t;
	BenchmarkInfo_t out = {x, t};
    return out;
}

BenchmarkInfo_t run_serial_for(const unsigned int len)
{
    double x = 0;
    std::vector<double> v(len);
    std::iota(v.begin(), v.end(), 0);

    double t = wtime();
    std::for_each(v.begin(), v.end(), f<double>);
	for (unsigned int i = 0; i < len; ++i) x += v[i];
	t = wtime() - t;
    BenchmarkInfo_t out = {x, t};
    return out;
}
