// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> a;
    ll co = 0;
    while(n--)
    {
        ll temp;
        cin >> temp;
        a.push_back(make_pair(temp, co));
        co++;
    }

    sort(a.begin(), a.end());

    ll i = 0, j = a.size() - 1;

    while(i < j)
    {
        if (a[i].first + a[j].first == x)
        {
            cout << a[i].second + 1 << " " << a[j].second + 1<< "\n";
            return 0;
        }
        else if (a[i].first + a[j].first > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "IMPOSSIBLE\n";
}