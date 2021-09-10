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
        ll tmp;
        cin >> tmp;
        ti.push_back(make_pair(tmp, 1));

        cin >> tmp;
        ti.push_back(make_pair(tmp, -1));
    }

    ll ans = INT_MIN, curr = 0;

    sort(ti.begin(), ti.end());

    for (auto x: ti)
    {
        curr += x.second;
        ans = max(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}

