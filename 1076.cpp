// https://cses.fi/problemset/task/1076

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> s(k);

    for (int i = 0; i < k; i++)
        s[i] = a[i];

    sort(s.begin(), a.end());

    for (int i = k; i < n; i++)
    {
        if (k % 2 == 0)
        {
            cout << (s[k / 2] + s[(k / 2) + 1]) / 2 << " ";
        }
        else
        {
            cout << s[(k + 1) / 2] << " ";
        }
        auto pos = find(s.begin(), s.end(), a[i - k]);
        s.erase(pos);
        s.push_back(a[i]);
        sort(a.begin(), s.end());        
    }
    cout << "\n";
}