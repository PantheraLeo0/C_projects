#include "phonebook_MAIN.c"

void searchFun(){
    char name[100], temp_name[100];
    char phone_number[100], temp_phone_number[100];
    int option;
    buffer_area = fopen("contacts.txt","r");

    printf("\n\tSearch By...\n\n ");
    printf("\n\t1.Name\n");
    printf("\n\t2.Phone Number\n");
    printf("\n\tEnter (1-2): ");\
    scanf("%d",&option);

    system("cls");

    if(option == 1){
        printf("\n\tEnter name : ");
        scanf("%s",temp_name);
        while(fscanf(buffer_area,"%s %s",name,phone_number) != EOF){
            if(strcmp(name,temp_name) == 0){
                printf("\n\t%s\t\t\t%s\n",name,phone_number);
            }
        }
    }
    if(option == 2){
        printf("\n\tEnter Phone : ");
        scanf("%s",temp_phone_number);
        while(fscanf(buffer_area,"%s %s",name,phone_number) != EOF){
            if(strcmp(temp_phone_number,phone_number) == 0){
                printf("\n\t%s\t\t\t%s\n",name,phone_number);
            }
        }
    }
    fclose(buffer_area);
    display();
}