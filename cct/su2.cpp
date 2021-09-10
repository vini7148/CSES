#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> tt(n);

    for (unsigned int i = 0; i < n; i++)
        cin >> tt[i];

    map<ll, ll> hmap;

    for (unsigned int i = 0; i < n; i++)
    {
        ll comp = k - tt[i];

        if (hmap.find(comp) != hmap.end())
        {
            cout << i + 1 << " " << hmap[comp] + 1 << "\n";
            return 0;
        }

        hmap[tt[i]] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
