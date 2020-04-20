#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> P;

struct Edge {
    ll from, to, weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(ll f, ll t, ll w) : from(f), to(t), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &g, ll a, ll b, ll w = 1){
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}

//最小共通祖先
//前処理O(N log N)でグラフgの頂点rを根として構築
//クエリO(log N)でグラフgの点u,vの最小共通祖先を取得
//lca lca(g)で構築, lca.query(u, v)で取得
class lca {
public:
    const int n = 0;
    const int log2_n = 0;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;

    lca() {}

    lca(const Graph &g, int root)
        : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
        dfs(g, root, -1, 0);
        for (int k = 0; k + 1 < log2_n; k++) {
            for (int v = 0; v < (int)g.size(); v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(const Graph &g, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto &e : g[v]) {
            if (e.to != p) dfs(g, e.to, v, d + 1);
        }
    }

    ll query(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int k = 0; k < log2_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};