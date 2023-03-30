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
            printf("\t%d\t%s\t%s\t%s\n",s_temp_class,s_temp_name,s_temp_address,s_temp_phone);
        }
    }
    fclose(buffer_area);

    printf("\n\tData searched\n");
    display();
}