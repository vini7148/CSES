// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll sol(vector<ll> a, ll i, ll diff)
{
    if (i == a.size())
        return abs(diff);

    return min(sol(a, i + 1, diff + a[i]), sol(a, i + 1, diff - a[i]));
}

int main()
{
    ll n, su = 0;
    cin >> n;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // ll ans = LONG_MAX;

    // for (ll i = 0; i < pow(2, n); i++)
    // {
    //     ll sum1 = 0, sum2 = 0;
    //     for (ll j = 0; j < n; j++)
    //     {
    //         if(i & 1 << j)
    //         {
    //             sum1 += a[j];
    //         }
    //         else
    //         {
    //             sum2 += a[j];
    //         }
    //     }

    //     ll su = (sum1 > sum2)?(sum1 - sum2):(sum2 - sum1);

    //     if (su < ans)
    //     {
    //         ans = su;
    //     }
    // }

    ll ans = sol(a, 0, 0);

    cout << ans << "\n";
}