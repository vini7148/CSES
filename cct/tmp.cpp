#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a[4];

        for (int i = 0; i < 4; i++)
            cin >> a[i];

        ll x1 = min(max(a[0], a[1]), max(a[2], a[3]));

        sort(a, a + 4);

        if (a[1] != x1)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}
