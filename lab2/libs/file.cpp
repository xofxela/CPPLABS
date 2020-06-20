/* FILE.CPP */

#include "file.h"

int write_str_to_file(const char* fullPath, const char* str)
{
	std::ofstream out;
    out.open(fullPath, std::ios::out | std::ios::binary | std::ios::app);
    if (!out.is_open())
    {
        std::cout<<"Unable to write file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        out << str << std::endl;
    }
    out.close();
    std::cout << "Write successful to " << fullPath << std::endl;
    return 0;
}

int read_str_from_file(const char* fullPath)
{
    std::string line;
	std::ifstream in;
    in.open(fullPath);
    if (!in.is_open())
    {
        std::cout<<"Unable to read file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        while(std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
    std::cout << "Read successful from " << fullPath << std::endl;
    return 0;
}

std::vector<int> read_file_to_vector(const char* fullPath)
{
    std::vector<int> numbers{};
    std::ifstream in(fullPath);
    if (!in.is_open())
    {
        std::cout<<"Unable to read file: " << fullPath << std::endl;
        assert(0);
    }
    else
    {

        std::string line{};
        std::string number{};
        while (std::getline(in, line))
        {
            std::stringstream strStream(line);
            while (std::getline(strStream, number, ' '))
            {
                if (!is_number(number.c_str()))
                {
                    std::cout << "File contains non-integer or signed data! " << std::endl;
                    assert(0);
                }
                numbers.push_back(atoi(number.c_str()));
            }
        }
        std::cout << "FILE DATA:" << std::endl;
        for (unsigned int i = 0; i < numbers.size(); i++) std::cout << numbers[i] << ' ';
        std::cout << std::endl;
    }
    in.close();
    std::cout << "Read file successful from " << fullPath << std::endl;
    return numbers;
}

int write_sorted_file(const char* fullPath, std::vector<int>& numbers)
{
    std::ofstream clear_file(fullPath, std::ios::out | std::ofstream::trunc);
    if (!clear_file.is_open())
    {
        std::cout<<"Unable to flush file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        clear_file.close();
    }
    std::ofstream out(fullPath, std::ios::out | std::ios::binary | std::ios::app);
    if (!out.is_open())
    {
        std::cout << "Unable to write file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            out << numbers[i] << ' ';
        }
    //            std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(out));
    }
    out << std::endl;
    out.close();
    std::cout << "Write sorted file successful to " << fullPath << std::endl;
    return 0;
}

bool is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

/* END OF FILE */
