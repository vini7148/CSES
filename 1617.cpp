// https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>

#define ll long long 
#define LIMIT 1000000007

using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll ans = 1;

    for (ll i = 0; i < n; i++)
    {
        ans *= 2;

        ans %= LIMIT;
    }

    cout << ans << "\n";
}