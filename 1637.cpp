// https://cses.fi/problemset/task/1637/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while(n)
    {
        ll ma = 0, t = n;
        while(t)
        {
            ma = max(ma, t %10);
            t /= 10;
        }
        n -= ma;
        ans++;
    }
    cout << ans << "\n";
}