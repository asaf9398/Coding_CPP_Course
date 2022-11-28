//
// Created by עידו הירשמן on 23/11/2022.
//

#include "funcs.h"

User ** userArrMyRealloc(User ** arr, int currSize,int newSize)
{
    User ** newArr = new User*[newSize];

    for(int i =0; i<currSize;i++)
    {
        newArr[i]= arr[i];
    }

    delete[] arr;
    return newArr;
}

Status **  statusArrMyRealloc(Status ** arr, int currSize,int newSize)
{
    Status ** newArr = new Status*[newSize];

    for(int i =0; i<currSize;i++)
    {
        newArr[i]= arr[i];
    }

    delete[] arr;
    return newArr;
}