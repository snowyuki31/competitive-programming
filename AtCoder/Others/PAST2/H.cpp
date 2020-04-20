#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
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

//f :　単調性の関数
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
double trisearch(S left, T right, F f, double precision = 1e-10){
    double low = left, high = right;
    while(high - low > precision){
        double mid_left = high / 3 + low * 2 / 3;
        double mid_right = high * 2 / 3 + low / 3;
        if(f(mid_left) >= f(mid_right)) low = mid_left;
        else high = mid_right;
    }
    return high;
}

/*---------------------------------Grid Template------------------------------------------*/
vector<string> getGrid(int H, int W){
    vector<string> grid;
    string s;
    for (int i = 0; i < H; ++i){
        cin >> s;
        grid.pb(s);
    }
    return grid;
}

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
vector<ll> dijkstra(Graph &g, ll s){
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


/*------------------------------- Main Code Here -----------------------------------------*/

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> grid = getGrid(H, W);

    vector<char> ls = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'G'};

    Graph G(H * W);

    char prev = 'S';
    for(auto l : ls){
        ll ct = 0;
        rep(I, H) rep(J, W) if(grid[I][J] == prev) rep(i, H) rep(j, W) if(grid[i][j] == l){
            ll dist = abs(I - i) + abs(J - j);
            ll from = I * W + J;
            ll to = i * W + j;
            add_edge(G, from, to, abs(I - i) + abs(J - j));
            ++ct;
        }
        if(ct == 0) drop(-1);
        prev = l;
    }

    P start, goal;
    rep(i, H) rep(j, W){
        if(grid[i][j] == 'S') start = {i, j};
        if(grid[i][j] == 'G') goal = {i, j};
    }

    auto [i, j] = start;
    vec d = dijkstra(G, i * W + j);

    auto [I, J] = goal;
    print(d[I * W + J]);
    return 0;
}