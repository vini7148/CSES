#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll e, f;
        cin >> e >> f;

        ll wt = f - e;

        ll n;
        cin >> n;
        vector<ll> p(n), w(n);
        for (int i = 0; i < n; i++)
            cin >> w[i] >> w[i];

        // knap sack

        ll dp[wt + 1];

        dp[0] = 0;
        
        for (int i = 1; i <= wt; i++)
        {
            dp[i] = -1;
            for (int j = 0; j < n; j++)
            {
                if (i >= w[j] && dp[i - w[j]] != -1 && (dp[i] == -1 || p[j] + dp[i - w[j]] < dp[i]))
                {
                    dp[i] = dp[i - w[j]] + p[j];
                }
            }
        }

        if (dp[wt] == -1)
            cout << "This is impossble\n";

        else
            cout << "The minimum amount of money in piggy-bank is " << dp[wt] << "\n";
    }

    return 0;
}
