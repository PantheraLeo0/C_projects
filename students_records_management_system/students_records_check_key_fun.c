#include "students_records_display_fun.c"

void check_key(){
    char key[] = "password";
    char temp_key[100];

    printf("Password : ");
    scanf("%s",key);

    key_buffer = fopen("current.txt","w");
    fprintf(buffer_area,"%s",key);
    fclose(buffer_area);

    key_buffer = fopen("current_key.txt","r");
    while(fscanf(key_buffer,"%s",temp_key) != EOF){
        if(strcmp(key,temp_key) == 0){
            printf("Access Granted");
        }
    }
    fclose(key_buffer);
    display();
}
