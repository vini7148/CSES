// https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
	ll n, su = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        su += a[i];
    }

    vector<ll> dp(su + 1, 0);

    for (int i = 0; i <= su; i++)
    {
        for (int x = 0; x < n; x++)
        {
            if (a[x] <= i)
            {
                dp[i] = max(dp[i], dp[i - a[x]] + a[x]);
            }
        }
    }

    set<ll> ans;
    for (int i = 0; i <= su; i++)
    {
        ans.insert(dp[i]);
    }

    cout << ans.size() - 1 << "\n";
    for (auto x : ans)
    {
        if (x != 0)
            cout << x << " ";
    }
    cout << "\n";
}
