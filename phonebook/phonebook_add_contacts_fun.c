#include "phonebook_MAIN.c"

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
