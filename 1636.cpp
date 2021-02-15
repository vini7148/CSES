// https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> dp(x + 1);
    dp[0] = 1;
    for (int j = 0; j < n; j++)
    {    
        for (int i = 1; i <= x; i++)
        {
            if (a[j] <= i)
            {
                dp[i] = (dp[i] + dp[i - a[j]]) % 1000000007;
            }
        }
    }

    cout << dp[x] << "\n";
}