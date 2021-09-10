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

    sort(a.begin(), a.end());

    ll su = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > su + 1)
        {
            cout << su + 1 << "\n";
            return 0;
        }
        su += a[i];
    }

    cout << su + 1 << "\n";
    return 0;
}
