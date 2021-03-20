// https://cses.fi/problemset/task/1673

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long 

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    bool self_loop = false;

    vector<vector<pair<ll, ll> > > edges(2501);
    for (ll i = 0 ; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;

        // remember one way tunnels
        edges[x].push_back(make_pair(y, w));
        // edges[y].push_back(make_pair(x, w));

        if (x == y)
            self_loop = true;
    }

    if (self_loop)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<ll> dist(2501, INT_MIN);
    
    dist[1] = 0;

    bool ch_last = false;

    // bellman ford 
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < edges[j].size(); k++)
            {
                if (dist[j] + edges[j][k].second > dist[edges[j][k].first])
                {
                    dist[edges[j][k].first] = dist[j] + edges[j][k].second;
                }
            }
        }
    }

    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < edges[j].size(); k++)
            {
                if (dist[j] + edges[j][k].second > dist[edges[j][k].first])
                {
                    dist[edges[j][k].first] = dist[j] + edges[j][k].second;

                    if (edges[j][k].first == n)
                        ch_last = true;
                }
            }
        }
    }

    if (ch_last)
    {
        cout << -1 << "\n";
        return 0;
    }

    cout << dist[n] << "\n";
}
