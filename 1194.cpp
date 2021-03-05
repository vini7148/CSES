// https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll n, m;

vector<string> path(1001);
vector<vector<bool> > vi(1001, vector<bool>(1001, false));

vector<char> ans;

bool dfs(ll x, ll y, ll prev = 0, ll ti = 1)
{
    // cout << ans.size() << "\n";
    // for (ll i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    // cout << "\n";
    
    if ((x == 0 || x == n - 1) && (path[x][y] != '#'))
        return true;

    if ((y == 0 || y == m - 1) && (path[x][y] != '#'))
        return true;

    if ((x == 0 || x == n - 1) && (path[x][y] == '#'))
        return false;

    if ((y == 0 || y == m - 1) && (path[x][y] == '#'))
        return false;

    if (ti % 2 == 0)
        if (path[x][y] == '#' || path[x][y] == 'M')
            return false;
    
    if (ti % 2 == 1)
        if (path[x][y] == '#' || path[x - 1][y] == 'M' || path[x + 1][y] == 'M' || path[x][y - 1] == 'M' || path[x][y + 1] == 'M')
            return false;

    if (prev != 2)
    {
        ans.push_back('U');
        if (dfs(x - 1, y, 1, ti + 1))
            return true;
        ans.pop_back();
    }

    if (prev != 1)
    {
        ans.push_back('D');
        if (dfs(x + 1, y, 2, ti + 1))
            return true;
        ans.pop_back();
    }

    if (prev != 4)
    {
        ans.push_back('L');
        if (dfs(x, y - 1, 3, ti + 1))
            return true;
        ans.pop_back();
    }

    if (prev != 3)
    {
        ans.push_back('R');
        if (dfs(x, y + 1, 4, ti + 1))
            return true;
        ans.pop_back();
    }

    return false;
}

bool solve(bool N_ALLOW = false)
{
    ll t = 1;
    if (N_ALLOW)
        cin >> t;

    while (t--)
    {
        // ll n, m;
        cin >> n >> m;

        ll x, y;

        for (ll i = 0; i < n; i++)
        {
            cin >> path[i];

            if (path[i].find('A') != string::npos)
            {
                x = i;
                y = path[i].find('A');
            }
        }

        // cout << x << " " << y << "\n";

        if (dfs(x, y))
        {
            cout << "YES\n";

            cout << ans.size() << "\n";
            for (ll i = 0; i < ans.size(); i++)
                cout << ans[i];
            cout << "\n";
            return 0;
        }

        cout << "NO\n";
        return 0;
    }

    return 0;
}

int main()
{
    solve();

    return 0;
}