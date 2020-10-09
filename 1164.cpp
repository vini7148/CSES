// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> a;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, make_pair(-1, i)));
        a.push_back(make_pair(y, make_pair(1, i)));
    }

    ll ans = 0, curr = 0, io, ind;

    sort(a.begin(), a.end());

    vector<ll> rooms;
    
    ll rno[200005];
    
    for (auto x : a)
    {
        io = x.second.first;
        ind = x.second.second;

        if(io == 1)
        {
            rooms.push_back(rno[ind]);
        }
        else if (curr == rooms.size())
        {
            rno[ind] = ++ans;
        }
        else
        {
            rno[ind] = rooms[curr++];
        }
    }

    cout << ans << "\n";

    for (ll i = 1; i <= n; i++)
    {
        cout << rno[i] << " ";
    }
}