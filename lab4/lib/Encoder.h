#ifndef ENCODER_H_
#define ENCODER_H_

#include <iostream>
#include <vector>
#include <cstdint>

class _Encode
{
public:
	~_Encode() {}

	virtual std::vector<uint8_t> encode(std::vector<uint8_t> &inpData) = 0;
};

class EncodeHamming : public _Encode
{
private:
	const uint8_t inpDataBits = 4;
	const uint8_t outDataBits = 7;

public:
	~EncodeHamming() {}

	std::vector<uint8_t> encode(std::vector<uint8_t> &inpData) override;
	void validate_inp_data(std::vector<uint8_t> &inpData);
	void zero_padding(std::vector<uint8_t> &inpData);
};

#endif // ENCODER
