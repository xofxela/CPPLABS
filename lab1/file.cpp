/* FILE.CPP */

#include "file.h"

int writeFile( char* str )
{
	std::ofstream out;
    out.open("C:\\file.txt");
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    return 0;
}

int writeFileAdd( char* str )
{
    std::ofstream out("C:\\file.txt", std::ios::app);
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    return 0;
}

int readFile( void )
{
    std::string line;
    std::ifstream in("C:\\file.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
    return 0;
}

int compare( const void *arg1, const void *arg2 )
{
    int& a = *(int*)arg1;
    int& b = *(int*)arg2;
        if (a == b) return 0;
        if (a > b) return 1;
    return -1;
}

int fileSort(void)
{
    std::string line;

    char path[] = "";
    //char fullPath[] = "C:\\";

    std::cout << "Choose file:\n" << std::endl;
    std::cin >> path;

    //std::ifstream in(strcat(fullPath , path));
    //printf("\tFile path set to: %s\n",fullPath);
    std::ifstream in(path);
    if (in.is_open())
    {
        //  Count num of strings in file
        char *strInFile = new char [1024];
        int numStr = 0;
        while (!in.eof())
        {
            in.getline(strInFile, 1024, '\0');
            numStr++;
        }
        delete[] strInFile;

        //  Init array
        char **sortArray = new char*[numStr];
        for (int i = 0; i < numStr; i++)
        {
          sortArray[i] = new char[1024];
        }

        // Array sorting

        qsort(sortArray, numStr, sizeof(char[1024]), compare);

        // Delete array
        for (int i = 0; i < numStr; i++)
        {
          delete[] sortArray[i];
        }
        delete[] sortArray;

        // Print sorted array
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
    return 0;
}


/* END OF FILE */
