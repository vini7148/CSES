// https://cses.fi/problemset/task/1674

// #include <bits/stdc++.h>

#include <iostream>
#include <vector>

#define ll long long 

using namespace std;

vector<vector<ll> > edges(200001);

vector<ll> ans(200001);

void dfs(ll u)
{
    ans[u] = 1;
    for (int i = 0; i < edges[u].size(); i++)
    {
        dfs(edges[u][i]);

        ans[u] += ans[edges[u][i]];
    }
}

int main()
{
    ll n;
    cin >> n;
    
    for (int i = 2; i <= n; i++)
    {
        int tmp;
        cin >> tmp;

        edges[tmp].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] - 1 << " ";
    cout << "\n";
}
