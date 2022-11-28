#include "User.h"
#include "FanPage.h"

class FanPage;
void User :: addStatus(Status* stat)
{
    if(numOfStatus == statusArrPhySize)
    {
        statusArrPhySize*=2;
        this->statusArr =  statusArrMyRealloc(this->statusArr,numOfStatus,statusArrPhySize);
    }

    this-> statusArr[numOfStatus] = stat;
    numOfStatus++;
}
void User::printMyFriendsStatuses()
{
    for (int i = 0; i < numOfFriends; i++)
    {
        cout << "The statuses of " << friendsArr[i]->getName() << endl;
        friendsArr[i]->printLastTenStat();
    }
}
void User::printLastTenStat()
{
    for (int i = 0; i < 10 && i < numOfStatus; i++)
    {
        cout << "Status number: " << i + 1 << "\n" << endl;
        this->statusArr[i]->printStatus();
    }
}
void User :: removeFriend(const char * fToRemove)
{
    bool found = false;

    for(int i = 0; i < numOfFriends && !found ; i++)
    {
        if(strcmp(fToRemove, friendsArr[i]->getName()) == 0)
        {
            found = true;
            //found him!
            friendsArr[i] = friendsArr[numOfFriends-1];
            friendsArr[numOfFriends-1] = nullptr;
            numOfFriends--;
        }
    }
    if(!found)
    {
        cout << "friend not found!!"<<endl;
    }
    if(numOfFriends == friendsArrPhySize/2 && numOfFriends!=0)
    {
        this-> friendsArr = userArrMyRealloc(this->friendsArr,numOfFriends,numOfFriends);
    }
}

void User ::addFriend(User *user)
{
    bool flag = isFriend(user);
    if (!flag)
    {
        if (numOfFriends == friendsArrPhySize)
        {
            friendsArrPhySize *= 2;
            this->friendsArr = userArrMyRealloc(this->friendsArr, numOfFriends, friendsArrPhySize);
        }

        this->friendsArr[numOfFriends] = user;
        numOfFriends++;
    }
}

void User ::printFriends()
{
    if(numOfFriends==0)
    {
        cout<<"no friends "<< endl;
    }
    else
    {
        for(int i = 0; i < numOfFriends;i++)
        {
            this ->friendsArr[i]->printUser();
        }
    }
}

void User :: likePage(FanPage* pageToLike)
{
    if (numOfFanPages == fanPagesArrPhySize)
    {
        fanPagesArrPhySize *= 2;
        this->fanPagesArr = fanPagesArrmyRealloc(this->fanPagesArr, numOfFanPages, fanPagesArrPhySize);
    }

    this->fanPagesArr[numOfFanPages] = pageToLike;
    numOfFanPages++;
}

void User :: unlikePage(char* fpToUnlike)
{
    bool found = false;

    for (int i = 0; i < numOfFanPages && !found; i++)
    {
        if (strcmp(fpToUnlike, fanPagesArr[i]->getName()) == 0)
        {
            found = true;
            //found him!
            fanPagesArr[i] = fanPagesArr[numOfFanPages - 1];
            fanPagesArr[numOfFanPages - 1] = nullptr;
            numOfFanPages--;
        }
    }
    if (!found)
    {
        cout << "page not found!!" << endl;
    }
    if (numOfFanPages == fanPagesArrPhySize / 2 && numOfFanPages != 0)
    {
        this->fanPagesArr = fanPagesArrmyRealloc(this->fanPagesArr, numOfFanPages, numOfFanPages);
    }
}


void User :: printUser()
{
    cout<< this->name <<endl;
}

bool User::isFriend(User* user)
{
    bool found = false;
    
    for (int i = 0; i < numOfFriends && !found; i++)
    {
        if (strcmp(friendsArr[i]->getName(), user->getName()) == 0)
        {
            found = true;
  
        }
    }
    return found;
}