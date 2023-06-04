#include <iostream>
#include <conio.h>
#include <ctime>
#include "T_Box.h"
// #include "Coord.h"
using namespace std;

void delay(double wait){
    clock_t timea,timeb;
    timea = clock();
    do{
        timeb = clock();
    }while((double)(timeb - timea) <= wait);
    
}

int main(void){
    // mkbox();
    int dTime = 505;
    int level = 0;
    srand(time(NULL));
    T_Box tempA(0,5,rand()%7,0), tempB(0,5,rand()%7,0);
    // tempA.show();

    for(int i=0;;i++){
        for(;;){
            if(kbhit()) // 判斷是否有按鍵按下，如果有則可能是旋轉或者加速按鍵
            {
                char ch = getch();
                switch(ch)
                {
                    case 'a' :   tempA.l() ; break;    //  向左移動一格
                    case 'd' :   tempA.r() ;  break;    //  向右移動一格
                    case 'w' :   tempA.tl() ; break;    //  左旋
                    case 's' :   tempA.tr() ; break;  //  右旋
                    default :    break; // 如果都不是則不執行
                }
                while(kbhit()){
                    ch = getch();
                }
                ch = ' ';
            }
            tempA.create();
            tempB.preview();
            tempA.show(level);
            tempA.ereace();
            if(tempA.judge()) break;
            delay(dTime);
            tempA.d();
            system("cls");
        }
        if(tempA.end()) break;
        tempA.create();
        tempA.check(level);
        tempA = tempB;
        tempB.setValue(0,5,rand()%7,0);
        system("cls");
        if(i%5 == 0){
            dTime -= 10;
            level++;
        }
    }
}