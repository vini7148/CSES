//https://cses.fi/problemset/task/1085/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

bool ck(vector<ll> a, ll mid , ll k)
{
    ll co = 1;
    ll su = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > mid)
            return false;

        su += a[i];

        if (su > mid)
        {
            co++;
            su = a[i];
        }
    }

    if (co <= k)
        return true;
    return false;
}

int main()
{
    ll n, k, su = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        su += a[i];
    }
        
    ll st = 1, en = su;
    ll ans = 0;
    while(st <= en)
    {
        ll mid = (st + en) / 2;

        if (ck(a, mid, k))
        {
            ans = mid;
            en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    cout << ans << "\n";
}