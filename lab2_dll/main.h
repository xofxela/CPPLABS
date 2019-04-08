#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>
#include <cstdio>
#include <algorithm>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//#define DEBUG

#ifdef DEBUG
#define _printf(args ...) printf(args)
#else
#define _printf(...)
#endif // DEBUG

#endif // MAIN_H_
