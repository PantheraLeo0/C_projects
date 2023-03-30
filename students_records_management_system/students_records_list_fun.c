#include "students_records_display_fun.c"

void listFun(){
    int s_class;
    char s_name[100], s_address[100];
    long int s_phone;
    char temp;

    buffer_area = fopen("records.txt","r");

    printf("\tClass\tName\t\t\t\tAddress\t\t\t\tContact\n\n");
    while(fscanf(buffer_area,"%d %s %s %ld",&s_class,s_name,s_address,s_phone) != EOF){
        printf("\t%d\t%s\t\t\t%s\t\t\t%ld\n",s_class,s_name,s_address,s_phone);
    }
    fclose(buffer_area);
    printf("Press 'D' for Menu : ");
    scanf("%c",&temp);
    if(temp == 'D'){
        display();
    }
}