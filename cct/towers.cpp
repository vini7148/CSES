#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> s;
    while (n--)
    {
        ll tmp;
        cin >> tmp;

        auto pt = upper_bound(s.begin(), s.end(), tmp);

        if (pt == s.end())
            s.push_back(tmp);

        else
            *pt = tmp;
    }

    cout << s.size() << "\n";
    return 0;
}
