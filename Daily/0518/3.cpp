#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
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
template<class S, class T> inline bool chmax(S &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline ll msb(ll v) { return 1 << (31 - __builtin_clzll(v)); }
inline ll devc(ll x, ll y) { return (x + y - 1) / y; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

template< typename T1, typename T2 >
ostream &operator << (ostream &os, const pair< T1, T2 > &p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
istream &operator >> (istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T1, typename T2, typename T3 >
ostream &operator << (ostream &os, const tuple< T1, T2, T3 > &t) {
    os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    return os;
}

template< typename T1, typename T2, typename T3 >
istream &operator >> (istream &is, tuple< T1, T2, T3 > &t) {
    is >> get<0>(t) >> get<1>(t) >> get<2>(t);
    return is;
}

template< typename T >
ostream &operator << (ostream &os, const vector< T > &v){
    for (int i = 0; i < (int)v.size(); ++i) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator >>  (istream &is, vector< T > &v){
    for(T &in : v) is >> in;
    return is;
}

/*---------------------------------    Tools    ------------------------------------------*/
template< typename T >
vector<T> cumsum(const vector<T> &X){
    vector<T> res(X.size() + 1, 0);
    for(int i = 0; i < X.size(); ++i) res[i + 1] += res[i] + X[i];
    return res;
}

template< typename S, typename T, typename F>
pair<T, T> bisearch(S left, T right, F f) {
    while(abs(right - left) > 1){
        T mid = (right + left) / 2;
        if(f(mid)) right = mid;
        else left = mid;
    }
    return {left, right};
}

template< typename S, typename T, typename F>
double trisearch(S left, T right, F f, int maxLoop = 90){
    double low = left, high = right;
    while(maxLoop--){
        double mid_left = high / 3 + low * 2 / 3;
        double mid_right = high * 2 / 3 + low / 3;
        if(f(mid_left) >= f(mid_right)) low = mid_left;
        else high = mid_right;
    }
    return (low + high) * 0.5;
}

/*---------------------------------    Graph    ------------------------------------------*/

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

template< typename T >
vector<T> dijkstra(Graph &g, T s, bool restore = false){
    vector<T> dist(g.size(), INF);
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);

    vector<T> prev(g.size(), -1);

    while(!que.empty()){
        T cost, idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]){
            auto next_cost = cost + e.weight;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;

            if(restore) prev[e.to] = e.from;
            que.emplace(dist[e.to], e.to);
        }
    }
    if(restore) return prev;
    return dist;
}

vector<ll> shortest_path(Graph &g, ll start, ll goal){
    vector<ll> prev = dijkstra(g, start, true);
    vector<ll> path;
    for (int cur = goal; cur != -1; cur = prev[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

vector<ll> topological_sort(Graph &G){
    vector<ll> ls;
    vector<ll> visited(G.size(), false);
    auto topo_sort = [&](auto &&self, Graph &g, ll s = 0LL) -> void {
        if (visited[s]) return;
        visited[s] = true;
        for (auto &&e : g[s]) if (!visited[e.to]) self(self, g, e.to);
        ls.pb(s);
    };

    for (int i = 0; i < G.size(); ++i) topo_sort(topo_sort, G, i);
    reverse(ALL(ls));

    return ls;
}

/*------------------------------- Main Code Here -----------------------------------------*/

int main()
{
    ll N, M;
    cin >> N >> M;

    Graph G(N);
    rep(_, M){
        ll u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        add_edge(G, u, v, l);
    }

    ll ans = INF;

    rep(i, N) if(i != 0){
        Graph X = G;
        vector<ll> path = shortest_path(G, 0, i);
        vector<ll> dist = dijkstra(G, 0LL);

        ll sum = dist[i];

        if(dist[i] == INF) continue;

        rep(j, len(path)) for(auto&& e : X[path[j]]){
            if(j < len(path) - 1) if(e.to == path[j + 1]) e.weight = 1e9;
            if(j >= 1) if(e.to == path[j - 1]) e.weight = 1e9;
        }

        vector<ll> dist2 = dijkstra(X, i);


        if(dist2[0] >= 1e9) continue;

        sum += dist2[0];

        chmin(ans, sum);
    }

    print(ans == INF ? -1 : ans);

    return 0;
}