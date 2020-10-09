// https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }    
    sort(p.begin(), p.end());
    ll tar = p[n / 2], ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(tar - p[i]);
    }
    cout << ans << "\n";

}