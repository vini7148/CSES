// https://cses.fi/problemset/task/2431

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    string s = "";

    ll tmp = 1;

    while (s.length() <= 1e18)
    {
        // cout << tmp << " " << s << "\n";
        s += to_string(tmp);
        tmp++;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << s[x - 1] << "\n";
    }
}