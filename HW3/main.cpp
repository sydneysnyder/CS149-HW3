//
//  main.cpp
//  HW3
//
//  Created by Tyler Veeman on 9/29/16.
//  Copyright © 2016 TylerVeeman. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include "Customers.hpp"
#include "Seats.hpp"

typedef int stype;
#define H 1
#define M 2
#define L 3

int qSize = 15;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// seller thread to serve one time slice (1 minute)
void * sell(void *seller_type)
{
    stype type;
    type = *(int *)seller_type;
    std::queue <Customer> q;
    q = getQueue(qSize);
    
    While (!q.empty())
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        
        pthread_mutex_unlock(&mutex);
        // Serve any buyer available in this seller queue that is ready
        // now to buy ticket till done with all relevant buyers in their queue ..................
    }
    return NULL; // thread exits
}

void wakeup_all_seller_threads()
{
    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);
}

int main()
{
    int i;
    pthread_t tids[10];
    stype Seller_type;
    // Create necessary data structures for the simulator.
    // Create buyers list for each seller ticket queue based on the // N value within an hour and have them in the seller queue.
    
    // Create 10 threads representing the 10 sellers.
    Seller_type = H;
    pthread_create(&tids[0], NULL, sell, &Seller_type);
    
    Seller_type = M;
    for (i = 1; i < 4; i++)
    {
        pthread_create(&tids[i], NULL, sell, &Seller_type);
    }
    
    Seller_type = L;
    for (i = 4; i < 10; i++)
    {
        pthread_create(&tids[i], NULL, sell, &Seller_type);
    }
    
        // wakeup all seller threads
        wakeup_all_seller_threads();
    
        // wait for all seller threads to exit
        for (i = 0 ; i < 10 ; i++)
        {
            pthread_join(tids[i], NULL);
        }
        // Printout simulation results
    //add code here
        exit(0);
}
