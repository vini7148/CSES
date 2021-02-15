// https://cses.fi/problemset/task/1077

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, k;

    cin >> n >> k;

    vector<ll> x(n);

    for (int i = 0; i < n; i++)
        cin >> x[i];

    // start - program 

    vector<ll> s;
    ll su = 0;

    for (int i = 0; i < k; i++)
    {
        s.push_back(x[i]);
        su += x[i];

    }

    for (int i = k; i <= n; i++)
    {
        // main for loop with addition and sub to mean


        // end part 
        su -= x[i - k];
        su += x[i];
    }
}