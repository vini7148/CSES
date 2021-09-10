#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    string s;

    cin >> s;

    map<char, ll> hmap;

    for (auto x:s)
        hmap[x]++;

    ll oddco = 0;
    char odd_char;
    ll co = 0;

    for (auto x:hmap)
    {
        co += x.second;

        if (x.second&1)
        {
            oddco++;
            odd_char = x.first;
        }
    }

    if (s.length()&1)
    {
        if (oddco > 1)
        {
            cout << "NO SOLUTION\n";
            return 0;
        }

        if (oddco)
        {
            string l, r;
            l = "";
            for (auto x:hmap)
                for (int i = 0; i < x.second / 2; i++)
                    l += x.first;
            
            r = l;
            reverse(r.begin(), r.end());

            string ans;
            ans = l + odd_char + r;
            cout << ans << "\n";
        }
        else
        {
            string l, r;
            l = "";
            for (auto x:hmap)
                for (int i = 0; i < x.second/ 2; i++)
                    l += x.first;
            
            r = l;
            reverse(r.begin(), r.end());

            string ans;
            ans = l + r;
            cout << ans << "\n";
        }
        return 0;
    }

    if (oddco > 0)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    string l, r;
    l = "";
    for (auto x:hmap)
        for (int i = 0; i < x.second/ 2; i++)
            l += x.first;
    
    r = l;
    reverse(r.begin(), r.end());

    string ans;
    ans = l + r;
    cout << ans << "\n";

    return 0;
}

