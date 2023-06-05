#ifndef T_BOX_H
#define T_BOX_H
#include <iostream>
#include <ctime>
// #include "Coord.h"
using namespace std;
class T_Box
{
    static int space[40][10];
//     static int score;

    private :
            int x ,y ; // 座標
            int type ; // 型別
            int ang ; // 某個圖形的第 fg 個變化的圖形
    public :
            T_Box(int sx = 0 ,int sy = 5 ,int st = 0 ,int f = 0);
            void setValue(int sx = 0 ,int sy = 5 ,int st = 0 ,int f = 0) ;
            void l();
            void r();
            void d();
            void tl();
            void tr();
            void show(int, int);
            void create();
            void ereace();
            int judge();
            void check(int, int*);
            int end(int);
            void preview();
            void emptySpace();


};

#endif