// https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll grey(ll x)
{
    return x ^ (x >> 1);
}

void pri(ll n, ll a)
{
    for (unsigned ll i = 1 << a; i > 0; i /= 2)
        (n & i)? cout << "1": cout << "0";

    cout << "\n";
}

int main()
{
    ll n, a;
    cin >> a;
    n = 1 << a;

    for (int i = 0; i < n; i++)
    {
        pri(grey(i), a - 1);
    }
}