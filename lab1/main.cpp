/* MAIN.CPP */
#include "main.h"
#include "file.h"

int main( int argc, char* argv[])
{
	char str4File[] = "Initial commit";
    writeFile(str4File);

	char str4FileAdd[] = "Additional commit";
	writeFileAdd(str4FileAdd);

	std::cout<<"Write 5 numbers to file:"<<std::endl;
	int arr[5];
	for(int i=0; i<5; i++)
        {
            std::cin>>arr[i];
            //writeFileAdd(std::to_string(arr[i]));
        }

	readFile();
	fileSort();
    //if(/*assertion cause */)gError = false;
    //assert(gError);
	return 0;

}
/* END OF FILE */
