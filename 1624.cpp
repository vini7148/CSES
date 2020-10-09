// https://cses.fi/problemset/task/1624/

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

ll ans = 0;
bool tcol[8], tdg1[16], tdg2[16];

void ways(string board[8], ll r, ll &ans)
{
    if (r == 8)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if(board[r][i] == '.')
        {
            if(!tcol[i] && !tdg1[r - i +7] && !tdg2[i + r])
            {
                tcol[i] = tdg1[r - i +7] = tdg2[i + r] = true;

                ways(board, r + 1, ans);

                tcol[i] = tdg1[r - i +7] = tdg2[i + r] = false;
            }
        }
    }
}

int main()
{
    string board[8];
    
    ll ans = 0;

    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }

    ways(board, 0, ans);

    cout << ans << "\n";
}