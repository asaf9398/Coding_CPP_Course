//
// Created by עידו הירשמן on 23/11/2022.
//

#include "FanPage.h"
#include "User.h"

void FanPage :: addStatus(Status* stat)
{
    if(numOfStatus == statusArrPhySize)
    {
        statusArrPhySize*=2;
        this->statusArr =  statusArrMyRealloc(this->statusArr,numOfStatus,statusArrPhySize);
    }

    this-> statusArr[numOfStatus] = stat;
    numOfStatus++;
}

void FanPage :: removeFan(const char * fToRemove)
{
    bool found = false;

    for(int i = 0; i < numOfFans && !found ; i++)
    {
        if(strcmp(fToRemove, fansArr[i]->getName()) == 0)
        {
            found = true;
            //found him!
            fansArr[i] = fansArr[numOfFans-1];
            fansArr[numOfFans-1] = nullptr;
             numOfFans--;
        }
    }
    if(!found)
    {
        cout << "fan not found!!"<<endl;
    }
    if(numOfFans == fansArrPhySize/2 && numOfFans!=0)
    {
        this-> fansArr = userArrMyRealloc(this->fansArr,numOfFans,numOfFans);
    }
}

void FanPage :: addFan(User * newFan)
{
    bool flag = isFan(newFan);
    if (!flag)
    {
    if(numOfFans == fansArrPhySize)
    {
        fansArrPhySize*=2;
        this-> fansArr = userArrMyRealloc(this->fansArr,numOfFans,fansArrPhySize);
    }

    this-> fansArr[numOfFans] = newFan;
    numOfFans++;
    }
}

void FanPage :: printFans()
{
    if (numOfFans == 0)
    {
        cout << "no fans!" << endl;
    }
    else
    {

    for(int i = 0; i < numOfFans;i++)
        {
            (this ->fansArr[i])->printUser();
        }
    }
     
}

bool FanPage::isFan(User* user)
{
    bool found = false;
  
    for (int i = 0; i < numOfFans && !found; i++)
    {
        if (strcmp(fansArr[i]->getName(), user->getName()) == 0)
        {
            found = true;
        }
    }
    return found;
}

