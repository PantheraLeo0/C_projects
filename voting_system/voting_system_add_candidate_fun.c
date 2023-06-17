#include "voting_system_MAIN.c"

void add_candidate()
{
    system("cls");                      /* Clear the screen */
    
    char CANDIDATE_NAME[256], CANDIDATE_ADDRESS[256];
    char input = '\0';

    CANDIDATE_NUMBER++;                 /* increases the number of candidate by 1 */

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
        printf("\n\tEnter candidate name : ");      /* input CANDIDATE_NAME */
        scanf("%s",CANDIDATE_NAME);

        printf("\n\tEnter candidate address : ");   /* input CANDIDATE_ADDRESS*/
        scanf("%s",CANDIDATE_ADDRESS);

        printf("\n\tDo you want to ADD candidate (y/n) : ");        /* input y for yes to ADD more candidate & n for no to go to HOME*/
        input = getchar();

        /* Opens FILE pointer and save candidate details in CANDIDATE_LIST.txt file */
        buffer = fopen("CANDIDATE_LIST.txt","a");
        fprintf(buffer,"%d %s %s\n",CANDIDATE_NUMBER,CANDIDATE_NAME,CANDIDATE_ADDRESS);
        fclose(buffer);

        CANDIDATE_NUMBER++;                         /* increases the number of candidate by 1 */

        getchar();                                  /* MOST ADD THIS LINE FOR ONE TIME CODE RUN */
    }while(input == 'y' || input == 'Y');
    
    if(input != 'y' || input != 'Y')
    {
        printf("\n\tCandidate ADDED successfully.\n\n");

        main();
    }
}
