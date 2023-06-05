#include "User.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
    // void User::addGrade(){

    // }
    // void User::levelUp();
    User::User(){
        grade = 0;
        level = 0;
        string n = "zbcd";
        strcpy(name,n.c_str());
    }
    void User::setName(string n){
        strcpy(name, n.c_str());
    }
    void User::setGrade(int g){
        grade = g;
    }
    void User::setLevel(int l){
        level = l;
    }
    string User::getName(){
        stringstream ss;
        ss << name;
        string s;
        ss >> s;
        return s;
    }
    int User::getLevel(){
        return level;
    }
    int User::getGrade(){
        return grade;
    }

    int User::setUser(User user1[], int &num){
        for(int i=0;i<num;i++){
            cout << endl << endl << user1[i].getName() << " ";
            cout << "level:" << user1[i].getLevel() << " ";
            cout << "score:" << user1[i].getGrade() << " " << endl;
        }
        cout << "Type your mame and start game: ";
        string n;
        cin >> n;
        for(int i=0;i<num;i++){
            if(n == user1[i].getName()){
                return i;
            }
        }
        user1[++num].setName(n);
        fstream io;
        io.open("file.txt", ios::out|ios::app);
        io << user1[num].getName() << " ";
        io << user1[num].getLevel() << " ";
        io << user1[num].getGrade();
        io.close();
        return num;
    }

    // void User::writeToFile(){
    //     fstream io;
    //     io.open("file.txt", ios::out|ios::app);
    //     io << getName() << " ";
    //     io << getLevel() << " ";
    //     io << getGrade() << " " << ednl;
    //     io.close()
    // }
    // void User::readFromFile(){
    //     fstream io;
    //     io.open("file.txt", ios::in)
    // }