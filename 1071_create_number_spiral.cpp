#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    for (ll x = 1; x <= n; x++)
    {
        for (ll y = 1; y <= n; y++)
        {
            if (x == y)
            {
                cout << (x * x) - x + 1 << "\t";
            }
            else if(x > y)
            {
                ll no = 0;
                if (x % 2 == 0)
                {
                    no = x * x;
                    no -= (y - 1);
                }
                else
                {
                    no = (x - 1) * (x - 1) + 1;
                    no += (y - 1);
                }

                cout << no << "\t";
            }
            else
            {
                ll no = 0;
                if (y % 2 == 1)
                {
                    no = y * y;
                    no -= (x - 1);
                }
                else
                {
                    no = (y - 1) * (y - 1) + 1;
                    no += (x - 1);
                }

                cout << no << "\t";
            }
        }
        cout << "\n";
    }
}