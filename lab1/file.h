#ifndef FILE_H_
#define FILE_H_

#include "main.h"

#define stringLen 100

int writeFile( char* str );
int writeFileAdd( char* str );
int readFile( void );
int compare (const void * a, const void * b);
int fileSort(void);

#endif // FILE_H_
