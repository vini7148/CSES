#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        ll comp = t - a[i];
        map<ll, ll> hmap;

        for (int j = i + 1; j < n; j++)
        {
            ll comp2 = comp - a[j];

            if (hmap[comp2]) // hmap.find(comp2) != hmap.end()) // this is log(n) TC
            {
                cout << i + 1 << " " << j + 1 << " " << hmap[comp2] + 1 << "\n";

                return 0;
            }
            hmap[a[j]] = j;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
