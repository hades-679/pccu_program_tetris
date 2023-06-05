#ifndef USER_H
#define USER_H
#include <cstring>
#include <iostream>
using namespace std;

class User{

    private:
    
    int grade;
    int level;
    char name[30];

    public:
    // void addGrade(int);
    // void levelUp();
    User();
    void setName(string);
    void setGrade(int);
    void setLevel(int);
    string getName();
    int getLevel();
    int getGrade();

    int setUser(User user1[], int &num);
    // void writeToFile();
    // void readFromFile();

};
#endif 