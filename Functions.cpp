#include "Functions.h"
using namespace std;
char* getString()
{
	char array[MAX_SIZE];
	
	char ch;
	cin >> ch;
	int index = 0;
	while (ch!=(int)'\n')
	{
		array[index] = ch;
		cin >> ch;
		index++;
	}
	array[index] = '\0';
	cin.getline(array,MAX_SIZE);

	return array;
}
void freeString(char* array)
{
	delete[]array;
}