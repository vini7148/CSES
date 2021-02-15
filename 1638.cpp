// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<ll>> dp(n, vector<ll> (n));
    dp[0][0] = s[0][0] == '.';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == '*')
            {
                continue;
            }
            if (i > 0)
            {
                dp[i][j] += (dp[i - 1][j]) % 1000000007;
            }
            if (j > 0)
            {
                dp[i][j] += (dp[i][j - 1]) % 1000000007;
            }
        }
    }
    cout << dp[n - 1][n - 1] % 1000000007 << "\n";
}