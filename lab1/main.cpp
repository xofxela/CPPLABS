/* MAIN.CPP */

#include "main.h"
#include "file.h"

int main(int argc, char* argv[])
{
    char fullPath2File[100] = "C:\\file.txt";

	const char stringWriteToFile[] = "Initial commit";
    write_str_to_file(fullPath2File, stringWriteToFile);
    read_str_from_file(fullPath2File);

	char fileName[] = "";
    char fullPath[500] = "C:\\";

    std::cout << "Choose file name to read, sort and write:\n" << std::endl;
    std::cin >> fileName;
    std::strcat(fullPath, fileName);

    std::vector<int> vectorToSort{};

    vectorToSort = read_file_to_vector(fullPath);
    sort_file(vectorToSort);
    write_sorted_file(fullPath, vectorToSort);

	return 0;
}
/* END OF FILE */
