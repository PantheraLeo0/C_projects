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