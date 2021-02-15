// https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;

    if ( n == 1)
    {
        cout << 1;
    }
    else if(1 < n && n < 4)
    {
        cout << "NO SOLUTION";
    }
    else if (n == 4)
    {
        cout << "2 4 1 3";
    }
    else
    {
        int st = n - 1;

        while(st > 0)
        {
            cout << st << " ";
            st -= 2;
        }

        st = n;
        
        while(st > 0)
        {
            cout << st << " ";
            st -= 2;
        }
    }
    cout << "\n";
}