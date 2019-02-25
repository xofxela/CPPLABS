/* FILE.CPP */

#include "file.h"

int writeFile( char* str )
{
    char path[] = "";
    char fullPath[500] = "C:\\";

    std::cout << "Choose file to re-write:\n" << std::endl;
    std::cin >> path;
	std::ofstream out;
    out.open(strcat(fullPath , path));
    if (!out.is_open())
    {
        std::cout<<"Unable to re-write file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        out << str << std::endl;
    }
    out.close();
    std::cout << "Re-write successful\n" << std::endl;
    return 0;
}

int writeFileAdd( char* str )
{
    char path[] = "";
    char fullPath[500] = "C:\\";
    std::cout << "Choose file to write:\n" << std::endl;
    std::cin >> path;
    std::ofstream out(strcat(fullPath , path), std::ios::app);
    if (!out.is_open())
    {
        std::cout<<"Unable to write file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        out << '\n' << str;
    }
    out.close();
    std::cout << "Write successful\n" << std::endl;
    return 0;
}

int readFile( void )
{
    char path[] = "";
    char fullPath[500] = "C:\\";

    std::cout << "Choose file to read:\n" << std::endl;
    std::cin >> path;

    std::ifstream in(strcat(fullPath , path));
    if (!in.is_open())
    {
        std::cout<<"Unable to read file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        std::string line;
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
    std::cout << "Read successful\n" << std::endl;
    return 0;
}

int fileSort(void)
{
    char filePath[] = "";
    char fullPath[500] = "C:\\";

    std::cout << "Choose file to sort:\n" << std::endl;
    std::cin >> filePath;

    std::strcat(fullPath, filePath);
    std::ifstream in(fullPath, std::ios::in | std::ios::binary);
    _printf("1 File path set to: %s\n", fullPath);

    if (!in.is_open())
    {
        std::cout << "Unable to read file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        std::vector<int> numbers{};
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
                    return -1;
                }
                numbers.push_back(atoi(number.c_str()));
            }
        }
        std::cout << "Data to sort: ";
        for (unsigned int i = 0; i < numbers.size(); i++) std::cout << numbers[i]<< ' ';
        std::cout << std::endl;

        std::sort(numbers.begin(), numbers.end());
        _printf("2 File path set to: %s\n", fullPath);
        std::ofstream clear_file(fullPath, std::ios::out | std::ofstream::trunc);
        clear_file.close();
        _printf("3 File path set to: %s\n", fullPath);
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
                _printf("Write to file, indx = %d\n", i);
                out << numbers[i] << ' ';
            }
//            std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(out));
        }
        out << std::endl;
        out.close();
    }
    in.close();
    return 0;
}

bool is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

/* END OF FILE */
