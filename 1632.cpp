// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
 
    multiset<ll> en;

    for (ll i = 0; i < k; i++)
        en.insert(0);

    vector<pair<ll, ll>> time;
 
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        time.push_back(make_pair(y, x));
    }
 
    sort(time.begin(), time.end());
 
    ll curr = 0, ans = 0;
 
    for (auto ele : time)
    {
        auto it = en.upper_bound(ele.second);

        if (it == en.begin())
            continue;

        it--;
        ans++;
        en.erase(it);
        en.insert(ele.first);
    }// (╯°□°）╯︵ ┻━┻
 
    cout << ans << "\n";
}

/* 
curr = 0;
        // (╯°□°）╯︵ ┻━┻
        // for (auto ptr = time.begin(); ptr < time.end(); ptr++)
        // {
        //     pair<ll, ll> tem = *ptr;
        //     if (tem.second >= curr)
        //     {
        //         curr = tem.first;
        //         ans++;
                
        //         // remove this element
                
        //         time.erase(ptr);
        //     }
        // }
*/