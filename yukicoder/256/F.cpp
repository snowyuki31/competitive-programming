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

/*----------------------------------- Matrix ---------------------------------------------*/

template< typename T >
struct Matrix{
    vector<vector<T>> mat;
    constexpr Matrix(int n = 1, int m = 1, T v = 0) noexcept : mat(n, vector<T>(m, v)) {}
    constexpr Matrix(vector<vector<T>> v) noexcept: mat(v) {}
    void init(int n, int m, T v = 0) { mat.assign(n, vector<T>(m, v)); }

    size_t size() const { return mat.size(); }

    Matrix<T>& operator = (const Matrix<T> &A){
        mat = A.mat;
        return *this;
    }

    constexpr Matrix operator+(const Matrix &A) const noexcept { return Matrix(*this) += A; }
    constexpr Matrix operator-(const Matrix &A) const noexcept { return Matrix(*this) -= A; }
    constexpr Matrix operator*(const Matrix &A) const noexcept { return Matrix(*this) *= A; }

    constexpr Matrix& operator+=(const Matrix &A) noexcept{
        int n = mat.size(), m = A[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mat[i][j] += A[i][j];
        return *this;
    }

    constexpr Matrix& operator-=(const Matrix &A) noexcept{
        int n = mat.size(), m = A[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mat[i][j] -= A[i][j];
        return *this;
    }

    constexpr Matrix& operator*=(const Matrix &A) noexcept{
        int n = mat.size(), m = A[0].size();
        Matrix<T> res(n, m);
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < A.size(); ++k) 
                    {
                        res[i][j] += (mat[i][k] % MOD) * (A[k][j] % MOD);
                        res[i][j] %= MOD;   
                    }
        mat = res.mat;
        return *this;
    }

    friend constexpr Matrix<T> pow(const Matrix<T> &A, long long n) noexcept{
        Matrix<T> res(A.size(), A.size());
        auto B = A;
        for (int i = 0; i < A.size(); ++i) res[i][i] = 1;
        while(n){
            if(n & 1) res = res * B;
            B *= B;
            n >>= 1;
        }
        return res;
    }
    
    vector<T> &operator[](int i) { return mat[i]; }
    const vector<T> &operator[](int i) const { return mat[i]; }

    friend ostream& operator << (ostream& os, const Matrix<T> &M){
        for (int i = 0; i < M.size(); ++i) os << M[i] << (i == (M.size() - 1) ? "" : "\n");
        return os;
    }
};


/*------------------------------- Main Code Here -----------------------------------------*/
 
int main()
{
    ll K, M, N;
    cin >> K >> M >> N;

    vector<vector<ll>> res(K * K, vector<ll>(K * K));

    vector<ll> init(K * K);

    rep(i, M){
        ll P, Q, R;
        cin >> P >> Q >> R;
        --P, --Q, --R;

        res[Q + R * K][P + Q * K] = 1;

        if(P == 0){
            init[P + Q * K] = 1;
        }
    }

    Matrix<ll> state(res);

    Matrix<ll> ans = pow(state, N - 2);

    vec rem(len(ans));

    rep(i, len(ans)) rep(j, len(ans)){
        rem[i] += (ans[i][j] % MOD) * (init[j] % MOD);
    }

    ll x = 0;
    rep(j, K) x += rem[j] % MOD;

    print(x % MOD);

    return 0;
}