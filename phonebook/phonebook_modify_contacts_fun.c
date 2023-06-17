#include "phonebook_MAIN.c"

void modifyFun(){
    int option;
    char current_name[100], new_name[100], temp_name[100];
    char temp_phone[100];
    char current_phone[100], new_phone[100];

    buffer_area = fopen("contacts.txt","r");
    
    if(buffer_area == NULL){
        printf("Error!");
        fclose(buffer_area);
    }
    else{
        fclose(buffer_area);

        printf("\n\tWhat do you want to Modify?\n");
        printf("\n\t1.Name\n");
        printf("\n\t2.Phone Number\n");
        printf("\n\tEnter (1-2): ");
        scanf("%d",&option);

        system("cls");
        if(option == 1){
            printf("\n\tEnter current name : ");
            scanf("%s",current_name);
            printf("\n\tEnter new name : ");
            scanf("%s",new_name);

            buffer_area = fopen("contacts.txt","r");
            temp_buffer_area = fopen("temp_contacts.txt","w");

            while(fscanf(buffer_area,"%s %s",temp_name,temp_phone) != EOF){
                if(strcmp(current_name,temp_name) == 0){
                    fprintf(temp_buffer_area,"%s %s\n",new_name,temp_phone);
                }
                else{
                    fprintf(temp_buffer_area,"%s %s\n",temp_name,temp_phone);
                }
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);

            buffer_area = fopen("contacts.txt","w");
            temp_buffer_area = fopen("temp_contacts.txt","r");
            
            while(fscanf(temp_buffer_area,"%s %s",temp_name,temp_phone) != EOF){
                fprintf(buffer_area,"%s %s\n",temp_name,temp_phone);
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);

            buffer_area = fopen("temp_contacts.txt","w");
            fclose(buffer_area);
        }

        if(option == 2){
            printf("\n\tEnter current Phone : ");
            scanf("%s",current_phone);
            printf("\n\tEnter new Phone : ");
            scanf("%s",new_phone);

            buffer_area = fopen("contacts.txt","r");
            temp_buffer_area = fopen("temp_contacts.txt","w");

            while(fscanf(buffer_area,"%s %s",temp_name,temp_phone) != EOF){
                if(strcmp(current_phone,temp_phone) == 0){
                    fprintf(temp_buffer_area,"%s %s\n",temp_name,new_phone);
                }
                else{
                    fprintf(temp_buffer_area,"%s %s\n",temp_name,temp_phone);
                }
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);

            buffer_area = fopen("contacts.txt","w");
            temp_buffer_area = fopen("temp_contacts.txt","r");
            
            while(fscanf(temp_buffer_area,"%s %s",temp_name,temp_phone) != EOF){
                fprintf(buffer_area,"%s %s\n",temp_name,temp_phone);
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);

            buffer_area = fopen("temp_contacts.txt","w");
            fclose(buffer_area);
        }
        printf("\n\tData modified Successfully\n\n");
        display();
    }
}