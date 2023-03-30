#include "students_records_add_fun.c"
#include "students_records_list_fun.c"
#include "students_records_modify_fun.c"
#include "students_records_search_fun.c"
#include "students_records_delete_fun.c"
#include "students_records_change_key_fun.c"

void display(){
    int option;
    
    printf("\tWELCOME TO STUDENT MANAGEMENT SYSTEM\n");
    printf("\t1.Add\n");
    printf("\t2.List\n");
    printf("\t3.Modify\n");
    printf("\t4.Search\n");
    printf("\t5.Delete\n");
    printf("\t6.Exit\n");
    printf("\n\tPress 7 to change the login Password\n");
    printf("\tEnter your option : ");
    scanf("%d",&option);

    option:
    switch(option){
        case 1: addFun();
        break;

        case 2: listFun();
        break;

        case 3: modifyFun();
        break;

        case 4: searchFun();
        break;

        case 5: deleteFun();
        break;

        case 6: return 0;
        break;

        case 7: change_key();
        break;

        default: 
        printf("Enter valid option(1-7) : ");
        scanf("%d",&option);
        goto option;
        break;
    }
}