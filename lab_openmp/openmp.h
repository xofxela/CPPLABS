#ifndef OPEENMP_H_
#define OPEENMP_H_

#include <stdio.h>
#include <omp.h>
#include <cstdint>
#include <time.h>
#include <malloc.h>
#include <cinttypes>

//std::thread -std=c++11 standard support for MinGW
#include "libthread\mingw.thread.h"

// parallel_for.cpp
// compilation: g++ -O3 -std=c++0x parallel_for.cpp -o parallel_for -lpthread
// execution: time ./parallel_for 100 50000000
// (100: number of threads, 50000000: vector size)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <thread>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>

//Show items per thread split macro
//define THREAD_SPLIT

struct BenchmarkInfo_t
{
    double x, t;
};

double wtime (void);
void matrix_vector_product(double *a, double *b, double *c, int m, int n);
double run_serial(const int m, const int n);
void matrix_vector_product_omp(double *a, double *b, double *c, int m, int n);
double run_parallel(const int m, const int n);
BenchmarkInfo_t run_parallel_for(const unsigned int nthreads, const unsigned int len);
BenchmarkInfo_t run_serial_for(const unsigned int len);

#endif // OPEENMP_H_
