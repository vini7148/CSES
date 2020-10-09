// https://cses.fi/problemset/task/1631

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n, su = 0, ma = INT_MIN;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (ma < temp)
            ma = temp;
        su += temp;
    }

    cout << (ma > (su - ma)? 2 * ma : su) << "\n";
}