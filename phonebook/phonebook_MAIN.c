#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void password();
void display();
void addFun();
void listFun();
void modifyFun();
void searchFun();
void deleteFun();
void change_password();

FILE *buffer_area, *temp_buffer_area;

int main(){
    password();   
    return 0;
}

void password(){
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

    system("cls");

    if(strcmp(access_key,temp_access_key) == 0){
        printf("\n\tAccess Granted\n\n");
        display();
    }
    else{
        printf("\n\tAccess Denied\n");
    }
}

void display(){
    int option;
    printf("\n\t1.Add Contact\n");
    printf("\n\t2.List Contact\n");
    printf("\n\t3.Modify or Alter Contact\n");
    printf("\n\t4.Search Contact\n");
    printf("\n\t5.Delete Contact\n");
    printf("\n\t6.Exit Contact\n");
    printf("\n\t7.Change Password\n");
    printf("\n\tEnter (1-7) : ");
    scanf("%d",&option);

    system("cls");

    switch(option){
        case 1: addFun();
        break;
        case 2: listFun();
        break;
        case 3: modifyFun();
        break;
        case 4: searchFun();
        break;
        case 5: deleteFun();
        break;
        case 6: break;
        case 7: change_password();
        break;
    }
}

void addFun(){
    char name[100];
    char phone_number[100];
    char decision;

    buffer_area = fopen("contacts.txt","a");   /* Opening contacts.txt file */

    /* do while loop to input data */
    do{
        system("cls");
        printf("\n\tName : ");
        scanf("%s",name);
        printf("\n\tContact No. : ");
        scanf("%s",phone_number);

        fprintf(buffer_area,"%s %s\n",name,phone_number); /* store data in contacts.txt */

        printf("\n\tContact added successfully\n\n");
        printf("\n\tDo you want to add contact(y/n) : ");
        scanf(" %c",&decision);
        system("cls");         /*clear the screen */
    }while(decision == 'y');
    fclose(buffer_area);       /* closing FILE pointer */
    display();                 /* display function call */
}

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

void change_password(){
    char current_key[100], temp_key[100], new_key[100];

    system("cls");
    
    printf("\n\tCurrent Password : ");
    scanf("%s",current_key);

    buffer_area = fopen("access_key.txt","r");

    while(fscanf(buffer_area,"%s",temp_key) != EOF){
        if(strcmp(current_key,temp_key) == 0){
            goto new_key;
        }
    }
    new_key:
    fclose(buffer_area);
    buffer_area = fopen("access_key.txt","w");

    printf("\n\tNew Password : ");
    scanf("%s",new_key);

    fprintf(buffer_area,"%s",new_key);

    fclose(buffer_area);

    printf("\n\tPassword Changed Successfully\n");
    password();
}