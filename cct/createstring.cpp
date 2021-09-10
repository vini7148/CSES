#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll fact(ll n)
{
    ll ans = n;

    while (--n)
    {
        ans *= n;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    map<char, int> hmap;

    for (int i = 0; i < s.length(); i++)
        hmap[s[i]]++;

    ll ans = fact(s.length());

    for (auto x:hmap)
        ans /= fact(x.second);

    cout << ans << "\n";

    sort(s.begin(), s.end());

    do{
        cout << s << "\n";
    }while (next_permutation(s.begin(), s.end()));

    return 0;
}