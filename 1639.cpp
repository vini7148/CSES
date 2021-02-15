// https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<ll> > dp(s1.length() + 1, vector<ll> (s2.length() + 1, 0));

    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = i + j;
            }

            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            
            else
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    // cout << "\t\t";
    // for (int j = 0; j < s2.length(); j++)
    //     cout << "\t" << s2[j];

    // cout << "\n\t";

    // for (int i = 0; i <= s1.length(); i++)
    // {
    //     if (i)
    //         cout << "\t" << s1[i - 1];

    //     for (int j = 0; j <= s2.length(); j++)
    //     {
    //         cout << "\t" << dp[i][j];
    //     }
    //     cout << "\n";
    // }

    cout << dp[s1.length()][s2.length()] << "\n";
}