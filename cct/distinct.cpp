#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    map<ll, ll> hmap;

    while (n--)
    {
        ll tmp;
        cin >> tmp;
        hmap[tmp]++;
    }

    cout << hmap.size() << "\n";

    return 0;
}
