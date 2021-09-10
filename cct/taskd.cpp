#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll> > a;

    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y) );
    }

    sort(a.begin(), a.end());

    ll ti = 0;
    ll ans = 0;

    for (auto x: a)
    {
        ti += x.first;
        ans += x.second - ti;
    }

    cout << ans << "\n";

    return 0;
}
