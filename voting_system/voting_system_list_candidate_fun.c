#include "voting_system_MAIN.c"

int list_candidate()
{
    system("cls");                   /* Clear the screen */

    printf("\n\tS.N CAMDIDATE NAME\tCANDIDATE ADDRESS\n\n");       /* output the column name */

    buffer = fopen("CANDIDATE_LIST.txt","r");                    /* open CANDIDATE_LIST.txt file in read mode */

    /* While loop to extract data from CANDIDATE_LIST.txt and output the data */
    while((fscanf(buffer,"%d %s %s",&CANDIDATE_SERIAL_NUMBER,CANDIDATE_NAME,CANDIDATE_ADDRESS)) != EOF)
       printf("\n\t%d\t%s\t\t%s\n",CANDIDATE_SERIAL_NUMBER,CANDIDATE_NAME,CANDIDATE_ADDRESS);

    fclose(buffer);             /* close CANDIDATE_LIST.txt */

    printf("\n\tDo you want to go to home (y/n): ");            /* input y to go to starting of the program & input n to exit program */
    scanf(" %c",&input);

    if(input == 'y')            /* input == y, if true go to home */
        display_home();
    else                        /* input == y, if false exit program */
        return 0;
} 