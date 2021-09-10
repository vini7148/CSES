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
    ll ans = 0, curr = 0;

    ll i = 0, j = 0;

    while (i < n)
    {
        if (hmap.find(a[i]) == hmap.end() || hmap[a[i]] == 0)
        {
            curr++;
            hmap[a[i]]++;
            i++;
            ans = max(ans, curr);
        }
        else
        {
            curr--;
            hmap[a[j]]--;
            j++;
        }
    }

    cout << ans << "\n";
    return 0;
}

