// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<int> par(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> par[i];
        par[i] -= 1;
    }

    vector<int> co(n, 0);

    for (int i = n - 1; i > -1; i--)
    {
        int st = i, cou = 1;
        while(st != par[st])
        {
            co[st] += cou;
            st = par[st];
            cou++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << co[i] << " ";
    }

    cout << "\n";
}
