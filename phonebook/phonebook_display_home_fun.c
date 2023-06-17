#include "phonebook_MAIN.c"

void display(){
    int option;
    printf("\n\t1.Add Contact\n");
    printf("\n\t2.List Contact\n");
    printf("\n\t3.Modify or Alter Contact\n");
    printf("\n\t4.Search Contact\n");
    printf("\n\t5.Delete Contact\n");
    printf("\n\t6.Exit Contact\n");
    printf("\n\t7.Change Password\n");
    printf("\n\tEnter (1-7) : ");
    scanf("%d",&option);

    system("cls");

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
        case 6: break;
        case 7: change_password();
        break;
    }
}
