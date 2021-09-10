#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<vector<ll> > edges(100001);
vector<int> col(100001, -1);
vector<bool> vi(100001, false);

bool isbi(ll u)
{
    for (int i = 0; i < edges[u].size(); i++)
    {
        if (!vi[edges[u][i]])
        {
            vi[edges[u][i]] = true;
            col[edges[u][i]] = (col[u] + 1) % 2;

            if (!isbi(edges[u][i]))
                return false;
        }

        else if (col[edges[u][i]] == col[u])
            return false;
    }

    return true;
}

int main()
{
    ll n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        ll x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    bool res = true;

    for (int i = 1; i <= n; i++)
    {
        if (!vi[i])
        {
            vi[i] = true;
            col[i] = 0;

            res = res && isbi(i);
        }
    }

    if (!res)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << col[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}
