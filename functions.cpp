#include "onegin.h"

//---------------------------String--Functions------------------------------------

int puts_(const char *str)
{
    if(str == NULL)
    {
        return EOF;
    }


    while(*str != '\0')
    {        
        putc(*str, stdout);
        str++;
    }

    printf("\n");

    return 0;
}

size_t strlen_(const char *str)
{
    size_t len = 0;

    while(*str != '\0')
    {
        str++;
        len++;
    }

    return len;
}

char *strchr_(const char *str, int ch)
{
    while(*str != '\0' && *str != ch)
    {
        str++;
    }
    return (char*) str;
}

char *strcpy_(char *dst, const char *src) // src -откуда копируем(str2), dst - куда копируем(str1)
{
    char *src_iter = dst;
    while(*src != '\0')
    {
        *src_iter = *src;
        src_iter++;
        src++;
    }
    *src_iter = '\0';
    return dst;
}

char *strncpy_(char *dst, const char *src, size_t count)
{
    char *src_iter = dst;

    while(count > 0 && *(src+1) != '\0')
    {
        *src_iter = *src;
        count--;
        src_iter++;
        src++;
    }

    return dst;
}

char *strcat_(char *dst, const char *src)
{
    char *src_iter = dst;
    while(*src_iter != '\0')
    {
        src_iter++;
    }
    while(*src != '\0')
    {
        *src_iter = *src;
        src++;
        src_iter++;
    }
    *src_iter = '\0';
    return dst;
}

char *strncat_(char *dst, const char *src, size_t count)
{
    char *src_iter = dst;
    while(*src_iter != '\0')
    {
        src_iter++;
    }
    while(*src != '\0' && count > 0)
    {
        *src_iter = *src;
        src++;
        src_iter++;
        count--;
    }
    *src_iter = '\0';
    return dst;
}

char *fgets_(char *str, int num, FILE *stream)
{
    char *str_iter = str;
    char symbol = '\0';

    symbol = fgetc(stream);

    while(symbol != '\n' && symbol != EOF && (num) > 0)
    {
        num--;
        *str_iter = symbol;
        str_iter++;
        symbol = fgetc(stream);
    }
    *str_iter = '\0';
    return str;
}

char *strdup_(const char *src)// don't forget use free() !!!!
{
    char* dst = (char*) calloc(strlen_(src) + 1, sizeof(char));
    
    return strcpy_(dst, src);
}

int strcmp_(const char *str1, const char *str2) // str1>str2 -> >0, str1==str2 -> 0
{
    while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}



//------------------------------------------Print------------------------------------------------


void Print_Data(const char* data, size_t rows, size_t cols)
{
    for(size_t i=0; i < rows; i++)
    {
        for(size_t j=0; j < cols; j++)
        {
            if(*(data + i*cols + j) != '\0')
                printf("%c ", *(data + i*cols + j));
        }
        printf("\n");
    }

}

void Print_Data_with_zero(const char* data, size_t rows, size_t cols)
{
    for(size_t i=0; i < rows; i++)
    {
        for(size_t j=0; j < cols; j++)
        {
            if(*(data + i*cols + j) != '\0')
                printf("%c  ", *(data + i*cols + j));
            else
                printf("\\0 "); 
        }
        printf("\n");
    }
}

void Print_triangle_data(const int* data, size_t rows)
{
    for(size_t i=0; i < rows; i++)
    {
        for(size_t j=0; j<=i; j++)
        {
            printf("%d ", *(data + (i*(i+1))/2 + j));
        }
        printf("\n");
    }
}

void Print_data_shift(const int* data)
{
    
    printf("%d %d \n", *(data), *(data+1));

    for(size_t i=0; i < (size_t)*(data); i++)
    {
        for(size_t j=0; j < (size_t)*(data+1); j++)
        {
            printf("%d  ", *(data + i*(size_t)*(data+1) + j + 2));
        }
        printf("\n");
    }
}

//----------------------------Save--text--------------------------------------------------------------------

size_t get_file_size(FILE *stream)
{ 
    long file_size = -1;
    if (stream == NULL)
    {
        printf("Ошибка открытия файла, переданного в get_file_size() \n");
    }
    else
    {
        fseek(stream, 0, SEEK_END);                               
        file_size = ftell(stream);                                     
    }
    return (size_t) file_size;
}

/*
char* create_buf(FILE *stream) //обязательно потом почистить!!!!!!
{
    size_t buf_size = get_file_size(stream);

    char* buf = (char*) calloc(buf_size + 1, sizeof(char));

    char symbol = '\0';
    for(size_t buf_iter = 0; buf_iter < buf_size; buf_iter++)
    {
        *(buf + buf_iter) = fgetc(stream);
    }
    *(buf + buf_size) = '\0';
}
*/

char* create_buf(size_t buf_size) //обязательно потом почистить!!!!!!
{
    return (char*) calloc(buf_size + 1, sizeof(char));
}

void copy_in_buf(FILE *stream, char* buf, size_t buf_size)
{
    char symbol = '\0';
    for(size_t buf_iter = 0; buf_iter < buf_size; buf_iter++)
    {
        *(buf + buf_iter) = fgetc(stream);
    }
    *(buf + buf_size) = '\0';
}

size_t change_symbol(char* str, size_t str_len, char symbol_old, char symbol_new)
{
    size_t n_symbol_new = 0;
    for(size_t str_iter = 0; str_iter < str_len; str_iter++)
    {
        if(*(str + str_iter) == symbol_old)
        {
            *(str + str_iter) = symbol_new;
        }
        if(*(str + str_iter) == symbol_new)
        {
            n_symbol_new ++;
        }
    }

    return n_symbol_new;
}

char** create_text5(FILE *stream)
{
    //работа с самим файлом

    FILE * stream = fopen("test.txt","rb");

    size_t file_size = get_file_size(stream);  
    char* buf = create_buf(file_size);
    copy_in_buf(stream, buf, file_size);//возможно стоит объединить в одну функцию create_buf

    fclose (stream);  

    //работа с буфером

    size_t n_str = change_symbol(buf, file_size, '\n', '\0');

    char** text5 = (char**) calloc(n_str+1, sizeof(char*));

    char* buf_iter = buf;

    for(int str_iter = 0; str_iter < n_str; str_iter++)
    {
        while(*(buf_iter) == '\0')
        {
            buf_iter ++;
        }

        *(text5 + str_iter) = strdup_(buf_iter);

        while(*(buf_iter) != '\0')
        {
            buf_iter ++;
        }
    }

    *(text5 + n_str) = 0;

    free(buf);

    return text5;
}

size_t text5_size(char** data)
{
    size_t data_size = 0;
    char** data_iter = data;

    while(*(data_iter) != 0)
    {
        data_size ++;
    }

    return data_size;
}

void clear_data(char** data)
{
    size_t data_size = text5_size(data);

    for(size_t data_iter=0; data_iter < data_size; data_iter ++)
    {
        free(*(data + data_iter));
    }

    free(data);
}



//----------------------------Sort--string-----------------------------------------------------------------

void bubble_sort(char** data, int size)
{
    for(int n_pass = 0; n_pass < size-1; n_pass++)
    {
        size_t n_swops = 0;
    }
}