#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

FILE *key_buffer;
FILE *buffer_area;
FILE *data_buffer;

int check_key(void);
int display(void);
int addFun(void);
int listFun(void);
int modifyFun(void);


int main(){
    check_key();
    return 0;
}

int check_key(){
    char key[100];
    char set_key[100];
    char temp_key[100];

    buffer_area = fopen("current_key.txt","r"); /* Checking file is created or not */
    if(buffer_area == NULL){                    /* File not created i.e. password is not set */
        fclose(buffer_area);                    /* closing FILE pointer */

        buffer_area = fopen("current_key.txt","w"); /* Creating file to store password */ 
        fclose(buffer_area);                        /* Closing FILE pointer*/

        system("cls");                              /* Clear the screen */

        printf("Enter password to set : ");         /* Input password to set the lock */
        scanf("%s",set_key);

        key_buffer = fopen("current_key.txt","r+"); /* Opening current_key.txt file */
        fprintf(buffer_area,"%s",set_key);          /* Storing password in current_key.txt file */
        fclose(key_buffer);                         /* Cloding FILE pointer */
    }

    system("cls");   
    system("color b");                               /* Clear the screen */

    printf("Password : ");                          /* Input password to access */
    scanf("%s",key);

    key_buffer = fopen("current_key.txt","r");      /* Opening current_key.txt file */

    while(fscanf(key_buffer,"%s",temp_key) != EOF){ /* Extracting password from current_key.txt file */
        if(strcmp(key,temp_key) == 0){              /* Comparing input password & stored password */

            /* Executed when input & stored password are same */
            printf("Access Granted\n\n"); 
            fclose(key_buffer);
            display();          
        }
        else{
            /* Executed when input & password are different */
            printf("Access Denied");
            return 0;
        }
    }
}

int display(){
    int option;

    option:
    printf("\n\t");
    for(int i=1;i<=37;i++){
        printf("%c",219);
    }
    printf("\n\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n\n");
    printf("\t1.Add\n");
    printf("\t2.List\n");
    printf("\t3.Modify\n");
    printf("\t4.Search\n");
    printf("\t5.Delete\n");
    printf("\t6.Exit\n");
    printf("\t7.Change Login Password\n\n");
    printf("\tEnter your choice : ");
    scanf("%d",&option);

    switch(option){
        case 1: addFun();
        break;

        case 2: listFun();
        break;

        case 3: modifyFun();
        break;

        case 4: //searchFun();
        break;

        case 5: //deleteFun();
        break;

        case 6: system("cls"); 
        return 0;
        break;

        case 7: //change_key();
        break;

        default: 
        printf("Enter valid option(1-7) : ");
        scanf("%d",&option);
        system("cls");
        goto option;
        break;
    }
    return 0;
}

int addFun(){
    int s_class;
    char s_name[100], s_address[100];
    char s_phone[20];
    char decision;

    buffer_area = fopen("records.txt","a");

    do{
        system("cls");
        printf("Class : ");
        scanf("%d",&s_class);
        printf("Student Name : ");
        scanf("%s",s_name);
        printf("Student Address : ");
        scanf("%s",s_address);
        printf("Student Contact : ");
        scanf("%s",s_phone);

        fprintf(buffer_area,"%d %s %s %s\n",s_class,s_name,s_address,s_phone);

        printf("\nData entered successfully\n\n");
        printf("Do you want to add data(y/n) : ");
        scanf(" %c",&decision);
        system("cls");
    }while(decision == 'y');
    fclose(buffer_area);
    display();
}

int listFun(){
    int s_class;
    char s_name[100], s_address[100];
    char s_phone[20];
    char temp;

    buffer_area = fopen("records.txt","r+");

    system("cls");

    printf("\tClass\tName    \t\t\tAddress\t\t\tContact\n\n");
    while(fscanf(buffer_area,"%d%s%s%s",&s_class,s_name,s_address,s_phone) != EOF){
        printf("\t%d\t%s    \t\t\t%s\t\t\t%s\n\n",s_class,s_name,s_address,s_phone);
    }
    fclose(buffer_area);
    printf("\tPress 'y' to exit or 'n' to Menu : ");
    scanf(" %c",&temp);
    if(temp == 'y'){
        return 0;
    }
    if(temp == 'n'){
        system("cls");
        display();
    }
}

int modifyFun(){
    int option;
    int s_temp_class;
    int s_new_class;
    int s_class;
    char s_name[100], s_address[100];
    long int s_phone;


    printf("Class : ");
    scanf("%d",&s_class);
    printf("Name : ");
    scanf("%s",s_name);

    printf("What do you want to modify?\n\n");
    printf("1.Class\n");
    printf("2.Name\n");
    printf("3.Address\n");
    printf("4.Contact\n");
    printf("Your choice(1-4) : ");
    scanf("%d",&option);

    if(option == 1){
        printf("Class : ");
        scanf("%d",&s_new_class);

        data_buffer = fopen("records.txt","r");
        buffer_area = fopen("temp_records.txt","w");

        while(fscanf(data_buffer,"%s %s %s %ld",&s_temp_class,s_name,s_address,s_phone) != 0){
            if(s_class == s_temp_class){
                fprintf(buffer_area,"%d %s %s %ld",s_temp_class,s_name,s_address,s_phone);
                

            }
        }
    }
}
