/* MAIN.CPP */

#include "main.h"
#include "file.h"

int main( int argc, char* argv[])
{
//	const char str4File[] = "Initial commit";
//    write_str_to_file(str4File);
//
//	const char str4FileAdd[] = "Additional commit";
//	write_str_to_file(str4FileAdd);
	char fileNameRead[] = "";
    char fullPathRead[500] = "D:\\";
    std::cout << "Choose file name to read:\n" << std::endl;
    std::cin >> fileNameRead;
    std::strcat(fullPathRead, fileNameRead);
    read_str_from_file(fullPathRead);

	char fileName[] = "";
    char fullPath[500] = "D:\\";

    std::cout << "Choose file name to read, sort and write:\n" << std::endl;
    std::cin >> fileName;
    std::strcat(fullPath, fileName);

    std::vector<int> numToSort{};

    numToSort = read_file_to_vector(fullPath);
    sort_file(fullPath, numToSort);
    write_sorted_file(fullPath, numToSort);

	return 0;
}
/* END OF FILE */
