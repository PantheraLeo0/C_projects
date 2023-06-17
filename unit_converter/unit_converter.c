#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "unit_converter_functions.c"

int main(){
    int option;
    home : 
    printf("Choose the unit to unit option(1-7) : \n\n");
    printf("1.Length\n");
    printf("2.Temperature\n");
    printf("3.Area\n");
    printf("4.Volume\n");
    printf("5.Weight\n");
    printf("6.Time\n");
    printf("7.Exit\n");
    scanf("%d",&option);
    system("cls");
    if(option == 1){
        printf("Choose the unit to ....(1-6) : \n\n");
        printf("1.Centimeter to ...\n");
        printf("2.Meter to ...\n");
        printf("3.Kilometer to ...\n");
        printf("4.Mile to ...\n");
        printf("5.Yard to ...\n");
        printf("6.Foot to ...\n");
        scanf("%d",&option);
        system("cls");
        if(option == 1){
            printf("1.Centimeter to Meter\n");
            printf("2.Centimeter to Millimeter\n"); 
            printf("3.Centimeter to Kilometer\n");  
            printf("4.Centimeter to Mile\n");
            printf("5.Centimeter to Yard\n");
            printf("6.Centimeter to Foot\n"); 
            scanf("%d",&option);
            system("cls");
            switch(option){
                case 1: centi_to_meter();
                goto home;
                break;
                case 2: centi_to_millimeter();
                goto home;
                break;
                case 3: centi_to_kilometer();
                goto home;
                break;
                case 4: centi_to_mile();
                goto home;
                break;
                case 5: centi_to_yard();
                goto home;
                break;
                case 6: centi_to_foot();
                goto home;
                break;
            }
        }
        if(option == 2){
            printf("1.Meter to Centimeter\n");
            printf("2.Meter to Millimeter\n");
            printf("3.Meter to Kilometer\n");
            printf("4.Meter to Mile\n");
            printf("5.Meter to Yard\n");
            printf("6.Meter to Foot\n\n");
            scanf("%d",&option);
            system("cls");
            switch(option){
                case 1: meter_to_centimeter();
                goto home;
                break;
                case 2: meter_to_millimeter();
                goto home;
                break;
                case 3: meter_to_kilometer();
                goto home;
                break;
                case 4: meter_to_mile();
                goto home;
                break;
                case 5: meter_to_yard();
                goto home;
                break;
                case 6: meter_to_foot();
                goto home;
                break;
            }
        }
        if(option == 3){
            printf("1.Kilometer to Centimeter\n");
            printf("2.Kilometer to Meter\n");
            printf("3.Kilometer to Millimeter\n");
            printf("4.Kilometer to Mile\n");
            printf("5.Kilometer to Yard\n");
            printf("6.Kilometer to Foot\n\n");
            scanf("%d",&option);
            system("cls");
            switch(option){
                case 1: kilometer_to_centimeter();
                goto home;
                break;
                case 2: kilometer_to_meter();
                goto home;
                break;
                case 3: kilometer_to_millimeter();
                goto home;
                break;
                case 4: kilometer_to_mile();
                goto home;
                break;
                case 5: kilometer_to_yard();
                goto home;
                break;
                case 6: kilometer_to_foot();
                goto home;
                break;
            }
        }
        if(option == 4){
            printf("1.Mile to Centimeter\n");
            printf("2.Mile to Meter\n");
            printf("3.Mile to Kilometer\n");
            printf("4.Mile to Yard\n");
            printf("5.Mile to Foot\n");
            printf("6.Mile to millimeter\n\n");
            scanf("%d",&option);
            system("cls");
            switch(option){
                case 1: mile_to_centimeter();
                goto home;
                break;
                case 2: mile_to_meter();
                goto home;
                break;
                case 3: mile_to_kilometer();
                goto home;
                break;
                case 4: mile_to_yard();
                goto home;
                break;
                case 5: mile_to_foot();
                goto home;
                break;
                case 6: mile_to_millimeter();
                goto home;
                break;
            }
        }
        if(option == 5){
            printf("1.Yard to Centimeter\n");
            printf("2.Yard to Meter\n");
            printf("3.Yard to Kilometer\n");
            printf("4.Yard to Millimeter\n");
            printf("5.Yard to Mile\n");
            printf("6.Yard to Foot\n\n");
            scanf("%d",&option);
            system("cls");
            switch(option){
                case 1: yard_to_centimeter();
                goto home;
                break;
                case 2: yard_to_meter();
                goto home;
                break;
                case 3: yard_to_kilometer();
                goto home;
                break;
                case 4: yard_to_millimeter();
                goto home;
                break;
                case 5: yard_to_mile();
                goto home;
                break;
                case 6: yard_to_foot();
                goto home;
                break;
            }
        }
        if(option == 6){
            printf("1.Foot to Centimeter\n");
            printf("2.Foot to Meter\n");
            printf("3.Foot to Kilometer\n");
            printf("4.Foot to Millimeter\n");
            printf("5.Foot to Mile\n");
            printf("6.Foot to Yard\n\n");
            scanf("%d",&option);
            system("cls");
            switch(option){
                case 1: foot_to_centimeter();
                goto home;
                break;
                case 2: foot_to_meter();
                goto home;
                break;
                case 3: foot_to_kilometer();
                goto home;
                break;
                case 4: foot_to_millimeter();
                goto home;
                break;
                case 5: foot_to_mile();
                goto home;
                break;
                case 6: foot_to_yard();
                goto home;
                break;
            }
        }
    }
    return 0;
}