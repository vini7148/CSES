// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll t;
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        ll a, b;
        cin >> a >> b;

        ll s = a + b;
        if (s % 3)
        {
            cout << "NO\n";

            // return 0;

            continue;
        }

        s /= 3;

        if (s <= min(a, b))
            cout << "YES\n";

        else
            cout << "NO\n";
    }
}