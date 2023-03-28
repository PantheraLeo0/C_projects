#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int column, int line);

int main(){
    system("cls");
    for(int i=1;i<=50;i++){
        for(int j=1;j<=25;j++){
            gotoxy(i, j);
            printf("%c",219);
        }
    }
    return 0;
}

COORD coord = {0, 0};
void gotoxy(int x, int y){
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
