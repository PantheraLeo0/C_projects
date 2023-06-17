#include "phonebook_MAIN.c"

void listFun(){
    char name[100];
    char phone_number[100];
    buffer_area = fopen("contacts.txt","r");
    if(buffer_area == NULL){
        printf("No contacts Available");
    }
    else{
        printf("\n\tName\t\t\t\tContact\n");
        while(fscanf(buffer_area,"%s %s",name,phone_number) != EOF){
            printf("\n\t%s\t\t\t\t%s\n",name,phone_number);
        }
    }
    printf("\n");
    fclose(buffer_area);
    display();
}