#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    multiset<ll, greater<ll> > ss;

    while (n--)
    {
        ll tmp;
        cin >> tmp;
        ss.insert(tmp);
    }

    while (m--)
    {
        ll tmp;
        cin >> tmp;

        auto pt = ss.lower_bound(tmp);

        if (pt == ss.end())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << *pt << "\n";
            ss.erase(pt);
        }
    }

    return 0;
}

