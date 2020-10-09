// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0, ma = 0;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        if (ma < temp)
        {
            ma = temp;
        }

        if (i > 0)
        {
            if (temp < ma )
            {
                ans += ma - temp;
            }
        }
    }

    cout << ans << "\n";
}