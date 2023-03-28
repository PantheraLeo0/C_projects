#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

FILE *key_buffer;
FILE *buffer_area;

void password(void);
void display(void);
void addFun(void);
void listFun(void);
void modifyFun(void);
void searchFun(void);
void deleteFun(void);
void change_key(void);
void key_check(void);

int main(){
    check_key();
    return 0;
}

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

void display(){
    int option;
    
    printf("\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n");
    printf("\t1.Add\n");
    printf("\t2.List\n");
    printf("\t3.Modify\n");
    printf("\t4.Search\n");
    printf("\t5.Delete\n");
    printf("\t6.Exit\n");
    printf("\n\tPress 7 to change the login Password\n");
    printf("\tEnter your option : ");
    scanf("%d",&option);

    option:
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

        case 6: return 0;
        break;

        case 7: change_key();
        break;

        default: 
        printf("Enter valid option(1-7) : ");
        scanf("%d",&option);
        goto option;
        break;
    }
}

void addFun(){
    int s_class;
    char s_name[100], s_address[100];
    long int s_phone;
    char decision;

    do{
        printf("Class : ");
        scanf("%d",&s_class);
        printf("Student Name : ");
        scanf("%s",s_name);
        printf("Student Address : ");
        scanf("%s",s_address);
        printf("Student Contact : ");
        scanf("%ld",&s_phone);

        buffer_area = fopen("records.txt","w");

        fprintf(buffer_area,"%d %s %s %ld",s_class,s_name,s_address,s_phone);

        printf("Data entered successfully\n\n");
        printf("Do you want to add data(y/n) : ");
        scanf("%c",&decision);
        system("cls");
    }while(decision == 'y');
    fclose(buffer_area);
    display();
}

void listFun(){
    int s_class;
    char s_name[100], s_address[100];
    long int s_phone;
    char temp;

    buffer_area = fopen("records.txt","r");

    printf("\tClass\tName\t\t\t\tAddress\t\t\t\tContact\n\n");
    while(fscanf(buffer_area,"%d %s %s %ld",&s_class,s_name,s_address,s_phone) != EOF){
        printf("\t%d\t%s\t\t\t%s\t\t\t%ld\n",s_class,s_name,s_address,s_phone);
    }
    fclose(buffer_area);
    printf("Press 'D' for Menu : ");
    scanf("%c",&temp);
    if(temp == 'D'){
        display();
    }
}

void modifyFun(){
    int s_class;
    char s_name[100];

    printf("Class : ");
    scanf("%d",&s_class);
    printf("Name : ");
    scanf("%s",s_name);
}

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

    key_buffer = fopen("current_key","r");

    while(fscanf(key_buffer,"%s",temp_current_key) != EOF){
        if(strcmp(current_key,temp_current_key) == 0){
            if(strcmp(new_key,confirm_new_key) == 0){
                
            }
        }
    }
}

