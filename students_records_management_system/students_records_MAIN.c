#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

FILE *key_buffer;
FILE *buffer_area;
FILE *buffer_area_2;

int check_key(void);
int display(void);
int addFun(void);
int listFun(void);
int modifyFun(void);
int searchFun(void);
int deleteFun(void);
int change_key(void);


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
        fclose(buffer_area);                    /* closing current_key.txt file */

        buffer_area = fopen("current_key.txt","w"); /* Creating file to store password */ 
        fclose(buffer_area);                        /* Closing closing current_key.txt*/

        system("cls");                              /* Clear the screen */

        printf("Enter password to set : ");         /* Input password to set the lock */
        scanf("%s",set_key);

        key_buffer = fopen("current_key.txt","r+"); /* Opening current_key.txt file */
        fprintf(buffer_area,"%s",set_key);          /* Storing password in current_key.txt file */
        fclose(key_buffer);                         /* Closing current_key.txt file */
    }

    system("cls");   
    system("color b");                               /* Clear the screen */

    printf("\n\tPassword : ");                          /* Input password to access */
    scanf("%s",key);

    key_buffer = fopen("current_key.txt","r");      /* Opening current_key.txt file */

    while(fscanf(key_buffer,"%s",temp_key) != EOF){ /* Extracting password from current_key.txt file */
        if(strcmp(key,temp_key) == 0){              /* Comparing input password & stored password */

            /* Executed when input & stored password are same */
            printf("\n\tAccess Granted\n\n"); 
            fclose(key_buffer);   /* closing current_key.txt file */
            display();          
        }
        else{
            /* Executed when input & password are different */
            printf("\n\tAccess Denied\n");
            return 0;
        }
    }
}

int display(){
    int option;

    option:           /* goto (in case choice is invalid) */
    printf("\n\t");
    for(int i=1;i<=37;i++){                                     
        printf("%c",219);         /* print white line */
    }

    /* Option available */
    printf("\n\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n\n");
    printf("\t1.Add\n");
    printf("\t2.List\n");
    printf("\t3.Modify\n");
    printf("\t4.Search\n");
    printf("\t5.Delete\n");
    printf("\t6.Exit\n");
    printf("\t7.Change Login Password\n\n");

    /* enter integer 1-7 */
    printf("\tEnter your choice : ");
    scanf("%d",&option);

    /* switch to interger input */
    switch(option){
        case 1: addFun();              /* function call to add data */
        break;

        case 2: listFun();              /* function call to list data */
        break;

        case 3: modifyFun();            /* function call to modify data */
        break;

        case 4: searchFun();          /* function call to search specific data */
        break;

        case 5: deleteFun();          /* function call to delete specific data */
        break;

        case 6: system("cls");          /* clear the screen */
        return 0;                       /* exit the program */
        break;

        case 7: change_key();         /* function call to change access key */
        break;

        default: 
        printf("Enter valid option(1-7) : "); /* invalid interger input */
        scanf("%d",&option);
        system("cls");                        /* clear the screeen */
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

    buffer_area = fopen("records.txt","a");   /* Opening records.txt file */

    /* do while loop to input data */
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

        fprintf(buffer_area,"%d %s %s %s\n",s_class,s_name,s_address,s_phone); /* store data in records.txt */

        printf("\nData entered successfully\n\n");
        printf("Do you want to add data(y/n) : ");
        scanf(" %c",&decision);
        system("cls");         /*clear the screen */
    }while(decision == 'y');
    fclose(buffer_area);       /* closing FILE pointer */
    display();                 /* display function call */
}

int listFun(){
    int s_class;
    char s_name[100], s_address[100];
    char s_phone[20];
    char temp;

    buffer_area = fopen("records.txt","r+");     /* Opening records.txt file */

    system("cls");      /* clear the screen */

    printf("\tClass\tName    \t\t\tAddress\t\t\tContact\n\n");       /* print the attributes */

    while(fscanf(buffer_area,"%d%s%s%s",&s_class,s_name,s_address,s_phone) != EOF){     /* extracting data till the end of file */
        printf("\t%d\t%s    \t\t\t%s\t\t\t%s\n\n",s_class,s_name,s_address,s_phone);    /* printf data in table form */
    }

    fclose(buffer_area);        /* closing records.txt file*/
    printf("\tPress 'y' to exit or 'n' to Menu : ");    
    scanf(" %c",&temp);

    if(temp == 'y'){
        system("cls");
        return 0;
    }
    if(temp == 'n'){
        system("cls");
        display();
    }
}

