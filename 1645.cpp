// https://cses.fi/problemset/task/1645

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

    for (int i = 0; i < n; i++)
    {
        int st = i - 1;
        while (st >= 0 && a[st] >= a[i])
        {
            st--;
        }

        cout << st + 1 << " ";

        // cout << lower_bound(a.begin(), a.begin() + i + 1, a[i]) - a.begin() << " ";

        // -a.begin() pe int return 
    }    
    cout << "\n";
}