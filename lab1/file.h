#ifndef FILE_H_
#define FILE_H_

#include "main.h"

int write_str_to_file(const char* str);
int read_str_from_file(const char* fullPath);
std::vector<int> read_file_to_vector(char* fullPath);
int sort_file(const char* fullPath, std::vector<int>& numbers);
int write_sorted_file(const char* fullPath, std::vector<int>& numbers);
bool is_number(const std::string &s);
#endif // FILE_H_
