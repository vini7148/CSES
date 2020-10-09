// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    string s;
    cin >> s;

    int co = 1, ma = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i - 1])
        {
            co++;
        }
        else
        {
            co = 1;
        }

        if (ma < co)
        {
            ma = co;
        }
    }

    cout << ma << "\n";
}