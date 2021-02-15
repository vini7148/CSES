// https://cses.fi/problemset/task/1643/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // sort(a.begin(), a.end());

    ll ma = a[0], curr = a[0];
    for (ll i = 1; i < n; i++)
    {
        curr = max(curr + a[i], a[i]);
        ma = max(ma, curr);
    }

    cout << ma << "\n";
}