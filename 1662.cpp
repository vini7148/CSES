// https://cses.fi/problemset/task/1662/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<ll, ll> prev;

    ll ans = 0, curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr += a[i];

        if (curr % n == 0)
            ans++;

        if (prev.find(curr % n) != prev.end())
            ans += prev[curr % n];

        prev[curr]++;
    }

    cout << ans << "\n";
}