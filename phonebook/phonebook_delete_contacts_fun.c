#include "phonebook_MAIN.c"

void deleteFun(){
    char name[100], temp_name[100];
    char phone_number[100], temp_phone_number[100];
    int option;

    buffer_area = fopen("contacts.txt","r");
    temp_buffer_area = fopen("temp_contacts.txt","w");

    printf("\n\tDelete By...\n");
    printf("\n\t1.Name\n");
    printf("\n\t2.Phone Number\n");
    printf("\n\tEnter : ");
    scanf("%d",&option);

    system("cls");

    if(option == 1){
        printf("\n\tEnter name : ");
        scanf("%s",temp_name);
        while(fscanf(buffer_area,"%s %s",name,phone_number) != EOF){
            if(strcmp(name,temp_name) != 0){
                fprintf(temp_buffer_area,"%s %s\n",name,phone_number);
            }
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);
        buffer_area = fopen("contacts.txt","w");
        temp_buffer_area = fopen("temp_contacts.txt","r");
        while(fscanf(temp_buffer_area,"%s %s",temp_name,temp_phone_number) != EOF){
            fprintf(buffer_area,"%s %s\n",temp_name,temp_phone_number);
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);

        buffer_area = fopen("temp_contacts.txt","w");
        fclose(buffer_area);

    }
    if(option == 2){
        printf("\n\tEnter Phone : ");
        scanf("%s",temp_phone_number);
        while(fscanf(buffer_area,"%s %s",name,phone_number) != EOF){
            if(strcmp(temp_phone_number,phone_number) != 0){
                fprintf(temp_buffer_area,"%s %s",name,phone_number);
            }
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);
        buffer_area = fopen("contacts.txt","w");
        temp_buffer_area = fopen("temp_contacts.txt","r");
        while(fscanf(temp_buffer_area,"%s %s",temp_name,temp_phone_number) != EOF){
            fprintf(buffer_area,"%s %s\n",temp_name,temp_phone_number);
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);

        buffer_area = fopen("temp_contacts.txt","w");
        fclose(buffer_area);
    }
    printf("\n\tData deleted successfully\n\n");
    display();
}
