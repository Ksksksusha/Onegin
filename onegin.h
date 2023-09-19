#ifndef ONEGIN_H
#define ONEGIN_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <locale>
#include <sys/stat.h>


//string functions

int puts_(const char *str);

size_t strlen_(const char *str);

char *strchr_(const char *str, int ch);

char *strcpy_(char *str1, const char *str2);

char *strncpy_(char *str1, const char *str2, size_t count);

char *strcat_(char *str1, const char *str2);

char *strncat_(char *str1, const char *str2, size_t count);

char *fgets_(char *str, int num, FILE *stream);

char *strdup_(const char *str);

int strcmp_(const char *str1, const char *str2);



//print functions

void Print_Data(const char* data, size_t rows, size_t cols); // print only data

void Print_Data_with_zero(const char* data, size_t rows, size_t cols); // print /0 with data

void Print_triangle_data(const int* data, size_t rows);

void Print_data_shift(const int* data);



//save functions

size_t get_file_size(FILE *stream);                                                         //узнаем размер файла

char* create_buf(size_t buf_size);                                                          //создаём буфер

void copy_in_buf(FILE *stream, char* buf, size_t buf_size);                                 //переносим файл в буфер

size_t change_symbol(char* str, size_t str_len, char symbol_old, char symbol_new);          //меняем \n на \0 и считаем  количество строк

size_t change_symbol_calc_str(char* str, size_t str_len, char symbol_old, char symbol_new, size_t normal_lenght);

char** create_text5(FILE *stream);                                                          //создаем массив text5 + заполняем text5 указателями на строки

size_t text5_size(char** data);                               

void clear_data(char** data);                                                               //чистит все строки через указатели, затем data




//sort functions

int is_letter(char c);

void swap_str(char** data, size_t iter_str1, size_t iter_str2);

int str_cmp(const char* str1, const char* str2);

char** bubble_sort(char** data, size_t size);



//check functions


void check_Print_Data();

void check_Print_Data_with_zero();

void check_Print_triangle_data();

void check_Print_data_shift();


void check_get_file_size();


#endif //ONEGIN_H