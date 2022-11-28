
#ifndef PROJECT1_FUNCTIONS_H
#define PROJECT1_FUNCTIONS_H
#include <iostream>
using namespace std;
class Status;
class User;
class FanPage;
// some useable funcs

User** userArrMyRealloc(User** arr, int currSize, int newSize);

Status** statusArrMyRealloc(Status** arr, int currSize, int newSize);

FanPage** fanPagesArrmyRealloc(FanPage** arr, int currSize, int newSize);

#endif //PROJECT1_FUNCTIONS_H
