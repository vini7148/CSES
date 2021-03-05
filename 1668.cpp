// https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<vector<ll> > edges(100001);
vector<bool> vi(100001, false);
vector<ll> col(100001, -1);

bool isBi(ll u)
{
    for (ll i = 0; i < edges[u].size(); i++)
    {
        if (!vi[edges[u][i]])
        {
            vi[edges[u][i]] = true;
            col[edges[u][i]] = (col[u] + 1) % 2;

            if (!isBi(edges[u][i]))
                return false;
        }

        else if (col[u] == col[edges[u][i]])
            return false;
    }

    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i ++)
    {
        ll x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // col[1] = 0;
    // vi[1] = true;

    bool res = true;

    for (ll i = 1; i <= n; i++)
    {
        if (!vi[i])
        {
            vi[i] = true;
            col[i] = 0;

            res = res && isBi(i);
        }
    }

    if (!res)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }


    // vector<ll> col(n + 1, -1);

    // col[1] = 0;
    // queue<ll> Q;
    // Q.push(1);

    // while (!Q.empty())
    // {
    //     ll u = Q.front();
    //     Q.pop();

    //     for (ll i = 0; i < edges[u].size(); i++)
    //     {
    //         if (col[edges[u][i]] == -1)
    //         {
    //             col[edges[u][i]] = (col[u] + 1) % 2;
    //             Q.push(edges[u][i]);
    //         }
    //         else if (col[u] == col[edges[u][i]])
    //         {
    //             cout << "IMPOSSIBLE\n";
    //             return 0;
    //         }
    //     }
    // }

    for (ll i = 1; i <= n; i++)
    {
        cout << col[i] + 1 << " ";
    }

    cout << "\n";
}