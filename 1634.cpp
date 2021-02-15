// https://cses.fi/problemset/task/1634/

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

    sort (a.begin(), a.end());
    vector<ll> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] <= i)
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }

    if (dp[x] == x + 1)
        cout << -1 << "\n";
    else
        cout << dp[x] << "\n";    
}