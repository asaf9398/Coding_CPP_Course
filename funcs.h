//
// Created by עידו הירשמן on 23/11/2022.
//

#ifndef PROJECT1_FUNCS_H
#define PROJECT1_FUNCS_H
#include <iostream>
using namespace std;
class Status;
class User;

// some useable funcs

User ** userArrMyRealloc(User ** arr, int currSize,int newSize);

Status ** statusArrMyRealloc(Status ** arr, int currSize,int newSize);


#endif //PROJECT1_FUNCS_H
