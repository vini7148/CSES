// https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<vector<ll> > edges(200001);
vector<bool> vi(200001, false);

ll ans = 0;

void dfs(ll u, ll p)
{
    for (ll i = 0; i < edges[u].size(); i++)
    {
        if (edges[u][i] != p)
            dfs(edges[u][i], u);
    }

    if (!vi[u] && !vi[p] && p != 0)
    {
        ans++;

        vi[u] = true;
        vi[p] = true;
    }
}

int main()
{
    ll n;
    cin >> n;

    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1, 0);

    cout << ans << "\n";
}