int modifyFun(){
    int option;
    int s_class, s_temp_class;
    char s_name[100], s_temp_name[100], s_address[100], s_temp_address[100];
    char s_phone[20], s_temp_phone[20];

    system("cls");
    printf("\n\tClass : ");
    scanf("%d",&s_class);
    printf("\tName : ");
    scanf("%s",s_name);

    system("cls");

    printf("\n\tWhat do you want to modify?\n\n");
    printf("\t1.Address\n");
    printf("\t2.Contact\n");
    printf("\tYour choice(1-2) : ");
    scanf("%d",&option);

    system("cls");

    if(option == 1){
        printf("\n\tNew Address : ");
        scanf("%s",s_address);

        buffer_area_2 = fopen("records.txt","r");
        buffer_area = fopen("temp_records.txt","w");

        while(fscanf(buffer_area_2,"%d %s %s %s",&s_temp_class,s_temp_name,s_temp_address,s_temp_phone) != EOF){
            if((strcmp(s_name, s_temp_name) == 0) && (s_class == s_temp_class)){
                fprintf(buffer_area,"%d %s %s %s\n",s_temp_class,s_temp_name,s_address,s_temp_phone);                
            }
            else{
                fprintf(buffer_area,"%d %s %s %s\n",s_temp_class,s_temp_name,s_temp_address,s_temp_phone);
            }
        }
        fclose(buffer_area_2);
        fclose(buffer_area);
        buffer_area_2 = fopen("records.txt","w");
        buffer_area = fopen("temp_records.txt","r");

        while(fscanf(buffer_area,"%d %s %s %s",&s_temp_class,s_temp_name,s_temp_address,s_temp_phone) != EOF){
            fprintf(buffer_area_2,"%d %s %s %s\n",s_temp_class,s_temp_name,s_temp_address,s_temp_phone);
        }
        fclose(buffer_area_2);
        fclose(buffer_area);

        buffer_area = fopen("temp_records.txt","w");
        fclose(buffer_area);
        printf("\n\tData Modified\n");
        display();
    }
}

int searchFun(){
    int s_class, s_temp_class;
    char s_name[100], s_temp_name[100];
    char s_temp_address[100], s_temp_phone[20];

    system("cls");
    printf("\n\tClass : ");
    scanf("%d",&s_class);
    printf("\tName : ");
    scanf("%s",s_name);

    system("cls");

    buffer_area = fopen("records.txt","r");

    while(fscanf(buffer_area,"%d %s %s %s",&s_temp_class,s_temp_name,s_temp_address,s_temp_phone) != EOF){
        if((strcmp(s_name,s_temp_name) == 0) && (s_class == s_temp_class)){
            printf("\n\t%d\t%s\t%s\t%s\n",s_temp_class,s_temp_name,s_temp_address,s_temp_phone);
        }
    }
    fclose(buffer_area);

    printf("\n\tData searched\n");
    display();
}

int deleteFun(){
    int s_class, s_temp_class;
    char s_name[100], s_temp_name[100];
    char s_temp_address[100], s_temp_phone[20];

    system("cls");
    printf("\n\tClass : ");
    scanf("%d",&s_class);
    printf("\tName : ");
    scanf("%s",s_name);

    system("cls");

    buffer_area = fopen("records.txt","r");
    buffer_area_2 = fopen("temp_records.txt","w");

    extract:
    while(fscanf(buffer_area,"%d %s %s %s",&s_temp_class,s_temp_name,s_temp_address,s_temp_phone) != EOF){
        if((strcmp(s_name,s_temp_name) == 0) && (s_class == s_temp_class)){
            goto extract;
        }
        else{
            fprintf(buffer_area_2,"%d %s %s %s\n",s_temp_class,s_temp_name,s_temp_address,s_temp_phone);
        }
    }
    fclose(buffer_area);
    fclose(buffer_area_2);

    buffer_area = fopen("records.txt","w");
    buffer_area_2 = fopen("temp_records.txt","r");

    while(fscanf(buffer_area_2,"%d %s %s %s",&s_temp_class,s_temp_name,s_temp_address,s_temp_phone) != EOF){
        fprintf(buffer_area,"%d %s %s %s\n",s_temp_class,s_temp_name,s_temp_address,s_temp_phone);
    }

    fclose(buffer_area);
    fclose(buffer_area_2);

    buffer_area = fopen("temp_records.txt","w");
    fclose(buffer_area);
    printf("\n\tData Deleted\n");
    display();
}

int change_key(){
    char current_key[100], temp_key[100], new_key[100];

    system("cls");
    
    printf("\n\tCurrent Password : ");
    scanf("%s",current_key);

    buffer_area = fopen("current_key.txt","r");

    while(fscanf(buffer_area,"%s",temp_key) != EOF){
        if(strcmp(current_key,temp_key) == 0){
            goto new_key;
        }
    }
    new_key:
    fclose(buffer_area);
    buffer_area = fopen("current_key.txt","w");

    printf("\n\tNew Password : ");
    scanf("%s",new_key);

    fprintf(buffer_area,"%s",new_key);

    fclose(buffer_area);

    printf("\n\tPassword Changed Successfully\n");
    check_key();
}