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