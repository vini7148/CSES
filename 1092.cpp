// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll su = (n * (n + 1)) / 2;

    if (su & 1)
    {
        cout << "NO\n";
        return 0;
    }

    su /= 2;

    vector<ll> l, r;

    for (ll i = n; i > 0; i--)
    {
        if (i <= su)
        {
            su -= i;
            l.push_back(i);
        }
        else
        {
            r.push_back(i);
        }
    }

    cout << "YES\n";

    cout << l.size() << "\n";
    for (ll i = 0; i < l.size(); i++)
        cout << l[i] << " ";
    cout << "\n";

    cout << r.size() << "\n";
    for (ll i = 0; i < r.size(); i++)
        cout << r[i] << " ";
    cout << "\n";

    return 0;
}