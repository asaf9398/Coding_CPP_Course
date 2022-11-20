
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;
//enum statusType{TEXT,IMG,VIDEO};

class Status
{
	//statusType type;
	//date
	//time
	//data
	char* data;
	const int defStatusSize = 1;
	int statusSize;
	char* statusTime;

public:

	Status()
	{
		data = new char[defStatusSize];
		statusSize = defStatusSize-1;
		data[0] = '\0';
		statusTime = createTime();
	}


	Status(char * data)
	{
		statusSize = strlen(data);
		data = new char[statusSize+1];
		strcpy(this->data, data);
		this->data[statusSize] = '\0';
		statusTime = createTime();
	}
	
	char * getStatusData()
	{
		return this->data;
	}

	char* getStatusTime()
	{
		return this->statusTime;
	}
	Status* getStatus()
	{
		return this;
	}

	void printStatus()
	{
		cout << this->data << "Date and Time: " << this->statusTime << endl;
	}


private:
	char* createTime();
};

