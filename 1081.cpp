// https://cses.fi/problemset/task/1081

#include <bits/stdc++.h>

#define ll int

using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

int main()
{
    ll n;
    cin >> n;
    
    // vector<ll> a(n);

    ll ct[1000001] = { 0 };
    for (ll i = 0; i < n; i++)
    {   
        ll tmp;
        cin >> tmp;

        // cin >> a[i];
        
        ct[tmp]++;
    }

    ll ans = 1;

    for (ll i = 2; i <= long(1000000); i++)
    {
        ll tmp = 0;
        for (ll j = i; j <= long(1000000); j += i)
        {
            tmp += ct[j];

            if (tmp > 1)
            {
                ans = i;
                break;
            }
        } 
    }

    cout << ans << "\n";

    // ll mx = 0;
    // for (int i = 0; i < n; i++)
    //     mx = max(mx, a[i]);

    // ll div[mx + 1] = { 0 };
    // // memcpy(div, 0, sizeof(div));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= sqrt(a[i]); j++)
    //     {
    //         if (a[i] % j == 0)
    //         {
    //             div[j]++;
                
    //             if (j != a[i] / j)
    //                 div[a[i] / j]++;
    //         }
    //     }
    // }

    // for (int i = mx; i > 0; i--)
    // {
    //     if (div[i] > 1)
    //     {
    //         cout << i << "\n";
    //         return 0;
    //     }
    // }
}
