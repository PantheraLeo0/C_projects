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