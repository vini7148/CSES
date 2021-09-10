#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> dp(t + 1, t + 1);

    dp[0] = 0;

    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if (dp[t] == t + 1)
    {
        cout << "-1\n";

        return 0;
    }

    cout << dp[t] << "\n";

    return 0;
}
