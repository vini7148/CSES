// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, m;

    cin >> n >> m;

    multiset<ll, greater<ll>> h;

    while(n--)
    {
        ll temp;
        cin >> temp;
        h.insert(temp);
    }

    while(m--)
    {
        ll temp;
        cin >> temp;

        auto it = h.lower_bound(temp);
        if(it == h.end())
        {
            cout << "-1\n";
        }
        else
        {
            cout << *it << "\n";
            h.erase(it);
        }
    }
}