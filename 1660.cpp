// https://cses.fi/problemset/task/1660/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<ll, ll> prev;

    ll ans = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += a[i];

        if (curr == k)
            ans++;

        if (prev.find(curr - k) != prev.end())
            ans += prev[curr - k];

        prev[curr]++;
    }

    cout << ans << "\n";
}