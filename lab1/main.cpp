/* MAIN.CPP */

#include "main.h"
#include "file.h"

int main( int argc, char* argv[])
{
	char str4File[] = "Initial commit";
    writeFile(str4File);

	char str4FileAdd[] = "Additional commit";
	writeFileAdd(str4FileAdd);

	readFile();
	fileSort();

	return 0;
}
/* END OF FILE */
