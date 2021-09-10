#include <bits/stdc++.h>
 
#define ll long long 
 
using namespace std;
 
int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 1);
 
    dp[0] = 0;

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

    for (int i = 0; i <= n; i++)
        cout << dp[i] << " ";

    cout << "\n";

    cout << dp[n] << "\n";
    return 0;
}
