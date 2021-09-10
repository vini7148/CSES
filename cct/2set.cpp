#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll su = n * (n + 1);
    su /= 2;

    if (su&1)
    {
        cout << "NO\n";
        return 0;
    }

    vector<ll> l, r;

    su /= 2;

    for (int i = n; i >0; i--)
    {
        if (i <= su)
        {
            su -= i;
            r.push_back(i);
        }
        else
            l.push_back(i);
    }

    cout << "YES\n";

    cout << l.size() << "\n";
    for (int i = 0; i < l.size(); i++)
        cout << l[i] << " ";
    
    cout << "\n";

    cout << r.size() << "\n";
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << " ";
    
    cout << "\n";

    return 0;
}

