#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    string s;
    cin >> s;

    ll ans = 1;
    ll curr = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            curr++;

        else
            curr = 1;

        ans = max(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}