#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<vector<ll> > edges(100001);
vector<bool> vi(100001, false);

vector<vector<ll> > ans(100001);

ll il = 0;

void dfs(ll u)
{
    vi[u]= true;

    ans[il].push_back(u);

    for (int i = 0; i < edges[u].size(); i++)
    {
        if (!vi[edges[u][i]])
            dfs(edges[u][i]);
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vi[i])
        {
            dfs(i);

            il++;
        }
    }

    cout << il - 1 << "\n";

    for (int i = 0; i < il - 1; i++)
    {
        cout << ans[i][0] << " " << ans[i + 1][0] << "\n";
    }

    return 0;
}
