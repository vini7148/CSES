// https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, bool>> time;

    while(n--)
    {
        ll st, en;

        cin >> st >> en;

        time.push_back(make_pair(st, true));
        time.push_back(make_pair(en, false));
    }

    sort(time.begin(), time.end());

    ll ans = 0, curr = 0;

    for (int i = 0; i < time.size(); i++)
    {
        curr += time[i].second ? 1 : -1;
        ans = max(ans, curr);
    }

    cout << ans << "\n";
}