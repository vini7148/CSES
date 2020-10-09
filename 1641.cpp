// https://cses.fi/problemset/task/1641

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        ll l = i + 1;
        ll r = n - 1;
        while(l < r)
        {
            if (a[i].first + a[l].first + a[r].first == k)
            {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            }
            else if (a[i].first + a[l].first + a[r].first < k)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}