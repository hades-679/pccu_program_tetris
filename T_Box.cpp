#include "T_Box.h"
#include <iostream>
#include "Coord.h"
using namespace std;


    int T_Box::space[40][10] = {{0},{0}};
    int T_Box::score = 0;
    
    T_Box::T_Box(int sx,int sy,int ty,int fg){
        this->x = sx;
        this->y = sy;
        this->type = ty;
        this->ang = fg;
    }
    void T_Box::setValue(int sx, int sy, int ty, int fg){
        this->x = sx;
        this->y = sy;
        this->type = ty;
        this->ang = fg;
    }
    void T_Box::l(){
        y--;
        for(int i=0;i<4;i++){
            if(y + boxs[type][ang][i].y < 0){
                y++;
                break;
            }
        }
    }
    void T_Box::r(){
        y++;
        for(int i=0;i<4;i++){
            if(y + boxs[type][ang][i].y >= 10){
                y--;
                break;
            }
        }
    }
    void T_Box::tl(){
        ang--;
        if(ang<0){
            ang = 3;
        }
    }
    void T_Box::tr(){
        ang++;
        if(ang>=4){
            ang = 0;
        }
    }
    void T_Box::d(){
        x++;
    }
    void T_Box::show(int level){
        cout << "LEVEL: " << level << " SCORE: " << score << endl; 
        for(int i=2;i<23;i++){
            for(int j=0;j<12;j++){
                if(i==22){
                    cout << "--";
                }else 
                if(j==0){
                    cout << "<";
                }else if(j==11){
                    cout << ">";
                }else if(space[i][j-1] == 0){
                    cout << ". ";
                }else if(space[i][j-1] == 1){
                    cout << "[]";
                }

            }
            cout << endl;
        }
    }
    void T_Box::create(){
        mkbox();
        for(int i=0;i<4;i++){
            space[x + boxs[type][ang][i].x][y + boxs[type][ang][i].y] = 1;
        }
        for(int i=0;i<10;i++){
            space[22][i] = 1;
        }
    }
    void T_Box::ereace(){
        for(int i=0;i<4;i++){
            space[x + boxs[type][ang][i].x][y + boxs[type][ang][i].y] = 0;
        }
    }
    int T_Box::judge(){
        for(int i=0;i<4;i++){
            if(space[x + boxs[type][ang][i].x+1][y + boxs[type][ang][i].y] == 1){
                return 1;
            }
        }
        return 0;
    }
    void T_Box::check(int level){
        int count = 0;
        for(int i=2;i<22;i++){
            int sum = 0;
            for(int j=0;j<10;j++){
                if(space[i][j] == 1){
                    sum++;
                }
            }
            if(sum == 10){
                count++;
                for(int j=0;j<10;j++){
                    space[i][j] = 0;
                }
                for(int k=i;k>0;k--){
                    for(int j=0;j<10;j++){
                        space[k][j] = space[k-1][j];
                    }
                }
                for(int k=0;k<10;k++){
                    space[0][k] = 0;
                }
            }
        }
        switch (count)
        {
        case 1:
            score += 40*(level+1);
            break;
        case 2:
            score += 100*(level+1);
            break;
        case 3:
            score += 300*(level+1);
            break;
        case 4:
            score += 1200*(level+1);
            break;
        
        default:
            break;
        }
    }
    int T_Box::end(){
        if(x<1){
            system("cls");
            cout << "game over" << endl;
            cout << "your score: " << score;
            return 1;
        }
        return 0;
    }
    void T_Box::preview(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(i == boxs[type][ang][k].x && j == boxs[type][ang][k].y){
                        cout << "[]";
                        break;
                    }else if(k==3){
                        cout << "  ";
                    }
                }
            }
            cout << endl;
        }
    }