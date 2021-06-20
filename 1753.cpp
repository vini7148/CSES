// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll kmp(string s, ll n)
{
    vector<ll> b(s.length());

    ll bo = 0;
    b[0] = 0;

    for (int i = 1; i < s.length(); i++)
    {
        while (bo > 0 && s[i] != s[bo])
            bo--;

        if (s[i] == s[bo])
            bo++;

        else
            bo = 0;

        b[i] = bo;
    }

    ll ans = 0;

    for (int i = n; i < b.size(); i++)
    {
        if (b[i] == n)
            ans++;
    }

    return ans;
}

int main()
{
    string s, p;
    cin >> s >> p;

    cout << kmp(p + "$" + s, p.length()) << "\n";

    return 0;
}
