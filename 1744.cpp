// https://cses.fi/problemset/task/1744

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    while (x != y)
    {
        if (x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
        ans++;
    }

    cout << ans << "\n";
}
