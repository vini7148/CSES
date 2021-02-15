// https://cses.fi/problemset/task/1746 

#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr ll MOD = 1e9 + 7;

void solve()
{
    ll t = 1;
    bool tk_t = false;
    if (tk_t)
        cin >> t;

    while(t--)
    {
        // solution
        
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        vector<vector<ll> > dp(n, vector<ll>(m + 2));

        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;

        ll ans = 1, st = 0;

        for (int i = 0; i < n; i++)
        {
            if (i)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[st + 1][j] = dp[st][j];
                    dp[st + 1][j] += dp[st][j + 1] % MOD;
                    dp[st + 1][j] += dp[st][j - 1] % MOD;
                    dp[st + 1][j] %= MOD;
                }
                st++;
            }

            if (a[i])
            {
                ans *= dp[st][a[i]] % MOD;
                ans %= MOD;
                st = 0;
                for (int j = 0; j <= m; j++)
                    dp[st][j] = (j == a[i]);
            }
        }

        ans *= accumulate(dp[st].begin(), dp[st].end(), 0LL);
        ans %= MOD;
        cout << ans << "\n";
    }
}

int main()
{
    solve();
    return 0;
}
