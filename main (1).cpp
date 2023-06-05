#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>
#include "T_Box.h"
#include "User.h"
using namespace std;

//從檔案讀取使用者紀錄
int readFromfile(User user1[]){
    fstream io;
    io.open("file.txt", ios::in);
    int i=0;
    while(!io.eof() && !io.fail()){
        string n;
        int l,g;
        io >> n >> l >> g;
        user1[i].setName(n);
        user1[i].setLevel(l);
        user1[i].setGrade(g);
        i++;
    }
    return i;
}

//延遲函數
void delay(double wait){
    clock_t timea,timeb;
    timea = clock();
    do{
        timeb = clock();
    }while((double)(timeb - timea) <= wait);
    
}

int main(void){
    // mkbox();
    int dTime = 505;    //延遲時間
    srand(time(NULL));  //設定亂數種子
    User userArr[10];   //使用者記錄陣列

    //第一層迴圈循環不同使用者
    for(;;){
        //初始化分數 等級
        int level = 0;
        int score = 0;
        int userNum = readFromfile(userArr);    //讀取使用者檔案並記錄人數
        int serial = userArr[0].setUser(userArr,userNum);   //選定使用者
        if(serial>userNum){
            userNum = serial;
        }  

        T_Box tempA(0,5,rand()%7,0), tempB(0,5,rand()%7,0);     //宣告方塊物件

        //第二層迴圈循環每次方塊
        for(int i=0;;i++){
            //第三層迴圈循環方塊下落及動作
            for(;;){
                if(kbhit()) // 判斷是否有按鍵按下，如果有則可能是旋轉或者移動按鍵
                {
                    char ch = getch();
                    switch(ch)
                    {
                        case 'a' :   tempA.l() ; break;    //  向左移動一格
                        case 'd' :   tempA.r() ;  break;    //  向右移動一格
                        case 'w' :   tempA.tl() ; break;    //  左旋
                        case 's' :   tempA.tr() ; break;  //  右旋
                        default :    break;     // 如果都不是則不執行
                    }
                    //清空緩衝區
                    while(kbhit()){
                        ch = getch();
                    }
                    ch = ' ';
                }
                tempA.create();     //空間中產生方塊
                tempB.preview();    //產生預覽方塊
                tempA.show(level, score);   //顯示等級 分數
                tempA.ereace();     

                if(tempA.judge()) break;    //判斷方塊到底了沒
                delay(dTime);   //延遲
                tempA.d();      //方塊下降
                system("cls");      //清空畫面
            }

            if(tempA.end(score)) break;     //判斷遊戲是否結束
            tempA.create();     
            tempA.check(level,&score);      //檢查是否成行
            tempA = tempB;      //更新方塊
            tempB.setValue(0,5,rand()%7,0);     //建立新的預覽方塊
            system("cls");

            //等級上升並減少延遲秒數
            if(i%5 == 0){
                dTime -= 10;
                level++;
            }
        }

        //檢查使者是否刷新紀錄
        if(userArr[serial].getLevel() < level || userArr[serial].getGrade() > score){
            userArr[serial].setGrade(score);
            userArr[serial].setLevel(level);
            fstream io;
            io.open("file.txt", ios::out);
            for(int i=0;i<userNum;i++){
                io << userArr[i].getName() << " ";
                io << userArr[i].getLevel() << " ";
                io << userArr[i].getGrade();
            }
            io.close();
        }
        tempA.emptySpace();     //清空遊戲空間
    }


}