// https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, t, ma = INT_MIN, mi = INT_MAX;
    cin >> n >> t;
    vector<ll> k(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> k[i];
    
        if (ma < k[i])
            ma = k[i];
    
        if (mi > k[i])
            mi = k[i];
    }

    // sort(k.begin(), k.end());

    // find a time such that sumof(time / a[i]) >= t
    ll l = 0, r = ma * t + 1, ans = -1, curr = 0, mid = 0;

    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        curr = 0;
        for (ll i = 0; i < n; i++)
        {
            curr += mid / k[i];
        }

        if (curr >= t)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
    
}