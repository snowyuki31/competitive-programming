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
    ll N;
    cin >> N;
    vec A(N), B(N);

    ll zero = 0;
    map<P, ll> res;

    ll ct = 0;

    rep(i, N){
        cin >> A[i] >> B[i];
        if(A[i] == 0 and B[i] == 0){
            zero++;
            continue;
        }
        if(A[i] == 0) B[i] = 1;
        if(B[i] == 0) A[i] = 1;

        ll a = A[i] / gcd(A[i], B[i]);
        ll b = B[i] / gcd(A[i], B[i]);
        ll sign = 1;
        if(A[i] < 0) sign *= -1;
        if(B[i] < 0) sign *= -1;

        res[{abs(a) * sign, abs(b)}]++;
    }

    mint out = 1, out2 = 1;

    for(auto& [key, val] : res){
        auto [a, b] = key;
        if(a < 0) b *= -1;
        P inv = {-b, abs(a)};

        if(res[inv] == -1) continue;

        //keyを使うとき
        ll ct = val;
        ll ctinv = res[inv];

        mint tp = (modpow(mint(2), ct) - 1) + (modpow(mint(2), ctinv) - 1) + 1;

        val = -1;
       
        if(a == 0 or b == 0) out2 *= tp;
        else out *= tp;
    }

    cerr << out << " " << out2 << endl;

    mint ans = out * out2;
    if(zero) ans += out * (zero + 1);
    --ans;

    print(ans);

    
    return 0;
}