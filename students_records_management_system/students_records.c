#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

#include "students_records_check_key_fun.c"

FILE *key_buffer;
FILE *buffer_area;
FILE *data_buffer;

void check_key(void);
void display(void);
void addFun(void);
void listFun(void);
void modifyFun(void);
void searchFun(void);
void deleteFun(void);
void change_key(void);

int main(){
    check_key();
    return 0;
}
