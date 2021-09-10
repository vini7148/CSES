#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll ans = 1;

    while (n--)
    {
        ans *= 2;

        ans %= 1000000007;
    }

    cout << ans << "\n";

    return 0;
}
