// https://cses.fi/problemset/task/1076

#include <bits/stdc++.h>

#define ll long long 



using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> s;

    for (int i = 0; i < k; i++)
        s.push_back(a[i]);

    sort(s.begin(), s.end());

    for (int i = k; i <= n; i++)
    {
        if (k % 2 == 0)
        {
            // cout << (s[k / 2] + s[(k / 2) - 1]) / 2 << " ";
            cout << s[(k / 2) - 1] << " ";
        }

        else
        {
            cout << s[k / 2] << " ";
        }
        
        auto pos = find(s.begin(), s.end(), a[i - k]);
        
        s.erase(pos);
        s.push_back(a[i]);
        // ll st = 0;

        // while (s[st] < a[i]);
        //     st++;

        // s.insert(s.begin() + st, a[i]);
        sort(s.begin(), s.end());
    }

    cout << "\n";
}