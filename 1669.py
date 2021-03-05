# https://cses.fi/problemset/task/1669

n, m = input().split()
n = int(n)
m = int(m)

import networkx as nx

nodes = [i for i in range(1, n + 1)]

G = nx.DiGraph()
G.add_nodes_from(nodes)

edges = []
for i in range(m):
    x, y = input().split()
    x = int(x)
    y = int(y)
    edges.append((x, y))

G.add_edges_from(edges)

all_cycles = list(nx.simple_cycles(G))

ans = []
long_len = 0

for cyc in all_cycles:
    if len(cyc) > long_len:
        ans = cyc
        long_len = len(cyc)


if (long_len == 0):
    print("IMPOSSIBLE")

else:
    print (long_len + 1)
    print ("{} {}").format(ans, ans[0])