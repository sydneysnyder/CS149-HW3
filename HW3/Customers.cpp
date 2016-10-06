//
//  Customers.cpp
//  HW3
//
//  Created by Tyler Veeman on 10/4/16.
//  Copyright © 2016 TylerVeeman. All rights reserved.
//

#include "Customers.hpp"

typedef int stype;
#define H 1
#define M 2
#define L 3

class Customer
{
    public:
    int arrival_time;
    int id;
};

int getRand();

std::queue <Customer> fillQueue(int n, std::queue <Customer> q)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = getRand();
    }
    std::sort(temp, temp + n);
    for (int i = 0; i < n; i++)
    {
        Customer c;
        c.arrival_time = temp[i];
        q.push(c);
    }
    return q;
}

std::queue <Customer> getQueue(int n, stype t)
{
    std::queue <Customer> result;
    result = fillQueue(n, result);
    return result;
}

int getRand()
{
    srand(time(NULL));
    return rand() % 100;
}
