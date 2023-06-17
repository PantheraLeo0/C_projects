#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void authenticating();
int display_home();
void add_candidate();
int list_candidate();

FILE *buffer;

int CANDIDATE_TOTAL_NUMBER = 0, CANDIDATE_SERIAL_NUMBER;
char CANDIDATE_NAME[256], CANDIDATE_ADDRESS[256];
char input = '\0';

void main()
{
    authenticating();
}

void authenticating()
{
    system("cls");              /* clear the screen */

    char CURRENT_PASSWORD[256], NEW_PASSWORD[256];

    buffer = fopen("AUTHENTICATING_PASS.txt","r");      /* checking whether AUTHENTICATING_PASS.txt is created or not*/

    if(buffer == NULL)                                  /* If AUTHENTICATING_PASS.txt is not created, execute this block of code */
    {
        printf("\n\tNEW PASSWORD : ");
        scanf("%s",NEW_PASSWORD);
    }

    fclose(buffer);                         /* close AUTHENTICATING_PASS.txt file */

    
}

int display_home()
{
    system("cls");                  /* clear the screen */

    int operation;                  

    printf("\n\tHello! There.\n");
    printf("\n\tV O T I N G    S Y S T E M\n\n");
    printf("\n\tChoose The Operation.\n");
    printf("\n\t1.ADD\n");
    printf("\n\t2.LIST\n");
    printf("\n\t");
    scanf("%d",&operation);

    switch(operation)
    {
        case 1: add_candidate();
                break;
        
        case 2: list_candidate();
                break;
                
        default : return 0;
    }
    return 0;
}

void add_candidate()
{
    system("cls");                      /* Clear the screen */

    buffer = fopen("CANDIDATE_LIST.txt","r");       /* checks whether the CANDIDATE_LIST.txt file is created or not*/
    if(buffer == NULL)
    {
        fclose(buffer);                             /* close FILE pointer */
        buffer = fopen("CANDIDATE_LIST.txt","w");   /* creating CANDIDATE_FILE.txt file */
        fclose(buffer);                             /* close FILE pointer */
    }

    /* Do while loop to ADD candidate to the list */
    do
    {
        CANDIDATE_TOTAL_NUMBER++;                         /* increases the number of candidate by 1 */

        printf("\n\tEnter candidate name : ");      /* input CANDIDATE_NAME */
        scanf("%s",CANDIDATE_NAME);

        printf("\n\tEnter candidate address : ");   /* input CANDIDATE_ADDRESS*/
        scanf("%s",CANDIDATE_ADDRESS);

        printf("\n\tDo you want to ADD candidate (y/n) : ");        /* input y for yes to ADD more candidate & n for no to go to HOME*/
        scanf(" %c",&input);

        /* Opens FILE pointer and save candidate details in CANDIDATE_LIST.txt file */
        buffer = fopen("CANDIDATE_LIST.txt","a");
        fprintf(buffer,"%d %s %s\n",CANDIDATE_TOTAL_NUMBER,CANDIDATE_NAME,CANDIDATE_ADDRESS);
        fclose(buffer);

        getchar();                                  /* MOST ADD THIS LINE FOR ONE TIME CODE RUN */
    }while(input == 'y');
    
    system("cls");                          /* clear the screen */

    if(input != 'y')
    {
        printf("\n\tCandidate ADDED successfully.\n\n");

        main();
    }
}

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