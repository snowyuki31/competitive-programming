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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll devc(ll x, ll y) { return (x + y - 1) / y; }

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
istream &operator >> (istream &is, vector< T > &v){
    for(T &in : v) is >> in;
    return is;
}

/*----------------------------------Others-----------------------------------------------*/
vector<ll> cumsum(const vector<ll> &X){
    vector<ll> res(X.size() + 1, 0);
    for(ll i = 0; i < X.size(); ++i) res[i + 1] += res[i] + X[i];
    return res;
}

/*-------------------------------Graph Template------------------------------------------*/
template< typename T >
struct Edge{
    int from, to;
    T weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(int from, int to, T weight) : from(from), to(to), weight(weight) {}
};

template< typename T >
using Edges = vector<Edge<T>>;

template< typename T >
using Graph = vector<Edges<T>>;

template< typename T >
void add_edge(Graph<T> &g, int a, int b, T w = 1, bool zero_indexed = true){
    if(zero_indexed) --a, --b;
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}

template< typename T >
vector<T> dijkstra(const Graph<T> &g, int s){
    vector<T> dist(g.size(), INF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    
    while(!que.empty()){
        T cost;
        int idx;
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

/*---------------------------------Tree Template------------------------------------------*/
template <typename T>
using Tree = vector<Edges<T>>;

template< typename T >
istream &operator >> (istream &is, Tree< T > &t){
    int a, b;
    for (int i = 0; i < t.size() - 1; ++ i) is >> a >> b, add_edge(t, a, b);
    return is;
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

/*---------------------------------Main Code Here-----------------------------------------*/
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> grid = getGrid(H, W);




    return 0;
}