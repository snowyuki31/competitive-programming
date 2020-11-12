#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
constexpr long long INF = 1LL << 60;
constexpr long long MOD = 1000000007;
double PI = acos(-1.0);
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
typedef tuple<ll, ll, ll> tpl;
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

template< typename T >
ostream &operator << (ostream &os, const set< T > &st){
    int ct = 0;
    for(auto& s : st) cout << s << (++ct != st.size() ? " " : "");
    return os;
}

template <typename T>
constexpr set<T> &operator|= (set<T> &st1, const set<T> &st2) { 
    for(auto& s : st2) st1.insert(s);
    return st1; 
}

template <typename T>
constexpr set<T> &operator-= (set<T> &st1, const set<T> &st2) {
    for(auto& s : st2) if(st1.count(s)) st1.erase(s);
    return st1;
}

template <typename T>
constexpr set<T> &operator&= (set<T> &st1, const set<T> &st2) {
    auto itr = st1.begin();
    while(itr != st1.end()){
        if(!st2.count(*itr)) itr = st1.erase(itr);
        else ++itr;
    }
    return st1;
}

template <typename T>
constexpr set<T> operator| (const set<T> &st1, const set<T> &st2) {
    set<T> res = st1;
    res |= st2;
    return res;
}

template <typename T>
constexpr set<T> operator- (const set<T> &st1, const set<T> &st2) {
    set<T> res = st1;
    res -= st2;
    return res;
}

template <typename T>
constexpr set<T> operator& (const set<T> &st1, const set<T> &st2) {
    set<T> res = st1;
    res &= st2;
    return res;
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

template< typename F >
ll ternarySearch(ll L, ll R, F f) { //[L, R)
    ll lo = L - 1, hi = R - 1;
    while (lo + 1 != hi) {
        ll mi = (lo + hi) / 2;
        if (f(mi) <= f(mi + 1)) hi = mi;
        else lo = mi;
    }
    return hi;
}


/*---------------------------------    Graph    ------------------------------------------*/
struct Graph {
    struct Edge {
        ll from, to, weight;
        Edge() : from(0), to(0), weight(0) {}
        Edge(ll f, ll t, ll w) : from(f), to(t), weight(w) {}
    };
    using Edges = vector<Edge>;

    vector<Edges> G;

    Graph() : G() {};

    Graph(int N) : G(N) {}

    Graph(int N, vector<P>& Edges) : G(N){
        for(auto e : Edges) add_arrow(e.first, e.second);
    }

    Graph(int N, vector<tuple<ll, ll, ll>>& Edges) : G(N) {
        for (auto e : Edges) add_arrow(get<0>(e), get<1>(e), get<2>(e));
    }

    Edges operator[](int k) const{
        return G[k];
    }

    int size() const{
        return G.size();
    }

    void resize(int N){
        G.resize(N);
    }

    void add_edge(int a, int b, ll w = 1){
        G[a].emplace_back(a, b, w);
        G[b].emplace_back(b, a, w);
    }

    void add_arrow(int a, int b, ll w = 1){
        G[a].emplace_back(a, b, w);
    }

    //Topological_sort
    //!!ONLY FOR DAG
    vector<ll> topological_sort() const;

    //Dijkstra and related
    template< typename T >
    vector<T> dijkstra(T s, bool restore = false) const;

    vector<ll> shortest_path(ll start, ll goal) const;

    //Warshall-Floyd
    vector<vector<ll>> Warshall_Floyd() const; 

    //Kruskal
    //!!Required UnionFind
    Graph Kruskal() const;
};


template< typename T >vector<T> Graph::dijkstra(T s, bool restore) const{
    vector<T> dist(G.size(), INF);
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);

    vector<T> prev(G.size(), -1);

    while(!que.empty()){
        T cost, idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : G[idx]){
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

vector<ll> Graph::shortest_path(ll start, ll goal) const{
    vector<ll> prev = dijkstra(start, true);
    vector<ll> path;
    for (int cur = goal; cur != -1; cur = prev[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    if (path.front() != start) return {};
    return path;
}

vector<vector<ll>> Graph::Warshall_Floyd() const {
    int N = G.size();
    vector<vector<ll>> d(N, vector<ll>(N));

    rep(i, N) rep(j, N) {
        if (i == j) d[i][j] = 0;
        else d[i][j] = INF;
    }

    rep(i, N) for (auto &e : G[i]) d[i][e.to] = e.weight;
    rep(k, N) rep(i, N) rep(j, N) {
        if (d[i][k] == INF or d[k][j] == INF) continue;
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }
    return d;
}

vector<ll> Graph::topological_sort() const{
    vector<ll> ans;
    int N = G.size();
    vector<int> ind(N);
    rep(i, N) for (auto &e : G[i]) ind[e.to]++;
    queue<int> que;
    rep(i, N) if (!ind[i]) que.push(i);
    while(!que.empty()){
        int now  = que.front();
        ans.pb(now);
        que.pop();
        for(auto& e : G[now]) {
            ind [e.to]--;
            if(!ind[e.to]) que.push(e.to);
        }
    }
    return ans;
}

struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<int> num;
  
  UnionFind(int N) : par(N),rank(N),num(N) {
        for(int i = 0; i < N; i++){ 
          par[i] = i;
          rank[i] = 0;
          num[i] = 1;
        }
   }
      
  void init(int N){
        for(int i = 0; i < N; i++){ 
          par[i] = i;
          rank[i] = 0;
          num[i] = 1;
        }
  }
  
  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  
  int ranker(int x){
    x = root(x);
    return rank[x];
  }
  
  int number(int x){
    x = root(x);
    return num[x];
   }
  
  void unite(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if ( rx == ry ) return;
    if ( rank[rx] < rank[ry] ){
      par[rx] = ry;
      num[ry] += num[rx];
      num[rx] = 0;
    } else {
      par[ry] = rx;
      num[rx] += num[ry];
      num[ry] = 0;
      if ( rank[rx] == rank[ry] ) rank[rx]++;
    }
   }
  
  bool same(int x, int y){
    return root(x) == root(y);
  }
};

Graph Graph::Kruskal() const{
    vector<tpl> E;
    for (auto& g : G) for (auto& e : g) E.emplace_back(e.weight, e.from, e.to);
    sort(E.begin(), E.end());
    Graph res(G.size());
    UnionFind UF(G.size());
    for(auto& e : E){ 
        ll w = get<0>(e), from = get<1>(e), to = get<2>(e);
        if(UF.same(from, to)) continue;
        res.add_arrow(from, to, w);
        UF.unite(from, to);
    }

    return res;
}


/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<tpl> E(M);
    cin >> E;
    Graph G(N, E);
    vec dist = G.dijkstra(s);
    vec res = G.shortest_path(s, t);
    if (res.empty()) drop(-1);

    cout << dist[t] << " " << len(res) - 1 << '\n';
    rep(i, len(res) - 1) cout << res[i] << " " << res[i + 1] << '\n';

    return 0;
}