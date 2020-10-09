// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> hmap;

    for (int i = 0; i < s.length(); i++)
    {
        hmap[s[i]]++;
    }

    int oddcount = 0;
    char oddchar;

    for (auto x : hmap)
    {
        if (x.second % 2 != 0)
        {
            oddcount++;
            oddchar = x.first;
        }
    }

    if(oddcount > 1)
    {
        cout << "NO SOLUTION\n";
    }
    else if(oddcount == 1 && s.length() % 2 == 0)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        string fh = "", sh = "";

        for(auto x : hmap)
        {
            string str(x.second / 2, x.first);

            fh = fh + str;

            sh = str + sh;
        }

        string ans = "";

        if (oddcount == 1)
        {
            ans = fh + oddchar + sh;
        }
        else
        {
            ans = fh + sh;
        }

        cout << ans << "\n";
    }
}