// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ma = INT_MAX;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        if (ma < a[i].second)
            ma = a[i].second;
    }

    sort(a.begin(), a.end());

    ll ans = 0, j = 0;

    for (ll i = 0; i < a.size(); i++)
    {
        j += a[i].first;
        ans += a[i].second - j;
    }

    cout << ans << "\n";
}