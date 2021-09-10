#include "array.h"
#include "quicksort.h"

ll binary_search(ll *a, ll n, ll k)
{
    ll st = 0, en = n - 1;

    while (st <= en)
    {
        ll mid = (st + en) / 2;

        if (a[mid] == k)
            return mid;

        else if (a[mid] < k)
            st = mid + 1;

        else 
            en = mid - 1;
    }

    return -1;
}

void test_binary()
{
    ll n = 10;
    ll *a = new ll[n];

    a = randomarray(n);

    quicksort(a, 0, n - 1);

    print_array(a, n);

    std::cout << binary_search(a, n, a[3]) << std::endl;
}