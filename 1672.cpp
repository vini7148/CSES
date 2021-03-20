// https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>

#define ll long long int

using namespace std;

constexpr long long int MAX = (1LL << 60);

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;

    ll dist[501][501];

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            dist[i][j] = (i == j) ? 0 : MAX;
        }
    }

    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;

        dist[x][y] = min(dist[x][y], w);
        dist[y][x] = min(dist[y][x], w);
    }

    // floyd warshall

    for (ll k = 1; k <= n; k++) 
    {
        for (ll i = 1; i <= n; i++) 
        {
            for (ll j = 1; j <= n; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    }

    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;

        if (dist[x][y] == MAX)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << dist[x][y] << "\n";
    }

    return 0;
}