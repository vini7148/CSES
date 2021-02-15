// https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    while(n != 1)
    {
        cout << n << " ";

        if(n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = (3 * n) + 1;
        }
    }
    cout << n << "\n";
}