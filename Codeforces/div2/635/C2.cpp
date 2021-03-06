#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MAX max<ll>
#define MIN min<ll>
#define pb push_back
#define to_s to_string
#define len(v) (ll)v.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define print(x) cout << (x) << '\n'
#define drop(x) cout << (x) << '\n', exit(0)
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll devc(ll x, ll y) { return (x + y - 1) / y; }

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

void add_arrow(Graph &g, ll a, ll b, ll w = 1){
    g[a].emplace_back(a, b, w);
}

//ダイクストラ法
//グラフgの1点sからの最短距離をO((E + V) log V)で構築
vector<ll> dijkstra(const Graph &g, ll s){
    vector<ll> dist(g.size(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    
    while(!que.empty()){
        ll cost, idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]){
            auto next_cost = cost + e.weight;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

void dfs(Graph& g, int v,int p, int pos, vector<ll>& ls, vector<ll>& rs){
    ls[v]=pos++;
    for(auto e : g[v]) if(e.to != p) dfs(g, e.to, v, pos, ls, rs);
    rs[v]=pos;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll n, k;
    cin >> n >> k;
    Graph G(n);
    rep(i, n - 1){
        ll x, y;
        cin >> x >> y;
        --x, --y;
        add_edge(G, x, y);
    }
    vec dist = dijkstra(G, 0);
    vec ls(n), rs(n);
    dfs(G, 0, -1, 0, ls, rs);

    vector<tuple<ll,ll,ll>> info(n);
    rep(i, n) info[i] = {dist[i] - (rs[i] - ls[i])/2, dist[i], (rs[i] - ls[i])/2};
    sort(RALL(info));

    ll ans = 0;
    rep(i, k){
        auto [a, b, c] = info[i];
        ans += b - (c - 1);
    }

    print(ans);

    return 0;
}