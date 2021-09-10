#pragma once 

#include <cstdlib>
#include <iostream>
#include <climits>

#define ll long long

void swap(ll *a, ll *b)
{
    ll tmp;

    tmp = *a;
    
    *a = *b;
    *b = tmp;
}

ll* randomarray(ll n, ll _max = 100)
{
    ll *a = new ll[n];

    for (ll i = 0; i < n; i++)
        a[i] = 1 + rand() % (_max - 1);

    return a;
}

void print_array(ll *a, ll n)
{
    for (ll i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}