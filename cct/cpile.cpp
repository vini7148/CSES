#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll su = a + b;
        if (su % 3)
        {
            cout << "NO\n";
            continue;
        }

        su /= 3;

        if (su <= min(a, b))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
