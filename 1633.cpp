// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll dp[n + 1] = { 1 };

    for (int i = 1; i <= n; i++)
    {
        for (int j = max(0, i - 6); j < i; j++)
        {
            if (j <= i)
            {
                dp[i] = (dp[i] + dp[j]) % 1000000007;
            }
        }
    }

    cout << dp[n] << "\n";
}