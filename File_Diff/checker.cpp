#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ifstream orig("orig.txt"), ne("new.txt");

    ll i = 1;

    while (!orig.eof())
    {
        ll a, b;
        
        orig >> a;
        ne >> b;

        if (a != b)
        {
            cout << i << ": " << a << " " << b << "\n";
        }

        i++;
    }

    orig.close();
    ne.close();
    
    return 0;
}