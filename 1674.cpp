// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
	ll n;
    cin >> n;
    vector<ll> par(n, -1);
    for (int i = 1; i < n; i++)
    {
        cin >> par[i];
        par[i] = par[i] - 1;
    }

    // set each parent in the above part and count in the next part 

    vector<int> co(n, 0);

    for (int i = 0; i < n; i++)
    {
        int st = n - i - 1;
        int su = 0;
        while (par[st] != -1)
        {
            co[st] += su;
            su += 1;
            st = par[st];
        }
    }

    cout << n - 1 << " ";
    for (int i = 1; i < n; i++)
    {
        cout << co[i] << " ";
    }
}
