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
