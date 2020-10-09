// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> time;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        time.push_back(make_pair(y, x));
    }

    sort(time.begin(), time.end());

    ll curr = 0, ans = 0;

    for (auto ele : time)
    {
        if (ele.second >= curr)
        {
            curr = ele.first;
            ans++;
        }
    }

    cout << ans << "\n";
}