#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    vector<pair<ll, pair<ll, ll> > > a;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        a.push_back(make_pair(x, make_pair(1, i)));
        a.push_back(make_pair(y, make_pair(-1, i)));
    }

    sort(a.begin(), a.end());

    vector<ll> ans(n);
    

