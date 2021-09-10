#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    set<ll> pt;

    pt.insert(0);
    pt.insert(n);

    multiset<ll> len;

    len.insert(n);

    while (k--)
    {
        ll tmp;
        cin >> tmp;

        auto it = pt.upper_bound(tmp);

        ll lf = *prev(it);
        ll rt = *it;

        len.erase(len.find(rt - lf));

        len.insert(tmp - lf);
        len.insert(rt - tmp);

        pt.insert(it, tmp);

        cout << *len.rbegin() << " ";
    }

    cout << "\n";

    return 0;
}

