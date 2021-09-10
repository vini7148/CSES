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

    ll ans = INT_MIN, curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr = max(curr + a[i], a[i]);

        ans = max(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}

