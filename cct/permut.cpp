#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << "\n";

        return 0;
    }

    if (n == 2 || n == 3) 
    {
        cout << "NO SOLUTION\n";

        return 0;
    }

    if (n == 4)
    {
        cout << "2 4 1 3\n";
        return 0;
    }

    ll en = 1;

    if (n&1)
    {
        en = 0;
    }

    ll st = n;

    while (st > en)
    {
        cout << st << " ";
        st -= 2;
    }

    en = (st&1)?1: 0;

    st = n - 1;
    while (st > en)
    {
        cout << st << " ";
        st -= 2;
    }

    cout << "\n";

    return 0;
}