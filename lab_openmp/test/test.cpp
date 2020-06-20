#include "../openmp.h"
#include <windows.h>
#include <gtest/gtest.h>

namespace {
	TEST(TestMP, OpenMPZeroArrayTest)
	{
		unsigned int m = 0, n = 0;
		double tser = run_serial(m,n);
		double tpar = run_parallel(m,n);
		
		ASSERT_EQ(tser, tpar);
	}

	TEST(TestMP, OpenMPParallelSpeedUpTest)
	{
		unsigned int m = 10000, n = 10000;
		double tser = run_serial(m,n);
		double tpar = run_parallel(m,n);
		
		ASSERT_GE(tpar, tser);
	}
	
	TEST(TestMP, StdThreadZeroArrayTest)
	{
		const unsigned int nthreads = 4;
		const unsigned int len = 0;
		BenchmarkInfo_t infoSerial = run_serial_for(len);
		BenchmarkInfo_t infoParallel = run_parallel_for(nthreads, len);
			
		ASSERT_EQ(infoSerial.t, infoParallel.t);
	}

	TEST(TestMP, StdThreadParallelSpeedUpTest)
	{
		const unsigned int nthreads = 4;
		const unsigned int len = 100000;
		BenchmarkInfo_t infoSerial = run_serial_for(len);
		BenchmarkInfo_t infoParallel = run_parallel_for(nthreads, len);
			
		ASSERT_GE(infoParallel.t, infoSerial.t);
	}
	
	TEST(TestMP, StdThreadCorrectSumCountingTest)
	{
		const unsigned int nthreads = 4;
		const unsigned int len = 100000;
		BenchmarkInfo_t infoSerial = run_serial_for(len);
		BenchmarkInfo_t infoParallel = run_parallel_for(nthreads, len);
			
		ASSERT_EQ(infoParallel.x, infoSerial.x);
	}
	
} // namespace

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
