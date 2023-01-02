#ifndef MY_FUNC_H
#define MY_FUNC_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"

void sort(TEL** tel_list, int count);
void insert(TEL** tel_list, int* count, int max_num);
void print_all(TEL** tel_list, int count);
void delete_tel(TEL** tel_list, int* count);
void find_by_birth(TEL** tel_list, int count);
void RegFromFile(TEL** tel_list, int* count, int max_num);
void storeExit(TEL** tel_list, int count);


#endif