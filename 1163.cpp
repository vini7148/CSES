// https://cses.fi/problemset/task/1163

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, x;
    cin >> x >> n;
    // vector<ll> a;

    set<int> pt = {0, x};
    
    multiset<int> lengths = {x};
    // a.push_back(x);
    
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;

        auto it = pt.upper_bound(temp);

        ll lf = *prev(it);
        ll rt = *it;

        lengths.erase(lengths.find(rt - lf));

        lengths.insert(temp - lf);
        lengths.insert(rt - temp);
        // a.push_back(temp);

        pt.insert(it, temp);

        cout << *lengths.rbegin() << " ";

        // *lengths.end() - multi set is sorted 

        // sort(a.begin(), a.end());

        // ll ma = 0, st = 0;
        // for (ll j = 0; j < a.size(); j++)
        // {
        //     ma = max(ma, a[j] - st);
        //     st = a[j];
        // }
        // cout << ma << " ";
    }
}