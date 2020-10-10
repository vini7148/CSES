// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
 
    vector<pair<ll, ll>> time;
 
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        time.push_back(make_pair(y, x));
    }
 
    sort(time.begin(), time.end());
 
    ll curr = 0, ans = 0;
 
    while(k--)
    {
        curr = 0;
        // (╯°□°）╯︵ ┻━┻
        for (auto ptr = time.begin(); ptr < time.end(); ptr++)
        {
            pair<ll, ll> tem = *ptr;
            if (tem.second >= curr)
            {
                curr = tem.first;
                ans++;
                
                // remove this element
                
                time.erase(ptr);
            }
        }
    }// (╯°□°）╯︵ ┻━┻
 
    cout << ans << "\n";
}