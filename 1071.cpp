// https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        if (x == y)
            {
                cout << (x * x) - x + 1 << "\n";
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

                cout << no << "\n";
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

                cout << no << "\n";
            }

        // if (x == 1)
        // {
        //     if (y % 2 == 1)
        //     {
        //         cout << y * y << "\n";
        //     }
        //     else
        //     {
        //         cout << (y - 1) * (y - 1) + 1 << "\n";
        //     }
        // }
        // else if (y == 1)
        // {
        //     if (x % 2 == 0)
        //     {
        //         cout << x * x << "\n";
        //     }
        //     else
        //     {
        //         cout << (x - 1) * (x - 1) + 1 << "\n";
        //     }
        // }
        // else
        // {
        //     if (x == y)
        //     {
        //         cout << (x * x) - x + 1 << "\n";
        //     }
        //     else if(x > y)
        //     {
        //         ll no = 0;
        //         if (x % 2 == 0)
        //         {
        //             no = x * x;
        //         }
        //         else
        //         {
        //             no = (x - 1) * (x - 1) + 1;
        //         }

        //         cout << no - y + 1 << "\n";
        //     }
        //     else
        //     {
        //         ll no = 0;
        //         if (y % 2 == 1)
        //         {
        //             no = y * y;
        //         }
        //         else
        //         {
        //             no = (y - 1) * (y - 1) + 1;
        //         }

        //         cout << no - x + 1 << "\n";
        //     }
        // }
    }
}