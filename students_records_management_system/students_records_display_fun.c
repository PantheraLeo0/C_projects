int display(){
    int option;

    option:           /* goto (in case choice is invalid) */
    printf("\n\t");
    for(int i=1;i<=37;i++){                                     
        printf("%c",219);         /* print white line */
    }

    /* Option available */
    printf("\n\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n\n");
    printf("\t1.Add\n");
    printf("\t2.List\n");
    printf("\t3.Modify\n");
    printf("\t4.Search\n");
    printf("\t5.Delete\n");
    printf("\t6.Exit\n");
    printf("\t7.Change Login Password\n\n");

    /* enter integer 1-7 */
    printf("\tEnter your choice : ");
    scanf("%d",&option);

    /* switch to interger input */
    switch(option){
        case 1: addFun();              /* function call to add data */
        break;

        case 2: listFun();              /* function call to list data */
        break;

        case 3: modifyFun();            /* function call to modify data */
        break;

        case 4: searchFun();          /* function call to search specific data */
        break;

        case 5: deleteFun();          /* function call to delete specific data */
        break;

        case 6: system("cls");          /* clear the screen */
        return 0;                       /* exit the program */
        break;

        case 7: change_key();         /* function call to change access key */
        break;

        default: 
        printf("Enter valid option(1-7) : "); /* invalid interger input */
        scanf("%d",&option);
        system("cls");                        /* clear the screeen */
        goto option;
        break;
    }
    return 0;
}