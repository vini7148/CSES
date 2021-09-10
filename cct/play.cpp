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

    ll i = 0, j = 0;

    ll ans = 0, si = 0;

    map<int, int> hmap;
    while (j < n)
    {
        if (hmap.find(a[j]) == hmap.end() || hmap[a[j]] == 0)
        {
            hmap[a[j]]++;
            si++;
            j++;

            ans = max(ans, si);
        }

        else
        {
            hmap[a[i]] = 0;
            i++;
            si--;
        }
    }

    cout << ans << "\n";

    return 0;
}
