#include "Status.h"

char* Status:: createTime()
{
	char* res;
	time_t curr_time;
	curr_time = time(NULL);
	char* tm = ctime(&curr_time);
	res = new char[strlen(tm)];
	return res;
}