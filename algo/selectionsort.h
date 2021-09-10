// #pragma once

#include "array.h"

void selection_sort(ll *a, ll n)
{
    // ll n = sizeof(*a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        ll _min = a[i], ind = i;

        for (int j = i + 1; j < n; j++)
        {
            if (_min > a[j])
            {
                _min = a[j];
                ind = j;
            }
        }

        swap(&a[i], &a[ind]);
    }
}

void test_selectionsort()
{
    ll n = 10;
    ll *a = randomarray(n);

    selection_sort(a, n);

    print_array(a, n);
}