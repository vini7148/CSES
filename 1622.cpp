// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll fact(ll n)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
    {
        ans *= i;
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());

    unordered_map<char, int> hmap;

    for (int i = 0; i < s.length(); i++)
    {
        hmap[s[i]]++;
    }

    ll ways = fact(s.length());

    for (auto x : hmap)
    {
        ways /= fact(x.second);
    }

    cout << ways << "\n";

    do 
    {
        for(auto&& element : s)
            std::cout << element;
        std::cout << std::endl;
    } while (std::next_permutation(std::begin(s), std::end(s)));
    
}