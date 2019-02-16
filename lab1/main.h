#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <array>

//#define NDEBUG
//bool gError = true;

extern int writeFile( char* str );
extern int writeFileAdd( char* str );
extern int readFile( void );
extern int compare( const void *arg1, const void *arg2 );
extern int fileSort(void);

#endif // MAIN_H_
