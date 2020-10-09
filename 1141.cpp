// https://cses.fi/problemset/task/1141

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<ll, ll> f;
    ll i = 0, j = 0, curr = 0, ans = 0;
    while (j < n)
    {
        if (f.find(a[j]) == f.end() || f[a[j]] == 0)
        {
            f[a[j]]++;
            j++;
            curr++;
            ans = max(curr, ans);
        }
        else
        {
            f[a[i]]--;
            i++;
            curr--;
        }
        
    }

    cout << ans << "\n";
}