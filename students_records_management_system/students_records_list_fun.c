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