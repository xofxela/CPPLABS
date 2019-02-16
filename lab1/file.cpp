/* FILE.CPP */

#include "file.h"

int writeFile( char* str )
{
    char path[] = "";
    char fullPath[] = "D:\\";

    std::cout << "Choose file to re-write in D root:\n" << std::endl;
    std::cin >> path;
	std::ofstream out;
    out.open(strcat(fullPath , path));
    if (out.is_open())
    {
        out << str << std::endl;
    }
    out.close();
    return 0;
}

int writeFileAdd( char* str )
{
    char path[] = "";
    char fullPath[] = "D:\\";
    std::cout << "Choose file to write in D root:\n" << std::endl;
    std::cin >> path;
    std::ofstream out(strcat(fullPath , path), std::ios::app);
    if (out.is_open())
    {
        out << ' ' << str;
    }
    out.close();
    return 0;
}

int readFile( void )
{
    std::string line;
    char path[] = "";
    char fullPath[] = "D:\\";

    std::cout << "Choose file to read in D root:\n" << std::endl;
    std::cin >> path;

    std::ifstream in(strcat(fullPath , path));
    if (!in.is_open())
    {
        std::cout<<"Unable to read file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
    return 0;
}

int fileSort(void)
{
    std::string line;

    char path[] = "";
    char fullPath[] = "D:\\";

    std::cout << "Choose file to sort in D root:\n" << std::endl;
    std::cin >> path;

    std::ifstream in(strcat(fullPath , path));
    printf("File path set to: %s\n",fullPath);
//    std::ifstream in(path);
    if (!in.is_open())
    {
        std::cout << "Unable to read file: " << fullPath << std::endl;
        return -1;
    }
    else
    {
        int intCounter = 0;
        int *data = new int[stringLen];
        for (int k=0;k<stringLen;k++) data[k]=0;

        printf("Start to scanning for data from file\n");
        while (!in.eof())
        {
            printf("Data has been set, count of int: %d\n",intCounter);
            in >> data[intCounter];
            ++intCounter;
        }
//        qsort (data, stringLen, sizeof(int), compare);
        printf("Sort succeeded\n");

        std::ofstream clear_file(fullPath, std::ios::out | std::ofstream::trunc);
        clear_file.close();

        std::ofstream out(fullPath, std::ios::app);
        if (out.is_open())
        {
            for (int i = 0; i < intCounter; i++)
            {
                printf("Write to file, indx = %d\n", i);
                out << data[i] << ' ';
            }
        }
        out.close();
        delete[] data;
    }
    in.close();
    return 0;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

/* END OF FILE */
