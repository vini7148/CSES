// https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        if(i == 1)
            cout << 0 << "\n";
        else if(i == 2)
            cout << 6 << "\n";
        else
        {
            ll p = i * i;
            ll j = i - 2, k = p * (p - 1) / 2;
            k -= 8 * j * (j + 1) / 2;
            cout << k << "\n";
        }
    }
}