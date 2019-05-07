#include "../lib/Encoder.h"
#include <windows.h>
#include <gtest/gtest.h>

namespace {
	TEST(TestEncodeHamming, InpDataValidationExceptionTest)
	{
		std::vector<uint8_t> inp{0,1,2,3,4};
		EncodeHamming hamming_encode;

		ASSERT_THROW(hamming_encode.encode(inp), const char*);
	}

	TEST(TestEncodeHamming, InpDataZeroPaddingTest)
	{
		std::vector<uint8_t> inpData{1,1,0,0,1};
		std::vector<uint8_t> inpPaddedData{1,1,0,0,1,0,0,0};

		EncodeHamming hamming_encode;
		hamming_encode.encode(inpData);
		ASSERT_EQ(inpData, inpPaddedData);
	}

	TEST(TestEncodeHamming, EncodingTest)
	{
		std::vector<uint8_t> inp{1,0,1,0};
		std::vector<uint8_t> out{1,0,1,1,0,1,0};
		EncodeHamming hamming_encode;
		std::vector<uint8_t> encodedData = hamming_encode.encode(inp);
		ASSERT_EQ(encodedData, out);
	}

	TEST(TestEncodeHamming, EmptyInputTest)
	{
		std::vector<uint8_t> inp = {};

		EncodeHamming hamming_encode;
		std::vector<uint8_t> out = hamming_encode.encode(inp);

		ASSERT_TRUE(out.size() == 0);
	}
} // namespace

GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
