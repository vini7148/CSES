#pragma once 

#include "array.h"

ll partition_rand(ll *a, ll l, ll h)
{
    ll pvt = l + rand() % (h - l + 1);

    swap(&a[h], &a[pvt]);

    ll ind = l;
    pvt = h;

    for (ll i = l; i < h; i++)
    {
        if (a[i] < a[pvt])
        {
            swap(&a[i], &a[ind]);
            ind++;
        }
    }

    swap(&a[ind], &a[pvt]);

    return ind;
}

void quicksort(ll *a, ll l, ll h)
{
    if (l < h)
    {
        ll j = partition_rand(a, l, h);

        quicksort(a, l, j - 1);
        quicksort(a, j + 1, h);
    }
}

void test_quicksort()
{
    ll n = 10;
    ll *a = randomarray(n);

    quicksort(a, 0, n - 1);

    print_array(a, n);
}