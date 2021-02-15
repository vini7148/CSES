// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;

    // unordered_map<int, int> hmap;

    set<int> s;

    for (ll i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
        // hmap[temp]++;
    }

    cout << s.size() << "\n";
}