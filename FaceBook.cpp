#include "FaceBook.h"
void FaceBook::initiate()
{
	while (choice != 12)
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			//addfriend
			this->addingUserToFaceBook();
			break;
		}
		case 2:
		{
			//add fan page
			this->addingPageToFaceBook();
			break;
		}
		case 3:
		{
			//adding status to a user/fan page
			int choosing = 0;
			while (choosing!=1 && choosing != 2)
			{
				cout << "Enter 1 if you want to add status to a user" << endl;
				cout << "Enter 2 if you want to add status to a fan page" << endl;
				cin >> choosing;
				switch (choosing)
				{
				case 1:
					this->addStatusToUser();
					break;	
				case 2:
					this->addStatusToFanPage();
						break;
				default:
					cout << "Re-enter your choice" << endl;
					break;
				}
			}		
			break;
		}
		case 4:
		{
			//printing all the friend's/fan page's statuses
			int choosing = 0;
			while (choosing != 1 && choosing != 2)
			{
				cout << "Enter 1 if you want to print all the statuses of a user" << endl;
				cout << "Enter 2 if you want to print all the statuses of a fan page" << endl;
				cin >> choosing;
				switch (choosing)
				{
				case 1:
					this->printUserStatuses();
					break;
				case 2:
					this->printFanPagesStatuses();
					break;
				default:
					cout << "Re-enter your choice" << endl;
					break;
				}
			}
			break;
		}
		case 5:
		{
			//printing the last 10 statuses of a specific user's friends
			printingLastTenStatusesOfMyFriedns();
			break;
		}
		case 6:
		{
			//making 2 users to be friends
			createFriendship();
			break;
		}
		case 7:
		{
			//cancelling friendship
			cancellingFriendship();
			break;
		}
		case 8:
		{
			//adding fan to a fan page
			addingFanToFanPage();
			break;
		}
		case 9:
		{
			//remove fan from fan page
			removeFanFromFanPage();
			break;
		}
		case 10:
		{
			//printing all the object that on FaceBook
			printAllObjects();
			break;
		}
		case 11:
		{
			//printing all someone's friends/page's followers
			int choosing = 0;
			while (choosing != 1 && choosing != 2)
			{
				cout << "Enter 1 if you want to print someone's friedns" << endl;
				cout << "Enter 2 if you want to print page's fans" << endl;
				cin >> choosing;
				switch (choosing)
				{
				case 1:
					this->printUserFriends();
					break;
				case 2:
					this->printPageFans();
					break;
				default:
					cout << "Re-enter your choice" << endl;
					break;
				}
			}
			break;
		}
		case 12:
		{
			//exiting from FaceBook
			cout << "Bye Bye" << endl;
			exit(1);
			break;
		}
		default:
			cout << "The choice you entered is not legitimate, please enter another one" << endl;
			break;
		}

	}
}
void FaceBook::printMenu()
{
	cout << "Hi, Welcome to FaceBook! " << endl;
	cout << "Please enter number between 1-12 " << endl;
	cout << "Enter 1 for addind a user to the system" << endl;
	cout << "Enter 2 for addind a fan page to the system" << endl;
	cout << "Enter 3 for addind a status to a friend/fan page" << endl;
	cout << "Enter 4 for printing all friend's/fan page's statuses" << endl;
	cout << "Enter 5 for printing the last 10 statuses for all the friedns of specific user" << endl;
	cout << "Enter 6 for making 2 users to be friends" << endl;
	cout << "Enter 7 for cancelling friednship between 2 friends" << endl;
	cout << "Enter 8 for adding fan to a fan page" << endl;
	cout << "Enter 9 for removing fan from a fan page" << endl;
	cout << "Enter 10 for printing all the object that are on FaceBook" << endl;
	cout << "Enter 11 for showing someon's friedns/page's fans" << endl;
	cout << "Enter 12 for exiting" << endl;
}
void FaceBook::addingUserToFaceBook()
{
	char *name=new char[maxNameLen];
	int day, month, year;
	cout << "Please enter user's data(name, day of birth,month of birth,year of birth)" << endl;
	cin.getline(name,maxNameLen);
	cin>> day >> month >> year;
	User* user;
	user = new User(name,day,month,year);
	//checking the array's size and coping the new user into it
	if (numOfUsers == usersArrPhySize)
	{
		usersArrPhySize *= 2;
		this->usersArr = userArrMyRealloc(this->usersArr, numOfUsers, usersArrPhySize);
	}
	this->usersArr[numOfUsers] = user;
	numOfUsers++;
}
void FaceBook::addingPageToFaceBook()
{
	char* name = new char[maxNameLen];
	cout << "Please enter page's name" << endl;
	cin.getline(name, maxNameLen);
	FanPage* page;
	page = new FanPage(name);
	//checking the array's size and coping the new user into it
	if (numOfFanPages == fanPagesArrPhySize)
	{
		numOfFanPages *= 2;
		this->fanPagesArr = fanPagesArrmyRealloc(this->fanPagesArr, numOfFanPages, fanPagesArrPhySize);
	}
	this->fanPagesArr[numOfFanPages] = page;
	numOfFanPages++;
}
void FaceBook::addStatusToUser()
{
	printAllUsers();
	char* name = new char[maxNameLen];
	cout << "Please enter the user's name:" << endl;
	cin.getline(name,maxNameLen);
	User* found=searchUser(name);
	if (found==nullptr)
	{
		cout << "No such user" << endl;
	}
	else
	{
		cout << "Enter data for the new status" << endl;
		char* data = new char[maxNameLen];
		cin.getline(data, maxNameLen);
		Status* status=new Status(data);
		found->addStatus(status);
	}

}
void FaceBook::addStatusToFanPage()
{
	printAllFanPages();
	char* pageName = new char[maxNameLen];
	cout << "Please enter the page's name:" << endl;
	cin.getline(pageName, maxNameLen);
	FanPage* found = searchFanPage(pageName);
	if (found == nullptr)
	{
		cout << "No such page" << endl;
	}
	else
	{
		cout << "Enter data for the new status" << endl;
		char* data = new char[maxNameLen];
		cin.getline(data, maxNameLen);
		Status* status = new Status(data);
		found->addStatus(status);
	}

}
void FaceBook::printAllUsers()
{
	cout << "These are all the system's users:" << endl;
	for (int i = 0; i < numOfUsers; i++)
	{
		usersArr[i]->printUser();
	}
}
void FaceBook::printAllFanPages()
{
	cout << "These are all the system's fan pages:" << endl;
	for (int i = 0; i < numOfFanPages; i++)
	{
		fanPagesArr[i]->printPage();
	}
}
User* FaceBook::searchUser(char* name)
{
	bool found = false;
	User* res = nullptr;
	for (int i = 0; i <numOfUsers&&!found; i++)
	{
		if (strcmp(usersArr[i]->getName(),name)==0)
		{
			found = true;
			res = usersArr[i];
		}
	}
	return res;
}
FanPage* FaceBook::searchFanPage(char* name)
{
	bool found = false;
	FanPage* res = nullptr;
	for (int i = 0; i < numOfFanPages && !found; i++)
	{
		if (strcmp(fanPagesArr[i]->getName(), name) == 0)
		{
			found = true;
			res = fanPagesArr[i];
		}
	}
	return res;
}
void FaceBook::printUserStatuses()
{
	printAllUsers();
	char* name = new char[maxNameLen];
	cout << "Please enter the user's name:" << endl;
	cin.getline(name, maxNameLen);
	User* found = searchUser(name);
	if (found == nullptr)
	{
		cout << "No such user" << endl;
	}
	else
	{
		found->printStatuses();
	}
}
void FaceBook::printFanPagesStatuses()
{
	printAllFanPages();
	char* pageName = new char[maxNameLen];
	cout << "Please enter the page's name:" << endl;
	cin.getline(pageName, maxNameLen);
	FanPage* found = searchFanPage(pageName);
	if (found == nullptr)
	{
		cout << "No such page" << endl;
	}
	else
	{
		found->printStatuses();
	}
}
void FaceBook::printingLastTenStatusesOfMyFriedns()
{
	printAllUsers();
	char* name = new char[maxNameLen];
	cout << "Please enter the user's name:" << endl;
	cin.getline(name, maxNameLen);
	User* found = searchUser(name);
	if (found == nullptr)
	{
		cout << "No such user" << endl;
	}
	else
	{
		found->printMyFriendsStatuses();
	}

}
void FaceBook::createFriendship()
{
	printAllUsers();
	cout << "Enter 2 names of users that will be frieds" << endl;
	char* firstUserName = new char[maxNameLen];
	char* secondUserName = new char[maxNameLen];
	cin.getline(firstUserName, maxNameLen);
	cin.getline(secondUserName, maxNameLen);
	User* firstUser = searchUser(firstUserName);
	User* secondUser = searchUser(secondUserName);
	if (firstUser == nullptr||secondUser == nullptr)
	{
		cout << "At least one of the users is not exist" << endl;
	}
	else
	{
		firstUser->addFriend(secondUser);
		secondUser->addFriend(firstUser);
	}

}
void FaceBook::cancellingFriendship()
{
	printAllUsers();
	cout << "Enter the user's name that you want to delete friend from" << endl;
	char* userName = new char[maxNameLen];
	cin.getline(userName, maxNameLen);
	User* user=searchUser(userName);
	if (user != nullptr)
	{
		cout << "Enter the friend's name that you want to delete from the friends list" << endl;
		user->printFriends();
		char* userToDelete = new char[maxNameLen];
		cin.getline(userToDelete, maxNameLen);
		user->removeFriend(userToDelete);
		User* secondUser = searchUser(userToDelete);
		secondUser->removeFriend(userName);
	}
	else
	{
		cout << "No such user" << endl;
	}

}
void FaceBook::addingFanToFanPage()
{
	printAllFanPages();
	cout << "Enter name of a fan page" << endl;
	char* fanPageName = new char[maxNameLen];
	cin.getline(fanPageName, maxNameLen);
	FanPage* page = searchFanPage(fanPageName);
	if (page==nullptr)
	{
		cout << "Fan page does not exist" << endl;

	}
	else
	{
		printAllUsers();
		cout << "Enter name of a user" << endl;
		char* userName = new char[maxNameLen];
		cin.getline(userName, maxNameLen);
		User* user = searchUser(userName);
		if (user == nullptr)
		{
			cout << "User does not exist" << endl;
		}
		else
		{
			page->addFan(user);
		}
	}
	

}
void FaceBook::removeFanFromFanPage()
{
	printAllFanPages();
	cout << "Enter the page's name that you want to delete fan from" << endl;
	char* pageName = new char[maxNameLen];
	cin.getline(pageName, maxNameLen);
	FanPage* page = searchFanPage(pageName);
	if (page != nullptr)
	{
		cout << "Enter user's name that you want to delete from fans list" << endl;
		page->printFans();
		char* userToRemove = new char[maxNameLen];
		cin.getline(userToRemove, maxNameLen);
		page->removeFan(userToRemove);
		User* user = searchUser(userToRemove);
		user->unlikePage(pageName);
	}
	else
	{
		cout << "No such fan page" << endl;
	}


}
void FaceBook::printAllObjects()
{
	cout << "The users are: " << endl;
	printAllUsers();
	cout << "The fan pages are: " << endl;
	printAllFanPages();
}
void FaceBook::printUserFriends()
{
	printAllUsers();
	cout << "Enter the user you want to print all his friends" << endl;
	char* name = new char[maxNameLen];
	cin.getline(name, maxNameLen);
	User* user =searchUser(name);
	if (user!=nullptr)
	{
		user->printFriends();
	}
	else
	{
		cout << "No such user" << endl;
	}
}
void FaceBook::printPageFans()
{
	printAllFanPages();
	cout << "Enter the page that you want to print all his fans" << endl;
	char* name = new char[maxNameLen];
	cin.getline(name, maxNameLen);
	FanPage* page = searchFanPage(name);
	if (page != nullptr)
	{
		page->printFans();
	}
	else
	{
		cout << "No such page" << endl;
	}
}
