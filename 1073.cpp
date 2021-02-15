// https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, curr;
    cin >> n;
    vector<ll> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> curr;
        auto it = upper_bound(k.begin(), k.end(), curr);
        if (it == k.end())
        {
            k.push_back(curr);
        }
        else
        {
            *it = curr;
        }
        // cout << *it << " " << curr << endl;
    }

    // ll ans = 0;

    // for (ll i = 0; i < n; i++)
    // {
    //     auto it = upper_bound(k.begin(), k.begin() + i, k[i]);
    //     // cout << *it << " ";
    //     if (*it == k[i])
    //     {
    //         ans ++;
    //     }
    // }
    // cout << "\n" << ans << "\n";

    cout << k.size() << "\n";
}