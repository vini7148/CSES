#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    map<ll, ll> a;
    while (n--)
    {
        ll tmp;
        cin >> tmp;

        if (a.find(tmp - 1) == a.end())
        {
            a[tmp]++;
        }

        else
        {
            a.erase(tmp - 1);
            a[tmp]++;
        }
    }

    cout << a.size() << "\n";
    return 0;
}
