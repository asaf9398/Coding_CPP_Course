#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Functions.h"
using namespace std;

int main()
{
	char* str = getString();
	cout << "The status is: " << endl;
	Status status = Status(str);
	status.getStatusData();
	status.getStatusTime();
	status.printStatus();
	



}

