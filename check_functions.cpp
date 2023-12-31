#include "onegin.h"

//----------------------Print--Functions-------------------

void check_Print_Data()
{
    char data_0[3][6] = {"12345", "1234", "123"};

    printf("check print data:\n");

    Print_Data((char *)data_0, 3, 5);

}

void check_Print_Data_with_zero()
{
    char data_0[3][6] = {"12345", "1234", "123"};
    
    printf("check print data with '\\0':\n");

    Print_Data_with_zero((char *)data_0, 3, 5);
}

void check_Print_triangle_data()
{
    int data_1[] = {0,
                  2, 3,
                  -2, -1, 5,
                  5, 2, -1, 0, 
                  5, 1, -3, 2, 0};
    
    printf("check Print_triangle_data:\n");

    Print_triangle_data((int *)data_1, 5);
}

void check_Print_data_shift()
{
    int data_2[] = {3, 5,
                    10, 20, 30, 40, 50,
                    11, 21, 31, 41, 51,
                    12, 22, 32, 42, 52};

    printf("check Print_data_shift:\n");

    Print_data_shift((int *)data_2);
}    

//----------------------------Save--text--------------------------------------------------------------------

void check_get_file_size()
{
    FILE * stream = fopen("test.txt","rb");
    size_t size = check_get_file_size(stream);                                      
    fclose (stream);                                                               
    printf("Размер файла %l байт \n", size);
}