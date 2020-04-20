#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
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
ll devc(ll x, ll y) { return 1 + (x - 1) / y; }

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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);

    ll N, M;
    cin >> N >> M;
    UnionFind UF(N);

    rep(i, M){
        ll x, y, z;
        cin >> x >> y >> z;
        --x, --y;
        UF.unite(x, y);
    }

    set<ll> st;
    rep(i, N) st.insert(UF.root(i));
    print(len(st));

    return 0;
}