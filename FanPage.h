#ifndef PROJECT1_FANPAGE_H
#define PROJECT1_FANPAGE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Functions.h"
#include "Status.h"

using namespace std;

class User;

class FanPage
{
    char * name;
    User ** fansArr;
    int numOfFans, fansArrPhySize;
    Status ** statusArr;
    int numOfStatus,statusArrPhySize;

public:
    FanPage():numOfFans(0),fansArrPhySize(0),numOfStatus(0),statusArrPhySize(0)
    {
        cout<<"def ctor used"<<endl;
        name = nullptr;
        fansArr = nullptr;
        statusArr= nullptr;
    }

    FanPage(const char * name): numOfFans(0),fansArrPhySize(1),numOfStatus(0),statusArrPhySize(1)
    {
        int len = strlen(name);
        this->name = new char[len+1];
        strcpy(this->name,name);
        this->name[len] = '\0';
        fansArr = new User*[fansArrPhySize];
        fansArr[0] = nullptr;
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
    void printPage()
    {
        cout << name << endl;
    }
    void addFan(User * newFan);
    bool isFan(User* user);
    void printFans();

    void removeFan(const char * fToRemove);
       
    char* getName()
    {
        return this->name;
    }

    ~FanPage()
    {
        delete[]name;
        if(fansArr != nullptr)
        {
            delete[]fansArr;
        }

        if(statusArr != nullptr)
        {
            delete[]statusArr;

        }
    }



};




#endif //PROJECT1_FANPAGE_H
