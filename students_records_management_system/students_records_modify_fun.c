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