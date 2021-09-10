#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, w;
    cin >> n >> w;

    vector<ll> wt(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    sort (wt.begin(), wt.end());

    ll st = 0, en = n - 1;

    ll ans = 1;

    ll su = 0, sel = 1;

    su += wt[en];
    while (st < en)
    {
        if (sel == 2)
        {
            ans ++;
            en --;

            su = wt[en];
            sel = 1;
        }

        else if ((su + wt[st]) > w)
        {
            ans ++;
            en --;

            su = wt[en];
            sel = 1;
        }

        else
        {
            su += wt[st];
            st++;
            sel++;
        }

    }

    cout << ans << "\n";

    return 0;
}

