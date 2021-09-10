#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    
    ll po5 = 5;
    ll ans = 0;

    while (n >= po5)
    {
        ans += n / po5;
        po5 *= 5;
    }

    cout << ans << "\n";

    return 0;
}
