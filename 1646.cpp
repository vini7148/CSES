// https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
	ll n, q, su = 0;
    cin >> n >> q;
    vector<ll> a(n), pre(n + 1, 0);
    if (n)
        pre[0] = su;
    
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        su += a[i];
        pre[i + 1] = su;
    }

    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        cout << pre[y] - pre[x - 1] << "\n";
    }
}
