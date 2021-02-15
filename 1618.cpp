// https://cses.fi/problemset/task/1618/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll p5 = 5, ans = 0;

    while (p5 <= n)
    {
        ans += n / p5;

        p5 *= 5;
    }

    cout << ans << "\n";
}