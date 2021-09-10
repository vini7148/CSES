#pragma once

#include "array.h"

void heapify(ll *a, ll i, ll n)
{
    ll _lar = i;
    
    ll l = 2 * i + 1;
    ll r = 2 * i + 2;

    if (l < n && a[l] > a[_lar])
        _lar = l;

    if (r < n && a[r] > a[_lar])
        _lar = r;

    if (_lar != i)
    {
        swap(&a[_lar], &a[i]);

        heapify(a, _lar, n);
    }
}

void heapsort(ll *a, ll n)
{
    for (ll i = n / 2 - 1; i > -1; i--)
        heapify(a, i, n);

    for (ll i = n - 1; i > -1; i--)
    {
        swap(&a[0], &a[i]);

        heapify(a, 0, i);
    }
}

void test_heapsort()
{
    ll n = 10;
    ll *a = randomarray(n);

    heapsort(a, n);

    print_array(a, n);
}