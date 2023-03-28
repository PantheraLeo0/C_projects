#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

FILE *key_buffer;

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
    char key[100], temp_key[100];

    printf("Password : ");
    scanf("%s",key);

    key_buffer = fopen("current_key","r");

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
    
}
void change_key(){
    char current_key[100], temp_current_key[100];
    char new_key[100];
    char confirm_new_key[100];
    
    printf("Current Key : ");
    scanf("%s",&);
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

