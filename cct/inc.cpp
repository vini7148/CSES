#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;

    cin >> n;

    ll curr, prev;

    cin >> curr;
    prev = curr;

    ll ans = 0;

    for (int i = 1; i < n; i++)
    {
        cin >> curr;

        ll res = 0;

        if (prev > curr)
        {
            res = prev - curr;
            curr = prev;
        }

        ans += res;

        prev = curr;
    }

    cout << ans << "\n";

    return 0;
}