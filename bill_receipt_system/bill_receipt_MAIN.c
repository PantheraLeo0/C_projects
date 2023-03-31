#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

FILE *buffer_area;

int access_key(void);
int bill_interface(void);

int main(){
    access_key();
    return 0;
}

int access_key(){
    char access_key[100], temp_access_key[100];

    buffer_area = fopen("access_key.txt","r");
    if(buffer_area == NULL){
        fclose(buffer_area);

        buffer_area = fopen("access_key.txt","w");
        fclose(buffer_area);

        system("cls");

        printf("\n\tNew Password : ");
        scanf("%s",access_key);

        buffer_area = fopen("access_key.txt","r+");
        fprintf(buffer_area,"%s",access_key);

        fclose(buffer_area);
    }

    system("cls");

    printf("\n\tPassword : ");
    scanf("%s",access_key);

    buffer_area = fopen("access_key.txt","r");
    fscanf(buffer_area,"%s",temp_access_key);
    fclose(buffer_area);

    if(strcmp(access_key,temp_access_key) == 0){
        printf("\n\tAccess Granted\n\n");
        bill_interface();
    }
    else{
        printf("\n\tAccess Denied\n");
        return 0;
    }
}

int bill_interface(){
    printf("\n\t1.Add\n");
    return 0;
}