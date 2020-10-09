// https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0, curr = 0;
    while (n--)
    {
        ll tmp;
        cin >> tmp;

        curr = max(curr + tmp, tmp);
        ans = max(ans, curr);
    }
    cout << ans << "\n";
}