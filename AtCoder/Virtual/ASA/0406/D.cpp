#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
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
ll MOD = 1e9 + 7;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

vector<ll> dist(vector<vector<P>> G, ll N, ll K){
    vector<ll> dist(N);
    vector<ll> visit(N, 0);
    dist[K] = 0;

    stack<P> sk;
    sk.push({K, 0});
    while(!sk.empty()){
        P n = sk.top();
        ll now = n.first;
        sk.pop();
        if(visit[now]) continue;
        visit[now] = 1;
        dist[now] = n.second;

        for(auto e : G[now]) if(!visit[e.first]) sk.push({e.first, n.second + e.second});
    }

    return dist;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vector<vector<P>> tree(N);
    rep(i, N - 1){
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        tree[a].pb({b, c});
        tree[b].pb({a, c});
    }
    ll Q, K;
    cin >> Q >> K;
    --K;

    vector<ll> d = dist(tree, N, K);
    rep(i, Q){
        ll x, y;
        cin >> x >> y;
        --x, --y;
        print(d[x] + d[y]);
    }
    return 0;
}