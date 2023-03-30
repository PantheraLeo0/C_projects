#include "students_records_display_fun.c"

void modifyFun(){
    int option;
    int s_temp_class;
    int s_new_class;
    int s_class;
    char s_name[100], s_address[100];
    long int s_phone;


    printf("Class : ");
    scanf("%d",&s_class);
    printf("Name : ");
    scanf("%s",s_name);

    printf("What do you want to modify?\n\n");
    printf("1.Class\n");
    printf("2.Name\n");
    printf("3.Address\n");
    printf("4.Contact\n");
    printf("Your choice(1-4) : ");
    scanf("%d",&option);

    if(option == 1){
        printf("Class : ");
        scanf("%d",&s_new_class);

        data_buffer = fopen("records.txt","r");
        buffer_area = fopen("temp_records.txt","w");

        while(fscanf(data_buffer,"%s %s %s %ld",&s_temp_class,s_name,s_address,s_phone) != 0){
            if(s_class == s_temp_class){
                fprintf(buffer_area,"%d %s %s %ld",s_temp_class,s_name,s_address,s_phone);
                

            }
        }
    }
}

