#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
constexpr long long INF = 1LL << 60;
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
typedef long long ll;
typedef unsigned long long ull;
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
  
  int size(int x){
    x = root(x);
    return num[x];
   }
  
  void merge(int x, int y){
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


// #include <atcoder/all>
// using namespace atcoder;
constexpr long long MOD = 998244353;

template<int MOD>
struct modint {
    ll val;
    constexpr modint(ll v = 0) noexcept : val(v % MOD){
        if(val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr modint operator-() const noexcept { return val ? MOD - val : 0; }
    constexpr modint operator+ (const modint &r) const noexcept { return modint(*this) += r; }
    constexpr modint operator- (const modint &r) const noexcept { return modint(*this) -= r; }
    constexpr modint operator* (const modint &r) const noexcept { return modint(*this) *= r; }
    constexpr modint operator/ (const modint &r) const noexcept { return modint(*this) /= r; }
    constexpr modint& operator++() noexcept {
        val += 1;
        return *this;
    }
    constexpr modint& operator--() noexcept {
        val -= 1;
        return *this;
    }
    constexpr modint& operator+= (const modint &r) noexcept {
        val += r.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator-= (const modint &r) noexcept {
        val -= r.val;
        if(val < 0) val += MOD;
        return *this;
    }
    constexpr modint& operator*= (const modint &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr modint& operator/= (const modint& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator== (const modint &r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!= (const modint &r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator >> (istream &is, modint<MOD>& x) noexcept {
        is >> x.val;
        x += 0;
        return is;
    }
    friend constexpr ostream& operator << (ostream &os, const modint<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr modint<MOD> modpow(const modint<MOD> &a, long long n) noexcept {
        if(n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if(n & 1) t = t * a;
        return t;
    }
};
using mint = modint<MOD>;
/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll N, K;
    cin >> N >> K;
    vec2 A(N, vec(N));
    cin >> A;

    UnionFind rows(N);
    UnionFind cols(N);

    rep(x, N){
        rep(y, N) if(x < y){
            bool pos_row = true;
            bool pos_col = true;
            rep(i, N) if (A[i][x] + A[i][y] > K) pos_row = false;
            rep(i, N) if(A[x][i] + A[y][i] > K) pos_col = false;
            if(pos_row){
                rows.merge(x, y);
            }

            if(pos_col){
                cols.merge(x, y);
            }
        }
    }

    set<ll> R, C;
    rep(i, N){
        R.insert(rows.root(i));
        C.insert(cols.root(i));
    }

    map<ll, mint> perm;
    mint p = 1;
    for(ll i = 1; i <= N; ++i){
        p *= i;
        perm[i] = p;
    }
    perm[1] = 1;

    mint ans = 1;
    for(auto r : R) ans *= perm[rows.size(r)];
    for(auto c : C) ans *= perm[cols.size(c)];

    print(ans);

    return 0;
}