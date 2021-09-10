#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, ll> hmap;

    for (int i = 0; i < n; i++)
    {
        if (hmap.find(a[i] - 1) == hmap.end())
            hmap[a[i]]++;

        else
        {
            hmap.erase(a[i] - 1);
            hmap[a[i]]++;
        }
    }

    cout << hmap.size() << "\n";

    return 0;
}
