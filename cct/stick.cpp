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

    sort(a.begin(), a.end());
    ll mid = a[n / 2], ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(mid - a[i]);
    }

    cout << ans << "\n";
    return 0;
}
