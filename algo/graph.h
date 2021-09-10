#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define ll long long

class graph
{
    std::vector<std::vector<ll> > edges;
    
    std::vector<bool> vi;

    std::vector<ll> prev;
    std::vector<ll> dist;

    ll n, e;
    bool is_dag;
public: 
    graph();
    graph(ll n, ll e, bool is_dag);
    ~graph(); bool input(); 

    bool rand_input(ll N = 100, ll E = 100);
    bool print_graph();
    ll exp(ll u);
    bool dfs(ll u = 0);
    bool bfs(ll u = 1);
    bool dij(ll u, ll end);
}; 

graph::graph()
{
    n = 1;
    e = 0;
    
    is_dag = false;
}

graph::graph(ll n, ll e, bool is_dag)
{
    this->n = n;
    this->e = e;
    this->is_dag = is_dag;

    edges.resize(n + 1);
    vi.assign(n + 1, false);
}

graph::~graph()
{

}

bool graph::input()
{
    for (ll i = 0; i < e; i++)
    {
        ll x, y;
        std::cin >> x >> y;

        edges[x].push_back(y);

        if (!is_dag)
        {
            edges[y].push_back(x);
        }
    }

    return true;
}

bool graph::rand_input(ll N, ll E)
{
    n = 1 + rand() % (N - 1);
    e = 1 + rand() % (E - 1);

    edges.clear();
    edges.resize(n + 1);
    vi.clear();
    vi.assign(n + 1, false);

    ll _max_n = n * (n - 1);

    while (e > _max_n)
    {
        e = 1 + rand() % (E - 1);
    }

    for (ll i = 0; i < e; i++)
    {
        ll x, y;

        x = 1 + rand() % (n - 1);
        y = 1 + rand() % (n - 1);

        edges[x].push_back(y);

        if (!is_dag)
        {
            edges[y].push_back(x);
        }
    }

    return true;
}

bool graph::print_graph()
{
    for (ll i = 1; i<= n; i++)
    {
        for (ll j = 0; j < edges[i].size(); j++)
        {
            std::cout << edges[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return true;
}

ll graph::exp(ll u)
{
    if (!vi[u])
    {
        vi[u] = true;

        std::cout << u << std::endl;

        for (ll i = 0; i < edges[u].size(); i++)
        {
            if (!vi[edges[u][i]])
                exp(edges[u][i]);
        }
    }

    return 0;
}

bool graph::dfs(ll u)
{
    vi.clear();
    vi.assign(n + 1, false);

    if (u != 0)
    {
        exp(u);

        return true;
    }

    for (ll i = 1; i <= n; i++)
    {
        if (!vi[i])
            exp(i);
    }

    // exp(u);

    return true;
}

bool graph::bfs(ll u)
{
    vi.clear();
    vi.assign(n + 1, false);

    std::queue<ll> Q;
    Q.push(u);

    while(!Q.empty())
    {
        ll x = Q.front();
        Q.pop();

        if (vi[x])
            continue;

        vi[x] = true;

        std::cout << x << std::endl;

        for (ll i = 0; i < edges[x].size(); i++)
        {
            if (!vi[edges[x][i]])
                Q.push(edges[x][i]);
        }
    }

    return true;
}

bool graph::dij(ll u, ll end)
{
    vi.clear();
    vi.resize(n + 1, false);

    prev.clear();
    prev.resize(n + 1, -1);

    dist.clear();
    dist.resize(n + 1, INT_MAX);

    dist[u] = 0;
    prev[u] = u;

    std::queue<ll> Q;
    Q.push(u);

    while (!Q.empty())
    {
        ll x = Q.front();
        Q.pop();

        if (vi[x])
            continue;

        vi[x] = true;

        for (ll i = 0; i < edges[x].size(); i++)
        {
            if (dist[edges[x][i]] > dist[x] + 1)
            {
                dist[edges[x][i]] = dist[x] + 1;

                prev[edges[x][i]] = x;

                Q.push(edges[x][i]);
            }
        }
    }

    if (dist[end] == INT_MAX)
        return false;

    return true;
}


/*


std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll> >, std::greater<std::pair<ll, ll> > > Q;

    Q.push(std::make_pair(dist[u], u));

    while (!Q.empty())
    {
        std::pair<ll, ll> x = Q.top();
        Q.pop();

        if (vi[x.second])
            continue;

        vi[x.second] = true;

        for (ll i = 0; i < edges[x.second].size(); i++)
        {
            if (dist[edges[x.second][i]] > dist[x.second] + )
        }
    }


*/
