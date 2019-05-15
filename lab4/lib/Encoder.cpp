#include "Encoder.h"

std::vector<uint8_t> EncodeHamming::encode(std::vector<uint8_t> &inpData)
{
	validate_inp_data(inpData);
	zero_padding(inpData);

	int redundancyBits = ((inpData.size() / 4) * 3);
	std::vector<uint8_t> output_data(inpData.size() + redundancyBits);

	int j = 0;
	for (int i = 0; i < output_data.size(); i += outDataBits)
	{
		for (j; j < inpData.size(); j++)
		{
			output_data.at(i) = inpData.at(j);
			output_data.at(i + 1) = inpData.at(j + 1);
			output_data.at(i + 2) = inpData.at(j + 2);
			output_data.at(i + 3) = inpData.at(j + 3);
			output_data.at(i + 4) = inpData.at(j) ^ inpData.at(j + 2) ^ inpData.at(j + 3);
			output_data.at(i + 5) = inpData.at(j) ^ inpData.at(j + 1) ^ inpData.at(j + 2);
			output_data.at(i + 6) = inpData.at(j + 1) ^ inpData.at(j + 2) ^ inpData.at(j + 3);
			j += inpDataBits;
			break;
		}
	}

	return output_data;
}

void EncodeHamming::validate_inp_data(std::vector<uint8_t> &inpData)
{
	for (int i = 0; i < inpData.size(); i++)
	{
		if (inpData.at(i) == 0 || inpData.at(i) == 1)
			continue;
		else
			throw "Error: Input data not valid.";
	}
}

void EncodeHamming::zero_padding(std::vector<uint8_t> &inpData)
{
	if (std::fmod(inpData.size(), inpDataBits) != 0)
	{
		for (int i = 0; i < std::fmod(inpData.size(), inpDataBits); i++)
		{
			inpData.push_back(0);
		}
	}
}
