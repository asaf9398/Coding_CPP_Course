#pragma once
#include "User.h";
#include "FanPage.h";

const int maxNameLen = 151;

class FaceBook
{
	User** usersArr;
	int numOfUsers, usersArrPhySize;
	FanPage** fanPagesArr;
	int numOfFanPages, fanPagesArrPhySize;
	int choice=0;
	FaceBook():numOfUsers(0), usersArrPhySize(1), numOfFanPages(0), fanPagesArrPhySize(1)
	{
		usersArr = new User*[usersArrPhySize];
		fanPagesArr = new FanPage*[fanPagesArrPhySize];
	}
public:
	void initiate();
	
private:
	void printMenu();
	void addingUserToFaceBook();
	void addingPageToFaceBook();
	void addStatusToUser();
	void addStatusToFanPage();
	void printAllUsers();
	void printAllFanPages();
	User* searchUser(char* name);
	FanPage* searchFanPage(char* name);
	void printFanPagesStatuses();
	void printUserStatuses();
	void printingLastTenStatusesOfMyFriedns();
	void createFriendship();
	void cancellingFriendship();
	void addingFanToFanPage();
	void removeFanFromFanPage();
	void printAllObjects(); 
	void printUserFriends();
	void printPageFans();



};

