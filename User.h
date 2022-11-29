#ifndef PROJECT1_USER_H
#define PROJECT1_USER_H
#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include "Functions.h"
#include "Date.h"
#include<iostream>

using namespace std;

class FanPage;

class User
{
    char * name;
    User ** friendsArr;
    int numOfFriends, friendsArrPhySize;
    FanPage** fanPagesArr;
    int numOfFanPages, fanPagesArrPhySize;
    Status ** statusArr;
    int numOfStatus,statusArrPhySize;
    Date birthday;

public:
    
    //Default cto'r
    User():numOfFriends(0),friendsArrPhySize(0),numOfFanPages(0),fanPagesArrPhySize(0),numOfStatus(0),statusArrPhySize(0)
    {
        cout<<"def ctor used"<<endl;
        name = nullptr;
        friendsArr= nullptr;
        fanPagesArr = nullptr;
        statusArr = nullptr;
        //Bday is already has been created by its def ctor
    }

    User(const char * name, int day, int month, int year):numOfFriends(0),friendsArrPhySize(1), numOfFanPages(0), fanPagesArrPhySize(1),numOfStatus(0),statusArrPhySize(1)
    {
        birthday = Date(day, month, year);
        int len = strlen(name);
        this->name = new char[len+1];
        strcpy(this->name,name);
        this->name[len] = '\0';
        friendsArr = new User*[friendsArrPhySize];
        friendsArr[0] = nullptr;
        fanPagesArr = new FanPage * [fanPagesArrPhySize];
        fanPagesArr[0] = nullptr;
        statusArr = new Status*[statusArrPhySize];
        statusArr[0] = nullptr;
    }

    void addStatus(Status * stat);

    void printStatuses()
    {
        for(int i=0; i < numOfStatus; i++)
        {
            cout <<"Status number: " <<i +1<<"\n"<<endl;
            this->statusArr[i]->printStatus();
        }
    }

    void addFriend(User * newFan);

    bool isFriend(User* user);

    void printUser();

    void printFriends();
    void printMyFriendsStatuses();
    
    void printLastTenStat();

    void removeFriend(const char * fToRemove);

    void likePage(FanPage * pageToLike);

    void unlikePage(char * fpToUnlike);

    char * getName()
    {
        return name;
    }
    ~User()
    {      
        delete[]name;

        if (friendsArr != nullptr)
        {
            delete[]friendsArr;
        }
        if (fanPagesArr != nullptr)
        {
            delete[]fanPagesArr;
        }
        if (statusArr != nullptr)
        {
            for(int i=0;i<numOfStatus;i++)
            {
                delete statusArr[i];
            }
            delete[]statusArr;
        }      
    }

};



#endif //PROJECT1_USER_H
