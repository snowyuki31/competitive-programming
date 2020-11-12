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

/*------------------------------- Main Code Here -----------------------------------------*/

int main()
{
    ll N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;

    UnionFind UF(26);

    map<ll, ll> assigned;

    set<ll> used;

    rep(i, N) if(isalpha(S1[i]) and isalpha(S2[i])) UF.unite(S1[i] - 'A', S2[i] - 'A'), used.insert(S1[i] - 'A');
 
    rep(i, N){
        if(isalpha(S1[i]) and isalpha(S2[i])) continue;
        if(!isalpha(S1[i])) swap(S1[i], S2[i]);

        ll r1 = UF.root(S1[i] - 'A');

        if(assigned.count(r1)){
            if(assigned[r1] != S2[i] - '0') drop(0);
        }
        else{
            assigned[r1] = S2[i] - '0';
        }

        used.insert(r1);
    }

    if(S1[0] == '0' or S2[0] == '0') drop(0);

    set<ll> st;
    ll ans = 1;
    for(auto u : used) if (!assigned.count(u)) st.insert(UF.root(u));

    if(st.empty()) drop(1);


    ans = pow(10, len(st) - 1);

    if(isalpha(S1[0]) and isalpha(S2[0]) and !assigned.count(S1[0])) ans *= 9;
    else ans *= 10;

    print(ans);

    

    return 0;
}