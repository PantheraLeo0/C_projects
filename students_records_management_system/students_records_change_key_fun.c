#include "students_records_check_key_fun.c"

void change_key(){
    char current_key[100], temp_current_key[100];
    char new_key[100];
    char confirm_new_key[100];
    
    printf("Current Key : ");
    scanf("%s",current_key);
    printf("New Key :  ");
    scanf("%s",new_key);
    printf("Confirm New Key : ");
    scanf("%s",confirm_new_key);

    key_buffer = fopen("current_key.txt","r");
    fscanf(key_buffer,"%s",temp_current_key);

    if(strcmp(current_key,temp_current_key) == 0){
        if(strcmp(new_key,confirm_new_key) == 0){
            fclose(key_buffer);
            key_buffer = fopen("current_key.txt","w");
            fprintf(key_buffer,"%s",new_key);
            printf("Password Changed Successfully");
            }
        }
    fclose(key_buffer);
}