#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
#define to_s to_string
#define len(v) (ll)v.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define print(x) cout << (x) << '\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll MOD = 1e9 + 7;
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

struct UnionFind
{
    vector<int> par;
    vector<int> rank;
    vector<int> num;

    UnionFind(int N) : par(N), rank(N), num(N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i] = 0;
            num[i] = 1;
        }
    }

    void init(int N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
            rank[i] = 0;
            num[i] = 1;
        }
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    int ranker(int x)
    {
        x = root(x);
        return rank[x];
    }

    int number(int x)
    {
        x = root(x);
        return num[x];
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if (rank[rx] < rank[ry])
        {
            par[rx] = ry;
            num[ry] += num[rx];
            num[rx] = 0;
        }
        else
        {
            par[ry] = rx;
            num[rx] += num[ry];
            num[ry] = 0;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;

    map<ll, ll> X, Y;
    UnionFind Group(N);

    ll now = 0;
    rep(i,N){
        ll x, y;
        cin >> x >> y;

        if(X.count(x) == 0 and Y.count(y) == 0){
            X[x] = now, Y[y] = now;
            ++now;
        }else if(X.count(x) == 0){
            X[x] = Y[y];
        }else if(Y.count(y) == 0){
            Y[y] = X[x];
        }else{
            if(X[x] != Y[y]){
                Group.unite(X[x], Y[y]);
            }
        }
    }

    vector<ll> xv(N, 0), yv(N, 0);

    for(auto x : X) ++xv[Group.root(x.second)];
    for(auto y : Y) ++yv[Group.root(y.second)];

    ll ans = 0;
    rep(i, N) ans += xv[i] * yv[i];

    print(ans - N);

    return 0;
}