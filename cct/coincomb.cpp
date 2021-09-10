#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll *a;
    a = new ll[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> dp(k + 1, 0);

    dp[0] = 1;

    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= i)
            {
                dp[i] = dp[i - a[j]] + dp[i];
                dp[i] %= 1000000007;
            }
        }
    }

    cout << dp[k] << "\n";

    return 0;
}
