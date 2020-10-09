// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> want(n), ap(m);
    for (int i = 0; i < n; i++)
        cin >> want[i];

    for (int i = 0; i < m; i++)
        cin >> ap[i];

    sort(want.begin(), want.end());

    sort(ap.begin(), ap.end());

    ll stw = 0, sta = 0, ans = 0;

    while(stw < n && sta < m)
    {
        if(want[stw] - k <= ap[sta] && ap[sta] <= want[stw] + k)
        {
            ans++;
            stw++;
            sta++;
        }
        else if(ap[sta] < want [stw] - k)
        {
            sta++;
        }
        else
        {
            stw++;
        }
    }

    cout << ans << "\n";
}