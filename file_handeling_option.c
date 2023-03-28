#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// function to create file
void create_file(){
    char file_name[20];
    printf("Create File \n\n");
    printf("Enter Filename : ");
    scanf("%s",file_name);
    system("cls");
    printf("File Created Successfully\n\n");
}

// function to write data in file
void write_file(){
    char file_name[20];
    int total_student;
    int student_roll;
    char student_name[50];
    char student_address[50];
    char student_contact_number[20];

    printf("Enter Filename : ");
    scanf("%s",file_name);
    system("cls");

    printf("Enter total number of students : ");
    scanf("%d",&total_student);
    system("cls");

    FILE *file_buffer;
    file_buffer = fopen(file_name,"w");

    for(int i = 0;i < total_student; i++){
        printf("Enter student Roll No. : ");
        scanf("%d",&student_roll);
        printf("Enter student Name : ");
        scanf("%s",student_name);
        printf("Enter student Address : ");
        scanf("%s",student_address);
        printf("Enter student Contact Number : ");
        scanf("%s",student_contact_number);
        fprintf(file_buffer,"%d\t%s\t\t\t\t%s\t\t\t\t%s\n",student_roll,student_name,student_address,student_contact_number);
        system("cls");
    }
    printf("Data Entred Successfully\n\n");
    fclose(file_buffer);
}

// function to read data from file
void read_file(){
    char file_name[20];
    int student_roll;
    char student_name[50];
    char student_address[50];
    char student_contact_number[20];

    printf("Enter Filename : ");
    scanf("%s",file_name);
    system("cls");

    FILE *file_buffer;
    file_buffer = fopen(file_name,"r");
    printf("Roll No.\tName\t\t\t\tAddress\t\t\t\tContact\n\n");
    while(fscanf(file_buffer,"%d%s%s%s",&student_roll,student_name,student_address,student_contact_number) != EOF){
        printf("%d\t\t%s\t\t\t\t%s\t\t\t\t%s\n",student_roll,student_name,student_address,student_contact_number);
    }
    printf("\nData Read Successfully\n\n");
    fclose(file_buffer);
}

// function to delete file
void delete_file(){
    char file_name[20];

    printf("Enter Filename : ");
    scanf("%s",file_name);
    system("cls");

    if(remove(file_name) == 0){
        printf("Deleted successfully.\n\n");
    }
    else{
        printf("Unable to delete the file.\n\n");
    }
}
int main(){
    int option;
    menu :
    printf("Choose the service(1-5) : \n\n");
    printf("1. Create File.\n");
    printf("2. Write File.\n");
    printf("3. Read File.\n");
    printf("4. Delete File.\n");
    printf("5. Exit.\n\n");
    scanf("%d",&option);
    system("cls");
    switch(option){
        case 1: create_file();
        goto menu;
        break;
        case 2: write_file();
        goto menu;
        break;
        case 3: read_file();
        goto menu;
        break;
        case 4: delete_file();
        goto menu;
        break;
        case 5: return 0;
        break;
    } 
  
    return 0;
}