// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main ()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll> > edges(100001);
    ll wt[100000][100000] = { 0 };

    for (ll i = 0 ; i < m; i++)
    {
        ll x, y ,w;

        cin >> x >> y >> w;

        edges[x].push_back(y);
        edges[y].push_back(x);

        wt[x][y] = w;
        wt[y][x] = w;
    }

    vector<ll> cost(100001, INT_MAX);
    vector<ll> par(100001, -1);

    cost[1] = 0;

    queue<ll> Q;

    Q.push(1);

    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop();

        for (ll i = 0; i < edges[u].size(); i++)
        {
            if (cost[edges[u][i]] > wt[u][edges[u][i]])
            {
                cost[edges[u][i]] = wt[u][edges[u][i]];
                par[edges[u][i]] = u;

                Q.push(edges[u][i]);
            }
        }
    }

    for (ll i = 2; i <= n; i++)
    {
        cout << cost[i] << " ";
    }

    cout << "\n";
}