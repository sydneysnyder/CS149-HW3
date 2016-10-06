//
//  Customers.cpp
//  HW3
//
//  Created by Tyler Veeman on 10/4/16.
//  Copyright © 2016 TylerVeeman. All rights reserved.
//

#include "Customers.hpp"

int getRand();

std::queue <int> fillQueue(int n, std::queue <int> q)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = getRand();
    }
    std::sort(temp, temp + n);
    for (int i = 0; i < n; i++)
    {
        int c = temp[i];
        q.push(c);
    }
    return q;
}

std::queue <int> getQueue(int n, int t)
{
    std::queue <int> result;
    result = fillQueue(n, result);
    return result;
}

int getRand()
{
    srand(time(NULL));
    return rand() % 100;
}
