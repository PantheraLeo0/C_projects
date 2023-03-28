#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

FILE *buffer_area, *temp_buffer_area;
void password(){
    char initial_password[] = "password";
    char final_password[50];
    printf("password : ");
    scanf("%s",final_password);
    if(strcmp(initial_password,final_password) == 0){
        printf("Password Correct");
    }
    system("cls");
}

void display(){
    int option;
    printf("1.Add\n");
    printf("2.List\n");
    printf("3.Modify or Alter\n");
    printf("4.Search\n");
    printf("5.Delete\n");
    printf("6.Exit\n");

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
    }
}

void addFun(){
    char name[100];
    long int phone_number;
    buffer_area = fopen("contacts.txt","w");
    if(buffer_area == NULL){
        printf("Error!");
    }
    else{
        printf("Name : ");
        scanf("%s",name);
        printf("Phone Number : ");
        scanf("%ld",&phone_number);

        system("cls");

        fprintf(buffer_area,"%s %ld",name,phone_number);
        printf("\nData entered successfully\n");
    }
    fclose(buffer_area);
    display();
}

void listFun(){
    char name[100];
    long int phone_number;
    buffer_area = fopen("contacts.txt","r");
    if(buffer_area == NULL){
        printf("No Data Available");
    }
    else{
        while(fscanf(buffer_area,"%s %ld",name,&phone_number) != EOF){
            printf("Name\t\t\t\tContact\n");
            printf("\n%s\t\t\t\t%ld\n");
        }
    }
    fclose(buffer_area);
    display();
}

void modifyFun(){
    char current_name[100], new_name[100];
    char temp_name[100];
    long int current_phone_number, new_phone_number;
    long int phone_number, temp_phone_number;
    int option;

    buffer_area = fopen("contacts.txt","r");
    temp_buffer_area = fopen("temp_contacts.txt","w");

    if(buffer_area == NULL){
        printf("Error!");
    }
    if(temp_buffer_area == NULL){
        printf("Error!");
    }
    printf("Change By...\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("Enter : ");
    scanf("%d",&option);

    if(option == 1){
        printf("Enter current name : ");
        scanf("%s",current_name);
        printf("Enter new name");
        scanf("%s",new_name);

        while(fscanf(buffer_area,"%s %ld",temp_name,temp_phone_number) != EOF){
                if(strcmp(current_name,temp_name) == 0){
                    strcpy(temp_name,new_name);
                }
                fprintf(temp_buffer_area,"%s\t\t\t%ld",temp_name,temp_phone_number);
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);

            buffer_area = fopen("contacts.txt","w");
            temp_buffer_area = fopen("temp_contacts.txt","r");

            while(fscanf(temp_buffer_area,"%s %ld",temp_name,temp_phone_number) != 0){
                fprintf(buffer_area,"%s\t\t\t%ld\n",temp_name,temp_phone_number);
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);
            printf("Record Modified");
            modifyFun();
    }
        if(option == 2){
            printf("Enter current Phone : ");
            scanf("%ld",current_phone_number);
            printf("Enter new Phone : ");
            scanf("%ld",&new_phone_number);
            
            while(fscanf(buffer_area,"%s %ld",temp_name,temp_phone_number) != EOF){
                if(current_phone_number == temp_phone_number){
                    temp_phone_number = new_phone_number;
                }
                fprintf(temp_buffer_area,"%s\t\t\t%ld",temp_name,temp_phone_number);
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);

            buffer_area = fopen("contacts.txt","w");
            temp_buffer_area = fopen("temp_contacts.txt","r");

            while(fscanf(temp_buffer_area,"%s %ld",temp_name,temp_phone_number) != 0){
                fprintf(buffer_area,"%s\t\t\t%ld\n",temp_name,temp_phone_number);
            }
            fclose(buffer_area);
            fclose(temp_buffer_area);
            printf("Data Modified Successfully");
            modifyFun();
        }
        display();
}

void searchFun(){
    char name[100], temp_name[100];
    long int phone_number, temp_phone_number;
    int option;
    buffer_area = fopen("contacts.txt","r");

    printf("Search By...\n\n ");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("Enter : ");\
    scanf("%d",&option);
    if(option == 1){
        printf("Enter name : ");
        scanf("%s",temp_name);
        while(fscanf(buffer_area,"%s %ld",name,&phone_number) != EOF){
            if(strcmp(name,temp_name) == 0){
                printf("\n%s\t\t\t%ld\n",name,phone_number);
            }
        }
    }
    if(option == 2){
        printf("Enter Phone : ");
        scanf("%ld",&temp_phone_number);
        while(fscanf(buffer_area,"%s %ld",name,&phone_number) != EOF){
            if(phone_number == temp_phone_number){
                printf("\n%s\t\t\t%ld\n",name,phone_number);
            }
        }
    }
    fclose(buffer_area);
    display();
}

void deleteFun(void){
    char name[100], temp_name[100];
    long int phone_number, temp_phone_number;
    int option;

    buffer_area = fopen("contacts.txt","r");
    temp_buffer_area = fopen("temp_contacts.txt","w");

    printf("Delete By...\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("Enter : ");
    scanf("%d",&option);
    if(option == 1){
        printf("Enter name : ");
        scanf("%s",temp_name);
        while(fscanf(buffer_area,"%s %ld",name,&phone_number) != EOF){
            if(strcmp(name,temp_name) != 0){
                fprintf(temp_buffer_area,"%s %ld",name,phone_number);
            }
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);
        buffer_area = fopen("contacts.txt","w");
        temp_buffer_area = fopen("temp_contacts.txt","r");
        while(fscanf(temp_buffer_area,"%s %ld",temp_name,temp_phone_number) != EOF){
            fprintf(buffer_area,"%s\t\t\t%ld\n",temp_name,temp_phone_number);
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);
    }
    if(option == 2){
        printf("Enter Phone : ");
        scanf("%ld",temp_phone_number);
        while(fscanf(buffer_area,"%s %ld",name,&phone_number) != EOF){
            if(phone_number != temp_phone_number){
                fprintf(temp_buffer_area,"%s %ld",name,phone_number);
            }
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);
        buffer_area = fopen("contacts.txt","w");
        temp_buffer_area = fopen("temp_contacts.txt","r");
        while(fscanf(temp_buffer_area,"%s %ld",temp_name,temp_phone_number) != EOF){
            fprintf(buffer_area,"%s\t\t\t%ld\n",temp_name,temp_phone_number);
        }
        fclose(buffer_area);
        fclose(temp_buffer_area);
    }
    display();
}

int main(){
    password();   
    display(); 
    return 0;
}