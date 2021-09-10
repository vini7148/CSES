#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll> > ti;

    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        ti.push_back(make_pair(y, x));
    }

    sort (ti.begin(), ti.end());

    ll ans = 1;
    ll curr = ti[0].first;

    for (int i = 1; i < ti.size(); i++)
    {
        if (ti[i].second >= curr)
        {
            ans++;
            curr = ti[i].first;
        }
    }
    
    cout << ans << "\n";

    return 0;
}
