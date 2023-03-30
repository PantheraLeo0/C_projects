int check_key(){
    char key[100];
    char set_key[100];
    char temp_key[100];

    buffer_area = fopen("current_key.txt","r"); /* Checking file is created or not */
    if(buffer_area == NULL){                    /* File not created i.e. password is not set */
        fclose(buffer_area);                    /* closing current_key.txt file */

        buffer_area = fopen("current_key.txt","w"); /* Creating file to store password */ 
        fclose(buffer_area);                        /* Closing closing current_key.txt*/

        system("cls");                              /* Clear the screen */

        printf("Enter password to set : ");         /* Input password to set the lock */
        scanf("%s",set_key);

        key_buffer = fopen("current_key.txt","r+"); /* Opening current_key.txt file */
        fprintf(buffer_area,"%s",set_key);          /* Storing password in current_key.txt file */
        fclose(key_buffer);                         /* Closing current_key.txt file */
    }

    system("cls");   
    system("color b");                               /* Clear the screen */

    printf("\n\tPassword : ");                          /* Input password to access */
    scanf("%s",key);

    key_buffer = fopen("current_key.txt","r");      /* Opening current_key.txt file */

    while(fscanf(key_buffer,"%s",temp_key) != EOF){ /* Extracting password from current_key.txt file */
        if(strcmp(key,temp_key) == 0){              /* Comparing input password & stored password */

            /* Executed when input & stored password are same */
            printf("\n\tAccess Granted\n\n"); 
            fclose(key_buffer);   /* closing current_key.txt file */
            display();          
        }
        else{
            /* Executed when input & password are different */
            printf("\n\tAccess Denied\n");
            return 0;
        }
    }
}