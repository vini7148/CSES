// https://cses.fi/problemset/task/2165

#include <bits/stdc++.h>

#define ll long long 

using namespace std;

vector<pair<int, int> > moves;

void tower_of_hanoi(ll n, int a, int c, int b)
{
    if (n == 1)
    {
        moves.push_back(make_pair(a, c));

        return;
    }

    tower_of_hanoi(n - 1, a, b, c);

    moves.push_back(make_pair(a, c));

    tower_of_hanoi(n - 1, b, c, a);
}

int main()
{
    ll n;
    cin >> n;

    tower_of_hanoi(n, 1, 3, 2);

    cout << moves.size() << "\n";

    for (auto x: moves)
    {
        cout << x.first << " " << x.second << "\n";
    }
}