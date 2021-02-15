// https://cses.fi/problemset/task/1158

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> p(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<ll> dp(x + 1);

    for (int i = 0; i <= n; i++)
    {
        for (int w = x; w > 0; w--)
        {
            if (p[i] <= w)
            {
                dp[w] = max(dp[w], dp[w - p[i]] + s[i]);
            }
        }
    }

    cout << dp[x] << "\n";
}